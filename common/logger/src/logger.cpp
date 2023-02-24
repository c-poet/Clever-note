#include <QString>
#include "inc/logger.h"
#include "inc/log_adapter.h"
#include "inc/log_context.h"

using namespace cc;

Logger::Logger(LogLevel level) {
    this->_level = level;
}

LogLevel Logger::level() {
    return this->_level;
}

Logger &Logger::operator<<(bool b) {
    return *this << QString(b ? "true" : "false");
}

Logger &Logger::operator<<(int i) {
    return *this << QString::number(i);
}

Logger &Logger::operator<<(unsigned int i) {
    return *this << QString::number(i);
}

Logger &Logger::operator<<(long l) {
    return *this << QString::number(l);
}

Logger &Logger::operator<<(unsigned long l) {
    return *this << QString::number(l);
}

Logger &Logger::operator<<(float f) {
    return *this << QString::number(f);
}

Logger &Logger::operator<<(double d) {
    return *this << QString::number(d);
}

Logger &Logger::operator<<(char c) {
    return *this << QString(c);
}

Logger &Logger::operator<<(unsigned char c) {
    return *this << QString(c);
}

Logger &Logger::operator<<(const char *c) {
    return *this << QString(c);
}

Logger &Logger::operator<<(const QString &str) {
    if (LogContext::level() <= this->_level) {
        LogContext::adapter().handle(str);
    }
    return *this;
}
