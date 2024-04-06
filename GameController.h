#pragma once
#include "CharacterStyleWidget.h"
namespace cube {
	struct GameController
	{
		char unknown_00[0x2E4];
		char world[0x80029C]; // World Struct containing 0x800000 alocated space for chunks
		char uknown_800B5B[0x3E8]; // i think it's the right adress, but not sure
		cube::CharacterStyleWidget* character_style_widget_ptr;
	};
};

