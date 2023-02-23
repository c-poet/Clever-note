#include "inc/log_config.h"
#include "inc/log_context.h"

using namespace cc;

LogConfig LogContext::_config;

LogLevel LogContext::level() {
    return _config.getLevel();
}

LogAdapter &LogContext::adapter() {
    return *_config.getAdapter();
}

LogConfig &LogContext::getConfig() {
    return _config;
}

void LogContext::setConfig(const LogConfig &config) {
    _config = config;
}
