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
        /// 日志对象指针
        Logger **loggerArr = nullptr;

        /// 校验日志实例是否已存在，不存在则实例化
        /// @param level 日志等级
        /// @return 日志对象实例
        Logger *checkAndGetLogger(LogLevel level);

    public:
        virtual ~LoggerFactory();

        /// 获取默认的日志工厂实例
        /// @return 日志工厂实例，全局单例
        static LoggerFactory getInstance();

        /// 获取日志对象实例
        /// @param level 日志等级
        /// @return 日志对象实例
        Logger &getLogger(LogLevel level);
    };
}

#endif
