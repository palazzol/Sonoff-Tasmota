/*
  nl-NL.h - localization for Dutch - Nederland for Sonoff-Tasmota

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

#ifndef _LANGUAGE_NL_NL_H_
#define _LANGUAGE_NL_NL_H_

/*************************** ATTENTION *******************************\
 *
 * Due to memory constraints only UTF-8 is supported.
 * To save code space keep text as short as possible.
 * Time and Date provided by SDK can not be localized (yet).
 * Use online command StateText to translate ON, OFF, HOLD and TOGGLE.
 * Use online command Prefix to translate cmnd, stat and tele.
 *
 * Updated until v6.0.0a
\*********************************************************************/

//#define LANGUAGE_MODULE_NAME         // Enable to display "Module Generic" (ie Spanish), Disable to display "Generic Module" (ie English)

#define LANGUAGE_LCID 1043
// HTML (ISO 639-1) Language Code
#define D_HTML_LANGUAGE "nl"

// "2017-03-07T11:08:02" - ISO8601:2004
#define D_YEAR_MONTH_SEPARATOR "-"
#define D_MONTH_DAY_SEPARATOR "-"
#define D_DATE_TIME_SEPARATOR "T"
#define D_HOUR_MINUTE_SEPARATOR ":"
#define D_MINUTE_SECOND_SEPARATOR ":"

#define D_DAY3LIST "Zo Ma Di Wo Do Vr Za "
#define D_MONTH3LIST "JanFebMarAprMeiJunJulAugSepOktNovDec"

// Non JSON decimal separator
#define D_DECIMAL_SEPARATOR ","

