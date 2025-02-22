/*
  sv-SE.h - localization for Swedish - Svenska for Sonoff-Tasmota

  Copyright (C) 2019  Gunnar Norin

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

#ifndef _LANGUAGE_SV_SE_H_
#define _LANGUAGE_SV_SE_H_

/*************************** ATTENTION *******************************\
 *
 * Due to memory constraints only UTF-8 is supported.
 * To save code space keep text as short as possible.
 * Time and Date provided by SDK can not be localized (yet).
 * Use online command StateText to translate ON, OFF, HOLD and TOGGLE.
 * Use online command Prefix to translate cmnd, stat and tele.
 *
 * Updated until v6.2.1.11
\*********************************************************************/

//#define LANGUAGE_MODULE_NAME         // Enable to display "Module Generic" (ie Spanish), Disable to display "Generic Module" (ie English)
// https://www.science.co.il/language/Locale-codes.php
#define LANGUAGE_LCID 1053
// HTML (ISO 639-1) Language Code
#define D_HTML_LANGUAGE "sv"

// "2017-03-07T11:08:02" - ISO8601:2004
#define D_YEAR_MONTH_SEPARATOR "-"
#define D_MONTH_DAY_SEPARATOR "-"
#define D_DATE_TIME_SEPARATOR "T"
#define D_HOUR_MINUTE_SEPARATOR ":"
#define D_MINUTE_SECOND_SEPARATOR ":"

#define D_DAY3LIST "SönMånTisOnsTorFreLör"
#define D_MONTH3LIST "JanFebMarAprMajJunJulAugSepOktNovDec"

// Non JSON decimal separator
#define D_DECIMAL_SEPARATOR ","

// Common
#define D_ADMIN "Admin"
#define D_AIR_QUALITY "Luftkvalitet"
#define D_AP "AP"                    // Access Point
#define D_AS "som"
#define D_AUTO "AUTO"
#define D_BLINK "Blinka"
#define D_BLINKOFF "BlinkaAv"
#define D_BOOT_COUNT "Uppstartsräknare"
#define D_BRIGHTLIGHT "Ljust"
#define D_BSSID "BSSId"
#define D_BUTTON "Knapp"
#define D_BY "av"                    // Written by me
#define D_BYTES "Bytes"
#define D_CELSIUS "Celsius"
#define D_CHANNEL "Kanal"
#define D_CO2 "Koldioxid"
#define D_CODE "kod"                // Button code
#define D_COLDLIGHT "Kallt"
#define D_COMMAND "Kommando"
#define D_CONNECTED "Ansluten"
#define D_COUNT "Räkna"
#define D_COUNTER "Räknare"
#define D_CURRENT "Ström"          // As in Voltage and Current
#define D_DATA "Data"
#define D_DARKLIGHT "Mörkt"
#define D_DEBUG "Debug"
#define D_DISABLED "Inaktiverad"
#define D_DISTANCE "Distans"
#define D_DNS_SERVER "DNS-server"
#define D_DONE "Gjort"
#define D_DST_TIME "DST"
#define D_ECO2 "eCO2"
#define D_EMULATION "Emulation"
#define D_ENABLED "Aktiverad"
#define D_ERASE "Ta bort"
#define D_ERROR "Fel"
#define D_FAHRENHEIT "Fahrenheit"
#define D_FAILED "Misslyckades"
#define D_FALLBACK "Reserv"
#define D_FALLBACK_TOPIC "Reservämne"
#define D_FALSE "Falskt"
#define D_FILE "Fil"
#define D_FLOW_RATE "Flow rate"
#define D_FREE_MEMORY "Ledigt minne"
#define D_FREQUENCY "Frekvens"
#define D_GAS "Gas"
#define D_GATEWAY "Gateway"
#define D_GROUP "Grupp"
#define D_HOST "Värd"
#define D_HOSTNAME "Värdnamn"
#define D_HUMIDITY "Fuktighet"
#define D_ILLUMINANCE "Belysnings"
#define D_IMMEDIATE "Omedelbar"      // Button immediate
#define D_INDEX "Index"
#define D_INFO "Info"
#define D_INFRARED "Infraröd"
#define D_INITIALIZED "Initialiserad"
#define D_IP_ADDRESS "IP-adress"
#define D_LIGHT "Ljus"
#define D_LWT "LWT"
#define D_MODULE "Modul"
#define D_MQTT "MQTT"
#define D_MULTI_PRESS "fler tryck"
#define D_NOISE "Oväsen"
#define D_NONE "Ingen"
#define D_OFF "Av"
#define D_OFFLINE "Off-line"
#define D_OK "Ok"
#define D_ON "På"
#define D_ONLINE "Ansluten"
#define D_PASSWORD "Lösenord"
#define D_PORT "Port"
#define D_POWER_FACTOR "Spänningsfaktor"
#define D_POWERUSAGE "Spänning"
#define D_POWERUSAGE_ACTIVE "Aktiv spänning"
#define D_POWERUSAGE_APPARENT "Skenbar spänning"
#define D_POWERUSAGE_REACTIVE "Responsiv spänning"
#define D_PRESSURE "Tryck"
#define D_PRESSUREATSEALEVEL "Havstryck"
#define D_PROGRAM_FLASH_SIZE "Program-flashstorlek"
#define D_PROGRAM_SIZE "Programstorlek"
#define D_PROJECT "Projekt"
#define D_RAIN "Regn"
#define D_RECEIVED "Mottagen"
#define D_RESTART "Omstart"
#define D_RESTARTING "Startar om"
#define D_RESTART_REASON "Omstartsorsak"
#define D_RESTORE "återställ"
#define D_RETAINED "bevarad"
#define D_RULE "Regel"
#define D_SAVE "Spara"
#define D_SENSOR "Sensor"
#define D_SSID "SSId"
#define D_START "Starta"
#define D_STD_TIME "STD"
#define D_STOP "Stoppa"
#define D_SUBNET_MASK "Nätmask"
#define D_SUBSCRIBE_TO "Prenumera på"
#define D_UNSUBSCRIBE_FROM "Unsubscribe from"
#define D_SUCCESSFUL "Lyckat"
#define D_SUNRISE "Soluppgång"
#define D_SUNSET "Solnedgång"
#define D_TEMPERATURE "Temperatur"
#define D_TO "till"
#define D_TOGGLE "Växla"
#define D_TOPIC "Ämne"
#define D_TOTAL_USAGE "Total Usage"
#define D_TRANSMIT "Sänd"
#define D_TRUE "Sant"
#define D_TVOC "TVOC"
#define D_UPGRADE "uppgradera"
#define D_UPLOAD "Ladda upp"
#define D_UPTIME "Upptid"
#define D_USER "Användare"
#define D_UTC_TIME "UTC"
#define D_UV_INDEX "UV Index"
#define D_UV_INDEX_1 "Låg"
#define D_UV_INDEX_2 "Med"
#define D_UV_INDEX_3 "Hög"
#define D_UV_INDEX_4 "Farligt"
#define D_UV_INDEX_5 "Skadligt"
#define D_UV_INDEX_6 "Extremt"
#define D_UV_INDEX_7 "UO"         // Out of Range
#define D_UV_LEVEL "UV nivå"
#define D_UV_POWER "UV kraft"
#define D_VERSION "Version"
#define D_VOLTAGE "Volttal"
#define D_WEIGHT "Vikt"
#define D_WARMLIGHT "Varm"
#define D_WEB_SERVER "Webbserver"

