#ifndef CC_LOGGER_LOG_H
#define CC_LOGGER_LOG_H

#include "logger.h"

namespace cc {
    // 对外日志类
    class Log {
    public:
        inline static bool isDebugEnabled() {
            return debug().isEnabled();
        };

        static Logger &debug();

        inline static bool isInfoEnabled() {
            return info().isEnabled();
        };

        static Logger &info();

        inline static bool isWarnEnabled() {
            return warn().isEnabled();
        }

        static Logger &warn();

        inline static bool isErrorEnabled() {
            return error().isEnabled();
        }

        static Logger &error();
    };
}

#endif