// Common
#define D_ADMIN "Admin"
#define D_AIR_QUALITY "Lucht kwaliteit"
#define D_AP "AP"                    // Access Point
#define D_AS "als"
#define D_AUTO "AUTO"
#define D_BLINK "Knipper"
#define D_BLINKOFF "KnipperUit"
#define D_BOOT_COUNT "Herstarts"
#define D_BRIGHTLIGHT "Fel"
#define D_BSSID "BSSId"
#define D_BUTTON "DrukKnop"
#define D_BY "door"                  // Written by me
#define D_BYTES "Bytes"
#define D_CELSIUS "Celsius"
#define D_CHANNEL "Kanaal"
#define D_CO2 "Koolstofdioxide"
#define D_CODE "code"                // Button code
#define D_COLDLIGHT "Koud"
#define D_COMMAND "Opdracht"
#define D_CONNECTED "Verbonden"
#define D_COUNT "Aantal"
#define D_COUNTER "Teller"
#define D_CURRENT "Stroom"          // As in Voltage and Current
#define D_DATA "Data"
#define D_DARKLIGHT "Donker"
#define D_DEBUG "Debug"
#define D_DISABLED "Uitgeschakeld"
#define D_DISTANCE "Afstand"
#define D_DNS_SERVER "DNS Server"
#define D_DONE "Klaar"
#define D_DST_TIME "ZT"
#define D_ECO2 "eCO2"
#define D_EMULATION "Emulatie"
#define D_ENABLED "Geactiveerd"
#define D_ERASE "Wissen"
#define D_ERROR "Fout"
#define D_FAHRENHEIT "Fahrenheit"
#define D_FAILED "Mislukt"
#define D_FALLBACK "Fallback"
#define D_FALLBACK_TOPIC "Fallback Topic"
#define D_FALSE "Onwaar"
#define D_FILE "Bestand"
#define D_FLOW_RATE "Flow rate"
#define D_FREE_MEMORY "Vrij geheugen"
#define D_FREQUENCY "Frequentie"
#define D_GAS "Gas"
#define D_GATEWAY "Gateway"
#define D_GROUP "Groep"
#define D_HOST "Host"
#define D_HOSTNAME "Hostnaam"
#define D_HUMIDITY "Luchtvochtigheid"
#define D_ILLUMINANCE "Verlichtingssterkte"
#define D_IMMEDIATE "onmiddelijk"      // Button immediate
#define D_INDEX "Index"
#define D_INFO "Info"
#define D_INFRARED "Infrarood"
#define D_INITIALIZED "Geinitialiseerd"
#define D_IP_ADDRESS "IP Adres"
#define D_LIGHT "Licht"
#define D_LWT "LWT"
#define D_MODULE "Module"
#define D_MQTT "MQTT"
#define D_MULTI_PRESS "meervoudig"
#define D_NOISE "Lawaai"
#define D_NONE "Geen"
#define D_OFF "Uit"
#define D_OFFLINE "Offline"
#define D_OK "Ok"
#define D_ON "Aan"
#define D_ONLINE "Online"
#define D_PASSWORD "Wachtwoord"
#define D_PORT "Poort"
#define D_POWER_FACTOR "Arbeidsfactor"
#define D_POWERUSAGE "Vermogen"
#define D_POWERUSAGE_ACTIVE "Werkelijk vermogen"
#define D_POWERUSAGE_APPARENT "Schijnbaar vermogen"
#define D_POWERUSAGE_REACTIVE "Blindvermogen"
#define D_PRESSURE "Luchtdruk"
#define D_PRESSUREATSEALEVEL "ZeeLuchtdruk"
#define D_PROGRAM_FLASH_SIZE "Programma Flash Grootte"
#define D_PROGRAM_SIZE "Programma Grootte"
#define D_PROJECT "Project"
#define D_RAIN "Regen"
#define D_RECEIVED "Ontvangen"
#define D_RESTART "Herstart"
#define D_RESTARTING "Herstarten"
#define D_RESTART_REASON "Reden herstart"
#define D_RESTORE "herstellen"
#define D_RETAINED "retained"
#define D_RULE "Regel"
#define D_SAVE "Opslaan"
#define D_SENSOR "Sensor"
#define D_SSID "SSId"
#define D_START "Start"
#define D_STD_TIME "WT"
#define D_STOP "Stop"
#define D_SUBNET_MASK "Subnet Masker"
#define D_SUBSCRIBE_TO "Abonneer op"
#define D_UNSUBSCRIBE_FROM "Unsubscribe from"
#define D_SUCCESSFUL "Gelukt"
#define D_SUNRISE "Zonsopgang"
#define D_SUNSET "Zonsondergang"
#define D_TEMPERATURE "Temperatuur"
#define D_TO "naar"
#define D_TOGGLE "Toggle"  // Wissel, Tuimel
#define D_TOPIC "Topic"  // Onderwerp
#define D_TOTAL_USAGE "Total Usage"
#define D_TRANSMIT "Verzend"
#define D_TRUE "Waar"
#define D_TVOC "TVOC"
#define D_UPGRADE "opwaarderen"
#define D_UPLOAD "Verzenden"
#define D_UPTIME "Bedrijfstijd"
#define D_USER "Gebruiker"
#define D_UTC_TIME "UTC"
#define D_UV_INDEX "UV-index"
#define D_UV_INDEX_1 "Low"
#define D_UV_INDEX_2 "Mid"
#define D_UV_INDEX_3 "High"
#define D_UV_INDEX_4 "Danger"
#define D_UV_INDEX_5 "BurnL1/2"
#define D_UV_INDEX_6 "BurnL3"
#define D_UV_INDEX_7 "OoR"
#define D_UV_LEVEL "UV niveau"
#define D_UV_POWER "UV Power"
#define D_VERSION "Versie"
#define D_VOLTAGE "Spanning"
#define D_WEIGHT "Gewicht"
#define D_WARMLIGHT "Warm"
#define D_WEB_SERVER "Webserver"

// sonoff.ino
#define D_WARNING_MINIMAL_VERSION "WAARSCHUWING Deze versie bewaart geen instellingen"
#define D_LEVEL_10 "niveau 1-0"
#define D_LEVEL_01 "niveau 0-1"
#define D_SERIAL_LOGGING_DISABLED "Serieel logging uitgeschakeld"
#define D_SYSLOG_LOGGING_REENABLED "Syslog logging weer ingeschakeld"

#define D_SET_BAUDRATE_TO "Zet baudrate op"
#define D_RECEIVED_TOPIC "Ontvangen topic"
#define D_DATA_SIZE "Data lengte"
#define D_ANALOG_INPUT "Analoog"