// sonoff.ino
#define D_WARNING_MINIMAL_VERSION "VARNING Denna version supporterar inte beständiga inställningar"
#define D_LEVEL_10 "nivå 1-0"
#define D_LEVEL_01 "nivå 0-1"
#define D_SERIAL_LOGGING_DISABLED "Seriell loggning inaktiverad"
#define D_SYSLOG_LOGGING_REENABLED "Syslog återaktiverad"

#define D_SET_BAUDRATE_TO "Ange Baudrate till"
#define D_RECEIVED_TOPIC "Mottaget ämne"
#define D_DATA_SIZE "Datastorlek"
#define D_ANALOG_INPUT "Analog"

// support.ino
#define D_OSWATCH "osWatch"
#define D_BLOCKED_LOOP "Blockerad loop"
#define D_WPS_FAILED_WITH_STATUS "WPS-konfigurering MISSLYCKADES med status"
#define D_ACTIVE_FOR_3_MINUTES "aktiv för 3 minuter"
#define D_FAILED_TO_START "misslyckades att starta"
#define D_PATCH_ISSUE_2186 "Laga problem 2186"
#define D_CONNECTING_TO_AP "Ansluter till AP"
#define D_IN_MODE "i läge"
#define D_CONNECT_FAILED_NO_IP_ADDRESS "Anslutning misslyckades mottog ingen IP-adress"
#define D_CONNECT_FAILED_AP_NOT_REACHED "Anslutning misslyckades, kunde inte nå AP"
#define D_CONNECT_FAILED_WRONG_PASSWORD "Anslutning misslyckades, fel lösenord för AP"
#define D_CONNECT_FAILED_AP_TIMEOUT "Anslutning misslyckadess med AP, timeout"
#define D_ATTEMPTING_CONNECTION "Försöker ansluta..."
#define D_CHECKING_CONNECTION "Kontrollerar anslutning..."
#define D_QUERY_DONE "Fråga utförd. MQTT-tjänster hittades"
#define D_MQTT_SERVICE_FOUND "MQTT-tjänst hittades på"
#define D_FOUND_AT "hittades vid"
#define D_SYSLOG_HOST_NOT_FOUND "Syslog-värd hittades inte"

