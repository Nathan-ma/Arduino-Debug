#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

#include "Macros.h"
#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include <WiFiUdp.h>
const int FacilityCode = 16;

#ifndef PRINT_DEBUG
#define PRINT_DEBUG true
#endif

#ifndef DEBUG_BUFFER_SIZE
#define DEBUG_BUFFER_SIZE 1024
#endif

typedef enum {
  PT_ERROR = 3,
  PT_WARNING = 4,
  PT_NOTICE = 5,
  PT_PRINT = 6,
  PT_DETAIL = 7
} papertrail_log_level_t;

class DebugClass {
 private:
  /* Variables */
  bool const debug = PRINT_DEBUG;
  char const* TAG;
  static const char* address;
  static uint32_t port;
  static String systemName;
  

  /* Methods */
  void remote_log(papertrail_log_level_t level, String color, char* msg) {
    if (WiFi.status() != WL_CONNECTED || (address && !address[0])) {
      return;
    }
    WiFiUDP wifiUDP;

    wifiUDP.beginPacket(address, port);
    String syslogMessage = "<" + String(FacilityCode * 8 + level) + ">1 - " + systemName + " " + TAG + " - - - " + color + String((const char*)msg);
    wifiUDP.write((const uint8_t*)syslogMessage.c_str(), syslogMessage.length());
    wifiUDP.endPacket();
  }

 public:
  /* Static */
  /** @brief Defines PaperTrail Address */
  void setAddress(const char* _address_, uint32_t _port_) {
    address = _address_;
    port = _port_;
  }

  void setSystemName(const String& name) {
    systemName = name;
  }

  /** @brief Class Constructor */
  DebugClass(const char* ClassTag) : TAG(ClassTag){};

  /** @brief Debug Print */
  void print(const char* fmt, ...);

  /** @brief Debug Override*/
  void print(const __FlashStringHelper* fmt, ...);

  /** @brief Error Print*/
  void error(const char* fmt, ...);
  /** @brief Error Override*/
  void error(const __FlashStringHelper* fmt, ...);

  /** @brief Warn Print*/
  void warn(const char* fmt, ...);

  /** @brief Warn Override*/
  void warn(const __FlashStringHelper* fmt, ...);

  /** @brief Warn Print*/
  void detail(const char* fmt, ...);
  /** @brief Warn Override*/
  void detail(const __FlashStringHelper* fmt, ...);

  /** @brief Notice Print*/
  void notice(const char* fmt, ...);
  /** @brief Noticve Override */
  void notice(const __FlashStringHelper* fmt, ...);
};

#endif
