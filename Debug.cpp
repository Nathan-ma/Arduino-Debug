#include "Debug.h"

const char* DebugClass::address = "";
uint32_t DebugClass::port = 0;
bool DebugClass::activate = true;
String DebugClass::systemName = "";
remote_log_settings_t DebugClass::Settings = {
    .print = false, .warn = false, .error = false, .detail = false};

/** @brief Debug Print */
void DebugClass::print(const char* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  size_t len = vsnprintf(temp, sizeof(loc_buf), fmt, copy);
  va_end(copy);
  if (len < 0) {
    va_end(arg);
    return;
  };
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      va_end(arg);
      return;
    }
    len = vsnprintf(temp, len + 1, fmt, arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[%s] : %s \r\n", TAG, temp);
  } else {
    LOG_INFO(TAG, "%s", temp);
  }
#if defined(ESP32) || defined(ESP8266)
  if (Settings.print)
    remote_log(PT_PRINT, LOG_COLOR_NORMAL(COLOR_GREEN), temp);
#endif
  if (len >= sizeof(loc_buf))
    free(temp);
}

/** @brief Debug Override*/
void DebugClass::print(const __FlashStringHelper* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  size_t len = vsnprintf(temp, sizeof(loc_buf), reinterpret_cast<const char*>(fmt), copy);
  va_end(copy);
  if (len < 0) {
    va_end(arg);
    return;
  };
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      va_end(arg);
      return;
    }
    len = vsnprintf(temp, len + 1, reinterpret_cast<const char*>(fmt), arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[%s] : %s \r\n", TAG, temp);
  } else {
    LOG_INFO(TAG, "%s", temp);
  }
#if defined(ESP32) || defined(ESP8266)
  if (Settings.print)
    remote_log(PT_PRINT, LOG_COLOR_NORMAL(COLOR_GREEN), temp);
#endif
  if (len >= sizeof(loc_buf))
    free(temp);
}

/** @brief Error Print*/
void DebugClass::error(const char* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  size_t len = vsnprintf(temp, sizeof(loc_buf), fmt, copy);
  va_end(copy);
  if (len < 0) {
    va_end(arg);
    return;
  };
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      va_end(arg);
      return;
    }
    len = vsnprintf(temp, len + 1, fmt, arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[ERR][%s] : %s \r\n", TAG, temp);
  } else {
    LOG_ERRO(TAG, "%s", temp);
  }
#if defined(ESP32) || defined(ESP8266)
  if (Settings.error)
    remote_log(PT_ERROR, LOG_COLOR_NORMAL(COLOR_RED), temp);
#endif
  if (len >= sizeof(loc_buf))
    free(temp);
}

/** @brief Error Override*/
void DebugClass::error(const __FlashStringHelper* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  size_t len = vsnprintf(temp, sizeof(loc_buf), reinterpret_cast<const char*>(fmt), copy);
  va_end(copy);
  if (len < 0) {
    va_end(arg);
    return;
  };
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      va_end(arg);
      return;
    }
    len = vsnprintf(temp, len + 1, reinterpret_cast<const char*>(fmt), arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[ERR][%s] : %s \r\n", TAG, temp);
  } else {
    LOG_ERRO(TAG, "%s", temp);
  }
#if defined(ESP32) || defined(ESP8266)
  if (Settings.error)
    remote_log(PT_ERROR, LOG_COLOR_NORMAL(COLOR_RED), temp);
#endif
  if (len >= sizeof(loc_buf))
    free(temp);
}

/** @brief Warn Print*/
void DebugClass::warn(const char* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  size_t len = vsnprintf(temp, sizeof(loc_buf), fmt, copy);
  va_end(copy);
  if (len < 0) {
    va_end(arg);
    return;
  };
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      va_end(arg);
      return;
    }
    len = vsnprintf(temp, len + 1, fmt, arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[WARN][%s] : %s \r\n", TAG, temp);
  } else {
    LOG_WARN(TAG, "%s", temp);
  }
#if defined(ESP32) || defined(ESP8266)
  if (Settings.warn)
    remote_log(PT_WARNING, LOG_COLOR_NORMAL(COLOR_YELLOW), temp);
