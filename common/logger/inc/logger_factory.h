#ifndef CC_LOGGER_FACTORY_H
#define CC_LOGGER_FACTORY_H

namespace cc {
    /// 日志级别
    enum class LogLevel;

    /// 日志类
    class Logger;

    /// 日志对象工厂
    class LoggerFactory {
    private:
        /// 日志对象工厂实例，全局唯一
        static LoggerFactory INSTANCE;

        /// debug日志实例
        Logger *_debug = nullptr;
        /// info日志实例
        Logger *_info = nullptr;
        /// warn日志实例
        Logger *_warn = nullptr;
        /// error日志实例
        Logger *_error = nullptr;

        /// 校验及获取日志实例
        /// @param level 日志等级
        /// @return 日志对象实例
        Logger &getAndCheckLogger(LogLevel level);

    public:
        /// 析构函数
        virtual ~LoggerFactory();

        /// 获取日志工厂实例
        /// @return 日志工厂实例
        static LoggerFactory &getInstance();

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
