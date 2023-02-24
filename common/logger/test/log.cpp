#include "common/logger/inc/log.h"
#include "common/logger/inc/log_config.h"
#include "common/logger/inc/log_context.h"
#include "common/logger/inc/log_console_adapter.h"

using namespace cc;

#define bebug() (Log::debug() << __FILE__ << __LINE__ << __FUNCTION__)

/// 日志测试
void logTest() {
    LogContext::getConfig().setAdapter(new LogConsoleAdapter());
    Log::debug() << "Hello World" << "\n";
    Log::debug() << "Hello World" << "\n";
    Log::debug() << "你好，世界！！！" << "\n";
}

void logTestInfo() {
    LogContext::getConfig().setAdapter(new LogConsoleAdapter());
    bebug() << "\nHello World" << "\n";
    bebug();
    bebug();
    bebug();
}

int main(int argc, char *argv[]) {
    logTestInfo();
    return 0;
}