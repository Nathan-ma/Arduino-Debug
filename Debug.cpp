#include <Debug.h>

const char*  DebugClass::address = "";
uint32_t DebugClass::port = 0;
String  DebugClass::systemName = "";

/** @brief Debug Print */
void DebugClass::print(const char* fmt, ...) {
  char buf[DEBUG_BUFFER_SIZE];
  va_list arg;
  va_start(arg, fmt);
  vsnprintf(buf, sizeof(buf), fmt, arg);
  va_end(arg);

  if (debug) {
    Serial.printf("[%s] : %s \r\n", TAG, buf);
  } else {
    ESP_LOGI(TAG, "%s", buf);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_PRINT, LOG_COLOR(LOG_COLOR_GREEN), buf);
#endif
}

/** @brief Debug Override*/
void DebugClass::print(const __FlashStringHelper* fmt, ...) {
  char buf[DEBUG_BUFFER_SIZE];
  va_list arg;
  va_start(arg, fmt);
  vsnprintf(buf, sizeof(buf), (const char*)fmt, arg);
  va_end(arg);

  if (debug) {
    Serial.printf("[%s] : %s \r\n", TAG, buf);
  } else {
    ESP_LOGI(TAG, "%s", buf);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_PRINT, LOG_COLOR(LOG_COLOR_GREEN), buf);
#endif
}

/** @brief Error Print*/
void DebugClass::error(const char* fmt, ...) {
  char buf[DEBUG_BUFFER_SIZE];
  va_list arg;
  va_start(arg, fmt);
  vsnprintf(buf, sizeof(buf), fmt, arg);
  va_end(arg);

  if (debug) {
    Serial.printf("[ERR][%s] : %s \r\n", TAG, buf);
  } else {
    ESP_LOGE(TAG, "%s", buf);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_ERROR, LOG_COLOR(LOG_COLOR_RED), buf);
#endif
}

/** @brief Error Override*/
void DebugClass::error(const __FlashStringHelper* fmt, ...) {
  char buf[DEBUG_BUFFER_SIZE];
  va_list arg;
  va_start(arg, fmt);
  vsnprintf(buf, sizeof(buf), (const char*)fmt, arg);
  va_end(arg);

  if (debug) {
    Serial.printf("[ERR][%s] : %s \r\n", TAG, buf);
  } else {
    ESP_LOGE(TAG, "%s", buf);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_ERROR, LOG_COLOR(LOG_COLOR_RED), buf);
#endif
}

/** @brief Warn Print*/
void DebugClass::warn(const char* fmt, ...) {
  char buf[DEBUG_BUFFER_SIZE];
  va_list arg;
  va_start(arg, fmt);
  vsnprintf(buf, sizeof(buf), fmt, arg);
  va_end(arg);

  if (debug) {
    Serial.printf("[WARN][%s] : %s \r\n", TAG, buf);
  } else {
    ESP_LOGW(TAG, "%s", buf);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_WARNING, LOG_COLOR(LOG_COLOR_YELLOW), buf);
#endif
}

/** @brief Warn Override*/
void DebugClass::warn(const __FlashStringHelper* fmt, ...) {
  char buf[DEBUG_BUFFER_SIZE];
  va_list arg;
  va_start(arg, fmt);
  vsnprintf(buf, sizeof(buf), (const char*)fmt, arg);
  va_end(arg);

  if (debug) {
    Serial.printf("[WARN][%s] : %s \r\n", TAG, buf);
  } else {
    ESP_LOGW(TAG, "%s", buf);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_WARNING, LOG_COLOR(LOG_COLOR_YELLOW), buf);
#endif
}

/** @brief Warn Print*/
void DebugClass::detail(const char* fmt, ...) {
  char buf[DEBUG_BUFFER_SIZE];
  va_list arg;
  va_start(arg, fmt);
  vsnprintf(buf, sizeof(buf), fmt, arg);
  va_end(arg);

  if (debug) {
    Serial.printf("[WARN][%s] : %s \r\n", TAG, buf);
  } else {
    ESP_LOGD(TAG, "%s", buf);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_DETAIL, LOG_COLOR(LOG_COLOR_CYAN), buf);
#endif
}

/** @brief Warn Override*/
void DebugClass::detail(const __FlashStringHelper* fmt, ...) {
  char buf[DEBUG_BUFFER_SIZE];
  va_list arg;
  va_start(arg, fmt);
  vsnprintf(buf, sizeof(buf), (const char*)fmt, arg);
  va_end(arg);

  if (debug) {
    Serial.printf("[WARN][%s] : %s \r\n", TAG, buf);
  } else {
    ESP_LOGD(TAG, "%s", buf);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_DETAIL, LOG_COLOR(LOG_COLOR_CYAN), buf);
#endif
}

void DebugClass::notice(const char* fmt, ...) {
  char buf[DEBUG_BUFFER_SIZE];
  va_list arg;
  va_start(arg, fmt);
  vsnprintf(buf, sizeof(buf), fmt, arg);
  va_end(arg);

  if (debug) {
    Serial.printf("[%s] : %s \r\n", TAG, buf);
  } else {
    ESP_LOGN(TAG, "%s", buf);
  }
  remote_log(PT_NOTICE, LOG_COLOR(LOG_COLOR_MAGENTA), buf);
}

void DebugClass::notice(const __FlashStringHelper* fmt, ...) {
  char buf[DEBUG_BUFFER_SIZE];
  va_list arg;
  va_start(arg, fmt);
  vsnprintf(buf, sizeof(buf), (const char*)fmt, arg);
  va_end(arg);

  if (debug) {
    Serial.printf("[%s] : %s \r\n", TAG, buf);
  } else {
    ESP_LOGN(TAG, "%s", buf);
  }
  remote_log(PT_NOTICE, LOG_COLOR(LOG_COLOR_MAGENTA), buf);
}
