/*
  support_command.ino - command support for Sonoff-Tasmota

  Copyright (C) 2019  Theo Arends

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

const char kTasmotaCommands[] PROGMEM = "|"  // No prefix
  D_CMND_BACKLOG "|" D_CMND_DELAY "|" D_CMND_POWER "|" D_CMND_STATUS "|" D_CMND_STATE "|" D_CMND_SLEEP "|" D_CMND_UPGRADE "|" D_CMND_UPLOAD "|" D_CMND_OTAURL "|"
  D_CMND_SERIALLOG "|" D_CMND_RESTART "|" D_CMND_POWERONSTATE "|" D_CMND_PULSETIME "|" D_CMND_BLINKTIME "|" D_CMND_BLINKCOUNT "|" D_CMND_SAVEDATA "|"
  D_CMND_SETOPTION "|" D_CMND_TEMPERATURE_RESOLUTION "|" D_CMND_HUMIDITY_RESOLUTION "|" D_CMND_PRESSURE_RESOLUTION "|" D_CMND_POWER_RESOLUTION "|"
  D_CMND_VOLTAGE_RESOLUTION "|" D_CMND_FREQUENCY_RESOLUTION "|" D_CMND_CURRENT_RESOLUTION "|" D_CMND_ENERGY_RESOLUTION "|" D_CMND_WEIGHT_RESOLUTION "|"
  D_CMND_MODULE "|" D_CMND_MODULES "|" D_CMND_GPIO "|" D_CMND_GPIOS "|" D_CMND_TEMPLATE "|" D_CMND_PWM "|" D_CMND_PWMFREQUENCY "|" D_CMND_PWMRANGE "|"
  D_CMND_BUTTONDEBOUNCE "|" D_CMND_SWITCHDEBOUNCE "|" D_CMND_SYSLOG "|" D_CMND_LOGHOST "|" D_CMND_LOGPORT "|" D_CMND_SERIALSEND "|" D_CMND_BAUDRATE "|"
  D_CMND_SERIALDELIMITER "|" D_CMND_IPADDRESS "|" D_CMND_NTPSERVER "|" D_CMND_AP "|" D_CMND_SSID "|" D_CMND_PASSWORD "|" D_CMND_HOSTNAME "|" D_CMND_WIFICONFIG "|"
  D_CMND_FRIENDLYNAME "|" D_CMND_SWITCHMODE "|" D_CMND_INTERLOCK "|" D_CMND_TELEPERIOD "|" D_CMND_RESET "|" D_CMND_TIME "|" D_CMND_TIMEZONE "|" D_CMND_TIMESTD "|"
  D_CMND_TIMEDST "|" D_CMND_ALTITUDE "|" D_CMND_LEDPOWER "|" D_CMND_LEDSTATE "|" D_CMND_LEDMASK "|"
#ifdef USE_I2C
  D_CMND_I2CSCAN "|"
#endif
  D_CMND_SENSOR "|" D_CMND_DRIVER;

void (* const TasmotaCommand[])(void) PROGMEM = {
  &CmndBacklog, &CmndDelay, &CmndPower, &CmndStatus, &CmndState, &CmndSleep, &CmndUpgrade, &CmndUpgrade, &CmndOtaUrl,
  &CmndSeriallog, &CmndRestart, &CmndPowerOnState, &CmndPulsetime, &CmndBlinktime, &CmndBlinkcount, &CmndSavedata,
  &CmndSetoption, &CmndTemperatureResolution, &CmndHumidityResolution, &CmndPressureResolution, &CmndPowerResolution,
  &CmndVoltageResolution, &CmndFrequencyResolution, &CmndCurrentResolution, &CmndEnergyResolution, &CmndWeightResolution,
  &CmndModule, &CmndModules, &CmndGpio, &CmndGpios, &CmndTemplate, &CmndPwm, &CmndPwmfrequency, &CmndPwmrange,
  &CmndButtonDebounce, &CmndSwitchDebounce, &CmndSyslog, &CmndLoghost, &CmndLogport, &CmndSerialSend, &CmndBaudrate,
  &CmndSerialDelimiter, &CmndIpAddress, &CmndNtpServer, &CmndAp, &CmndSsid, &CmndPassword, &CmndHostname, &CmndWifiConfig,
  &CmndFriendlyname, &CmndSwitchMode, &CmndInterlock, &CmndTeleperiod, &CmndReset, &CmndTime, &CmndTimezone, &CmndTimeStd,
  &CmndTimeDst, &CmndAltitude, &CmndLedPower, &CmndLedState, &CmndLedMask,
#ifdef USE_I2C
  &CmndI2cScan,
#endif
  &CmndSensor, &CmndDriver };

/********************************************************************************************/

void ResponseCmndNumber(int value)
{
  Response_P(S_JSON_COMMAND_NVALUE, XdrvMailbox.command, value);
}

void ResponseCmndIdxNumber(int value)
{
  Response_P(S_JSON_COMMAND_INDEX_NVALUE, XdrvMailbox.command, XdrvMailbox.index, value);
}

void ResponseCmndChar(const char* value)
{
  Response_P(S_JSON_COMMAND_SVALUE, XdrvMailbox.command, value);
}

void ResponseCmndStateText(uint32_t value)
{
  ResponseCmndChar(GetStateText(value));
}

void ResponseCmndDone(void)
{
  ResponseCmndChar(D_JSON_DONE);
}

void ResponseCmndIdxChar(const char* value)
{
  Response_P(S_JSON_COMMAND_INDEX_SVALUE, XdrvMailbox.command, XdrvMailbox.index, value);
}

/********************************************************************************************/

void ExecuteCommand(char *cmnd, uint32_t source)
{
  char *start;
  char *token;

#ifdef USE_DEBUG_DRIVER
  ShowFreeMem(PSTR("ExecuteCommand"));
#endif
  ShowSource(source);

  token = strtok(cmnd, " ");
  if (token != nullptr) {
    start = strrchr(token, '/');   // Skip possible cmnd/sonoff/ preamble
    if (start) { token = start +1; }
  }
  uint32_t size = (token != nullptr) ? strlen(token) : 0;
  char stopic[size +2];  // / + \0
  snprintf_P(stopic, sizeof(stopic), PSTR("/%s"), (token == nullptr) ? "" : token);

  token = strtok(nullptr, "");
  size = (token != nullptr) ? strlen(token) : 0;
  char svalue[size +1];
  strlcpy(svalue, (token == nullptr) ? "" : token, sizeof(svalue));       // Fixed 5.8.0b
  CommandHandler(stopic, (uint8_t*)svalue, strlen(svalue));
}

/********************************************************************************************/

// topic:                    /power1  data: toggle  = Console command
// topic:         cmnd/sonoff/power1  data: toggle  = Mqtt command using topic
// topic:        cmnd/sonoffs/power1  data: toggle  = Mqtt command using a group topic
// topic: cmnd/DVES_83BB10_fb/power1  data: toggle  = Mqtt command using fallback topic

