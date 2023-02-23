#ifndef CC_LOGGER_LOG_NOP_ADAPTER_H
#define CC_LOGGER_LOG_NOP_ADAPTER_H

#include "log_adapter.h"

namespace cc {
    /// 日志输出适配，无操作
    class LogNopAdapter : public LogAdapter {
        void handle(const char *message) override {
        }
    };
}

#endif