// settings.ino
#define D_SAVED_TO_FLASH_AT "Sparade till flash vid"
#define D_LOADED_FROM_FLASH_AT "Laddade från flash vid"
#define D_USE_DEFAULTS "Använd standard"
#define D_ERASED_SECTOR "Rensade sektor"

// xdrv_02_webserver.ino
#define D_NOSCRIPT "För att använda Tasmota, aktivera JavaScript"
#define D_MINIMAL_FIRMWARE_PLEASE_UPGRADE "MINIMAL firmware<br>var god uppgradera"
#define D_WEBSERVER_ACTIVE_ON "Webbserver aktiv på"
#define D_WITH_IP_ADDRESS "med IP-adress"
#define D_WEBSERVER_STOPPED "Webbserver stoppad"
#define D_FILE_NOT_FOUND "Filen hittades inte"
#define D_REDIRECTED "Omdirigerad till fångstportal"
#define D_WIFIMANAGER_SET_ACCESSPOINT_AND_STATION "Wifihanterare ange accesspunkt och behåll station"
#define D_WIFIMANAGER_SET_ACCESSPOINT "Wifihanterare ange accesspunkt"
#define D_TRYING_TO_CONNECT "Försöker att ansluta enheten till nätverk"

#define D_RESTART_IN "Omstart om"
#define D_SECONDS "sekunder"
#define D_DEVICE_WILL_RESTART "Enheten kommer att starta om inom ett antal sekunder"
#define D_BUTTON_TOGGLE "Växla"
#define D_CONFIGURATION "Konfigurering"
#define D_INFORMATION "Information"
#define D_FIRMWARE_UPGRADE "Uppgradera firmware"
#define D_CONSOLE "Konsol"
#define D_CONFIRM_RESTART "Bekräfta omstart"

#define D_CONFIGURE_MODULE "Konfigurera modul"
#define D_CONFIGURE_WIFI "Konfigurera WiFi"
#define D_CONFIGURE_MQTT "Konfigurera MQTT"
#define D_CONFIGURE_DOMOTICZ "Konfigurera Domoticz"
#define D_CONFIGURE_LOGGING "Konfigurera loggning"
#define D_CONFIGURE_OTHER "Konfigurera annat"
#define D_CONFIRM_RESET_CONFIGURATION "Bekräfta nollställning av konfiguration"
#define D_RESET_CONFIGURATION "Nollställ konfiguration"
#define D_BACKUP_CONFIGURATION "Säkerhetskopiera konfiguration"
#define D_RESTORE_CONFIGURATION "Återställ konfiguration"
#define D_MAIN_MENU "Huvudmeny"

#define D_MODULE_PARAMETERS "Modulparameterar"
#define D_MODULE_TYPE "Modultyp"
#define D_PULLUP_ENABLE "Ingen knapp/brytare pull-up"
#define D_ADC "ADC"
#define D_GPIO "GPIO"
#define D_SERIAL_IN "Seriell in"
#define D_SERIAL_OUT "Seriell ut"

#define D_WIFI_PARAMETERS "Wifi-parameterar"
#define D_SCAN_FOR_WIFI_NETWORKS "Skanna efter wifi-nätverk"
#define D_SCAN_DONE "Skanning slutförd"
#define D_NO_NETWORKS_FOUND "Inga nätverk hittades"
#define D_REFRESH_TO_SCAN_AGAIN "Uppdatera för att skanna igen"
#define D_DUPLICATE_ACCESSPOINT "Dubblett accesspunkt"
#define D_SKIPPING_LOW_QUALITY "Hoppa över pga dålig kvalitet"
#define D_RSSI "RSSI"
#define D_WEP "WEP"
#define D_WPA_PSK "WPA PSK"
#define D_WPA2_PSK "WPA2 PSK"
#define D_AP1_SSID "AP1 SSId"
#define D_AP1_PASSWORD "AP1 lösenord"
#define D_AP2_SSID "AP2 SSId"
#define D_AP2_PASSWORD "AP2 lösenord"

#define D_MQTT_PARAMETERS "MQTT-parameterar"
#define D_CLIENT "Klient"
#define D_FULL_TOPIC "Fullt ämne"

#define D_LOGGING_PARAMETERS "Loggningsparametrar"
#define D_SERIAL_LOG_LEVEL "Seriell loggnivå"
#define D_WEB_LOG_LEVEL "Webb loggnivå"
#define D_SYS_LOG_LEVEL "Syslog-nivå"
#define D_MORE_DEBUG "Mer debugging"
#define D_SYSLOG_HOST "Syslog-värd"
#define D_SYSLOG_PORT "Syslog-port"
#define D_TELEMETRY_PERIOD "Telemetriperiod"

