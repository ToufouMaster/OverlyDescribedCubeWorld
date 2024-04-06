#pragma once

#include <stdint.h>

namespace cube {
	struct CharacterStyleWidget
	{
		char* vfptr;
		char* d3d9engine_ptr;
		char unknown_08[0x154];
		void* gc_ptr;
		char unknown_015C[0x24];
		uint32_t race;
		uint32_t class_id;
		uint32_t gender;
		uint32_t face;
		uint32_t haircut;
		uint32_t hair_color;
		uint32_t hair_color_selection_uv;
		char* unknown_1A8;
	};
};
