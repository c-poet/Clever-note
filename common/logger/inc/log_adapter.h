#ifndef CC_LOGGER_LOG_ADAPTER_H
#define CC_LOGGER_LOG_ADAPTER_H

namespace cc {
    /// 日志输出适配
    class LogAdapter {
    public:
        /// 析构函数
        virtual ~LogAdapter() = default;

        /// 处理日志消息
        /// @param message 日志消息
        virtual void handle(const char *message) = 0;
    };
}

#endif