// support.ino
#define D_OSWATCH "osWatch"
#define D_BLOCKED_LOOP "Blocked Loop"
#define D_WPS_FAILED_WITH_STATUS "WPSconfig mislukt met status"
#define D_ACTIVE_FOR_3_MINUTES "3 minuten actief"
#define D_FAILED_TO_START "mislukt"
#define D_PATCH_ISSUE_2186 "Patch issue 2186"
#define D_CONNECTING_TO_AP "Verbinden met AP"
#define D_IN_MODE "in stand"
#define D_CONNECT_FAILED_NO_IP_ADDRESS "Verbinding mislukt omdat geen IP adres werd ontvangen"
#define D_CONNECT_FAILED_AP_NOT_REACHED "Verbinding mislukt omdat AP onbereikbaar is"
#define D_CONNECT_FAILED_WRONG_PASSWORD "Verbinding mislukt door fout wachtwoord"
#define D_CONNECT_FAILED_AP_TIMEOUT "Verbinding mislukt door AP time-out"
#define D_ATTEMPTING_CONNECTION "Verbinden..."
#define D_CHECKING_CONNECTION "Controleer verbinding..."
#define D_QUERY_DONE "Aanvraag klaar. Aantal MQTT diensten gevonden"
#define D_MQTT_SERVICE_FOUND "MQTT dienst gevonden op"
#define D_FOUND_AT "gevonden op"
#define D_SYSLOG_HOST_NOT_FOUND "Syslog Host niet gevonden"

// settings.ino
#define D_SAVED_TO_FLASH_AT "Opgeslagen in flash op"
#define D_LOADED_FROM_FLASH_AT "Geladen vanuit flash op"
#define D_USE_DEFAULTS "Gebruik standaardwaarden"
#define D_ERASED_SECTOR "Wis sector"

// xdrv_02_webserver.ino
#define D_NOSCRIPT "Zet JavaScript aan voor Tasmota"
#define D_MINIMAL_FIRMWARE_PLEASE_UPGRADE "MINIMAL firmware<br>opwaarderen"
#define D_WEBSERVER_ACTIVE_ON "Webserver actief op"
#define D_WITH_IP_ADDRESS "met IP adres"
#define D_WEBSERVER_STOPPED "Webserver gestopt"
#define D_FILE_NOT_FOUND "Bestand niet gevonden"
#define D_REDIRECTED "Redirected to captive portal"
#define D_WIFIMANAGER_SET_ACCESSPOINT_AND_STATION "Wifimanager start AccessPoint en hou Station"
#define D_WIFIMANAGER_SET_ACCESSPOINT "Wifimanager start AccessPoint"
#define D_TRYING_TO_CONNECT "Apparaat probeert te verbinden met netwerk"

#define D_RESTART_IN "Herstart over"
#define D_SECONDS "seconden"
#define D_DEVICE_WILL_RESTART "Herstart over enkele seconden"
#define D_BUTTON_TOGGLE "Toggle"  // Wissel, Tuimel
#define D_CONFIGURATION "Configuratie"
#define D_INFORMATION "Informatie"
#define D_FIRMWARE_UPGRADE "Opwaarderen"
#define D_CONSOLE "Console"
#define D_CONFIRM_RESTART "Bevestig herstart"

#define D_CONFIGURE_MODULE "Configureer Module"
#define D_CONFIGURE_WIFI "Configureer WiFi"
#define D_CONFIGURE_MQTT "Configureer MQTT"
#define D_CONFIGURE_DOMOTICZ "Configureer Domoticz"
#define D_CONFIGURE_LOGGING "Configureer Logging"
#define D_CONFIGURE_OTHER "Configureer Overige"
#define D_CONFIRM_RESET_CONFIGURATION "Bevestig reset configuratie"
#define D_RESET_CONFIGURATION "Reset Configuratie"
#define D_BACKUP_CONFIGURATION "Bewaar Configuratie"
#define D_RESTORE_CONFIGURATION "Herstel Configuration"
#define D_MAIN_MENU "Hoofdmenu"

