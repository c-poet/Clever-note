#include <QString>
#include <iostream>
#include "inc/log_console_adapter.h"

using namespace cc;

void LogConsoleAdapter::handle(const QString &message) {
    std::cout << message.toStdString();
}