void CommandHandler(char* topic, uint8_t* data, uint32_t data_len)
{
#ifdef USE_DEBUG_DRIVER
  ShowFreeMem(PSTR("CommandHandler"));
#endif

  char topicBuf[TOPSZ];
  strlcpy(topicBuf, topic, sizeof(topicBuf));

  uint32_t i = 0;
  for (i = 0; i < data_len; i++) {
    if (!isspace(data[i])) { break; }  // Skip leading spaces in data
  }
  data_len -= i;
  char dataBuf[data_len+1];
  memcpy(dataBuf, data +i, sizeof(dataBuf));

  bool grpflg = (strstr(topicBuf, Settings.mqtt_grptopic) != nullptr);

  char stemp1[TOPSZ];
  GetFallbackTopic_P(stemp1, CMND, "");  // Full Fallback topic = cmnd/DVES_xxxxxxxx_fb/
  fallback_topic_flag = (!strncmp(topicBuf, stemp1, strlen(stemp1)));

  char *type = strrchr(topicBuf, '/');  // Last part of received topic is always the command (type)

  uint32_t index = 1;
  bool user_index = false;
  if (type != nullptr) {
    type++;
    for (i = 0; i < strlen(type); i++) {
      type[i] = toupper(type[i]);
    }
    while (isdigit(type[i-1])) {
      i--;
    }
    if (i < strlen(type)) {
      index = atoi(type +i);
      user_index = true;
    }
    type[i] = '\0';
  }

  DEBUG_CORE_LOG(PSTR("CMD: " D_GROUP " %d, " D_INDEX " %d, " D_COMMAND " \"%s\", " D_DATA " \"%s\""), grpflg, index, type, dataBuf);

  if (type != nullptr) {
    Response_P(PSTR("{\"" D_JSON_COMMAND "\":\"" D_JSON_ERROR "\"}"));

    if (Settings.ledstate &0x02) { blinks++; }

    if (!strcmp(dataBuf,"?")) { data_len = 0; }

    char *p;
    int32_t payload = strtol(dataBuf, &p, 0);  // decimal, octal (0) or hex (0x)
    if (p == dataBuf) { payload = -99; }
    int temp_payload = GetStateNumber(dataBuf);
    if (temp_payload > -1) { payload = temp_payload; }

    DEBUG_CORE_LOG(PSTR("CMD: Payload %d"), payload);

    backlog_delay = millis() + (100 * MIN_BACKLOG_DELAY);

    char command[CMDSZ];
    XdrvMailbox.command = command;
    XdrvMailbox.index = index;
    XdrvMailbox.data_len = data_len;
    XdrvMailbox.payload = payload;
    XdrvMailbox.grpflg = grpflg;
    XdrvMailbox.usridx = user_index;
    XdrvMailbox.topic = type;
    XdrvMailbox.data = dataBuf;

    if (!DecodeCommand(kTasmotaCommands, TasmotaCommand)) {
      if (!XdrvCall(FUNC_COMMAND)) {
        if (!XsnsCall(FUNC_COMMAND)) {
          type = nullptr;  // Unknown command
        }
      }
    }
  }

  if (type == nullptr) {
    blinks = 201;
    snprintf_P(topicBuf, sizeof(topicBuf), PSTR(D_JSON_COMMAND));
    Response_P(PSTR("{\"" D_JSON_COMMAND "\":\"" D_JSON_UNKNOWN "\"}"));
    type = (char*)topicBuf;
  }

  if (mqtt_data[0] != '\0') {
     MqttPublishPrefixTopic_P(RESULT_OR_STAT, type);
#ifdef USE_SCRIPT
     XdrvRulesProcess();
#endif
  }
  fallback_topic_flag = false;
}

/********************************************************************************************/

void CmndBacklog(void)
{
  if (XdrvMailbox.data_len) {
    uint32_t bl_pointer = (!backlog_pointer) ? MAX_BACKLOG -1 : backlog_pointer;
    bl_pointer--;
    char *blcommand = strtok(XdrvMailbox.data, ";");
    while ((blcommand != nullptr) && (backlog_index != bl_pointer)) {
      while(true) {
        blcommand = Trim(blcommand);
        if (!strncasecmp_P(blcommand, PSTR(D_CMND_BACKLOG), strlen(D_CMND_BACKLOG))) {
          blcommand += strlen(D_CMND_BACKLOG);                                  // Skip unnecessary command Backlog
        } else {
          break;
        }
      }
      if (*blcommand != '\0') {
        backlog[backlog_index] = String(blcommand);
        backlog_index++;
        if (backlog_index >= MAX_BACKLOG) backlog_index = 0;
      }
      blcommand = strtok(nullptr, ";");
    }
//    ResponseCmndChar(D_JSON_APPENDED);
    mqtt_data[0] = '\0';
  } else {
    bool blflag = (backlog_pointer == backlog_index);
    backlog_pointer = backlog_index;
    ResponseCmndChar(blflag ? D_JSON_EMPTY : D_JSON_ABORTED);
  }
}

void CmndDelay(void)
{
  if ((XdrvMailbox.payload >= MIN_BACKLOG_DELAY) && (XdrvMailbox.payload <= 3600)) {
    backlog_delay = millis() + (100 * XdrvMailbox.payload);
  }
  uint32_t bl_delay = 0;
  long bl_delta = TimePassedSince(backlog_delay);
  if (bl_delta < 0) { bl_delay = (bl_delta *-1) / 100; }
  ResponseCmndNumber(bl_delay);
}

void CmndPower(void)
{
  if ((XdrvMailbox.index > 0) && (XdrvMailbox.index <= devices_present)) {
    if ((XdrvMailbox.payload < 0) || (XdrvMailbox.payload > 4)) { XdrvMailbox.payload = 9; }
//      Settings.flag.device_index_enable = user_index;
    ExecuteCommandPower(XdrvMailbox.index, XdrvMailbox.payload, SRC_IGNORE);
    mqtt_data[0] = '\0';
  }
}

