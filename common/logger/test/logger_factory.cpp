#include "common/logger/inc/logger.h"
#include "common/logger/inc/logger_factory.h"

using namespace cc;

/// 日志工厂测试
void logTest() {
    LoggerFactory factory = LoggerFactory::getInstance();
    Logger debug = factory.getLogger(LogLevel::Debug);
    debug << "Hello World" << "12345678";
    Logger error = factory.getLogger(LogLevel::Error);
    error << "Hello World" << "12345678";
    error << "9999999";
}

int main(int argc, char *argv[]) {
    logTest();
    return 0;
}