#define D_OTHER_PARAMETERS "Andra parametrar"
#define D_TEMPLATE "Template"
#define D_ACTIVATE "Activate"
#define D_WEB_ADMIN_PASSWORD "Webbadmin-lösenord"
#define D_MQTT_ENABLE "MQTT aktivera"
#define D_FRIENDLY_NAME "Läsbart namn"
#define D_BELKIN_WEMO "Belkin WeMo"
#define D_HUE_BRIDGE "Hue Bridge"
#define D_SINGLE_DEVICE "soloenhet"
#define D_MULTI_DEVICE "multienhet"

#define D_CONFIGURE_TEMPLATE "Configure Template"
#define D_TEMPLATE_PARAMETERS "Template parameters"
#define D_TEMPLATE_NAME "Name"
#define D_BASE_TYPE "Based on"
#define D_TEMPLATE_FLAGS "Options"

#define D_SAVE_CONFIGURATION "Spara konfiguration"
#define D_CONFIGURATION_SAVED "Konfiguration sparad"
#define D_CONFIGURATION_RESET "Konfiguration nollställd"

#define D_PROGRAM_VERSION "Programversion"
#define D_BUILD_DATE_AND_TIME "Kompilerings datum & tid"
#define D_CORE_AND_SDK_VERSION "Core/SDK version"
#define D_FLASH_WRITE_COUNT "Flash-skrivningsräknare"
#define D_MAC_ADDRESS "MAC-adress"
#define D_MQTT_HOST "MQTT-värd"
#define D_MQTT_PORT "MQTT-port"
#define D_MQTT_CLIENT "MQTT-klient"
#define D_MQTT_USER "MQTT-användare"
#define D_MQTT_TOPIC "MQTT-ämne"
#define D_MQTT_GROUP_TOPIC "MQTT gruppämne"
#define D_MQTT_FULL_TOPIC "MQTT fullt ämne"
#define D_MDNS_DISCOVERY "mDNS upptäckning"
#define D_MDNS_ADVERTISE "mDNS annonsering"
#define D_ESP_CHIP_ID "ESP Chip Id"
#define D_FLASH_CHIP_ID "Flash Chip Id"
#define D_FLASH_CHIP_SIZE "Flash-storlek"
#define D_FREE_PROGRAM_SPACE "Ledigt programutrymme"

#define D_UPGRADE_BY_WEBSERVER "Uppgradering via webbserver"
#define D_OTA_URL "OTA Url"
#define D_START_UPGRADE "Starta uppdatering"
#define D_UPGRADE_BY_FILE_UPLOAD "Uppgradering via filuppladdning"
#define D_UPLOAD_STARTED "Uppladdning startad"
#define D_UPGRADE_STARTED "Uppgradeing startad"
#define D_UPLOAD_DONE "Uppladdning klar"
#define D_UPLOAD_ERR_1 "Ingen fil vald"
#define D_UPLOAD_ERR_2 "Inte tillräckligt med ledigt utrymme"
#define D_UPLOAD_ERR_3 "Magisk byte är inte 0xE9"
#define D_UPLOAD_ERR_4 "Programmets flashstorlek är större än den verkliga flashstorleken"
#define D_UPLOAD_ERR_5 "Uppladdningbuffert stämmer inte överens"
#define D_UPLOAD_ERR_6 "Uppladdning misslyckad. Aktivera loggning 3"
#define D_UPLOAD_ERR_7 "Uppladdning avbruten"
#define D_UPLOAD_ERR_8 "Ogiltig fil"
#define D_UPLOAD_ERR_9 "För stor fil"
#define D_UPLOAD_ERR_10 "Misslyckades initera RF chip"
#define D_UPLOAD_ERR_11 "Misslyckades rensa RF chip"
#define D_UPLOAD_ERR_12 "Misslyckades skriva till RF chip"
#define D_UPLOAD_ERR_13 "Misslyckades avkoda RF firmware"
#define D_UPLOAD_ERROR_CODE "Uppladdningsfelkod"

#define D_ENTER_COMMAND "Ange kommando"
#define D_ENABLE_WEBLOG_FOR_RESPONSE "Aktivera webblogg 2 om svar förväntas"
#define D_NEED_USER_AND_PASSWORD "Behöver user=<användarnamn>&password=<lösenord>"

// xdrv_01_mqtt.ino
#define D_FINGERPRINT "Verifierar TLS fingeravtryck..."
#define D_TLS_CONNECT_FAILED_TO "TLS-anslutning misslyckades"
#define D_RETRY_IN "Försöker igen om"
#define D_VERIFIED "Verifierad med fingeravtryck"
#define D_INSECURE "Osäker anslutning pga ogiltigt fingeravtryck"
#define D_CONNECT_FAILED_TO "Anslutning misslyckades"

// xplg_wemohue.ino
#define D_MULTICAST_DISABLED "Multicast inaktiverad"
#define D_MULTICAST_REJOINED "Multicast (åter)anslöt"
#define D_MULTICAST_JOIN_FAILED "Multicast anslutning misslyckades"
#define D_FAILED_TO_SEND_RESPONSE "Misslyckades skicka svar"

