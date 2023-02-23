#ifndef CC_LOGGER_LOG_CONSOLE_ADAPTER_H
#define CC_LOGGER_LOG_CONSOLE_ADAPTER_H

#include "log_adapter.h"

namespace cc {
    /// 日志输出适配，输出至控制台
    class LogConsoleAdapter : public LogAdapter {
        void handle(const char *message) override;
    };
}

#endif
