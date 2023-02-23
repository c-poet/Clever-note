#ifndef CC_LOGGER_LOG_CONTEXT_H
#define CC_LOGGER_LOG_CONTEXT_H

namespace cc {
    /// 日志级别
    enum class LogLevel;

    /// 日志配置
    class LogConfig;

    /// 日志适配器
    class LogAdapter;

    /// 日志上下文
    class LogContext {
    private:
        /// 日志配置
        static LogConfig _config;
    public:
        /// 获取当前日志输出等级
        /// @return 日志输出等级
        static LogLevel level();

        /// 获取当前日志输出适配器
        /// @return 日志输出适配器
        static LogAdapter &adapter();

        /// 获取当前日志配置
        /// @return 返回日志配置
        static LogConfig &getConfig();

        /// 设置当前日志配置
        /// @param config 日志配置
        static void setConfig(const LogConfig &config);
    };
}

#endif
