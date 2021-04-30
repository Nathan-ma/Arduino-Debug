#include <Debug.h>

const char* DebugClass::address = "";
uint32_t DebugClass::port = 0;
String DebugClass::systemName = "";

/** @brief Debug Print */
void DebugClass::print(const char* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  int len = vsnprintf(temp, sizeof(loc_buf), fmt, copy);
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
    ESP_LOGI(TAG, "%s", temp);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_PRINT, LOG_COLOR(LOG_COLOR_GREEN), temp);
#endif
}

/** @brief Debug Override*/
void DebugClass::print(const __FlashStringHelper* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  int len = vsnprintf(temp, sizeof(loc_buf), reinterpret_cast<const char *>(fmt), copy);
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
    len = vsnprintf(temp, len + 1, reinterpret_cast<const char *>(fmt), arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[%s] : %s \r\n", TAG, temp);
  } else {
    ESP_LOGI(TAG, "%s", temp);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_PRINT, LOG_COLOR(LOG_COLOR_GREEN), temp);
#endif
}

/** @brief Error Print*/
void DebugClass::error(const char* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  int len = vsnprintf(temp, sizeof(loc_buf), fmt, copy);
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
    ESP_LOGE(TAG, "%s", temp);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_ERROR, LOG_COLOR(LOG_COLOR_RED), temp);
#endif
}

/** @brief Error Override*/
void DebugClass::error(const __FlashStringHelper* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  int len = vsnprintf(temp, sizeof(loc_buf), reinterpret_cast<const char *>(fmt), copy);
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
    len = vsnprintf(temp, len + 1, reinterpret_cast<const char *>(fmt), arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[ERR][%s] : %s \r\n", TAG, temp);
  } else {
    ESP_LOGE(TAG, "%s", temp);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_ERROR, LOG_COLOR(LOG_COLOR_RED), temp);
#endif
}

/** @brief Warn Print*/
void DebugClass::warn(const char* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  int len = vsnprintf(temp, sizeof(loc_buf), fmt, copy);
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
    ESP_LOGW(TAG, "%s", temp);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_WARNING, LOG_COLOR(LOG_COLOR_YELLOW), temp);
#endif
}

/** @brief Warn Override*/
void DebugClass::warn(const __FlashStringHelper* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  int len = vsnprintf(temp, sizeof(loc_buf), reinterpret_cast<const char *>(fmt), copy);
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
    len = vsnprintf(temp, len + 1, reinterpret_cast<const char *>(fmt), arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[WARN][%s] : %s \r\n", TAG, temp);
  } else {
    ESP_LOGW(TAG, "%s", temp);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_WARNING, LOG_COLOR(LOG_COLOR_YELLOW), temp);
#endif
}

/** @brief Warn Print*/
void DebugClass::detail(const char* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  int len = vsnprintf(temp, sizeof(loc_buf), fmt, copy);
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
    ESP_LOGD(TAG, "%s", temp);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_DETAIL, LOG_COLOR(LOG_COLOR_CYAN), temp);
#endif
}

/** @brief Warn Override*/
void DebugClass::detail(const __FlashStringHelper* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  int len = vsnprintf(temp, sizeof(loc_buf), reinterpret_cast<const char *>(fmt), copy);
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
    len = vsnprintf(temp, len + 1, reinterpret_cast<const char *>(fmt), arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[WARN][%s] : %s \r\n", TAG, temp);
  } else {
    ESP_LOGD(TAG, "%s", temp);
  }
#ifdef PAPER_TRAIL
  remote_log(PT_DETAIL, LOG_COLOR(LOG_COLOR_CYAN), temp);
#endif
}

void DebugClass::notice(const char* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  int len = vsnprintf(temp, sizeof(loc_buf), fmt, copy);
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
    ESP_LOGN(TAG, "%s", temp);
  }

  remote_log(PT_NOTICE, LOG_COLOR(LOG_COLOR_MAGENTA), temp);
}

void DebugClass::notice(const __FlashStringHelper* fmt, ...) {
  char loc_buf[64];
  char* temp = loc_buf;
  va_list arg;
  va_list copy;
  va_start(arg, fmt);
  va_copy(copy, arg);
  int len = vsnprintf(temp, sizeof(loc_buf), reinterpret_cast<const char *>(fmt), copy);
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
    len = vsnprintf(temp, len + 1, reinterpret_cast<const char *>(fmt), arg);
  }
  va_end(arg);

  if (debug) {
    Serial.printf("[%s] : %s \r\n", TAG, temp);
  } else {
    ESP_LOGN(TAG, "%s", temp);
  }
  remote_log(PT_NOTICE, LOG_COLOR(LOG_COLOR_MAGENTA), temp);
}
