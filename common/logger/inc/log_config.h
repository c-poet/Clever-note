#ifndef CC_LOGGER_LOG_CONFIG_H
#define CC_LOGGER_LOG_CONFIG_H

#include "log_level.h"

namespace cc {
    /// 日志输出适配器
    class LogAdapter;

    /// 日志配置
    class LogConfig {
    private:
        /// 日志等级,默认Info
        LogLevel _level = LogLevel::Info;
        /// 日志适配器
        LogAdapter *_adapter = nullptr;
    protected:
        /// 获取默认的日志输出适配器
        /// 默认日志输出适配器
        LogAdapter *getDefaultAdapter();

    public:
        /// 日志配置析构
        virtual ~LogConfig();

        /// 获取日志等级
        /// @return 日志等级
        LogLevel getLevel() const;

        /// 设置日志等级
        /// @param level 日志等级
        void setLevel(LogLevel level);

        /// 获取当前日志适配器
        /// @return 日志适配器
        LogAdapter *getAdapter();

        /// 设置日志适配器
        /// @param adapter 日志适配器
        void setAdapter(LogAdapter *adapter);
    };
}

#endif
