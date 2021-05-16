#ifndef MACROS_DEBUG_H
#define MACROS_DEBUG_H

#define LOG_LEVEL_NONE (0)
#define LOG_LEVEL_ERROR (1)
#define LOG_LEVEL_WARN (2)
#define LOG_LEVEL_INFO (3)
#define LOG_LEVEL_DEBUG (4)
#define LOG_LEVEL_VERBOSE (5)

#define COLOR_BLACK     "30"
#define COLOR_RED       "31"   
#define COLOR_GREEN     "32" 
#define COLOR_YELLOW    "33"
#define COLOR_BLUE      "34"
#define COLOR_MAGENTA   "35"
#define COLOR_CYAN      "36"  
#define COLOR_GRAY      "37"  
#define COLOR_WHITE     "38"

#define LOG_COLOR_NORMAL(COLOR) "\x1b[0;" COLOR "m"
#define LOG_COLOR_BOLD(COLOR) "\x1b[1;" COLOR "m"
#define RESET_COLOR "\x1b[0m"

#if CONFIG_LOG_COLORS
#define LOG_COLOR_ERRO LOG_COLOR_BOLD(COLOR_RED)
#define LOG_COLOR_WARN LOG_COLOR_BOLD(COLOR_YELLOW)
#define LOG_COLOR_INFO LOG_COLOR_NORMAL(COLOR_GREEN)
#define LOG_COLOR_DEBG LOG_COLOR_NORMAL(COLOR_CYAN)
#define LOG_COLOR_NOTC LOG_COLOR_NORMAL(COLOR_MAGENTA)

#else
#define LOG_COLOR_ERRO
#define LOG_COLOR_WARN
#define LOG_COLOR_INFO
#define LOG_COLOR_DEBG
#define LOG_COLOR_NOTC
#endif

#define LOG_FORM(tag, letter, format) LOG_COLOR_##letter "[" #letter "] [%s] " format RESET_COLOR "\r\n", tag
#define LOG_N_FORM(tag, letter, format) LOG_COLOR_##letter "[%s] " format RESET_COLOR "\r\n", tag

#if LOG_LEVEL >= LOG_LEVEL_DEBUG
#define log_debg(tag, format, ...) printf(LOG_N_FORM(tag, DEBG, format), ##__VA_ARGS__)
#else
#define log_debg(tag, format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
#define log_info(tag, format, ...) printf(LOG_N_FORM(tag, INFO, format), ##__VA_ARGS__)
#define log_notc(tag, format, ...) printf(LOG_N_FORM(tag, NOTC, format), ##__VA_ARGS__)
#else
#define log_info(tag, format, ...)
#define log_notc(tag, format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#define log_warn(tag, format, ...) printf(LOG_FORM(tag, WARN, format), ##__VA_ARGS__)
#else
#define log_warn(tag, format, ...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define log_erro(tag, format, ...) printf(LOG_FORM(tag, ERRO, format), ##__VA_ARGS__)
#else
#define log_erro(tag, format, ...)
#endif

#ifdef DEBUG_ESP_PORT
#define LOG_INFO(tag, ...) 
#define LOG_WARN(tag, ...) 
#define LOG_ERRO(tag, ...) 
#define LOG_DEBG(tag, ...) 
#define LOG_NOTC(tag, ...)
#else
#define LOG_INFO(tag, ...) log_info(tag, __VA_ARGS__)
#define LOG_WARN(tag, ...) log_warn(tag, __VA_ARGS__)
#define LOG_ERRO(tag, ...) log_erro(tag, __VA_ARGS__)
#define LOG_DEBG(tag, ...) log_debg(tag, __VA_ARGS__)
#define LOG_NOTC(tag, ...) log_notc(tag, __VA_ARGS__)
#endif

#endif
