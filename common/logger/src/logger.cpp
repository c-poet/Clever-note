#include "inc/logger.h"

using namespace cc;

bool Logger::isEnabled() {
    return false;
}

LogLevel Logger::getLevel() {
    return level;
}

Logger &Logger::operator<<(char c) {

    return *this;
}

Logger &Logger::operator<<(const char *c) {
    return *this;
}

Logger &Logger::operator<<(const QString &str) {
    return *this;
}
