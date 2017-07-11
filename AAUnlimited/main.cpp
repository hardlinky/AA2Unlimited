#include <Windows.h>
#include "Files/Logger.h"
#include "Files/Config.h"
#include "General/ModuleInfo.h"
#include "MemMods/Hook.h"
#include "Script/ScriptLua.h"
#include "config.h"

#include <time.h>

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
	)
{ 
	if (fdwReason == DLL_PROCESS_ATTACH) {
		srand(time(NULL));
		//MessageBox(NULL, L"hi", L"hi", 0);
		//change calls in code to ours
		General::DllInst = hinstDLL;
		if (!General::Initialize()) {
			return FALSE;
		}
		g_Logger.Initialize(General::BuildAAUPath(LOGGER_FILE_PATH).c_str(), Logger::Priority::SPAM);
		g_L = LuaNewState();
		g_Config = Config(g_L);
		LuaRunScript(General::BuildAAUPath(LUA_FILE_PATH));
		InitializeHooks();
		return TRUE;
	}
}