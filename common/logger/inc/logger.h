#ifndef CC_LOGGER_H
#define CC_LOGGER_H

class QString;

namespace cc {
    /// 日志级别
    enum class LogLevel;

    /// 日志
    class Logger {
    private:
        LogLevel _level;
    public:
        /// 构造器
        /// @param level 日志级别
        explicit Logger(LogLevel level);

        /// 获取当前日志对象的日志级别
        /// @return 日志级别
        LogLevel level();

        Logger &operator<<(bool b);

        Logger &operator<<(int i);

        Logger &operator<<(long l);

        Logger &operator<<(float f);

        Logger &operator<<(double d);

        Logger &operator<<(char c);

        Logger &operator<<(const char *c);

        Logger &operator<<(const QString &str);
    };
}

#endif
