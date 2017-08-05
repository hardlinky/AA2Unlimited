#pragma once
#include "defs.h"
#include <string>
#include "Script/ScriptLua.h"

extern class Config
{
public:;
	int screenshotFormat;
	char sPoserHotKeys[16];
	int legacyMode;
	bool bSaveFileBackup;
	bool bSaveFileAutoRemove;
	int savedFileUsage;
	int savedEyeTextureUsage;
	bool bHAiOnNoPromptH;
	bool bUseDialoguePoser;
	bool bUseClothesPoser;
	bool bEnableHPosButtonReorder;
	bool bEnableFacecam;
	bool bUseShadowing;
	bool bUseHAi;
	bool bUsePPeX;
	bool bUsePP2;
	bool bTriggers;
	int PP2Cache;
	int PP2AudioCache;

	auto operator[](const char *name) const {
		LUA_SCOPE;
		return g_Lua[LUA_CONFIG_TABLE][name].get();
	}

	static inline void bindLua() {
		LUA_SCOPE;
#define LUA_CLASS Config
			LUA_BIND(screenshotFormat)
			LUA_BINDSTR(sPoserHotKeys)
			LUA_BIND(bSaveFileBackup)
			LUA_BIND(bSaveFileAutoRemove)
			LUA_BIND(savedFileUsage)
			LUA_BIND(savedEyeTextureUsage)
			LUA_BIND(bHAiOnNoPromptH)
			LUA_BIND(bUseDialoguePoser)
			LUA_BIND(bUseClothesPoser)
			LUA_BIND(bEnableHPosButtonReorder)
			LUA_BIND(bEnableFacecam)
			LUA_BIND(bUseShadowing)
			LUA_BIND(bUseHAi)
			LUA_BIND(bUsePPeX)
			LUA_BIND(bUsePP2)
			LUA_BIND(bTriggers)
			LUA_BIND(PP2Cache)
			LUA_BIND(PP2AudioCache)
			LUA_BIND(legacyMode)
#undef LUA_CLASS
		g_Lua[LUA_BINDING_TABLE]["Config"] = &g_Config;
	}
} g_Config;


