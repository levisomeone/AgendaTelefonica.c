#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR
} LogLevel;

void log_init(const char *filename, LogLevel level);
void log_close(void);
void log_write(LogLevel level, const char *format, ...);

#define LOG_DEBUG(...) log_write(LOG_LEVEL_DEBUG, __VA_ARGS__)
#define LOG_INFO(...)  log_write(LOG_LEVEL_INFO,  __VA_ARGS__)
#define LOG_WARN(...)  log_write(LOG_LEVEL_WARN,  __VA_ARGS__)
#define LOG_ERROR(...) log_write(LOG_LEVEL_ERROR, __VA_ARGS__)

#endif
