#ifndef CC_LOGGER_FACTORY_H
#define CC_LOGGER_FACTORY_H

namespace cc {
    /// 日志级别
    enum class LogLevel;

    /// 日志类
    class Logger;

    /// 日志对象工厂
    class LoggerFactory {
    public:
        /// 获取日志对象实例
        /// @param level 日志等级
        /// @return 日志对象实例
        static Logger &getLogger(LogLevel level);

        /// 获取日志对象实例
        /// @param level 日志等级
        /// @param file 发生日志的文件
        /// @param line 发生日志的行数
        /// @return 日志对象实例
        static Logger &getLogger(LogLevel level, const char *file, int line);

        /// 获取日志对象实例
        /// @param level 日志等级
        /// @param file 发生日志的文件
        /// @param func 发生日志的函数
        /// @param line 发生日志的行数
        /// @return 日志对象实例
        static Logger &getLogger(LogLevel level, const char *file, const char *func, int line);
    };
}

#endif