#endif
  if (len >= sizeof(loc_buf))
    free(temp);
}

/** @brief Warn Override*/
void DebugClass::warn(const __FlashStringHelper* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  size_t len = vsnprintf(temp, sizeof(loc_buf), reinterpret_cast<const char*>(fmt), copy);
  va_end(copy);
  if (len < 0) {
    va_end(arg);
    return;
  };
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      va_end(arg);
      return;
    }
    len = vsnprintf(temp, len + 1, reinterpret_cast<const char*>(fmt), arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[WARN][%s] : %s \r\n", TAG, temp);
  } else {
    LOG_WARN(TAG, "%s", temp);
  }
#if defined(ESP32) || defined(ESP8266)
  if (Settings.warn)
    remote_log(PT_WARNING, LOG_COLOR_NORMAL(COLOR_YELLOW), temp);
#endif
  if (len >= sizeof(loc_buf))
    free(temp);
}

/** @brief Warn Print*/
void DebugClass::detail(const char* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  size_t len = vsnprintf(temp, sizeof(loc_buf), fmt, copy);
  va_end(copy);
  if (len < 0) {
    va_end(arg);
    return;
  };
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      va_end(arg);
      return;
    }
    len = vsnprintf(temp, len + 1, fmt, arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[WARN][%s] : %s \r\n", TAG, temp);
  } else {
    LOG_DEBG(TAG, "%s", temp);
  }
#if defined(ESP32) || defined(ESP8266)
  if (Settings.detail)
    remote_log(PT_DETAIL, LOG_COLOR_NORMAL(COLOR_CYAN), temp);
#endif
  if (len >= sizeof(loc_buf))
    free(temp);
}

/** @brief Warn Override*/
void DebugClass::detail(const __FlashStringHelper* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  size_t len = vsnprintf(temp, sizeof(loc_buf), reinterpret_cast<const char*>(fmt), copy);
  va_end(copy);
  if (len < 0) {
    va_end(arg);
    return;
  };
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      va_end(arg);
      return;
    }
    len = vsnprintf(temp, len + 1, reinterpret_cast<const char*>(fmt), arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[WARN][%s] : %s \r\n", TAG, temp);
  } else {
    LOG_DEBG(TAG, "%s", temp);
  }
#if defined(ESP32) || defined(ESP8266)
  if (Settings.detail)
    remote_log(PT_DETAIL, LOG_COLOR_NORMAL(COLOR_CYAN), temp);
#endif
  if (len >= sizeof(loc_buf))
    free(temp);
}

void DebugClass::notice(const char* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  size_t len = vsnprintf(temp, sizeof(loc_buf), fmt, copy);
  va_end(copy);
  if (len < 0) {
    va_end(arg);
    return;
  };
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      va_end(arg);
      return;
    }
    len = vsnprintf(temp, len + 1, fmt, arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[%s] : %s \r\n", TAG, temp);
  } else {
    LOG_NOTC(TAG, "%s", temp);
  }

#if defined(ESP32) || defined(ESP8266)
  remote_log(PT_NOTICE, LOG_COLOR_NORMAL(COLOR_MAGENTA), temp);
#endif
  if (len >= sizeof(loc_buf))
    free(temp);
}

void DebugClass::notice(const __FlashStringHelper* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  size_t len = vsnprintf(temp, sizeof(loc_buf), reinterpret_cast<const char*>(fmt), copy);
  va_end(copy);
  if (len < 0) {
    va_end(arg);
    return;
  };
  if (len >= sizeof(loc_buf)) {
    temp = (char*)malloc(len + 1);
    if (temp == NULL) {
      va_end(arg);
      return;
    }
    len = vsnprintf(temp, len + 1, reinterpret_cast<const char*>(fmt), arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[%s] : %s \r\n", TAG, temp);
  } else {
    LOG_NOTC(TAG, "%s", temp);
  }

#if defined(ESP32) || defined(ESP8266)
  remote_log(PT_NOTICE, LOG_COLOR_NORMAL(COLOR_MAGENTA), temp);
#endif
  if (len >= sizeof(loc_buf))
    free(temp);
}
