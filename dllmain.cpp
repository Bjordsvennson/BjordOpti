
#include <Windows.h>
#include "vmt.h"
#include "entitylist.h"
#include "engine.h"
#include "client.h"
#include "netvars.h"
#include "createmove.h"
#include "clientmode.h"
#include "globals.h"
#include "offsets.h"
#include "settings.h"

void CreateConsole()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
}

void UnHook()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_END))
		{
			vmt.HookVirtual(clientmode, 21, oCreateMove);
			FreeConsole();
		}
	}
}

DWORD WINAPI ThreadCharter(LPVOID lpParameter)
{
	//CreateConsole();

	entitylist = (EntityList*)vmt.GetInterfaceVersion("client.dll", "VClientEntityList");
	engine =	 (Engine*)vmt.GetInterfaceVersion("engine.dll", "VEngineClient");
	client =	 (Client*)vmt.GetInterfaceVersion("client.dll", "VClient");
	clientmode = **(ClientMode***)((*(DWORD**)client)[10] + 0x5);
	globals =	 **(GlobalVars***)((*(DWORD**)client)[0]  + 0x34);

	netvars.Init();
	offsets.Init();
	settings.Init();

	oCreateMove = (CreateMoveFn)vmt.HookVirtual(clientmode, 21, hkCreateMove);
	
	UnHook();

	FreeLibraryAndExitThread((HMODULE)lpParameter, 0);
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hInstDll, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hInstDll);
		CreateThread(0, 0, ThreadCharter, 0, 0, 0);
		return TRUE;
	}
	
	return FALSE;
}
