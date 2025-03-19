// dllmain.cpp : Définit le point d'entrée de l'application DLL.#pragma once
#include <map>
#include <windows.h>
#include <string>

#define PUSH_ALL __asm {\
__asm push eax          \
__asm push ebx          \
__asm push ecx          \
__asm push edx          \
__asm push esi          \
__asm push edi          \
__asm push ebp          \
__asm push esp          \
}
#define POP_ALL __asm {\
__asm pop esp          \
__asm pop ebp          \
__asm pop edi          \
__asm pop esi          \
__asm pop edx          \
__asm pop ecx          \
__asm pop ebx          \
__asm pop eax          \
}

DWORD OnObjectInteractBackAddr;

std::map<int, const wchar_t*> object_descriptions{
	{0, L"This statue seems to hold the light of life in its hands."}, // Statue
	{1, L"Interactive object this text must not appear."}, // Door
	{2, L"Interactive object this text must not appear."}, // BigDoor
	{3, L"Interactive object this text must not appear."}, // Window
	{4, L"This window is huge!"}, // CastleWindow
	{5, L"Too bad, it's closed..."}, // Gate
	{6, L"Ouchy ouch, that's a fire trap."}, // FireTrap
	{7, L"It's a little spiky around here!"}, // SpikeTrap
	{8, L"It's a trap to be crushed like a pancake."}, // StompTrap
	{9, L"It must have opened a door somewhere."}, // Lever
	{10, L"Interactive object this text must not appear"}, // Chest
	{11, L"Interactive object this text must not appear"}, // ChestTop02
	{12, L"A simple wooden table, perfect for dining."}, // Table1
	{13, L"A big chunky, dusty stone table."}, // Table2
	{14, L"Just an other table."}, // Table3
	{15, L"Weirdly enough you can't sit there."}, // Stool1
	{16, L"A simple wooden stool."}, // Stool2
	{17, L"Another stool you can't sit on."}, // Stool3
	{18, L"Interactive object this text must not appear"}, // Bench
	{19, L"Interactive object this text must not appear"}, // Bed
	{20, L"A pretty bedside table with a pink flower on it."}, // BedTable
	{21, L"None of these items are for sale."}, // MarketStand1
	{22, L"Sellers don't even keep their stores."}, // MarketStand2
	{23, L"The same structure, but with a subtle color change."}, // MarketStand3
	{24, L"It must contain wine."}, // Barrel
	{25, L"Can it be opened?"}, // Crate
	{26, L"Oh, I see! There's nothing inside..."}, // OpenCrate
	{27, L"Does it contain food?"}, // Sack
	{28, L"A place to rest when it rains. if only rain was a thing..."}, // Shelter
	{29, L"A simple wooden cupboard."}, // Cupboard
	{30, L"An office to manage paperwork"}, // Desktop
	{31, L"Smaller than a desk, obviously useless."}, // Counter
	{32, L"There's a book on the shelf. \"The Art of War\" by OSU!"}, // Shelf1
	{33, L"A wooden herbalist's shelf."}, // Shelf2
	{34, L"A paper herbalist's shelf."}, // Shelf3
	{35, L"A bookshelf to sublimate the castle."}, // CastleShelf1
	{36, L"A wooden shelf."}, // CastleShelf2
	{37, L"An other shelf with random stuff on it."}, // CastleShelf3
	{38, L"A stone shelf where potions can be found."}, // StoneShelf1
	{39, L"What a weird stone shelf!"}, // StoneShelf2
	{40, L"That shelf is ugly."}, // StoneShelf3
	{41, L"An other shelf but with sand on it."}, // SandstoneShelf1
	{42, L"It looks like legs."}, // SandstoneShelf2
	{43, L"And there you have it! A normal-shaped shelf."}, // SandstoneShelf3
	{44, L"Ouch, that's an unpleasant sight."}, // Corpse
	{45, L"Interactive object this text must not appear"}, // RuneStone
	{46, L"It's an ancient artifact. It is written only Link can defeat Ganon."}, // Artifact
	{47, L"A pot of beautiful red flowers."}, // FlowerBox1
	{48, L"A pot of beautiful blue flowers"}, // FlowerBox2
	{49, L"A pot of beautiful yellow flowers"}, // FlowerBox3
	{50, L"The only source of light you can have when night falls."}, // StreetLight
	{51, L"The only source of light you can have when night falls."}, // FireStreetLight
	{52, L"This is a rudimentary fence."}, // Fence1
	{53, L"This is a rudimentary fence."}, // Fence2
	{54, L"This is a rudimentary fence."}, // Fence3
	{55, L"This is a rudimentary fence."}, // Fence4
	{56, L"A vase containing a single violet flower."}, // Vase1
	{57, L"A vase containing a single blue flower."}, // Vase2
	{58, L"A vase containing a single red flower."}, // Vase3
	{59, L"A vase containing multiple blades of grass."}, // Vase4
	{60, L"A sophisticated clay vase containing beautifull red flowers."}, // Vase5
	{61, L"A sophisticated clay vase containing beautifull green plants."}, // Vase6
	{62, L"A sophisticated clay vase containing beautifull pink flowers."}, // Vase7
	{63, L"A sophisticated clay vase containing multiple blades of grass."}, // Vase8
	{64, L"A sophisticated clay vase containing beautifull pink flowers."}, // Vase9
	{65, L"Interactive object this text must not appear"}, // Campfire
	{66, L"If only there were a way to lie down in this world..."}, // Tent
	{67, L"The crabs must be happy"}, // BeachUmbrella
	{68, L"A place to lie down and recover."}, // BeachTowel
	{69, L"A place to lie down and recover."}, // SleepingMat
	{70, L"That's an unused and unknown object, please ignore :D"}, // Unknown70
	{71, L"Interactive object this text must not appear"}, // Furnace
	{72, L"Interactive object this text must not appear"}, // Anvil
	{73, L"Interactive object this text must not appear"}, // SpinningWheel
	{74, L"Interactive object this text must not appear"}, // Loom
	{75, L"Interactive object this text must not appear"}, // SawBench
	{76, L"Interactive object this text must not appear"}, // WorkBench
	{77, L"Interactive object this text must not appear"}, // CustomizationBench
};
const wchar_t* default_description = L"There is nothing special here.";