#define D_MODULE_PARAMETERS "Module parameters"
#define D_MODULE_TYPE "Module soort"
#define D_PULLUP_ENABLE "Geen schakelaar pull-up"
#define D_ADC "ADC"
#define D_GPIO "GPIO"
#define D_SERIAL_IN "Serieel In"
#define D_SERIAL_OUT "Serieel Uit"

#define D_WIFI_PARAMETERS "Wifi parameters"
#define D_SCAN_FOR_WIFI_NETWORKS "Zoek wifi netwerken"
#define D_SCAN_DONE "Scan klaar"
#define D_NO_NETWORKS_FOUND "Geen netwerken gevonden"
#define D_REFRESH_TO_SCAN_AGAIN "Vernieuw om opnieuw te zoeken"
#define D_DUPLICATE_ACCESSPOINT "Dubbel AccessPoint"
#define D_SKIPPING_LOW_QUALITY "Overslaan agv lage ontvangskwaliteit"
#define D_RSSI "RSSI"
#define D_WEP "WEP"
#define D_WPA_PSK "WPA PSK"
#define D_WPA2_PSK "WPA2 PSK"
#define D_AP1_SSID "AP1 SSId"
#define D_AP1_PASSWORD "AP1 Wachtwoord"
#define D_AP2_SSID "AP2 SSId"
#define D_AP2_PASSWORD "AP2 Wachtwoord"

#define D_MQTT_PARAMETERS "MQTT parameters"
#define D_CLIENT "Client"
#define D_FULL_TOPIC "Volledig Topic"

#define D_LOGGING_PARAMETERS "Logging parameters"
#define D_SERIAL_LOG_LEVEL "Serieel log niveau"
#define D_WEB_LOG_LEVEL "Web log niveau"
#define D_SYS_LOG_LEVEL "Syslog niveau"
#define D_MORE_DEBUG "Meer debug"
#define D_SYSLOG_HOST "Syslog host"
#define D_SYSLOG_PORT "Syslog poort"
#define D_TELEMETRY_PERIOD "Telemetry periode"

#define D_OTHER_PARAMETERS "Overige parameters"
#define D_TEMPLATE "Sjabloon"
#define D_ACTIVATE "Activeer"
#define D_WEB_ADMIN_PASSWORD "Web Admin Wachtwoord"
#define D_MQTT_ENABLE "MQTT ingeschakeld"
#define D_FRIENDLY_NAME "Beschrijvende naam"
#define D_BELKIN_WEMO "Belkin WeMo"
#define D_HUE_BRIDGE "Hue Bridge"
#define D_SINGLE_DEVICE "een apparaat"
#define D_MULTI_DEVICE "meer apparaten"

#define D_CONFIGURE_TEMPLATE "Configureer Sjabloon"
#define D_TEMPLATE_PARAMETERS "Sjabloon parameters"
#define D_TEMPLATE_NAME "Naam"
#define D_BASE_TYPE "Op basis van"
#define D_TEMPLATE_FLAGS "Opties"

#define D_SAVE_CONFIGURATION "Bewaar configuratie"
#define D_CONFIGURATION_SAVED "Configuratie opgeslagen"
#define D_CONFIGURATION_RESET "Configuratie ge-reset"

#define D_PROGRAM_VERSION "Programma Versie"
#define D_BUILD_DATE_AND_TIME "Compileer Datum & Tijd"
#define D_CORE_AND_SDK_VERSION "Core/SDK Versie"
#define D_FLASH_WRITE_COUNT "Aantal Flash opslagen"
#define D_MAC_ADDRESS "MAC Adres"
#define D_MQTT_HOST "MQTT Host"
#define D_MQTT_PORT "MQTT Poort"
#define D_MQTT_CLIENT "MQTT Client"
#define D_MQTT_USER "MQTT Gebruiker"
#define D_MQTT_TOPIC "MQTT Topic"
#define D_MQTT_GROUP_TOPIC "MQTT Groep Topic"
#define D_MQTT_FULL_TOPIC "MQTT Volledig Topic"
#define D_MDNS_DISCOVERY "mDNS Discovery"
#define D_MDNS_ADVERTISE "mDNS Advertise"
#define D_ESP_CHIP_ID "ESP Chip Id"
#define D_FLASH_CHIP_ID "Flash Chip Id"
#define D_FLASH_CHIP_SIZE "Flash Grootte"
#define D_FREE_PROGRAM_SPACE "Programma ruimte over"

