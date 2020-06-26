/* How to use CoristatBase: Step 1: Find CoristatMain.cpp (this file), your code will
										be excecuted here
								Step 2: Dump fresh offsets into CoristatIncludes.h, there
										should be some example ones for you already
								Step 3: Create an object of the CoristatMemory Class
								Step 4: Look under the int main function for everything
								        that CoristatBase has. Code away!            */
#include "CoristatIncludes.h"

/* This file, CoristatMain.cpp contains the main function, code will be excecuted here */
int main()
{	
	
	return 0;
}

/* What does CoristatBase have?
	
	---------------------------Functions to get procId, get localPlayer, get Module--------------------------------------------------

	DWORD getProcessId(const char* process);
	DWORD getLocalPlayer(DWORD gameModule, DWORD LocalPlayerOffset);
	uintptr_t getModuleBaseAddr(DWORD, const char*);

	--------------------------Reading Entity functions that help with literally anything you need------------------------------------

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

	-------------------------Three Writing Entity functions as examples-----------------------------------------------------------------

	void writeFOV(DWORD LocalPlayer, int fovOffset, int fovValue);
	void writeSpotted(DWORD LocalPlayer, DWORD isSpottedOffset, bool spottedValue);
	void shoot();
	-------------------------Templates for WPM and RPM--------------------------------------------------------------------------------

	- WriteProcessMemory easy-to-use template
	- ReadProcessMemory easy-to-use template

*/