void CmndStatus(void)
{
  uint32_t payload = ((XdrvMailbox.payload < 0) || (XdrvMailbox.payload > MAX_STATUS)) ? 99 : XdrvMailbox.payload;

  uint32_t option = STAT;
  char stemp[MAX_FRIENDLYNAMES * (sizeof(Settings.friendlyname[0]) +MAX_FRIENDLYNAMES)];
  char stemp2[100];

  // Workaround MQTT - TCP/IP stack queueing when SUB_PREFIX = PUB_PREFIX
  if (!strcmp(Settings.mqtt_prefix[0],Settings.mqtt_prefix[1]) && (!payload)) { option++; }  // TELE

  if ((!Settings.flag.mqtt_enabled) && (6 == payload)) { payload = 99; }
  if (!energy_flg && (9 == payload)) { payload = 99; }

  if ((0 == payload) || (99 == payload)) {
    uint32_t maxfn = (devices_present > MAX_FRIENDLYNAMES) ? MAX_FRIENDLYNAMES : (!devices_present) ? 1 : devices_present;
#ifdef USE_SONOFF_IFAN
    if (IsModuleIfan()) { maxfn = 1; }
#endif  // USE_SONOFF_IFAN
    stemp[0] = '\0';
    for (uint32_t i = 0; i < maxfn; i++) {
      snprintf_P(stemp, sizeof(stemp), PSTR("%s%s\"%s\"" ), stemp, (i > 0 ? "," : ""), Settings.friendlyname[i]);
    }
    stemp2[0] = '\0';
    for (uint32_t i = 0; i < MAX_SWITCHES; i++) {
      snprintf_P(stemp2, sizeof(stemp2), PSTR("%s%s%d" ), stemp2, (i > 0 ? "," : ""), Settings.switchmode[i]);
    }
    Response_P(PSTR("{\"" D_CMND_STATUS "\":{\"" D_CMND_MODULE "\":%d,\"" D_CMND_FRIENDLYNAME "\":[%s],\"" D_CMND_TOPIC "\":\"%s\",\""
                          D_CMND_BUTTONTOPIC "\":\"%s\",\"" D_CMND_POWER "\":%d,\"" D_CMND_POWERONSTATE "\":%d,\"" D_CMND_LEDSTATE "\":%d,\""
                          D_CMND_LEDMASK "\":\"%04X\",\"" D_CMND_SAVEDATA "\":%d,\"" D_JSON_SAVESTATE "\":%d,\"" D_CMND_SWITCHTOPIC "\":\"%s\",\""
                          D_CMND_SWITCHMODE "\":[%s],\"" D_CMND_BUTTONRETAIN "\":%d,\"" D_CMND_SWITCHRETAIN "\":%d,\"" D_CMND_SENSORRETAIN "\":%d,\"" D_CMND_POWERRETAIN "\":%d}}"),
                          ModuleNr(), stemp, mqtt_topic,
                          Settings.button_topic, power, Settings.poweronstate, Settings.ledstate,
                          Settings.ledmask, Settings.save_data, Settings.flag.save_state, Settings.switch_topic,
                          stemp2, Settings.flag.mqtt_button_retain, Settings.flag.mqtt_switch_retain, Settings.flag.mqtt_sensor_retain, Settings.flag.mqtt_power_retain);
    MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS));
  }

  if ((0 == payload) || (1 == payload)) {
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS1_PARAMETER "\":{\"" D_JSON_BAUDRATE "\":%d,\"" D_CMND_GROUPTOPIC "\":\"%s\",\"" D_CMND_OTAURL "\":\"%s\",\""
                          D_JSON_RESTARTREASON "\":\"%s\",\"" D_JSON_UPTIME "\":\"%s\",\"" D_JSON_STARTUPUTC "\":\"%s\",\"" D_CMND_SLEEP "\":%d,\""
                          D_JSON_CONFIG_HOLDER "\":%d,\"" D_JSON_BOOTCOUNT "\":%d,\"" D_JSON_SAVECOUNT "\":%d,\"" D_JSON_SAVEADDRESS "\":\"%X\"}}"),
                          baudrate, Settings.mqtt_grptopic, Settings.ota_url,
                          GetResetReason().c_str(), GetUptime().c_str(), GetDateAndTime(DT_RESTART).c_str(), Settings.sleep,
                          Settings.cfg_holder, Settings.bootcount, Settings.save_flag, GetSettingsAddress());
    MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "1"));
  }

  if ((0 == payload) || (2 == payload)) {
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS2_FIRMWARE "\":{\"" D_JSON_VERSION "\":\"%s%s\",\"" D_JSON_BUILDDATETIME "\":\"%s\",\""
                          D_JSON_BOOTVERSION "\":%d,\"" D_JSON_COREVERSION "\":\"" ARDUINO_ESP8266_RELEASE "\",\"" D_JSON_SDKVERSION "\":\"%s\"}}"),
                          my_version, my_image, GetBuildDateAndTime().c_str(),
                          ESP.getBootVersion(), ESP.getSdkVersion());
    MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "2"));
  }

  if ((0 == payload) || (3 == payload)) {
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS3_LOGGING "\":{\"" D_CMND_SERIALLOG "\":%d,\"" D_CMND_WEBLOG "\":%d,\"" D_CMND_SYSLOG "\":%d,\""
                          D_CMND_LOGHOST "\":\"%s\",\"" D_CMND_LOGPORT "\":%d,\"" D_CMND_SSID "\":[\"%s\",\"%s\"],\"" D_CMND_TELEPERIOD "\":%d,\""
                          D_JSON_RESOLUTION "\":\"%08X\",\"" D_CMND_SETOPTION "\":[\"%08X\",\"%s\",\"%08X\"]}}"),
                          Settings.seriallog_level, Settings.weblog_level, Settings.syslog_level,
                          Settings.syslog_host, Settings.syslog_port, Settings.sta_ssid[0], Settings.sta_ssid[1], Settings.tele_period,
                          Settings.flag2.data, Settings.flag.data, ToHex_P((unsigned char*)Settings.param, PARAM8_SIZE, stemp2, sizeof(stemp2)), Settings.flag3.data);
    MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "3"));
  }

  if ((0 == payload) || (4 == payload)) {
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS4_MEMORY "\":{\"" D_JSON_PROGRAMSIZE "\":%d,\"" D_JSON_FREEMEMORY "\":%d,\"" D_JSON_HEAPSIZE "\":%d,\""
                          D_JSON_PROGRAMFLASHSIZE "\":%d,\"" D_JSON_FLASHSIZE "\":%d,\"" D_JSON_FLASHCHIPID "\":\"%06X\",\"" D_JSON_FLASHMODE "\":%d,\""
                          D_JSON_FEATURES "\":[\"%08X\",\"%08X\",\"%08X\",\"%08X\",\"%08X\",\"%08X\"]"),
                          ESP.getSketchSize()/1024, ESP.getFreeSketchSpace()/1024, ESP.getFreeHeap()/1024,
                          ESP.getFlashChipSize()/1024, ESP.getFlashChipRealSize()/1024, ESP.getFlashChipId(), ESP.getFlashChipMode(),
                          LANGUAGE_LCID, feature_drv1, feature_drv2, feature_sns1, feature_sns2, feature5);
    XsnsDriverState();
    ResponseAppend_P(PSTR(",\"Sensors\":"));
    XsnsSensorState();
    ResponseAppend_P(PSTR("}}"));
    MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "4"));
  }

  if ((0 == payload) || (5 == payload)) {
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS5_NETWORK "\":{\"" D_CMND_HOSTNAME "\":\"%s\",\"" D_CMND_IPADDRESS "\":\"%s\",\"" D_JSON_GATEWAY "\":\"%s\",\""
                          D_JSON_SUBNETMASK "\":\"%s\",\"" D_JSON_DNSSERVER "\":\"%s\",\"" D_JSON_MAC "\":\"%s\",\""
                          D_CMND_WEBSERVER "\":%d,\"" D_CMND_WIFICONFIG "\":%d}}"),
                          my_hostname, WiFi.localIP().toString().c_str(), IPAddress(Settings.ip_address[1]).toString().c_str(),
                          IPAddress(Settings.ip_address[2]).toString().c_str(), IPAddress(Settings.ip_address[3]).toString().c_str(), WiFi.macAddress().c_str(),
                          Settings.webserver, Settings.sta_config);
    MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "5"));
  }

  if (((0 == payload) || (6 == payload)) && Settings.flag.mqtt_enabled) {
#ifdef USE_MQTT_AWS_IOT
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS6_MQTT "\":{\"" D_CMND_MQTTHOST "\":\"%s%s\",\"" D_CMND_MQTTPORT "\":%d,\"" D_CMND_MQTTCLIENT D_JSON_MASK "\":\"%s\",\""
                          D_CMND_MQTTCLIENT "\":\"%s\",\"" D_JSON_MQTT_COUNT "\":%d,\"MAX_PACKET_SIZE\":%d,\"KEEPALIVE\":%d}}"),
                          Settings.mqtt_user, Settings.mqtt_host, Settings.mqtt_port, Settings.mqtt_client,
                          mqtt_client, MqttConnectCount(), MQTT_MAX_PACKET_SIZE, MQTT_KEEPALIVE);
#else
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS6_MQTT "\":{\"" D_CMND_MQTTHOST "\":\"%s\",\"" D_CMND_MQTTPORT "\":%d,\"" D_CMND_MQTTCLIENT D_JSON_MASK "\":\"%s\",\""
                          D_CMND_MQTTCLIENT "\":\"%s\",\"" D_CMND_MQTTUSER "\":\"%s\",\"" D_JSON_MQTT_COUNT "\":%d,\"MAX_PACKET_SIZE\":%d,\"KEEPALIVE\":%d}}"),
                          Settings.mqtt_host, Settings.mqtt_port, Settings.mqtt_client,
                          mqtt_client, Settings.mqtt_user, MqttConnectCount(), MQTT_MAX_PACKET_SIZE, MQTT_KEEPALIVE);
#endif
    MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "6"));
  }

  if ((0 == payload) || (7 == payload)) {
    if (99 == Settings.timezone) {
      snprintf_P(stemp, sizeof(stemp), PSTR("%d" ), Settings.timezone);
    } else {
      snprintf_P(stemp, sizeof(stemp), PSTR("\"%s\"" ), GetTimeZone().c_str());
    }
#if defined(USE_TIMERS) && defined(USE_SUNRISE)
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS7_TIME "\":{\"" D_JSON_UTC_TIME "\":\"%s\",\"" D_JSON_LOCAL_TIME "\":\"%s\",\"" D_JSON_STARTDST "\":\"%s\",\""
                          D_JSON_ENDDST "\":\"%s\",\"" D_CMND_TIMEZONE "\":%s,\"" D_JSON_SUNRISE "\":\"%s\",\"" D_JSON_SUNSET "\":\"%s\"}}"),
                          GetTime(0).c_str(), GetTime(1).c_str(), GetTime(2).c_str(),
                          GetTime(3).c_str(), stemp, GetSun(0).c_str(), GetSun(1).c_str());
#else
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS7_TIME "\":{\"" D_JSON_UTC_TIME "\":\"%s\",\"" D_JSON_LOCAL_TIME "\":\"%s\",\"" D_JSON_STARTDST "\":\"%s\",\""
                          D_JSON_ENDDST "\":\"%s\",\"" D_CMND_TIMEZONE "\":%s}}"),
                          GetTime(0).c_str(), GetTime(1).c_str(), GetTime(2).c_str(),
                          GetTime(3).c_str(), stemp);
#endif  // USE_TIMERS and USE_SUNRISE
    MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "7"));
  }

#if defined(USE_ENERGY_SENSOR) && defined(USE_ENERGY_MARGIN_DETECTION)
  if (energy_flg) {
    if ((0 == payload) || (9 == payload)) {
      Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS9_MARGIN "\":{\"" D_CMND_POWERDELTA "\":%d,\"" D_CMND_POWERLOW "\":%d,\"" D_CMND_POWERHIGH "\":%d,\""
                            D_CMND_VOLTAGELOW "\":%d,\"" D_CMND_VOLTAGEHIGH "\":%d,\"" D_CMND_CURRENTLOW "\":%d,\"" D_CMND_CURRENTHIGH "\":%d}}"),
                            Settings.energy_power_delta, Settings.energy_min_power, Settings.energy_max_power,
                            Settings.energy_min_voltage, Settings.energy_max_voltage, Settings.energy_min_current, Settings.energy_max_current);
      MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "9"));
    }
  }
#endif  // USE_ENERGY_MARGIN_DETECTION

  if ((0 == payload) || (8 == payload) || (10 == payload)) {
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS10_SENSOR "\":"));
    MqttShowSensor();
    ResponseJsonEnd();
    if (8 == payload) {
      MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "8"));
    } else {
      MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "10"));
    }
  }

  if ((0 == payload) || (11 == payload)) {
    Response_P(PSTR("{\"" D_CMND_STATUS D_STATUS11_STATUS "\":"));
    MqttShowState();
    ResponseJsonEnd();
    MqttPublishPrefixTopic_P(option, PSTR(D_CMND_STATUS "11"));
  }
  mqtt_data[0] = '\0';
}

