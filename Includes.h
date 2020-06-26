/* CoristatBase is a free-to-use framework, for your cheat. You are free 
to view, modify, and publish using this base. When publishing or distributing
please give the proper credit to this base*/

/* Discord: !Coristat#8862*/
#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <string>
#include "Memory.h"

/* Dump fresh offsets under here, these offsets are up-to-date as of 2020/06/25 */
#define dwLocalPlayer 0xD3ABEC
#define dwEntityList 0x4D4F25C
#define m_iCrosshairId 0xB3E4
#define m_iHealth 0x100
#define m_iTeamNum 0xF4
#define m_szCustomName 0x303C
#define m_bIsDefusing 0x3930
#define m_iFOV 0x31E4
#define m_bInReload 0x32A5