const wchar_t* On_Object_Interact(int* object_type_ptr) {
	int id = *object_type_ptr;
	auto search = object_descriptions.find(id);
	if (search != object_descriptions.end()) {
		return search->second;
	}
	return default_description;
}

void __declspec(naked) On_Object_Interact_Handler() {
	// STORE REG TO OLDREG
	//Store variables

	__asm {

		PUSH_ALL

		mov eax, [ebp + 0x08]
		push eax

		call On_Object_Interact

		mov[ebp + 0x08], eax
		pop eax

		POP_ALL

		// Original Code
		push[ebp + 0x08]
		mov dword ptr[ebp - 0x04], 0x00000000
		jmp[OnObjectInteractBackAddr]
	}
}

void setup_On_Object_Interact(int offset) {
	int hookLength = 12;
	auto imageBase = (DWORD)GetModuleHandleA(NULL);
	DWORD hookAdress = imageBase + offset;
	DWORD curProtection;
	DWORD temp;
	OnObjectInteractBackAddr = hookAdress + hookLength;

	void* toHook = (void*)hookAdress;

	if (hookLength < 5) {
		return;
	}

	VirtualProtect(toHook, hookLength, PAGE_EXECUTE_READWRITE, &curProtection);

	memset(toHook, 0x90, hookLength);

	DWORD relativeAddress = ((DWORD)On_Object_Interact_Handler - (DWORD)toHook) - 5;

	*(BYTE*)toHook = 0xE9;
	*(DWORD*)((DWORD)toHook + 1) = relativeAddress;

	VirtualProtect(toHook, hookLength, curProtection, &temp);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        setup_On_Object_Interact(0x881AC);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