void CmndState(void)
{
  mqtt_data[0] = '\0';
  MqttShowState();
  if (Settings.flag3.hass_tele_on_power) {
    MqttPublishPrefixTopic_P(TELE, PSTR(D_RSLT_STATE), MQTT_TELE_RETAIN);
  }
#ifdef USE_HOME_ASSISTANT
  if (Settings.flag.hass_discovery) {
    HAssPublishStatus();
  }
#endif  // USE_HOME_ASSISTANT
}

void CmndSleep(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload < 251)) {
    Settings.sleep = XdrvMailbox.payload;
    sleep = XdrvMailbox.payload;
    WiFiSetSleepMode();
  }
  Response_P(S_JSON_COMMAND_NVALUE_UNIT_NVALUE_UNIT, XdrvMailbox.command, sleep, (Settings.flag.value_units) ? " " D_UNIT_MILLISECOND : "", Settings.sleep, (Settings.flag.value_units) ? " " D_UNIT_MILLISECOND : "");
}

void CmndUpgrade(void)
{
  // Check if the payload is numerically 1, and had no trailing chars.
  //   e.g. "1foo" or "1.2.3" could fool us.
  // Check if the version we have been asked to upgrade to is higher than our current version.
  //   We also need at least 3 chars to make a valid version number string.
  if (((1 == XdrvMailbox.data_len) && (1 == XdrvMailbox.payload)) || ((XdrvMailbox.data_len >= 3) && NewerVersion(XdrvMailbox.data))) {
    ota_state_flag = 3;
    char stemp1[TOPSZ];
    Response_P(PSTR("{\"%s\":\"" D_JSON_VERSION " %s " D_JSON_FROM " %s\"}"), XdrvMailbox.command, my_version, GetOtaUrl(stemp1, sizeof(stemp1)));
  } else {
    Response_P(PSTR("{\"%s\":\"" D_JSON_ONE_OR_GT "\"}"), XdrvMailbox.command, my_version);
  }
}

void CmndOtaUrl(void)
{
  if ((XdrvMailbox.data_len > 0) && (XdrvMailbox.data_len < sizeof(Settings.ota_url))) {
    strlcpy(Settings.ota_url, (SC_DEFAULT == Shortcut()) ? OTA_URL : XdrvMailbox.data, sizeof(Settings.ota_url));
  }
  ResponseCmndChar(Settings.ota_url);
}

void CmndSeriallog(void)
{
  if ((XdrvMailbox.payload >= LOG_LEVEL_NONE) && (XdrvMailbox.payload <= LOG_LEVEL_ALL)) {
    Settings.flag.mqtt_serial = 0;
    SetSeriallog(XdrvMailbox.payload);
  }
  Response_P(S_JSON_COMMAND_NVALUE_ACTIVE_NVALUE, XdrvMailbox.command, Settings.seriallog_level, seriallog_level);
}

void CmndRestart(void)
{
  switch (XdrvMailbox.payload) {
  case 1:
    restart_flag = 2;
    ResponseCmndChar(D_JSON_RESTARTING);
    break;
  case 99:
    AddLog_P(LOG_LEVEL_INFO, PSTR(D_LOG_APPLICATION D_RESTARTING));
    EspRestart();
    break;
  default:
    ResponseCmndChar(D_JSON_ONE_TO_RESTART);
  }
}

void CmndPowerOnState(void)
{
  if (my_module_type != MOTOR) {
    /* 0 = Keep relays off after power on
      * 1 = Turn relays on after power on, if PulseTime set wait for PulseTime seconds, and turn relays off
      * 2 = Toggle relays after power on
      * 3 = Set relays to last saved state after power on
      * 4 = Turn relays on and disable any relay control (used for Sonoff Pow to always measure power)
      * 5 = Keep relays off after power on, if PulseTime set wait for PulseTime seconds, and turn relays on
      */
    if ((XdrvMailbox.payload >= POWER_ALL_OFF) && (XdrvMailbox.payload <= POWER_ALL_OFF_PULSETIME_ON)) {
      Settings.poweronstate = XdrvMailbox.payload;
      if (POWER_ALL_ALWAYS_ON == Settings.poweronstate) {
        for (uint32_t i = 1; i <= devices_present; i++) {
          ExecuteCommandPower(i, POWER_ON, SRC_IGNORE);
        }
      }
    }
    ResponseCmndNumber(Settings.poweronstate);
  }
}

void CmndPulsetime(void)
{
  if ((XdrvMailbox.index > 0) && (XdrvMailbox.index <= MAX_PULSETIMERS)) {
    if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload < 65536)) {
      Settings.pulse_timer[XdrvMailbox.index -1] = XdrvMailbox.payload;  // 0 - 65535
      SetPulseTimer(XdrvMailbox.index -1, XdrvMailbox.payload);
    }
    Response_P(S_JSON_COMMAND_INDEX_NVALUE_ACTIVE_NVALUE, XdrvMailbox.command, XdrvMailbox.index, Settings.pulse_timer[XdrvMailbox.index -1], GetPulseTimer(XdrvMailbox.index -1));
  }
}

void CmndBlinktime(void)
{
  if ((XdrvMailbox.payload > 1) && (XdrvMailbox.payload <= 3600)) {
    Settings.blinktime = XdrvMailbox.payload;
    if (blink_timer > 0) { blink_timer = millis() + (100 * XdrvMailbox.payload); }
  }
  ResponseCmndNumber(Settings.blinktime);
}

void CmndBlinkcount(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload < 65536)) {
    Settings.blinkcount = XdrvMailbox.payload;  // 0 - 65535
    if (blink_counter) { blink_counter = Settings.blinkcount *2; }
  }
  ResponseCmndNumber(Settings.blinkcount);
}

void CmndSavedata(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 3600)) {
    Settings.save_data = XdrvMailbox.payload;
    save_data_counter = Settings.save_data;
  }
  SettingsSaveAll();
  char stemp1[TOPSZ];
  if (Settings.save_data > 1) {
    snprintf_P(stemp1, sizeof(stemp1), PSTR(D_JSON_EVERY " %d " D_UNIT_SECOND), Settings.save_data);
  }
  ResponseCmndChar((Settings.save_data > 1) ? stemp1 : GetStateText(Settings.save_data));
}