#define D_WEMO "WeMo"
#define D_WEMO_BASIC_EVENT "WeMo standardhändelse"
#define D_WEMO_EVENT_SERVICE "WeMo händelsetjänst"
#define D_WEMO_META_SERVICE "WeMo metatjänst"
#define D_WEMO_SETUP "WeMo installation"
#define D_RESPONSE_SENT "Svar skickat"

#define D_HUE "Hue"
#define D_HUE_BRIDGE_SETUP "Hue installation"
#define D_HUE_API_NOT_IMPLEMENTED "Hue API inte implementerat"
#define D_HUE_API "Hue API"
#define D_HUE_POST_ARGS "Hue POST args"
#define D_3_RESPONSE_PACKETS_SENT "3 svarspaket skickade"

// xdrv_07_domoticz.ino
#define D_DOMOTICZ_PARAMETERS "Domoticz parametetrar"
#define D_DOMOTICZ_IDX "Idx"
#define D_DOMOTICZ_KEY_IDX "Nyckel idx"
#define D_DOMOTICZ_SWITCH_IDX "Switch idx"
#define D_DOMOTICZ_SENSOR_IDX "Sensor idx"
  #define D_DOMOTICZ_TEMP "Temp"
  #define D_DOMOTICZ_TEMP_HUM "Temp,Fuk"
  #define D_DOMOTICZ_TEMP_HUM_BARO "Temp,Fuk,Baro"
  #define D_DOMOTICZ_POWER_ENERGY "Spänning,Energi"
  #define D_DOMOTICZ_ILLUMINANCE "Belysningsstyrka"
  #define D_DOMOTICZ_COUNT "Antal/PM1"
  #define D_DOMOTICZ_VOLTAGE "Volt/PM2.5"
  #define D_DOMOTICZ_CURRENT "Ström/PM10"
  #define D_DOMOTICZ_AIRQUALITY "Luftkvalitet"
  #define D_DOMOTICZ_P1_SMART_METER "P1SmartMeter"
#define D_DOMOTICZ_UPDATE_TIMER "Uppdatera timer"

// xdrv_09_timers.ino
#define D_CONFIGURE_TIMER "Konfigurera timer"
#define D_TIMER_PARAMETERS "Timerparametrar"
#define D_TIMER_ENABLE "Aktivera timer"
#define D_TIMER_ARM "Aktivera"
#define D_TIMER_TIME "Tid"
#define D_TIMER_DAYS "Dagar"
#define D_TIMER_REPEAT "Repetera"
#define D_TIMER_OUTPUT "Utgång"
#define D_TIMER_ACTION "Åtgärd"

// xdrv_10_knx.ino
#define D_CONFIGURE_KNX "Konfigurera KNX"
#define D_KNX_PARAMETERS "KNX Parametrar"
#define D_KNX_GENERAL_CONFIG "Allmänt"
#define D_KNX_PHYSICAL_ADDRESS "Fysisk adress"
#define D_KNX_PHYSICAL_ADDRESS_NOTE "( Måste vara unik på KNX-nätverket )"
#define D_KNX_ENABLE "Aktivera KNX"
#define D_KNX_GROUP_ADDRESS_TO_WRITE "Data att skicka till gruppadresser"
#define D_ADD "Lägg till"
#define D_DELETE "Ta bort"
#define D_REPLY "Svara"
#define D_KNX_GROUP_ADDRESS_TO_READ "Gruppadresser att ta emot data från"
#define D_LOG_KNX "KNX: "
#define D_RECEIVED_FROM "Mottagen från"
#define D_KNX_COMMAND_WRITE "Skriv"
#define D_KNX_COMMAND_READ "Läs"
#define D_KNX_COMMAND_OTHER "Andra"
#define D_SENT_TO "skickad till"
#define D_KNX_WARNING "Gruppadressen ( 0 / 0 / 0 ) är reserverad och kan inte användas."
#define D_KNX_ENHANCEMENT "Kommuniceringsförbättring"
#define D_KNX_TX_SLOT "KNX TX"
#define D_KNX_RX_SLOT "KNX RX"

// xdrv_03_energy.ino
#define D_ENERGY_TODAY "Energi idag"
#define D_ENERGY_YESTERDAY "Energi igår"
#define D_ENERGY_TOTAL "Energi totalt"

// xsns_05_ds18b20.ino
#define D_SENSOR_BUSY "Sensor upptagen"
#define D_SENSOR_CRC_ERROR "Sensor CRC-fel"
#define D_SENSORS_FOUND "Sensorer hittades"

// xsns_06_dht.ino
#define D_TIMEOUT_WAITING_FOR "Timeout under väntan"
#define D_START_SIGNAL_LOW "startsignal låg"
#define D_START_SIGNAL_HIGH "startsignal hög"
#define D_PULSE "puls"
#define D_CHECKSUM_FAILURE "Fel kontrollsumma"

