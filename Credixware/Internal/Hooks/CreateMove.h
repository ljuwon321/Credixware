// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef CREATEMOVE_H
#define CREATEMOVE_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef bool(__thiscall* CreateMove_t)(void*, float, CUserCmd*);
CreateMove_t oCreateMove;
unsigned int* oCreateMoveFunc;

bool __fastcall hkCreateMove(void* ecx, void* edx, float sampleTime, CUserCmd* UserCmd) {
	//bool bReturnValue = AntiAim::Tick(UserCmd);;
	bool bReturnValue = true;
	oldViewAngles = UserCmd->viewangles;
	Bunnyhop::Tick(UserCmd);
	//GrenadeHelper::Tick(UserCmd);
	ClantagChanger::Set("Credixware");
	if (UserCmd->buttons & IN_ATTACK) {
		SilentAim::Shoot();
		if (Settings::Rage::bSilentAim) {
			UserCmd->viewangles.x = silentAimViewAngles.x;
			UserCmd->viewangles.y = silentAimViewAngles.y;
			UserCmd->viewangles.z = silentAimViewAngles.z;
			bReturnValue = false;
		}
	}
	CorrectMovement(oldViewAngles, UserCmd, UserCmd->forwardmove, UserCmd->sidemove);
	oCreateMove(ecx, sampleTime, UserCmd);
	return bReturnValue;
}

#endif