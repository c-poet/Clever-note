#include "inc/log.h"
#include "inc/logger_factory.h"

using namespace cc;

Logger &getLogger(LogLevel level) {
    return LoggerFactory::getInstance().getLogger(level);
}

Logger &Log::debug() {
    return getLogger(LogLevel::Debug);
}

Logger &Log::info() {
    return getLogger(LogLevel::Info);
}

Logger &Log::warn() {
    return getLogger(LogLevel::Wain);
}

Logger &Log::error() {
    return getLogger(LogLevel::Error);
}
