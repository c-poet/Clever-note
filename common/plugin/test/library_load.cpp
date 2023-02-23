// Copyright (c) 2022 Wanggf(CPoet)
// Project: Clever-note-desktop
// Author: CPoet
// Date: 2022/10/26

#include <QDir>
#include <QList>
#include <QLibrary>
#include "common/core/inc/core.h"
#include "common/logger/inc/log.h"

#define PLUGIN_PATH "plugin"
#define PLUGIN_INIT_FUNC "init"
#define PLUGIN_START_FUNC "start"

typedef int (*Handle)(int argc, char *args[]);

using namespace cc;

/// @brief 动态加载库测试
/// @author CPoet
int main(int argc, char *argv[]) {
    auto *libraries = new QList<QLibrary *>();
    auto *dir = new QDir(getApplicationFilePath(PLUGIN_PATH));
    if (dir->exists()) {
        Log::debug() << "扫描插件目录：" << dir->path();
        QStringList list = dir->entryList(QStringList("*.so"), QDir::Filter::Files);
        if (!list.isEmpty()) {
            Log::debug() << "遍历插件并调用约定方法，插件数量：" << list.size();
            for (const auto &item: list) {
                QString itemPath = getFitFilePath(dir->path(), item);
                Log::debug() << "加载插件：" << itemPath;
                auto *lib = new QLibrary(itemPath);
                libraries->append(lib);
                if (lib->load()) {
                    Log::debug() << "加载插件：" << item << "成功";
                    QFunctionPointer initFunc = lib->resolve(PLUGIN_INIT_FUNC);
                    if (initFunc) {
                        Log::debug() << "调用init方法返回" << ((Handle) initFunc)(10, nullptr);
                    }
                    QFunctionPointer startFunc = lib->resolve(PLUGIN_START_FUNC);
                    if (startFunc) {
                        Log::debug() << "调用start方法返回" << ((Handle) startFunc)(1000, nullptr);
                    }
                }
            }
        }
    } else {
        Log::debug() << "插件目录不存在";
    }

    if (!libraries->isEmpty()) {
        int len = libraries->size();
        for (int i = 0; i < len; ++i) {
            QLibrary *lib = (*libraries)[i];
            if (lib->isLoaded()) {
                Log::debug() << "关闭插件：" << lib->fileName() << ":" << lib->unload();
            }
            delete lib;
        }
    }
    delete dir;
    delete libraries;
    return 0;
}
