#include "inc/logger.h"
#include "inc/logger_factory.h"

using namespace cc;

Logger &LoggerFactory::getLogger(LogLevel level) {
    return getLogger(level, nullptr, nullptr, -1);
}

Logger &LoggerFactory::getLogger(LogLevel level, const char *file, int line) {
    return getLogger(level, file, nullptr, line);
}

Logger &LoggerFactory::getLogger(LogLevel level, const char *file, const char *func, int line) {
    return *new Logger();
}
