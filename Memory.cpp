/* CoristatBase is a free-to-use framework, for your cheat. You are free
to view, modify, and publish using this base. When publishing or distributing
please give the proper credit to this base*/

/* Discord: !Coristat#8862*/
#include "Includes.h"

DWORD CoristatMemory::getProcessId(const char* processId)
{
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(pEntry);
	DWORD procId = 0;
	HANDLE hProcessId = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	do
	{
		if (!strcmp(pEntry.szExeFile, processId))
		{
			procId = pEntry.th32ProcessID;
			CloseHandle(hProcessId);
			pHandle = OpenProcess(PROCESS_ALL_ACCESS, false, procId);
		}

	} while (Process32Next(hProcessId, &pEntry));
	return procId;
}

uintptr_t CoristatMemory::getModuleBaseAddr(DWORD procId, const char* modName)
{
	MODULEENTRY32 mEntry;
	mEntry.dwSize = sizeof(mEntry);
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);

	do
	{
		if (!strcmp(mEntry.szModule, modName))
		{
			CloseHandle(hModule);
			return (DWORD)mEntry.hModule;
		}
	} while (Module32Next(hModule, &mEntry));
	return 0;
}

DWORD CoristatMemory::getLocalPlayer(DWORD gameModule, DWORD LocalPlayerOffset)
{
	return CoristatMemory::ReadMemory<DWORD>(gameModule + LocalPlayerOffset);
}