void CmndSetoption(void)
{
  if (XdrvMailbox.index < 82) {
    uint32_t ptype;
    uint32_t pindex;
    if (XdrvMailbox.index <= 31) {         // SetOption0 .. 31 = Settings.flag
      ptype = 0;
      pindex = XdrvMailbox.index;          // 0 .. 31
    }
    else if (XdrvMailbox.index <= 49) {    // SetOption32 .. 49 = Settings.param
      ptype = 2;
      pindex = XdrvMailbox.index -32;      // 0 .. 17 (= PARAM8_SIZE -1)
    }
    else {                     // SetOption50 .. 81 = Settings.flag3
      ptype = 1;
      pindex = XdrvMailbox.index -50;      // 0 .. 31
    }
    if (XdrvMailbox.payload >= 0) {
      if (0 == ptype) {        // SetOption0 .. 31
        if (XdrvMailbox.payload <= 1) {
          switch (pindex) {
            case 5:            // mqtt_power_retain (CMND_POWERRETAIN)
            case 6:            // mqtt_button_retain (CMND_BUTTONRETAIN)
            case 7:            // mqtt_switch_retain (CMND_SWITCHRETAIN)
            case 9:            // mqtt_sensor_retain (CMND_SENSORRETAIN)
            case 14:           // interlock (CMND_INTERLOCK)
            case 22:           // mqtt_serial (SerialSend and SerialLog)
            case 23:           // mqtt_serial_raw (SerialSend)
            case 25:           // knx_enabled (Web config)
            case 27:           // knx_enable_enhancement (Web config)
              ptype = 99;      // Command Error
              break;           // Ignore command SetOption
            case 3:            // mqtt
            case 15:           // pwm_control
              restart_flag = 2;
            default:
              bitWrite(Settings.flag.data, pindex, XdrvMailbox.payload);
          }
          if (12 == pindex) {  // stop_flash_rotate
            stop_flash_rotate = XdrvMailbox.payload;
            SettingsSave(2);
          }
#ifdef USE_HOME_ASSISTANT
          if ((19 == pindex) || (30 == pindex)) {
            HAssDiscover();    // Delayed execution to provide enough resources during hass_discovery or hass_light
          }
#endif  // USE_HOME_ASSISTANT
        }
      }
      else if (1 == ptype) {   // SetOption50 .. 81
        if (XdrvMailbox.payload <= 1) {
          bitWrite(Settings.flag3.data, pindex, XdrvMailbox.payload);
          if (5 == pindex) {   // SetOption55
            if (0 == XdrvMailbox.payload) {
              restart_flag = 2;  // Disable mDNS needs restart
            }
          }
          if (10 == pindex) {  // SetOption60 enable or disable traditional sleep
            WiFiSetSleepMode();  // Update WiFi sleep mode accordingly
          }
          if (18 == pindex) { // SetOption68 for multi-channel PWM, requires a reboot
            restart_flag = 2;
          }
          if (15 == pindex) { // SetOption65 for tuya_disable_dimmer requires a reboot
            restart_flag = 2;
          }
        }
      }
      else {                   // SetOption32 .. 49
        uint32_t param_low = 0;
        uint32_t param_high = 255;
        switch (pindex) {
          case P_HOLD_TIME:
          case P_MAX_POWER_RETRY:
            param_low = 1;
            param_high = 250;
            break;
          case P_TUYA_RELAYS:
            param_high = 8;
            break;
        }
        if ((XdrvMailbox.payload >= param_low) && (XdrvMailbox.payload <= param_high)) {
          Settings.param[pindex] = XdrvMailbox.payload;
          switch (pindex) {
#ifdef USE_LIGHT
            case P_RGB_REMAP:
              LightUpdateColorMapping();
              break;
#endif
#if defined(USE_IR_REMOTE) && defined(USE_IR_RECEIVE)
            case P_IR_UNKNOW_THRESHOLD:
              IrReceiveUpdateThreshold();
              break;
#endif
#ifdef USE_TUYA_DIMMER
            case P_TUYA_RELAYS:
              restart_flag = 2;  // Need a restart to update GUI
              break;
#endif
          }
        }
      }
    }
    if (ptype < 99) {
      char stemp1[TOPSZ];
      if (2 == ptype) { snprintf_P(stemp1, sizeof(stemp1), PSTR("%d"), Settings.param[pindex]); }
      ResponseCmndIdxChar((2 == ptype) ? stemp1 : (1 == ptype) ? GetStateText(bitRead(Settings.flag3.data, pindex)) : GetStateText(bitRead(Settings.flag.data, pindex)));
    }
  }
}

void CmndTemperatureResolution(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 3)) {
    Settings.flag2.temperature_resolution = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.flag2.temperature_resolution);
}

void CmndHumidityResolution(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 3)) {
    Settings.flag2.humidity_resolution = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.flag2.humidity_resolution);
}

void CmndPressureResolution(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 3)) {
    Settings.flag2.pressure_resolution = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.flag2.pressure_resolution);
}

void CmndPowerResolution(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 3)) {
    Settings.flag2.wattage_resolution = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.flag2.wattage_resolution);
}

void CmndVoltageResolution(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 3)) {
    Settings.flag2.voltage_resolution = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.flag2.voltage_resolution);
}

void CmndFrequencyResolution(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 3)) {
    Settings.flag2.frequency_resolution = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.flag2.frequency_resolution);
}

void CmndCurrentResolution(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 3)) {
    Settings.flag2.current_resolution = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.flag2.current_resolution);
}

void CmndEnergyResolution(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 5)) {
    Settings.flag2.energy_resolution = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.flag2.energy_resolution);
}

void CmndWeightResolution(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 3)) {
    Settings.flag2.weight_resolution = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.flag2.weight_resolution);
}

void CmndModule(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= MAXMODULE)) {
    bool present = false;
    if (0 == XdrvMailbox.payload) {
      XdrvMailbox.payload = USER_MODULE;
      present = true;
    } else {
      XdrvMailbox.payload--;
      present = ValidTemplateModule(XdrvMailbox.payload);
    }
    if (present) {
      Settings.last_module = Settings.module;
      Settings.module = XdrvMailbox.payload;
      SetModuleType();
      if (Settings.last_module != XdrvMailbox.payload) {
        for (uint32_t i = 0; i < sizeof(Settings.my_gp); i++) {
          Settings.my_gp.io[i] = GPIO_NONE;
        }
      }
      restart_flag = 2;
    }
  }
  Response_P(S_JSON_COMMAND_NVALUE_SVALUE, XdrvMailbox.command, ModuleNr(), ModuleName().c_str());
}

void CmndModules(void)
{
  uint32_t midx = USER_MODULE;
  uint32_t lines = 1;
  bool jsflg = false;
  for (uint32_t i = 0; i <= sizeof(kModuleNiceList); i++) {
    if (i > 0) { midx = pgm_read_byte(kModuleNiceList + i -1); }
    if (!jsflg) {
      Response_P(PSTR("{\"" D_CMND_MODULES "%d\":["), lines);
    } else {
      ResponseAppend_P(PSTR(","));
    }
    jsflg = true;
    uint32_t j = i ? midx +1 : 0;
    if ((ResponseAppend_P(PSTR("\"%d (%s)\""), j, AnyModuleName(midx).c_str()) > (LOGSZ - TOPSZ)) || (i == sizeof(kModuleNiceList))) {
      ResponseAppend_P(PSTR("]}"));
      MqttPublishPrefixTopic_P(RESULT_OR_STAT, UpperCase(XdrvMailbox.command, XdrvMailbox.command));
      jsflg = false;
      lines++;
    }
  }
  mqtt_data[0] = '\0';
}

void CmndGpio(void)
{
  if (XdrvMailbox.index < sizeof(Settings.my_gp)) {
    myio cmodule;
    ModuleGpios(&cmodule);
    if (ValidGPIO(XdrvMailbox.index, cmodule.io[XdrvMailbox.index]) && (XdrvMailbox.payload >= 0) && (XdrvMailbox.payload < GPIO_SENSOR_END)) {
      bool present = false;
      for (uint32_t i = 0; i < sizeof(kGpioNiceList); i++) {
        uint32_t midx = pgm_read_byte(kGpioNiceList + i);
        if (midx == XdrvMailbox.payload) { present = true; }
      }
      if (present) {
        for (uint32_t i = 0; i < sizeof(Settings.my_gp); i++) {
          if (ValidGPIO(i, cmodule.io[i]) && (Settings.my_gp.io[i] == XdrvMailbox.payload)) {
            Settings.my_gp.io[i] = GPIO_NONE;
          }
        }
        Settings.my_gp.io[XdrvMailbox.index] = XdrvMailbox.payload;
        restart_flag = 2;
      }
    }
    Response_P(PSTR("{"));
    bool jsflg = false;
    for (uint32_t i = 0; i < sizeof(Settings.my_gp); i++) {
      if (ValidGPIO(i, cmodule.io[i])) {
        if (jsflg) { ResponseAppend_P(PSTR(",")); }
        jsflg = true;
        char stemp1[TOPSZ];
        ResponseAppend_P(PSTR("\"" D_CMND_GPIO "%d\":\"%d (%s)\""), i, Settings.my_gp.io[i], GetTextIndexed(stemp1, sizeof(stemp1), Settings.my_gp.io[i], kSensorNames));
      }
    }
    if (jsflg) {
      ResponseJsonEnd();
    } else {
      ResponseCmndChar(D_JSON_NOT_SUPPORTED);
    }
  }
}

void CmndGpios(void)
{
  myio cmodule;
  ModuleGpios(&cmodule);
  uint32_t midx;
  uint32_t lines = 1;
  bool jsflg = false;
  for (uint32_t i = 0; i < sizeof(kGpioNiceList); i++) {
    midx = pgm_read_byte(kGpioNiceList + i);
    if (!GetUsedInModule(midx, cmodule.io)) {
      if (!jsflg) {
        Response_P(PSTR("{\"" D_CMND_GPIOS "%d\":["), lines);
      } else {
        ResponseAppend_P(PSTR(","));
      }
      jsflg = true;
      char stemp1[TOPSZ];
      if ((ResponseAppend_P(PSTR("\"%d (%s)\""), midx, GetTextIndexed(stemp1, sizeof(stemp1), midx, kSensorNames)) > (LOGSZ - TOPSZ)) || (i == sizeof(kGpioNiceList) -1)) {
        ResponseAppend_P(PSTR("]}"));
        MqttPublishPrefixTopic_P(RESULT_OR_STAT, UpperCase(XdrvMailbox.command, XdrvMailbox.command));
        jsflg = false;
        lines++;
      }
    }
  }
  mqtt_data[0] = '\0';
}

