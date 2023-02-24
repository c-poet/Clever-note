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

        /// 输出日志
        /// @param b 日志内容
        /// @return 日志对象实例
        Logger &operator<<(bool b);

        /// 输出日志
        /// @param i 日志内容
        /// @return 日志对象实例
        Logger &operator<<(int i);

        /// 输出日志
        /// @param i 日志内容
        /// @return 日志对象实例
        Logger &operator<<(unsigned int i);

        /// 输出日志
        /// @param l 日志内容
        /// @return 日志对象实例
        Logger &operator<<(long l);

        /// 输出日志
        /// @param l 日志内容
        /// @return 日志对象实例
        Logger &operator<<(unsigned long l);

        /// 输出日志
        /// @param f 日志内容
        /// @return 日志对象实例
        Logger &operator<<(float f);

        /// 输出日志
        /// @param d 日志内容
        /// @return 日志对象实例
        Logger &operator<<(double d);

        /// 输出日志
        /// @param c 日志内容
        /// @return 日志对象实例
        Logger &operator<<(char c);

        /// 输出日志
        /// @param c 日志内容
        /// @return 日志对象实例
        Logger &operator<<(unsigned char c);

        /// 输出日志
        /// @param c 日志内容
        /// @return 日志对象实例
        Logger &operator<<(const char *c);

        /// 输出日志
        /// @param str 日志内容
        /// @return 日志对象实例
        Logger &operator<<(const QString &str);
    };
}

#endif
