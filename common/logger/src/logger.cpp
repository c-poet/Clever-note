#include <QString>
#include "inc/logger.h"
#include "inc/log_adapter.h"
#include "inc/log_context.h"

using namespace cc;

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
    return *this;
}

Logger &Logger::operator<<(const char *c) {
    LogContext::adapter().handle(c);
    return *this;
}

Logger &Logger::operator<<(const QString &str) {
    return *this;
}
