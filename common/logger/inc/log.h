#ifndef CC_LOGGER_LOG_H
#define CC_LOGGER_LOG_H

#include "logger.h"

namespace cc {
    // 对外日志类
    class Log {
    public:
        /// 判断是否开启debug日志
        /// @return 是否开启debug日志
        inline static bool isDebugEnabled() {
            return debug().isEnabled();
        };

        /// 输出debug日志
        /// @return 日志实例
        static Logger &debug();

        /// 判断是否开启info日志
        /// @return 是否开启info日志
        inline static bool isInfoEnabled() {
            return info().isEnabled();
        };

        /// 输出info日志
        /// @return 日志实例
        static Logger &info();

        /// 判断是否开启警告日志
        /// @return 是否开启警告日志
        inline static bool isWarnEnabled() {
            return warn().isEnabled();
        }

        /// 输出警告日志
        /// @return 日志实例
        static Logger &warn();

        /// 判断是否开启错误日志
        /// @return 是否开启错误日志
        inline static bool isErrorEnabled() {
            return error().isEnabled();
        }

        /// 输出错误日志
        /// @return 日志实例
        static Logger &error();
    };
}

#endif
