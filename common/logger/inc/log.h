#ifndef CC_LOGGER_LOG_H
#define CC_LOGGER_LOG_H

#include "logger.h"
#include "log_level.h"
#include "logger_factory.h"

#ifndef __FILE__
#define __FILE__ ""
#endif

#ifndef __FUNCTION__
#define __FUNCTION__ ""
#endif

#ifndef __LINE__
#define __LINE__ -1
#endif

namespace cc {
/// debug日志
#define debug() (cc::LoggerFactory::getLogger(cc::LogLevel::Debug, __FILE__, __FUNCTION__ , __LINE__))

/// info日志
#define info() (cc::LoggerFactory::getLogger(cc::LogLevel::Info, __FILE__, __FUNCTION__ , __LINE__))

/// warn警告日志
#define warn() (cc::LoggerFactory::getLogger(cc::LogLevel::Warn, __FILE__, __FUNCTION__ , __LINE__))

/// error错误日志
#define error() (cc::LoggerFactory::getLogger(cc::LogLevel::Error, __FILE__, __FUNCTION__ , __LINE__))
}
#endif