#define D_UPGRADE_BY_WEBSERVER "Opwaarderen dmv webserver"
#define D_OTA_URL "OTA Url"
#define D_START_UPGRADE "Start opwaarderen"
#define D_UPGRADE_BY_FILE_UPLOAD "Opwaarderen dmv verzenden bestand"
#define D_UPLOAD_STARTED "Verzending gestart"
#define D_UPGRADE_STARTED "Opwaarderen gestart"
#define D_UPLOAD_DONE "Opwaarderen klaar"
#define D_UPLOAD_ERR_1 "Geen bestand gekozen"
#define D_UPLOAD_ERR_2 "Onvoldoende geheugen ruimte"
#define D_UPLOAD_ERR_3 "Magische byte is niet 0xE9"
#define D_UPLOAD_ERR_4 "Programma flash grootte is groter dan werkelijke flash grootte"
#define D_UPLOAD_ERR_5 "Opwaardeer buffer verschil"
#define D_UPLOAD_ERR_6 "Opwaarderen mislukt. Schakel logging 3 in"
#define D_UPLOAD_ERR_7 "Opwaarderen afgebroken"
#define D_UPLOAD_ERR_8 "Ongeldig bestand"
#define D_UPLOAD_ERR_9 "Bestand is te groot"
#define D_UPLOAD_ERR_10 "Init RF chip mislukt"
#define D_UPLOAD_ERR_11 "Wissen RF chip mislukt"
#define D_UPLOAD_ERR_12 "Opwaarderen RF chip mislukt"
#define D_UPLOAD_ERR_13 "Decoderen RF bestand mislukt"
#define D_UPLOAD_ERROR_CODE "Opwaardeer foutcode"

#define D_ENTER_COMMAND "Geef opdracht"
#define D_ENABLE_WEBLOG_FOR_RESPONSE "Schakel weblog 2 in indien antwoord verwacht"
#define D_NEED_USER_AND_PASSWORD "Benodig user=<gebruiker>&password=<webwachtwoord>"

// xdrv_01_mqtt.ino
#define D_FINGERPRINT "Controleer TLS vingerafdruk..."
#define D_TLS_CONNECT_FAILED_TO "TLS Verbinding mislukt naar"
#define D_RETRY_IN "Opnieuw proberen over"
#define D_VERIFIED "Gecontroleerd met vingerafdruk"
#define D_INSECURE "Door ongeldige vingerafdruk een onveilige verbinding"
#define D_CONNECT_FAILED_TO "Verbinding mislukt naar"

// xplg_wemohue.ino
#define D_MULTICAST_DISABLED "Multicast uitgeschakeld"
#define D_MULTICAST_REJOINED "Multicast verbonden"
#define D_MULTICAST_JOIN_FAILED "Multicast verbinding mislukt"
#define D_FAILED_TO_SEND_RESPONSE "Antwoord versturen mislukt"

#define D_WEMO "WeMo"
#define D_WEMO_BASIC_EVENT "WeMo basis gebeurtenis"
#define D_WEMO_EVENT_SERVICE "WeMo gebeurtenis dienst"
#define D_WEMO_META_SERVICE "WeMo meta service"
#define D_WEMO_SETUP "WeMo installatie"
#define D_RESPONSE_SENT "Antwoord verstuurd"

#define D_HUE "Hue"
#define D_HUE_BRIDGE_SETUP "Hue installatie"
#define D_HUE_API_NOT_IMPLEMENTED "Hue API niet beschikbaar"
#define D_HUE_API "Hue API"
#define D_HUE_POST_ARGS "Hue POST argumenten"
#define D_3_RESPONSE_PACKETS_SENT "3 antwoord paketten verstuurd"

