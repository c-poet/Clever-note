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

Logger &Logger::operator<<(bool b) {
    return *this;
}

Logger &Logger::operator<<(int i) {
    return *this;
}

Logger &Logger::operator<<(long l) {
    return *this;
}

Logger &Logger::operator<<(float f) {
    return *this;
}

Logger &Logger::operator<<(double d) {
    return *this;
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
