#include <stdio.h>
#include <stdarg.h>
typedef enum {
    ERROR = 0,
    INFO,
    TRACE,
    DEBUG
} LogLevel;
LogLevel current_level = INFO;
const char* level_strings[] = {
    "ERROR",
    "INFO",
    "DEBUG",
    "TRACE"
};
LogLevel set_log_level(LogLevel level) {
    LogLevel previous = current_level;
    current_level = level;
    return previous;

}
void logger(LogLevel level, const char* format, ...) {
    if (level <= current_level) {
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
    }
}