// Copyright (c) 2022 Wanggf(CPoet)
// Project: Clever-note-desktop
// Author: CPoet
// Date: 2022/10/26

#include "inc/plugin.h"
#include "inc/plugin_function.h"
#include "common/logger/inc/log.h"
#include "inc/plugin_func_symbol.h"
#include "common/core/inc/exception.h"

using namespace cc;

Plugin::Plugin(const QString &file) {
    this->libFile = file;
    this->library = nullptr;
}


Plugin::Plugin(QLibrary *lib) {
    this->library = lib;
    this->libFile = lib->fileName();
}

Plugin::~Plugin() {
    if (this->library != nullptr && this->library->isLoaded()) {
        this->library->unload();
    }
    delete this->library;
}

void Plugin::load() noexcept(false) {
    if (this->library == nullptr) {
        this->library = new QLibrary(this->libFile);
    }
    if (!this->library->isLoaded()) {
        if (!this->library->load()) {
            warn() << "插件加载失败：" << this->library->errorString();
            throw Exception(this->library->errorString());
        }
    }
    auto pluginMain = (PluginMain) this->library->resolve(SYMBOL_PLUGIN_MAIN);
    if (!pluginMain) {
        throw Exception("插件加载找不到入口方法: " + this->library->fileName());
    }
    PluginInfo *pluginInfo = pluginMain();
    if (pluginInfo == nullptr) {
        throw Exception("插件返回的元信息为空: " + this->library->fileName());
    }
    debug() << pluginInfo->id;
    debug() << pluginInfo->name;
    debug() << pluginInfo->author;
    debug() << pluginInfo->description;
}

void Plugin::reload() noexcept(false) {
    if (this->library != nullptr) {
        if (this->library->isLoaded()) {
            this->library->unload();
        }
        delete this->library;
        this->library = nullptr;
    }
    this->load();
}
