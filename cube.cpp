#include "pch.h"
#include "cube.h"
#include <cstdint>
#include <iostream>

namespace cube {
	GameController* GetGameController() {
		auto imageBase = (char*)GetModuleHandleA(NULL);
		GameController* gc = *(GameController**)(imageBase + 0x36B1C8);
		return gc;
	}
};