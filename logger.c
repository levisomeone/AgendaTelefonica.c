#include "logger.h"
#include <time.h>
#include <stdarg.h>

static FILE *log_file = NULL;
static LogLevel current_level = LOG_LEVEL_DEBUG;

static const char *level_to_string(LogLevel level) {
    switch (level) {
        case LOG_LEVEL_DEBUG: return "DEBUG";
        case LOG_LEVEL_INFO:  return "INFO";
        case LOG_LEVEL_WARN:  return "WARN";
        case LOG_LEVEL_ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void log_init(const char *filename, LogLevel level) {
    log_file = fopen(filename, "a");
    current_level = level;
}

void log_close(void) {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}

void log_write(LogLevel level, const char *format, ...) {
    if (!log_file || level < current_level) return;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    fprintf(log_file,
        "[%02d/%02d/%04d %02d:%02d:%02d] [%s] ",
        t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
        t->tm_hour, t->tm_min, t->tm_sec,
        level_to_string(level)
    );

    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    va_end(args);

    fprintf(log_file, "\n");
    fflush(log_file);
}
