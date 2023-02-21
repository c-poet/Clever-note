// Copyright (c) 2022 Wanggf(CPoet)
// Project: Clever-note-desktop
// Author: CPoet
// Date: 2022/10/26

#ifndef CC_PLUGIN_FUNCTION_H
#define CC_PLUGIN_FUNCTION_H

#include "plugin_meta.h"
#include "plugin_context.h"

/// @brief 插件入口方法，获取插件信息
/// @details 所有插件有且仅有一个该类型的函数
typedef PluginInfo *(*PluginMain)();

#endif