void CmndTemplate(void)
{
  // {"NAME":"Generic","GPIO":[17,254,29,254,7,254,254,254,138,254,139,254,254],"FLAG":1,"BASE":255}
  bool error = false;

  if (strstr(XdrvMailbox.data, "{") == nullptr) {  // If no JSON it must be parameter
    if ((XdrvMailbox.payload > 0) && (XdrvMailbox.payload <= MAXMODULE)) {
      XdrvMailbox.payload--;
      if (ValidTemplateModule(XdrvMailbox.payload)) {
        ModuleDefault(XdrvMailbox.payload);     // Copy template module
        if (USER_MODULE == Settings.module) { restart_flag = 2; }
      }
    }
    else if (0 == XdrvMailbox.payload) {        // Copy current template to user template
      if (Settings.module != USER_MODULE) {
        ModuleDefault(Settings.module);
      }
    }
    else if (255 == XdrvMailbox.payload) {      // Copy current module with user configured GPIO
      if (Settings.module != USER_MODULE) {
        ModuleDefault(Settings.module);
      }
      snprintf_P(Settings.user_template.name, sizeof(Settings.user_template.name), PSTR("Merged"));
      uint32_t j = 0;
      for (uint32_t i = 0; i < sizeof(mycfgio); i++) {
        if (6 == i) { j = 9; }
        if (8 == i) { j = 12; }
        if (my_module.io[j] > GPIO_NONE) {
          Settings.user_template.gp.io[i] = my_module.io[j];
        }
        j++;
      }
    }
  }
  else {
    if (JsonTemplate(XdrvMailbox.data)) {    // Free 336 bytes StaticJsonBuffer stack space by moving code to function
      if (USER_MODULE == Settings.module) { restart_flag = 2; }
    } else {
      ResponseCmndChar(D_JSON_INVALID_JSON);
      error = true;
    }
  }
  if (!error) { TemplateJson(); }
}

void CmndPwm(void)
{
  if (pwm_present && (XdrvMailbox.index > 0) && (XdrvMailbox.index <= MAX_PWMS)) {
    if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= Settings.pwm_range) && (pin[GPIO_PWM1 + XdrvMailbox.index -1] < 99)) {
      Settings.pwm_value[XdrvMailbox.index -1] = XdrvMailbox.payload;
      analogWrite(pin[GPIO_PWM1 + XdrvMailbox.index -1], bitRead(pwm_inverted, XdrvMailbox.index -1) ? Settings.pwm_range - XdrvMailbox.payload : XdrvMailbox.payload);
    }
    Response_P(PSTR("{"));
    MqttShowPWMState();  // Render the PWM status to MQTT
    ResponseJsonEnd();
  }
}

void CmndPwmfrequency(void)
{
  if ((1 == XdrvMailbox.payload) || ((XdrvMailbox.payload >= PWM_MIN) && (XdrvMailbox.payload <= PWM_MAX))) {
    Settings.pwm_frequency = (1 == XdrvMailbox.payload) ? PWM_FREQ : XdrvMailbox.payload;
    analogWriteFreq(Settings.pwm_frequency);   // Default is 1000 (core_esp8266_wiring_pwm.c)
  }
  ResponseCmndNumber(Settings.pwm_frequency);
}

void CmndPwmrange(void)
{
  if ((1 == XdrvMailbox.payload) || ((XdrvMailbox.payload > 254) && (XdrvMailbox.payload < 1024))) {
    Settings.pwm_range = (1 == XdrvMailbox.payload) ? PWM_RANGE : XdrvMailbox.payload;
    for (uint32_t i = 0; i < MAX_PWMS; i++) {
      if (Settings.pwm_value[i] > Settings.pwm_range) {
        Settings.pwm_value[i] = Settings.pwm_range;
      }
    }
    analogWriteRange(Settings.pwm_range);      // Default is 1023 (Arduino.h)
  }
  ResponseCmndNumber(Settings.pwm_range);
}

void CmndButtonDebounce(void)
{
  if ((XdrvMailbox.payload > 39) && (XdrvMailbox.payload < 1001)) {
    Settings.button_debounce = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.button_debounce);
}

void CmndSwitchDebounce(void)
{
  if ((XdrvMailbox.payload > 39) && (XdrvMailbox.payload < 1001)) {
    Settings.switch_debounce = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.switch_debounce);
}

void CmndBaudrate(void)
{
  if (XdrvMailbox.payload > 1200) {
    XdrvMailbox.payload /= 1200;  // Make it a valid baudrate
    baudrate = XdrvMailbox.payload * 1200;
    SetSerialBaudrate(baudrate);
  }
  ResponseCmndNumber(Settings.baudrate * 1200);
}

void CmndSerialSend(void)
{
  if ((XdrvMailbox.index > 0) && (XdrvMailbox.index <= 5)) {
    SetSeriallog(LOG_LEVEL_NONE);
    Settings.flag.mqtt_serial = 1;
    Settings.flag.mqtt_serial_raw = (XdrvMailbox.index > 3) ? 1 : 0;
    if (XdrvMailbox.data_len > 0) {
      if (1 == XdrvMailbox.index) {
        Serial.printf("%s\n", XdrvMailbox.data);                    // "Hello Tiger\n"
      }
      else if (2 == XdrvMailbox.index || 4 == XdrvMailbox.index) {
        for (uint32_t i = 0; i < XdrvMailbox.data_len; i++) {
          Serial.write(XdrvMailbox.data[i]);                        // "Hello Tiger" or "A0"
        }
      }
      else if (3 == XdrvMailbox.index) {
        uint32_t dat_len = XdrvMailbox.data_len;
        Serial.printf("%s", Unescape(XdrvMailbox.data, &dat_len));  // "Hello\f"
      }
      else if (5 == XdrvMailbox.index) {
        SerialSendRaw(RemoveSpace(XdrvMailbox.data));               // "AA004566" as hex values
      }
      ResponseCmndDone();
    }
  }
}

void CmndSerialDelimiter(void)
{
  if ((XdrvMailbox.data_len > 0) && (XdrvMailbox.payload < 256)) {
    if (XdrvMailbox.payload > 0) {
      Settings.serial_delimiter = XdrvMailbox.payload;
    } else {
      uint32_t dat_len = XdrvMailbox.data_len;
      Unescape(XdrvMailbox.data, &dat_len);
      Settings.serial_delimiter = XdrvMailbox.data[0];
    }
  }
  ResponseCmndNumber(Settings.serial_delimiter);
}

void CmndSyslog(void)
{
  if ((XdrvMailbox.payload >= LOG_LEVEL_NONE) && (XdrvMailbox.payload <= LOG_LEVEL_ALL)) {
    SetSyslog(XdrvMailbox.payload);
  }
  Response_P(S_JSON_COMMAND_NVALUE_ACTIVE_NVALUE, XdrvMailbox.command, Settings.syslog_level, syslog_level);
}

void CmndLoghost(void)
{
  if ((XdrvMailbox.data_len > 0) && (XdrvMailbox.data_len < sizeof(Settings.syslog_host))) {
    strlcpy(Settings.syslog_host, (SC_DEFAULT == Shortcut()) ? SYS_LOG_HOST : XdrvMailbox.data, sizeof(Settings.syslog_host));
  }
  ResponseCmndChar(Settings.syslog_host);
}

void CmndLogport(void)
{
  if ((XdrvMailbox.payload > 0) && (XdrvMailbox.payload < 65536)) {
    Settings.syslog_port = (1 == XdrvMailbox.payload) ? SYS_LOG_PORT : XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.syslog_port);
}

void CmndIpAddress(void)
{
  if ((XdrvMailbox.index > 0) && (XdrvMailbox.index <= 4)) {
    uint32_t address;
    if (ParseIp(&address, XdrvMailbox.data)) {
      Settings.ip_address[XdrvMailbox.index -1] = address;
//        restart_flag = 2;
    }
    char stemp1[TOPSZ];
    snprintf_P(stemp1, sizeof(stemp1), PSTR(" (%s)"), WiFi.localIP().toString().c_str());
    Response_P(S_JSON_COMMAND_INDEX_SVALUE_SVALUE, XdrvMailbox.command, XdrvMailbox.index, IPAddress(Settings.ip_address[XdrvMailbox.index -1]).toString().c_str(), (1 == XdrvMailbox.index) ? stemp1:"");
  }
}

