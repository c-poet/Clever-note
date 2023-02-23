#ifndef CC_LOGGER_H
#define CC_LOGGER_H

class QString;

namespace cc {
    /// 日志级别
    enum class LogLevel;

    /// 日志
    class Logger {
    private:
        /// 当前日志的等级
        LogLevel _level;
    public:
        /// 判断当前日志等级是否开启
        /// @return 当前日志等级是否开启
        bool isEnabled();

        /// 获取当前日志等级
        /// @return 当前日志等级
        LogLevel getLevel();

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
