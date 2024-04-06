#pragma once
#include <cstdint>
#include "Cube.h"


// This class is a singleton that holds all of the function-pointers and their typedefs, auto-image-rebased on init
class cube_funcs
{
	// Typedefs.
	typedef void(__thiscall* gamecontroller_plasma_node_interact)(cube::GameController*, uint32_t mouse_button);

	// Singleton pattern start
	public:
		static cube_funcs* instance();

	public:
		cube_funcs(cube_funcs const&) = delete;
		void operator=(cube_funcs const&) = delete;

	private:
		static cube_funcs* _instance;
		cube_funcs();
		//bool Hook(void* toHook, void* ourFunct, int len);
		// Singleton pattern end

	public:
		uint32_t ImageBase;
		gamecontroller_plasma_node_interact	node_interact;
};