void CmndNtpServer(void)
{
  if ((XdrvMailbox.index > 0) && (XdrvMailbox.index <= 3)) {
    if ((XdrvMailbox.data_len > 0) && (XdrvMailbox.data_len < sizeof(Settings.ntp_server[0]))) {
      strlcpy(Settings.ntp_server[XdrvMailbox.index -1],
              (SC_CLEAR == Shortcut()) ? "" : (SC_DEFAULT == Shortcut()) ? (1==XdrvMailbox.index)?NTP_SERVER1:(2==XdrvMailbox.index)?NTP_SERVER2:NTP_SERVER3 : XdrvMailbox.data,
              sizeof(Settings.ntp_server[0]));
      for (uint32_t i = 0; i < strlen(Settings.ntp_server[XdrvMailbox.index -1]); i++) {
        if (Settings.ntp_server[XdrvMailbox.index -1][i] == ',') Settings.ntp_server[XdrvMailbox.index -1][i] = '.';
      }
//        restart_flag = 2;  // Issue #3890
      ntp_force_sync = true;
    }
    ResponseCmndIdxChar(Settings.ntp_server[XdrvMailbox.index -1]);
  }
}

void CmndAp(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 2)) {
    switch (XdrvMailbox.payload) {
    case 0:  // Toggle
      Settings.sta_active ^= 1;
      break;
    case 1:  // AP1
    case 2:  // AP2
      Settings.sta_active = XdrvMailbox.payload -1;
    }
    restart_flag = 2;
  }
  Response_P(S_JSON_COMMAND_NVALUE_SVALUE, XdrvMailbox.command, Settings.sta_active +1, Settings.sta_ssid[Settings.sta_active]);
}

void CmndSsid(void)
{
  if ((XdrvMailbox.index > 0) && (XdrvMailbox.index <= 2)) {
    if ((XdrvMailbox.data_len > 0) && (XdrvMailbox.data_len < sizeof(Settings.sta_ssid[0]))) {
      strlcpy(Settings.sta_ssid[XdrvMailbox.index -1],
              (SC_CLEAR == Shortcut()) ? "" : (SC_DEFAULT == Shortcut()) ? (1 == XdrvMailbox.index) ? STA_SSID1 : STA_SSID2 : XdrvMailbox.data,
              sizeof(Settings.sta_ssid[0]));
      Settings.sta_active = XdrvMailbox.index -1;
      restart_flag = 2;
    }
    ResponseCmndIdxChar(Settings.sta_ssid[XdrvMailbox.index -1]);
  }
}

void CmndPassword(void)
{
  if ((XdrvMailbox.index > 0) && (XdrvMailbox.index <= 2)) {
    if ((XdrvMailbox.data_len > 4 || SC_CLEAR == Shortcut() || SC_DEFAULT == Shortcut()) && (XdrvMailbox.data_len < sizeof(Settings.sta_pwd[0]))) {
      strlcpy(Settings.sta_pwd[XdrvMailbox.index -1],
              (SC_CLEAR == Shortcut()) ? "" : (SC_DEFAULT == Shortcut()) ? (1 == XdrvMailbox.index) ? STA_PASS1 : STA_PASS2 : XdrvMailbox.data,
              sizeof(Settings.sta_pwd[0]));
      Settings.sta_active = XdrvMailbox.index -1;
      restart_flag = 2;
      ResponseCmndIdxChar(Settings.sta_pwd[XdrvMailbox.index -1]);
    } else {
      Response_P(S_JSON_COMMAND_INDEX_ASTERISK, XdrvMailbox.command, XdrvMailbox.index);
    }
  }
}

void CmndHostname(void)
{
  if (!XdrvMailbox.grpflg && (XdrvMailbox.data_len > 0) && (XdrvMailbox.data_len < sizeof(Settings.hostname))) {
    strlcpy(Settings.hostname, (SC_DEFAULT == Shortcut()) ? WIFI_HOSTNAME : XdrvMailbox.data, sizeof(Settings.hostname));
    if (strstr(Settings.hostname, "%") != nullptr) {
      strlcpy(Settings.hostname, WIFI_HOSTNAME, sizeof(Settings.hostname));
    }
    restart_flag = 2;
  }
  ResponseCmndChar(Settings.hostname);
}

void CmndWifiConfig(void)
{
  char stemp1[TOPSZ];
  if ((XdrvMailbox.payload >= WIFI_RESTART) && (XdrvMailbox.payload < MAX_WIFI_OPTION)) {
    Settings.sta_config = XdrvMailbox.payload;
    wifi_state_flag = Settings.sta_config;
    snprintf_P(stemp1, sizeof(stemp1), kWifiConfig[Settings.sta_config]);
    Response_P(PSTR("{\"" D_CMND_WIFICONFIG "\":\"%s " D_JSON_SELECTED "\"}"), stemp1);
    if (WifiState() > WIFI_RESTART) {
//          ResponseAppend_P(PSTR(" after restart"));
      restart_flag = 2;
    }
  } else {
    snprintf_P(stemp1, sizeof(stemp1), kWifiConfig[Settings.sta_config]);
    Response_P(S_JSON_COMMAND_NVALUE_SVALUE, XdrvMailbox.command, Settings.sta_config, stemp1);
  }
}

void CmndFriendlyname(void)
{
  if ((XdrvMailbox.index > 0) && (XdrvMailbox.index <= MAX_FRIENDLYNAMES)) {
    if ((XdrvMailbox.data_len > 0) && (XdrvMailbox.data_len < sizeof(Settings.friendlyname[0]))) {
      char stemp1[TOPSZ];
      if (1 == XdrvMailbox.index) {
        snprintf_P(stemp1, sizeof(stemp1), PSTR(FRIENDLY_NAME));
      } else {
        snprintf_P(stemp1, sizeof(stemp1), PSTR(FRIENDLY_NAME "%d"), XdrvMailbox.index);
      }
      strlcpy(Settings.friendlyname[XdrvMailbox.index -1], (SC_DEFAULT == Shortcut()) ? stemp1 : XdrvMailbox.data, sizeof(Settings.friendlyname[XdrvMailbox.index -1]));
    }
    ResponseCmndIdxChar(Settings.friendlyname[XdrvMailbox.index -1]);
  }
}

void CmndSwitchMode(void)
{
  if ((XdrvMailbox.index > 0) && (XdrvMailbox.index <= MAX_SWITCHES)) {
    if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload < MAX_SWITCH_OPTION)) {
      Settings.switchmode[XdrvMailbox.index -1] = XdrvMailbox.payload;
    }
    ResponseCmndIdxNumber(Settings.switchmode[XdrvMailbox.index-1]);
  }
}

void CmndInterlock(void)
{
  // Interlock 0 - Off, Interlock 1 - On, Interlock 1,2 3,4 5,6,7
  uint32_t max_relays = devices_present;
  if (light_type) { max_relays--; }
  if (max_relays > sizeof(Settings.interlock[0]) * 8) { max_relays = sizeof(Settings.interlock[0]) * 8; }
  if (max_relays > 1) {                                         // Only interlock with more than 1 relay
    if (XdrvMailbox.data_len > 0) {
      if (strstr(XdrvMailbox.data, ",") != nullptr) {                    // Interlock entry
        for (uint32_t i = 0; i < MAX_INTERLOCKS; i++) { Settings.interlock[i] = 0; }  // Reset current interlocks
        char *group;
        char *q;
        uint32_t group_index = 0;
        power_t relay_mask = 0;
        for (group = strtok_r(XdrvMailbox.data, " ", &q); group && group_index < MAX_INTERLOCKS; group = strtok_r(nullptr, " ", &q)) {
          char *str;
          char *p;
          for (str = strtok_r(group, ",", &p); str; str = strtok_r(nullptr, ",", &p)) {
            int pbit = atoi(str);
            if ((pbit > 0) && (pbit <= max_relays)) {           // Only valid relays
              pbit--;
              if (!bitRead(relay_mask, pbit)) {                 // Only relay once
                bitSet(relay_mask, pbit);
                bitSet(Settings.interlock[group_index], pbit);
              }
            }
          }
          group_index++;
        }
        for (uint32_t i = 0; i < group_index; i++) {
          uint32_t minimal_bits = 0;
          for (uint32_t j = 0; j < max_relays; j++) {
            if (bitRead(Settings.interlock[i], j)) { minimal_bits++; }
          }
          if (minimal_bits < 2) { Settings.interlock[i] = 0; }  // Discard single relay as interlock
        }
      } else {
        Settings.flag.interlock = XdrvMailbox.payload &1;                   // Enable/disable interlock
        if (Settings.flag.interlock) {
          SetDevicePower(power, SRC_IGNORE);                    // Remove multiple relays if set
        }
      }
    }
    Response_P(PSTR("{\"" D_CMND_INTERLOCK "\":\"%s\",\"" D_JSON_GROUPS "\":\""), GetStateText(Settings.flag.interlock));
    uint32_t anygroup = 0;
    for (uint32_t i = 0; i < MAX_INTERLOCKS; i++) {
      if (Settings.interlock[i]) {
        anygroup++;
        ResponseAppend_P(PSTR("%s"), (anygroup > 1) ? " " : "");
        uint32_t anybit = 0;
        power_t mask = 1;
        for (uint32_t j = 0; j < max_relays; j++) {
          if (Settings.interlock[i] & mask) {
            anybit++;
            ResponseAppend_P(PSTR("%s%d"), (anybit > 1) ? "," : "", j +1);
          }
          mask <<= 1;
        }
      }
    }
    if (!anygroup) {
      for (uint32_t j = 1; j <= max_relays; j++) {
        ResponseAppend_P(PSTR("%s%d"), (j > 1) ? "," : "", j);
      }
    }
    ResponseAppend_P(PSTR("\"}"));
  } else {
    Settings.flag.interlock = 0;
    ResponseCmndStateText(Settings.flag.interlock);
  }
}

