#ifndef CC_LOGGER_LEVEL_H
#define CC_LOGGER_LEVEL_H

namespace cc {
     /// 日志级别
    enum class LogLevel {
        /// Debug级别
        Debug,

        /// Info级别
        Info,

        /// Warn警告级别
        Warn,

        /// Error错误级别
        Error
    };
}

#endif
