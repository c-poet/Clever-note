// Copyright (c) 2022 Wanggf(CPoet)
// Project: Clever-note-desktop
// Author: CPoet
// Date: 2022/10/26

#include "common/core/inc/core.h"
#include "common/logger/inc/log.h"
#include "common/core/inc/exception.h"
#include "common/plugin/inc/plugin_factory.h"

using namespace cc;

/// @brief 插件加载测试
int main(int argc, char *argv[]) {
#ifdef Q_OS_WINDOWS
    QString dllFile = getApplicationFilePath("plugin/plugin-github.dll");
#else
    QString dllFile = getApplicationFilePath("plugin/plugin-github.so");
#endif
    try {
        auto plugin = PluginFactory::load(dllFile);
        debug() << "插件加载成功";
        delete plugin;
    } catch (Exception &e) {
        debug() << "插件加载失败：" << e.getMessage();
    }
}
