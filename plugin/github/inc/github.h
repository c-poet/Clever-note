#ifndef CP_GITHUB_H
#define CP_GITHUB_H

#include "core.h"
#include "common/plugin/inc/plugin_meta.h"

extern "C" {
/// @brief 入口函数，获取插件信息
/// @return 插件信息
PUBLIC_API PluginInfo *pluginMain();
}
#endif