void CmndTeleperiod(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload < 3601)) {
    Settings.tele_period = (1 == XdrvMailbox.payload) ? TELE_PERIOD : XdrvMailbox.payload;
    if ((Settings.tele_period > 0) && (Settings.tele_period < 10)) Settings.tele_period = 10;   // Do not allow periods < 10 seconds
    tele_period = Settings.tele_period;
  }
  Response_P(S_JSON_COMMAND_NVALUE_UNIT, XdrvMailbox.command, Settings.tele_period, (Settings.flag.value_units) ? " " D_UNIT_SECOND : "");
}

void CmndReset(void)
{
  switch (XdrvMailbox.payload) {
  case 1:
    restart_flag = 211;
    ResponseCmndChar(D_JSON_RESET_AND_RESTARTING);
    break;
  case 2 ... 6:
    restart_flag = 210 + XdrvMailbox.payload;
    Response_P(PSTR("{\"" D_CMND_RESET "\":\"" D_JSON_ERASE ", " D_JSON_RESET_AND_RESTARTING "\"}"));
    break;
  default:
    ResponseCmndChar(D_JSON_ONE_TO_RESET);
  }
}

void CmndTime(void)
{
  if (XdrvMailbox.data_len > 0) {
    RtcSetTime(XdrvMailbox.payload);
  }
  ResponseBeginTime();
  ResponseJsonEnd();
}

void CmndTimezone(void)
{
  if ((XdrvMailbox.data_len > 0) && (XdrvMailbox.payload >= -13)) {
    Settings.timezone = XdrvMailbox.payload;
    Settings.timezone_minutes = 0;
    if (XdrvMailbox.payload < 15) {
      char *p = strtok (XdrvMailbox.data, ":");
      if (p) {
        p = strtok (nullptr, ":");
        if (p) {
          Settings.timezone_minutes = strtol(p, nullptr, 10);
          if (Settings.timezone_minutes > 59) { Settings.timezone_minutes = 59; }
        }
      }
    } else {
      Settings.timezone = 99;
    }
    ntp_force_sync = true;
  }
  if (99 == Settings.timezone) {
    ResponseCmndNumber(Settings.timezone);
  } else {
    char stemp1[TOPSZ];
    snprintf_P(stemp1, sizeof(stemp1), PSTR("%+03d:%02d"), Settings.timezone, Settings.timezone_minutes);
    ResponseCmndChar(stemp1);
  }
}

void CmndTimeStdDst(uint32_t ts)
{
  // TimeStd 0/1, 0/1/2/3/4, 1..12, 1..7, 0..23, +/-780
  if (XdrvMailbox.data_len > 0) {
    if (strstr(XdrvMailbox.data, ",") != nullptr) {   // Process parameter entry
      uint32_t tpos = 0;                      // Parameter index
      int value = 0;
      char *p = XdrvMailbox.data;                           // Parameters like "1, 2,3 , 4 ,5, -120" or ",,,,,+240"
      char *q = p;                           // Value entered flag
      while (p && (tpos < 7)) {
        if (p > q) {                         // Any value entered
          if (1 == tpos) { Settings.tflag[ts].hemis = value &1; }
          if (2 == tpos) { Settings.tflag[ts].week = (value < 0) ? 0 : (value > 4) ? 4 : value; }
          if (3 == tpos) { Settings.tflag[ts].month = (value < 1) ? 1 : (value > 12) ? 12 : value; }
          if (4 == tpos) { Settings.tflag[ts].dow = (value < 1) ? 1 : (value > 7) ? 7 : value; }
          if (5 == tpos) { Settings.tflag[ts].hour = (value < 0) ? 0 : (value > 23) ? 23 : value; }
          if (6 == tpos) { Settings.toffset[ts] = (value < -900) ? -900 : (value > 900) ? 900 : value; }
        }
        p = Trim(p);                        // Skip spaces
        if (tpos && (*p == ',')) { p++; }    // Skip separator
        p = Trim(p);                        // Skip spaces
        q = p;                               // Reset any value entered flag
        value = strtol(p, &p, 10);
        tpos++;                              // Next parameter
      }
      ntp_force_sync = true;
    } else {
      if (0 == XdrvMailbox.payload) {
        if (0 == ts) {
          SettingsResetStd();
        } else {
          SettingsResetDst();
        }
      }
      ntp_force_sync = true;
    }
  }
  Response_P(PSTR("{\"%s\":{\"Hemisphere\":%d,\"Week\":%d,\"Month\":%d,\"Day\":%d,\"Hour\":%d,\"Offset\":%d}}"),
    XdrvMailbox.command, Settings.tflag[ts].hemis, Settings.tflag[ts].week, Settings.tflag[ts].month, Settings.tflag[ts].dow, Settings.tflag[ts].hour, Settings.toffset[ts]);
}

void CmndTimeStd(void)
{
  CmndTimeStdDst(0);
}

void CmndTimeDst(void)
{
  CmndTimeStdDst(1);
}

void CmndAltitude(void)
{
  if ((XdrvMailbox.data_len > 0) && ((XdrvMailbox.payload >= -30000) && (XdrvMailbox.payload <= 30000))) {
    Settings.altitude = XdrvMailbox.payload;
  }
  ResponseCmndNumber(Settings.altitude);
}

void CmndLedPower(void)
{
  if ((XdrvMailbox.index > 0) && (XdrvMailbox.index <= MAX_LEDS)) {
    if (99 == pin[GPIO_LEDLNK]) { XdrvMailbox.index = 1; }
    if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload <= 2)) {
      Settings.ledstate &= 8;                // Disable power control
      uint32_t mask = 1 << (XdrvMailbox.index -1);        // Led to control
      switch (XdrvMailbox.payload) {
      case 0: // Off
        led_power &= (0xFF ^ mask);
        Settings.ledstate = 0;
        break;
      case 1: // On
        led_power |= mask;
        Settings.ledstate = 8;
        break;
      case 2: // Toggle
        led_power ^= mask;
        Settings.ledstate ^= 8;
        break;
      }
      blinks = 0;
      if (99 == pin[GPIO_LEDLNK]) {
        SetLedPower(Settings.ledstate &8);
      } else {
        SetLedPowerIdx(XdrvMailbox.index -1, (led_power & mask));
      }
    }
    bool state = bitRead(led_power, XdrvMailbox.index -1);
    if (99 == pin[GPIO_LEDLNK]) {
      state = bitRead(Settings.ledstate, 3);
    }
    ResponseCmndIdxChar(GetStateText(state));
  }
}

void CmndLedState(void)
{
  if ((XdrvMailbox.payload >= 0) && (XdrvMailbox.payload < MAX_LED_OPTION)) {
    Settings.ledstate = XdrvMailbox.payload;
    if (!Settings.ledstate) {
      SetLedPowerAll(0);
      SetLedLink(0);
    }
  }
  ResponseCmndNumber(Settings.ledstate);
}

void CmndLedMask(void)
{
  if (XdrvMailbox.data_len > 0) {
    Settings.ledmask = XdrvMailbox.payload;
  }
  char stemp1[TOPSZ];
  snprintf_P(stemp1, sizeof(stemp1), PSTR("%d (0x%04X)"), Settings.ledmask, Settings.ledmask);
  ResponseCmndChar(stemp1);
}

#ifdef USE_I2C
void CmndI2cScan(void)
{
  if (i2c_flg) {
    I2cScan(mqtt_data, sizeof(mqtt_data));
  }
}
#endif  // USE_I2C

void CmndSensor(void)
{
  XsnsCall(FUNC_COMMAND_SENSOR);
}

void CmndDriver(void)
{
  XdrvCall(FUNC_COMMAND_DRIVER);
}
