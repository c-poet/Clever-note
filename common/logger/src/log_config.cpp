#include "inc/log_config.h"
#include "inc/log_adapter.h"
#include "inc/log_nop_adapter.h"

using namespace cc;

LogConfig::~LogConfig() {
    delete this->_adapter;
    this->_adapter = nullptr;
}

LogAdapter *LogConfig::getDefaultAdapter() {
    return new LogNopAdapter();
}

LogLevel LogConfig::getLevel() const {
    return this->_level;
}

void LogConfig::setLevel(LogLevel level) {
    this->_level = level;
}

LogAdapter *LogConfig::getAdapter() {
    return this->_adapter == nullptr
           ? (this->_adapter = this->getDefaultAdapter())
           : this->_adapter;
}

void LogConfig::setAdapter(LogAdapter *adapter) {
    LogAdapter *old = this->_adapter;
    this->_adapter = adapter;
    delete old;
}