// xsns_07_sht1x.ino
#define D_SENSOR_DID_NOT_ACK_COMMAND "Sensor besvarade inte med ACK kommando"
#define D_SHT1X_FOUND "SHT1X hittades"

// xsns_18_pms5003.ino
#define D_STANDARD_CONCENTRATION "CF-1 PM"     // Standard Particle CF-1 Particle Matter
#define D_ENVIRONMENTAL_CONCENTRATION "PM"     // Environmetal Particle Matter
#define D_PARTICALS_BEYOND "Partiklar"

// xsns_32_mpu6050.ino
#define D_AX_AXIS "Accel. X-Axel"
#define D_AY_AXIS "Accel. Y-Axel"
#define D_AZ_AXIS "Accel. Z-Axel"
#define D_GX_AXIS "Gyro X-Axel"
#define D_GY_AXIS "Gyro Y-Axel"
#define D_GZ_AXIS "Gyro Z-Axel"

// xsns_34_hx711.ino
#define D_HX_CAL_REMOVE "Ta bort vikter"
#define D_HX_CAL_REFERENCE "Ladda referensvikt"
#define D_HX_CAL_DONE "Kalibrerad"
#define D_HX_CAL_FAIL "Kalibrering misslyckad"
#define D_RESET_HX711 "Återställ våg"
#define D_CONFIGURE_HX711 "Konfigurera våg"
#define D_HX711_PARAMETERS "Vågparametrar"
#define D_ITEM_WEIGHT "Objektsvikt"
#define D_REFERENCE_WEIGHT "Referensvikt"
#define D_CALIBRATE "Kalibrera"
#define D_CALIBRATION "Kalibrering"

//xsns_35_tx20.ino
#define D_TX20_WIND_DIRECTION "Vindriktning"
#define D_TX20_WIND_SPEED "Vindstyrka"
#define D_TX20_WIND_SPEED_AVG "Vindstyrka medel"
#define D_TX20_WIND_SPEED_MAX "Vindstyrka max"
#define D_TX20_NORTH "N"
#define D_TX20_EAST "Ö"
#define D_TX20_SOUTH "S"
#define D_TX20_WEST "V"

//xsns_43_hre.ino
#define D_LOG_HRE "HRE: "

