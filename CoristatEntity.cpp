/* CoristatBase is a free-to-use framework, for your cheat. You are free
to view, modify, and publish using this base. When publishing or distributing
please give the proper credit to this base*/

/* Discord: !Coristat#8862*/
#include "CoristatIncludes.h"

int CoristatMemory::getCrosshairId(DWORD LocalPlayer, int crosshairIdOffset)
{	
	return CoristatMemory::ReadMemory<int>(LocalPlayer + crosshairIdOffset);
}

int CoristatMemory::getLocalPlayerHealth(DWORD LocalPlayer, int healthOffset)
{
	return CoristatMemory::ReadMemory<int>(LocalPlayer + healthOffset);
}

int CoristatMemory::getGlowIndex(DWORD LocalPlayer, int glowIndexOffset)
{
	return CoristatMemory::ReadMemory<int>(LocalPlayer + glowIndexOffset);
}

bool CoristatMemory::isLocalPlayerAlive(DWORD LocalPlayer, int healthOffset)
{	
	int health = CoristatMemory::ReadMemory<int>(LocalPlayer + healthOffset);

	if (health > 0 && health < 101)
		return true;
	else
		return false;
}

DWORD CoristatMemory::getGlowObjectManager(DWORD gameModule, DWORD glowObjectManagerOffset)
{
	return CoristatMemory::ReadMemory<DWORD>(gameModule + glowObjectManagerOffset);
}

bool CoristatMemory::isPlayerInCrosshair(DWORD LocalPlayer, int crosshairIdOffset)
{	
	int crosshairId = CoristatMemory::ReadMemory<int>(LocalPlayer + crosshairIdOffset);

	if (crosshairId != 0 && crosshairId < 64)
		return true;
	else
		return false;
}

int CoristatMemory::getLocalPlayerTeam(DWORD LocalPlayer, int teamOffset)
{
	return CoristatMemory::ReadMemory<int>(LocalPlayer + teamOffset);
}

char* CoristatMemory::getLocalPlayerName(DWORD LocalPlayer, DWORD nameOffset)
{
	return CoristatMemory::ReadMemory<char*>(LocalPlayer + nameOffset);
}

bool CoristatMemory::getIsSpotted(DWORD LocalPlayer, DWORD isSpottedOffset)
{
	return CoristatMemory::ReadMemory<bool>(LocalPlayer + isSpottedOffset);
}

bool CoristatMemory::getIsDefusing(DWORD LocalPlayer, DWORD defusingOffset)
{
	return CoristatMemory::ReadMemory<bool>(LocalPlayer + defusingOffset);
}

int CoristatMemory::getFOV(DWORD LocalPlayer, int fovOffset)
{
	return CoristatMemory::ReadMemory<int>(LocalPlayer + fovOffset);
}

bool CoristatMemory::isPlayerReloading(DWORD LocalPlayer, DWORD reloadingOffset)
{
	return CoristatMemory::ReadMemory<bool>(LocalPlayer + reloadingOffset);
}

void CoristatMemory::writeFOV(DWORD LocalPlayer, int fovOffset, int fovValue)
{
	CoristatMemory::WriteMemory<int>(LocalPlayer + fovOffset, fovValue);
}

void CoristatMemory::writeSpotted(DWORD LocalPlayer, DWORD isSpottedOffset, bool spottedValue)
{
	CoristatMemory::WriteMemory<bool>(LocalPlayer + isSpottedOffset, spottedValue);
}

void shootMOUSEEVENT()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
	Sleep(10);
}