// xdrv_07_domoticz.ino
#define D_DOMOTICZ_PARAMETERS "Domoticz parameters"
#define D_DOMOTICZ_IDX "Idx"
#define D_DOMOTICZ_KEY_IDX "Toets idx"
#define D_DOMOTICZ_SWITCH_IDX "Schakelaar idx"
#define D_DOMOTICZ_SENSOR_IDX "Sensor idx"
  #define D_DOMOTICZ_TEMP "Temp"
  #define D_DOMOTICZ_TEMP_HUM "Temp,Hum"
  #define D_DOMOTICZ_TEMP_HUM_BARO "Temp,Hum,Baro"
  #define D_DOMOTICZ_POWER_ENERGY "Power,Energy"
  #define D_DOMOTICZ_ILLUMINANCE "Illuminance"
  #define D_DOMOTICZ_COUNT "Count/PM1"
  #define D_DOMOTICZ_VOLTAGE "Spanning/PM2,5"
  #define D_DOMOTICZ_CURRENT "Stroom/PM10"
  #define D_DOMOTICZ_AIRQUALITY "AirQuality"
  #define D_DOMOTICZ_P1_SMART_METER "P1SmartMeter"
#define D_DOMOTICZ_UPDATE_TIMER "Bijwerk timer"

// xdrv_09_timers.ino
#define D_CONFIGURE_TIMER "Configureer Tijdschakelaar"
#define D_TIMER_PARAMETERS "Tijdschakelaar parameters"
#define D_TIMER_ENABLE "Tijdschakelaars inschakelen"
#define D_TIMER_ARM "Actief"
#define D_TIMER_TIME "Tijd"
#define D_TIMER_DAYS "Dagen"
#define D_TIMER_REPEAT "Herhaal"
#define D_TIMER_OUTPUT "Uitgang"
#define D_TIMER_ACTION "Actie"

// xdrv_10_knx.ino
#define D_CONFIGURE_KNX "Configureer KNX"
#define D_KNX_PARAMETERS "KNX Parameters"
#define D_KNX_GENERAL_CONFIG "Algemeen"
#define D_KNX_PHYSICAL_ADDRESS "Eigen adres"
#define D_KNX_PHYSICAL_ADDRESS_NOTE "(Moet uniek zijn op het KNX netwerk)"
#define D_KNX_ENABLE "KNX inschakelen"
#define D_KNX_GROUP_ADDRESS_TO_WRITE "Stuur gegevens naar groep adressen"
#define D_ADD "Toevoegen"
#define D_DELETE "Verwijder"
#define D_REPLY "Antwoord"
#define D_KNX_GROUP_ADDRESS_TO_READ "Ontvang gegevens van groep adressen"
#define D_LOG_KNX "KNX: "
#define D_RECEIVED_FROM "Ontvangen van"
#define D_KNX_COMMAND_WRITE "Schrijven"
#define D_KNX_COMMAND_READ "Lezen"
#define D_KNX_COMMAND_OTHER "Overige"
#define D_SENT_TO "verzend naar"
#define D_KNX_WARNING "Groep adres (0/0/0) is gereserveerd en mag niet worden gebruikt."
#define D_KNX_ENHANCEMENT "Verbeter verbinding"
#define D_KNX_TX_SLOT "KNX TX"
#define D_KNX_RX_SLOT "KNX RX"

// xdrv_03_energy.ino
#define D_ENERGY_TODAY "Verbruik vandaag"
#define D_ENERGY_YESTERDAY "Verbruik gisteren"
#define D_ENERGY_TOTAL "Verbruik totaal"

// xsns_05_ds18b20.ino
#define D_SENSOR_BUSY "Sensor bezet"
#define D_SENSOR_CRC_ERROR "Sensor CRC fout"
#define D_SENSORS_FOUND "Aantal sensoren"

// xsns_06_dht.ino
#define D_TIMEOUT_WAITING_FOR "Te lang wachten op"
#define D_START_SIGNAL_LOW "laag start signaal"
#define D_START_SIGNAL_HIGH "hoog start signaal"
#define D_PULSE "signaal"
#define D_CHECKSUM_FAILURE "Controle mislukt"

// xsns_07_sht1x.ino
#define D_SENSOR_DID_NOT_ACK_COMMAND "Geen opdracht ACK van sensor"
#define D_SHT1X_FOUND "SHT1X gevonden"