// sonoff_template.h - keep them as short as possible to be able to fit them in GUI drop down box
#define D_SENSOR_NONE          "Ingen"
#define D_SENSOR_USER          "User"
#define D_SENSOR_DHT11         "DHT11"
#define D_SENSOR_AM2301        "AM2301"
#define D_SENSOR_SI7021        "SI7021"
#define D_SENSOR_DS18X20       "DS18x20"
#define D_SENSOR_I2C_SCL       "I2C SCL"
#define D_SENSOR_I2C_SDA       "I2C SDA"
#define D_SENSOR_WS2812        "WS2812"
#define D_SENSOR_DFR562        "MP3-spelare"
#define D_SENSOR_IRSEND        "IRsend"
#define D_SENSOR_SWITCH        "Omkopplare"  // Suffix "1"
#define D_SENSOR_BUTTON        "Knapp"      // Suffix "1"
#define D_SENSOR_RELAY         "Relä"       // Suffix "1i"
#define D_SENSOR_LED           "Led"        // Suffix "1i"
#define D_SENSOR_LED_LINK      "LedLink"    // Suffix "i"
#define D_SENSOR_PWM           "PWM"        // Suffix "1"
#define D_SENSOR_COUNTER       "Räknare"    // Suffix "1"
#define D_SENSOR_IRRECV        "IRrecv"
#define D_SENSOR_MHZ_RX        "MHZ Rx"
#define D_SENSOR_MHZ_TX        "MHZ Tx"
#define D_SENSOR_PZEM004_RX    "PZEM004 Rx"
#define D_SENSOR_PZEM016_RX    "PZEM016 Rx"
#define D_SENSOR_PZEM017_RX    "PZEM017 Rx"
#define D_SENSOR_PZEM0XX_TX    "PZEM0XX Tx"
#define D_SENSOR_SAIR_RX       "SAir Rx"
#define D_SENSOR_SAIR_TX       "SAir Tx"
#define D_SENSOR_SPI_CS        "SPI CS"
#define D_SENSOR_SPI_DC        "SPI DC"
#define D_SENSOR_BACKLIGHT     "Backlight"
#define D_SENSOR_PMS5003       "PMS5003"
#define D_SENSOR_SDS0X1_RX     "SDS0X1 Rx"
#define D_SENSOR_SDS0X1_TX     "SDS0X1 Tx"
#define D_SENSOR_SBR_RX        "SerBr Rx"
#define D_SENSOR_SBR_TX        "SerBr Tx"
#define D_SENSOR_SR04_TRIG     "SR04 Tri"
#define D_SENSOR_SR04_ECHO     "SR04 Ech"
#define D_SENSOR_SDM120_TX     "SDMx20 Tx"
#define D_SENSOR_SDM120_RX     "SDMx20 Rx"
#define D_SENSOR_SDM630_TX     "SDM630 Tx"
#define D_SENSOR_SDM630_RX     "SDM630 Rx"
#define D_SENSOR_TM1638_CLK    "TM16 CLK"
#define D_SENSOR_TM1638_DIO    "TM16 DIO"
#define D_SENSOR_TM1638_STB    "TM16 STB"
#define D_SENSOR_HX711_SCK     "HX711 SCK"
#define D_SENSOR_HX711_DAT     "HX711 DAT"
#define D_SENSOR_TX20_TX       "TX20"
#define D_SENSOR_RFSEND        "RFSend"
#define D_SENSOR_RFRECV        "RFrecv"
#define D_SENSOR_TUYA_TX       "Tuya Tx"
#define D_SENSOR_TUYA_RX       "Tuya Rx"
#define D_SENSOR_MGC3130_XFER  "MGC3130 Xfr"
#define D_SENSOR_MGC3130_RESET "MGC3130 Rst"
#define D_SENSOR_SSPI_MISO     "SSPI MISO"
#define D_SENSOR_SSPI_MOSI     "SSPI MOSI"
#define D_SENSOR_SSPI_SCLK     "SSPI SCLK"
#define D_SENSOR_SSPI_CS       "SSPI CS"
#define D_SENSOR_SSPI_DC       "SSPI DC"
#define D_SENSOR_RF_SENSOR     "RF Sensor"
#define D_SENSOR_AZ_RX         "AZ Rx"
#define D_SENSOR_AZ_TX         "AZ Tx"
#define D_SENSOR_MAX31855_CS   "MX31855 CS"
#define D_SENSOR_MAX31855_CLK  "MX31855 CLK"
#define D_SENSOR_MAX31855_DO   "MX31855 DO"
#define D_SENSOR_NRG_SEL       "HLWBL SEL"  // Suffix "i"
#define D_SENSOR_NRG_CF1       "HLWBL CF1"
#define D_SENSOR_HLW_CF        "HLW8012 CF"
#define D_SENSOR_HJL_CF        "BL0937 CF"
#define D_SENSOR_MCP39F5_TX    "MCP39F5 Tx"
#define D_SENSOR_MCP39F5_RX    "MCP39F5 Rx"
#define D_SENSOR_MCP39F5_RST   "MCP39F5 Rst"
#define D_SENSOR_CSE7766_TX    "CSE7766 Tx"
#define D_SENSOR_CSE7766_RX    "CSE7766 Rx"
#define D_SENSOR_PN532_TX      "PN532 Tx"
#define D_SENSOR_PN532_RX      "PN532 Rx"
#define D_SENSOR_SM16716_CLK   "SM16716 CLK"
#define D_SENSOR_SM16716_DAT   "SM16716 DAT"
#define D_SENSOR_SM16716_POWER "SM16716 PWR"
#define D_SENSOR_MY92X1_DI     "MY92x1 DI"
#define D_SENSOR_MY92X1_DCKI   "MY92x1 DCKI"
#define D_SENSOR_ARIRFRCV      "ALux IrRcv"
#define D_SENSOR_ARIRFSEL      "ALux IrSel"
#define D_SENSOR_TXD           "Serial Tx"
#define D_SENSOR_RXD           "Serial Rx"
#define D_SENSOR_ROTARY        "Rotary"     // Suffix "1A"
#define D_SENSOR_HRE_CLOCK     "HRE Clock"
#define D_SENSOR_HRE_DATA      "HRE Data"
#define D_SENSOR_ADE7953_IRQ   "ADE7953 IRQ"
#define D_SENSOR_BUZZER        "Buzzer"
#define D_SENSOR_OLED_RESET    "OLED Reset"
#define D_SENSOR_ZIGBEE_TXD    "Zigbee Tx"
#define D_SENSOR_ZIGBEE_RXD    "Zigbee Rx"
#define D_SENSOR_SOLAXX1_TX    "SolaxX1 Tx"
#define D_SENSOR_SOLAXX1_RX    "SolaxX1 Rx"
#define D_SENSOR_IBEACON_TX    "iBeacon TX"
#define D_SENSOR_IBEACON_RX    "iBeacon RX"
#define D_SENSOR_RDM6300_RX    "RDM6300 RX"
#define D_SENSOR_CC1101_CS     "CC1101 CS"

