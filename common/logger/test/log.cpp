#include "common/logger/inc/log.h"

using namespace cc;

/// 日志测试
void logTest() {
    Log::debug() << "Hello World";
}

int main(int argc, char *argv[]) {
    logTest();
    return 0;
}