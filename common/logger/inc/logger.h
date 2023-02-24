#ifndef CC_LOGGER_H
#define CC_LOGGER_H

class QString;

namespace cc {
    /// 日志级别
    enum class LogLevel;

    /// 日志
    class Logger {
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