// xsns_18_pms5003.ino
#define D_STANDARD_CONCENTRATION "CF-1 PM"     // Standard Particle CF-1 Particle Matter
#define D_ENVIRONMENTAL_CONCENTRATION "PM"     // Environmetal Particle Matter
#define D_PARTICALS_BEYOND "Stofdeeltjes"

// xsns_32_mpu6050.ino
#define D_AX_AXIS "Accel. X-Axis"
#define D_AY_AXIS "Accel. Y-Axis"
#define D_AZ_AXIS "Accel. Z-Axis"
#define D_GX_AXIS "Gyro X-Axis"
#define D_GY_AXIS "Gyro Y-Axis"
#define D_GZ_AXIS "Gyro Z-Axis"

// xsns_34_hx711.ino
#define D_HX_CAL_REMOVE "Verwijder gewicht"
#define D_HX_CAL_REFERENCE "Plaats ijkgewicht"
#define D_HX_CAL_DONE "Ge-ijkt"
#define D_HX_CAL_FAIL "Ijken is mislukt"
#define D_RESET_HX711 "Nulstelling weegschaal"
#define D_CONFIGURE_HX711 "Configureer Weegschaal"
#define D_HX711_PARAMETERS "Weegschaal parameters"
#define D_ITEM_WEIGHT "Gewicht van onderdeel"
#define D_REFERENCE_WEIGHT "Ijkgewicht"
#define D_CALIBRATE "Ijken"
#define D_CALIBRATION "Ijken"

//xsns_35_tx20.ino
#define D_TX20_WIND_DIRECTION "Windrichting"
#define D_TX20_WIND_SPEED "Windsnelheid"
#define D_TX20_WIND_SPEED_AVG "Windsnelheid gemiddeld"
#define D_TX20_WIND_SPEED_MAX "Windsnelhied maximaal"
#define D_TX20_NORTH "N"
#define D_TX20_EAST "E"
#define D_TX20_SOUTH "S"
#define D_TX20_WEST "W"

//xsns_43_hre.ino
#define D_LOG_HRE "HRE: "

// sonoff_template.h - keep them as short as possible to be able to fit them in GUI drop down box
#define D_SENSOR_NONE          "Geen"
#define D_SENSOR_USER          "Gebruiker"
#define D_SENSOR_DHT11         "DHT11"
#define D_SENSOR_AM2301        "AM2301"
#define D_SENSOR_SI7021        "SI7021"
#define D_SENSOR_DS18X20       "DS18x20"
#define D_SENSOR_I2C_SCL       "I2C SCL"
#define D_SENSOR_I2C_SDA       "I2C SDA"
#define D_SENSOR_WS2812        "WS2812"
#define D_SENSOR_DFR562        "MP3 Speler"
#define D_SENSOR_IRSEND        "IRsend"
#define D_SENSOR_SWITCH        "Switch"     // Suffix "1"
#define D_SENSOR_BUTTON        "Button"     // Suffix "1"
#define D_SENSOR_RELAY         "Relais"     // Suffix "1i"
#define D_SENSOR_LED           "Led"        // Suffix "1i"
#define D_SENSOR_LED_LINK      "LedLink"    // Suffix "i"
#define D_SENSOR_PWM           "PWM"        // Suffix "1"
#define D_SENSOR_COUNTER       "Teller"     // Suffix "1"
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
#define D_SENSOR_BUZZER        "Zoemer"
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
#define D_UNIT_HOUR "h"
#define D_UNIT_GALLONS "gal"
#define D_UNIT_GALLONS_PER_MIN "g/m"
#define D_UNIT_INCREMENTS "inc"
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
#define D_UNIT_SECOND "sec"
#define D_UNIT_SECTORS "sectoren"
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
#define D_PHASE_ANGLE     "Phase Angle"
#define D_IMPORT_ACTIVE   "Import Active"
#define D_EXPORT_ACTIVE   "Export Active"
#define D_IMPORT_REACTIVE "Import Reactive"
#define D_EXPORT_REACTIVE "Export Reactive"
#define D_TOTAL_REACTIVE  "Total Reactive"
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

#endif  // _LANGUAGE_NL_NL_H_
