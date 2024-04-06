// dllmain.cpp : Définit le point d'entrée de l'application DLL.
#include "pch.h"
#include <cstdio>
#include <iostream>
#include "globals.h"
#include "cwlib.h"
#include "On_Object_Interact.h"

// Open new console for c(in/out/err)
void OpenConsole()
{
    AllocConsole();
    FILE* cinStream;
    FILE* coutStream;
    FILE* cerrStream;
    freopen_s(&cinStream, "CONIN$", "r", stdin);
    freopen_s(&coutStream, "CONOUT$", "w", stdout);
    freopen_s(&cerrStream, "CONOUT$", "w", stderr);
}

DWORD WINAPI MyFunc(LPVOID lpvParam) {
    OpenConsole();
    setup_On_Object_Interact();
    auto gc = cube::GetGameController();
    std::cout << "GameController data [" << gc << "]:" << std::endl;
    try {
        while (true) {
            std::cout << "CharacterWidget data [" << &gc->character_style_widget_ptr << "]:" << std::endl;
            std::cout << "\trace:" << std::dec << gc->character_style_widget_ptr->race << std::endl;
            std::cout << "\tgender:" << std::dec << gc->character_style_widget_ptr->gender << std::endl;
            std::cout << "\tclass:" << std::dec << gc->character_style_widget_ptr->class_id << std::endl;
            std::cout << "\tface:" << std::dec << gc->character_style_widget_ptr->face << std::endl;
            std::cout << "\thaircut:" << std::dec << gc->character_style_widget_ptr->haircut << std::endl;
            Sleep(1000);
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error displaying CharacterWidget data: " << e.what() << std::endl;
    }
    //cube::InitGlobals();
    //std::cout << "\t:" << std::dec << gc->character_style_widget_ptr->class_id << std::endl;
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, MyFunc, 0, 0, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

