/* CoristatBase is a free-to-use framework, for your cheat. You are free
to view, modify, and publish using this base. When publishing or distributing
please give the proper credit to this base*/

/* Discord: !Coristat#8862*/
#include "CoristatIncludes.h"

class CoristatMemory
{
public:
	HANDLE pHandle;

	/* Functions for getting process, module, localplayer, defined in CoristatMemory.cpp*/
	DWORD getProcessId(const char* process);
	DWORD getLocalPlayer(DWORD gameModule, DWORD LocalPlayerOffset);
	uintptr_t getModuleBaseAddr(DWORD, const char*);

	/* Reading Entity functions, defined in CoristatEntity.cpp */
	DWORD getGlowObjectManager(DWORD gameModule, DWORD glowObjectManagerOffset);
	char* getLocalPlayerName(DWORD LocalPlayer, DWORD nameOffset);
	int getGlowIndex(DWORD LocalPlayer, int glowIndexOffset);
	int getFOV(DWORD LocalPlayer, int fovOffset);
	bool getIsDefusing(DWORD LocalPlayer, DWORD defusingOffset);
	bool getIsSpotted(DWORD LocalPlayer, DWORD isSpottedOffset);
	bool isLocalPlayerAlive(DWORD LocalPlayer, int healthOffset);
	bool isPlayerInCrosshair(DWORD LocalPlayer, int crosshairIdOffset);
	bool isPlayerReloading(DWORD LocalPlayer, DWORD reloadingOffset);
	int getLocalPlayerHealth(DWORD LocalPlayer, int healthOffset);
	int getLocalPlayerTeam(DWORD LocalPlayer, int teamOffset);
	int getCrosshairId(DWORD LocalPlayer, int crosshairIdOffset);

	/* Writing Entity functions, defined in CoristatEntity.cpp */
	void writeFOV(DWORD LocalPlayer, int fovOffset, int fovValue);
	void writeSpotted(DWORD LocalPlayer, DWORD isSpottedOffset, bool spottedValue);
	void shootMOUSEEVENT();

	/* Template for easy use of ReadProcessMemory */
	template <class buffer> buffer ReadMemory(DWORD address)
	{
		buffer value;
		ReadProcessMemory(pHandle, (LPBYTE*)address, &value, sizeof(value), NULL);
		return value;
	}
	/* Template for easy use of WriteProcessMemory */
	template <class buffer> buffer WriteMemory(DWORD address, buffer value)
	{
		WriteProcessMemory(pHandle, (LPBYTE*)address, &value, sizeof(value), NULL);
		return 0;
	}

};