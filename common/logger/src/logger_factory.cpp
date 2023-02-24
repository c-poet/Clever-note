#include "inc/logger.h"
#include "inc/log_level.h"
#include "inc/logger_factory.h"

using namespace cc;

/// 初始化日志工厂实例
LoggerFactory LoggerFactory::INSTANCE;

LoggerFactory &LoggerFactory::getInstance() {
    return LoggerFactory::INSTANCE;
}

Logger &LoggerFactory::getAndCheckLogger(LogLevel level) {
    switch (level) {
        case LogLevel::Debug:
            return *(this->debug == nullptr ? (this->debug = new Logger(level)) : this->debug);
        case LogLevel::Info:
            return *(this->info == nullptr ? (this->info = new Logger(level)) : this->info);
        case LogLevel::Warn:
            return *(this->warn == nullptr ? (this->warn = new Logger(level)) : this->warn);
        case LogLevel::Error:
            return *(this->error == nullptr ? (this->error = new Logger(level)) : this->error);
    }
}

Logger &LoggerFactory::getLogger(LogLevel level) {
    return getLogger(level, nullptr, nullptr, -1);
}

Logger &LoggerFactory::getLogger(LogLevel level, const char *file, int line) {
    return getLogger(level, file, nullptr, line);
}

Logger &LoggerFactory::getLogger(LogLevel level, const char *file, const char *func, int line) {
    // todo 20230224 cpoet 临时处理日志输出格式，后期根据配置文件完善
    Logger &logger = LoggerFactory::getInstance().getAndCheckLogger(level);
    logger << "[" << file << ":" << func << ":" << line << "] ";
    return logger;
}
