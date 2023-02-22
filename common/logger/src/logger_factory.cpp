#include "inc/logger.h"
#include "inc/logger_factory.h"

using namespace cc;

#define LOG_LEVEL_LENGTH 4

/// 日志工厂实例
LoggerFactory factory;

Logger *LoggerFactory::checkAndGetLogger(LogLevel level) {
    if (this->loggerArr == nullptr) {
        this->loggerArr = new Logger *[LOG_LEVEL_LENGTH];
    }
    int i = (int) level;
    Logger **p = this->loggerArr;
    if (*(p + i) == nullptr) {
        *(p + i) = new Logger();
    }
    return *(p + i);
}

LoggerFactory LoggerFactory::getInstance() {
    return factory;
}

Logger &LoggerFactory::getLogger(LogLevel level) {
    return *checkAndGetLogger(level);
}

LoggerFactory::~LoggerFactory() {
    if (this->loggerArr != nullptr) {
        delete this->loggerArr;
        this->loggerArr = nullptr;
    }
}
