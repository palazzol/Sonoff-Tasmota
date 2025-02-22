/*
  xdsp_05_epaper.ino - Display e-paper support for Sonoff-Tasmota

  Copyright (C) 2019  Theo Arends, Gerhard Mutz and Waveshare

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef USE_SPI
#ifdef USE_DISPLAY
#ifdef USE_DISPLAY_EPAPER_29

#define XDSP_05                5

#define EPD_TOP                12
#define EPD_FONT_HEIGTH        12

#define COLORED                1
#define UNCOLORED              0

// using font 8 is opional (num=3)
// very badly readable, but may be useful for graphs
#define USE_TINY_FONT

#include <epd2in9.h>
#include <epdpaint.h>

//unsigned char image[(EPD_HEIGHT * EPD_WIDTH) / 8];
extern uint8_t *buffer;
uint16_t epd_scroll;

Epd *epd;

/*********************************************************************************************/

void EpdInitDriver29()
{
  if (!Settings.display_model) {
    Settings.display_model = XDSP_05;
  }

  if (XDSP_05 == Settings.display_model) {
    if (Settings.display_width != EPD_WIDTH) {
      Settings.display_width = EPD_WIDTH;
    }
    if (Settings.display_height != EPD_HEIGHT) {
      Settings.display_height = EPD_HEIGHT;
    }

    // allocate screen buffer
    if (buffer) free(buffer);
    buffer=(unsigned char*)calloc((EPD_WIDTH * EPD_HEIGHT) / 8,1);
    if (!buffer) return;

    // init renderer
    epd  = new Epd(EPD_WIDTH,EPD_HEIGHT);

    // whiten display with full update, takes 3 seconds
    if ((pin[GPIO_SPI_CS] < 99) && (pin[GPIO_SPI_CLK] < 99) && (pin[GPIO_SPI_MOSI] < 99)) {
      epd->Begin(pin[GPIO_SPI_CS],pin[GPIO_SPI_MOSI],pin[GPIO_SPI_CLK]);
      AddLog_P2(LOG_LEVEL_DEBUG, PSTR("EPD: HardSPI CS %d, CLK %d, MOSI %d"),pin[GPIO_SPI_CS], pin[GPIO_SPI_CLK], pin[GPIO_SPI_MOSI]);
    }
    else if ((pin[GPIO_SSPI_CS] < 99) && (pin[GPIO_SSPI_SCLK] < 99) && (pin[GPIO_SSPI_MOSI] < 99)) {
      epd->Begin(pin[GPIO_SSPI_CS],pin[GPIO_SSPI_MOSI],pin[GPIO_SSPI_SCLK]);
      AddLog_P2(LOG_LEVEL_DEBUG, PSTR("EPD: SoftSPI CS %d, CLK %d, MOSI %d"),pin[GPIO_SSPI_CS], pin[GPIO_SSPI_SCLK], pin[GPIO_SSPI_MOSI]);
    } else {
      free(buffer);
      return;
    }

    renderer = epd;
    epd->Init(DISPLAY_INIT_FULL);
    epd->Init(DISPLAY_INIT_PARTIAL);
    renderer->DisplayInit(DISPLAY_INIT_MODE,Settings.display_size,Settings.display_rotate,Settings.display_font);

    renderer->setTextColor(1,0);

#ifdef SHOW_SPLASH
    // Welcome text
    renderer->setTextFont(1);
    renderer->DrawStringAt(50, 50, "Waveshare E-Paper Display!", COLORED,0);
    renderer->Updateframe();
    delay(1000);
    renderer->fillScreen(0);
#endif

  }
}

/*********************************************************************************************/



/*********************************************************************************************/

#ifdef USE_DISPLAY_MODES1TO5
#define EPD_FONT_HEIGTH        12
void EpdPrintLog29(void)
{
  disp_refresh--;
  if (!disp_refresh) {
    disp_refresh = Settings.display_refresh;
    if (Settings.display_rotate) {
      if (!disp_screen_buffer_cols) { DisplayAllocScreenBuffer(); }
    }

    char* txt = DisplayLogBuffer('\040');
    if (txt != nullptr) {
      uint8_t size = Settings.display_size;
      uint16_t theight = size * EPD_FONT_HEIGTH;

      renderer->setTextFont(size);
      uint8_t last_row = Settings.display_rows -1;

//      epd_scroll = theight;  // Start below header
      epd_scroll = 0;  // Start at top with no header
      for (uint32_t i = 0; i < last_row; i++) {
        strlcpy(disp_screen_buffer[i], disp_screen_buffer[i +1], disp_screen_buffer_cols);
        renderer->DrawStringAt(0, epd_scroll, disp_screen_buffer[i], COLORED, 0);
        epd_scroll += theight;
      }
      strlcpy(disp_screen_buffer[last_row], txt, disp_screen_buffer_cols);
      DisplayFillScreen(last_row);
      renderer->DrawStringAt(0, epd_scroll, disp_screen_buffer[last_row], COLORED, 0);
//      EpdDisplayFrame();

      AddLog_P2(LOG_LEVEL_DEBUG, PSTR(D_LOG_APPLICATION "[%s]"), txt);
    }
  }
}

void EpdRefresh29(void)  // Every second
{
  if (Settings.display_mode) {  // Mode 0 is User text
/*
    char tftdt[Settings.display_cols[0] +1];
    char date4[11];  // 24-04-2017
    char space[Settings.display_cols[0] - 17];
    char time[9];    // 13:45:43

    EpdSetFont(1);

    snprintf_P(date4, sizeof(date4), PSTR("%02d" D_MONTH_DAY_SEPARATOR "%02d" D_YEAR_MONTH_SEPARATOR "%04d"), RtcTime.day_of_month, RtcTime.month, RtcTime.year);
    memset(space, 0x20, sizeof(space));
    space[sizeof(space) -1] = '\0';
    snprintf_P(time, sizeof(time), PSTR("%02d" D_HOUR_MINUTE_SEPARATOR "%02d" D_MINUTE_SECOND_SEPARATOR "%02d"), RtcTime.hour, RtcTime.minute, RtcTime.second);
    snprintf_P(tftdt, sizeof(tftdt), PSTR("%s%s%s"), date4, space, time);

    EpdDrawStringAt(0, 0, tftdt, COLORED, 0);
*/
    switch (Settings.display_mode) {
      case 1:  // Text
      case 2:  // Local
      case 3:  // Local
      case 4:  // Mqtt
      case 5:  // Mqtt
        EpdPrintLog29();
        renderer->Updateframe();
        break;
    }

//    EpdDisplayFrame();
  }
}

#endif  // USE_DISPLAY_MODES1TO5

/*********************************************************************************************\
 * Interface
\*********************************************************************************************/

bool Xdsp05(uint8_t function)
{
  bool result = false;
    if (FUNC_DISPLAY_INIT_DRIVER == function) {
      EpdInitDriver29();
    }
    else if (XDSP_05 == Settings.display_model) {
      switch (function) {
        case FUNC_DISPLAY_MODEL:
          result = true;
          break;
#ifdef USE_DISPLAY_MODES1TO5
        case FUNC_DISPLAY_EVERY_SECOND:
          EpdRefresh29();
          break;
#endif  // USE_DISPLAY_MODES1TO5
      }
    }
  return result;
}

#endif  // USE_DISPLAY_EPAPER
#endif  // USE_DISPLAY
#endif  // USE_SPI
