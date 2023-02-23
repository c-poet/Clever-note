#include "inc/logger.h"
#include "inc/logger_factory.h"

using namespace cc;

#define LOG_LEVEL_LENGTH 4

/// 日志工厂实例
LoggerFactory factory;

Logger *LoggerFactory::checkAndGetLogger(LogLevel level) {
    Logger **p = this->loggerArr;
    if (p == nullptr) {
        p = new Logger *[LOG_LEVEL_LENGTH];
        for (int i = 0; i < LOG_LEVEL_LENGTH; ++i) {
            *(p + i) = nullptr;
        }
        this->loggerArr = p;
    }
    int i = (int) level;
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
        // 删除所有日志对象
        int i = 0;
        Logger **p = this->loggerArr;
        while (i < LOG_LEVEL_LENGTH) {
            if (*(p + i) != nullptr) {
                delete *(p + i);
                *(p + i) = nullptr;
            }
            ++i;
        }
        delete this->loggerArr;
        this->loggerArr = nullptr;
    }
}
