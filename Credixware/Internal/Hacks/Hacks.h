// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef HACKS_H
#define HACKS_H

#include "Menu.h"
#include "ESP.h"

namespace Hacks {
	void Init() {
		Menu::Init();
		ESP::Init();
	}
}

namespace Settings {
	namespace Misc {
		bool bThirdperson = true;
		float ThirdpersonDistance = 5.0f;
		short ThirdpersonOffKey = VK_MENU;
	}
}

float ViewangleX;
float ViewangleY;
float ViewangleZ;

#endif