// Units
#define D_UNIT_AMPERE "A"
#define D_UNIT_CENTIMETER "cm"
#define D_UNIT_HERTZ "Hz"
#define D_UNIT_HOUR "Tim"
#define D_UNIT_GALLONS "gal"
#define D_UNIT_GALLONS_PER_MIN "g/m"
#define D_UNIT_INCREMENTS "ink"
#define D_UNIT_KILOGRAM "kg"
#define D_UNIT_KILOMETER_PER_HOUR "km/h"  // or "km/h"
#define D_UNIT_KILOOHM "kOhm"
#define D_UNIT_KILOWATTHOUR "kWh"
#define D_UNIT_LUX "lx"
#define D_UNIT_MICROGRAM_PER_CUBIC_METER "ug/m3"
#define D_UNIT_MICROMETER "um"
#define D_UNIT_MICROSECOND "us"
#define D_UNIT_MILLIAMPERE "mA"
#define D_UNIT_MILLIMETER "mm"
#define D_UNIT_MILLIMETER_MERCURY "mmHg"
#define D_UNIT_MILLISECOND "ms"
#define D_UNIT_MINUTE "Min"
#define D_UNIT_PARTS_PER_BILLION "ppb"
#define D_UNIT_PARTS_PER_DECILITER "ppd"
#define D_UNIT_PARTS_PER_MILLION "ppm"
#define D_UNIT_PRESSURE "hPa"
#define D_UNIT_SECOND "sek"
#define D_UNIT_SECTORS "sektorer"
#define D_UNIT_VA "VA"
#define D_UNIT_VAR "VAr"
#define D_UNIT_VOLT "V"
#define D_UNIT_WATT "W"
#define D_UNIT_WATTHOUR "Wh"
#define D_UNIT_WATT_METER_QUADRAT "W/m²"

// Log message prefix
#define D_LOG_APPLICATION "APP: "  // Application
#define D_LOG_BRIDGE "BRG: "       // Bridge
#define D_LOG_CONFIG "CFG: "       // Settings
#define D_LOG_COMMAND "CMD: "      // Command
#define D_LOG_DEBUG "DBG: "        // Debug
#define D_LOG_DHT "DHT: "          // DHT sensor
#define D_LOG_DOMOTICZ "DOM: "     // Domoticz
#define D_LOG_DSB "DSB: "          // DS18xB20 sensor
#define D_LOG_HTTP "HTP: "         // HTTP webserver
#define D_LOG_I2C "I2C: "          // I2C
#define D_LOG_IRR "IRR: "          // Infra Red Received
#define D_LOG_LOG "LOG: "          // Logging
#define D_LOG_MODULE "MOD: "       // Module
#define D_LOG_MDNS "DNS: "         // mDNS
#define D_LOG_MQTT "MQT: "         // MQTT
#define D_LOG_OTHER "OTH: "        // Other
#define D_LOG_RESULT "RSL: "       // Result
#define D_LOG_RFR "RFR: "          // RF Received
#define D_LOG_SERIAL "SER: "       // Serial
#define D_LOG_SHT1 "SHT: "         // SHT1x sensor
#define D_LOG_UPLOAD "UPL: "       // Upload
#define D_LOG_UPNP "UPP: "         // UPnP
#define D_LOG_WIFI "WIF: "         // Wifi

//SDM220
#define D_PHASE_ANGLE     "Fasvinkel"
#define D_IMPORT_ACTIVE   "Import aktiv"
#define D_EXPORT_ACTIVE   "Export aktiv"
#define D_IMPORT_REACTIVE "Import reaktiv"
#define D_EXPORT_REACTIVE "Export reaktiv"
#define D_TOTAL_REACTIVE  "Total reaktiv"
#define D_UNIT_KWARH      "kVArh"
#define D_UNIT_ANGLE      "Deg"

//SOLAXX1
#define D_PV1_VOLTAGE     "PV1 Voltage"
#define D_PV1_CURRENT     "PV1 Current"
#define D_PV1_POWER       "PV1 Power"
#define D_PV2_VOLTAGE     "PV2 Voltage"
#define D_PV2_CURRENT     "PV2 Current"
#define D_PV2_POWER       "PV2 Power"
#define D_SOLAR_POWER     "Solar Power"
#define D_INVERTER_POWER  "Inverter Power"
#define D_STATUS          "Status"
#define D_WAITING         "Waiting"
#define D_CHECKING        "Checking"
#define D_WORKING         "Working"
#define D_FAILURE         "Failure"
#define D_SOLAX_ERROR_0   "No Error Code"
#define D_SOLAX_ERROR_1   "Grid Lost Fault"
#define D_SOLAX_ERROR_2   "Grid Voltage Fault"
#define D_SOLAX_ERROR_3   "Grid Frequency Fault"
#define D_SOLAX_ERROR_4   "Pv Voltage Fault"
#define D_SOLAX_ERROR_5   "Isolation Fault"
#define D_SOLAX_ERROR_6   "Over Temperature Fault"
#define D_SOLAX_ERROR_7   "Fan Fault"
#define D_SOLAX_ERROR_8   "Other Device Fault"

#endif  // _LANGUAGE_SV_SE_H_
