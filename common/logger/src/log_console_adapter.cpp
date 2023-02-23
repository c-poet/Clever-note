#include "iostream"
#include "inc/log_console_adapter.h"

using namespace cc;

void LogConsoleAdapter::handle(const char *message) {
    std::cout << message;
}
