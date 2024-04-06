#include "pch.h"
#include "cube_funcs.h"
#include <Windows.h>
#include <iostream>

// Singleton pattern methods.
cube_funcs* cube_funcs::_instance = nullptr;
cube_funcs* cube_funcs::instance() {
	if (_instance == nullptr) {
		_instance = new cube_funcs();
	}
	return _instance;
}

cube_funcs::cube_funcs() {
	ImageBase = (uint32_t)GetModuleHandleA(NULL);
	node_interact = (gamecontroller_plasma_node_interact)(ImageBase + 0x7B600);
}
/*
bool cube_funcs::Hook(void* toHook, void* ourFunct, int len) {
	if (len < 5) {
		return false;
	}

	DWORD curProtection;
	VirtualProtect(toHook, len, PAGE_EXECUTE_READWRITE, &curProtection);

	memset(toHook, 0x90, len);

	DWORD relativeAddress = ((DWORD)ourFunct - (DWORD)toHook) - 5;

	*(BYTE*)toHook = 0xE9;
	*(DWORD*)((DWORD)toHook + 1) = relativeAddress;

	DWORD temp;
	VirtualProtect(toHook, len, curProtection, &temp);

	return true;
}*/