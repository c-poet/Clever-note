#include "inc/logger.h"
#include <QString>
#include <iostream>

using namespace cc;

bool Logger::isEnabled() {
    return false;
}

LogLevel Logger::getLevel() {
    return level;
}

Logger &Logger::operator<<(char c) {
    std::cout << c;
    return *this;
}

Logger &Logger::operator<<(const char *c) {
    std::cout << c;
    return *this;
}

Logger &Logger::operator<<(const QString &str) {
    std::cout << str.toStdString();
    return *this;
}
