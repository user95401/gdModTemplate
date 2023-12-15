#include "mod_utils.hpp"
#include "hooks.hpp"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;

#include "Layers/MenuLayerExt.hpp"
#include "Layers/CreatorLayerExt.hpp"
#include "Layers/LoadingLayerExt.hpp"
#include "Layers/MappedHooksExample.hpp"//look it :>

#include "SimpleIni.h"
void ApplyPatches() {
    //Trail Bug Fix (Fixes trail cutting on high refresh rates)
    ModUtils::write_bytes(libcocos2d + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });

    //btw curly-eureka has SimpleIni, i -i show how to use it
    CSimpleIni ini;
    std::filesystem::create_directories("geode/config/");
    ini.LoadFile("geode/config/your_mod_cfg.ini");
    if (!(ini.KeyExists("MAIN_SECTION", "some_boolean_value")))//create value and section if dont exists
        ini.SetBoolValue("MAIN_SECTION", "some_boolean_value", true, "; //comment");
    ini.SaveFile("geode/config/your_mod_cfg.ini");//save if there is changes in program (from memory)

    //Verify Hack if some_boolean_value is true;
    if(ini.GetBoolValue("MAIN_SECTION", "some_boolean_value"))
        ModUtils::write_bytes(base + 0x71D48, { 0xEB });

}

DWORD WINAPI PROCESS_ATTACH(void* hModule) {
    //ApplyPatches i guess
    ApplyPatches();
    //create and enable hooks
    MH_Initialize();
    LoadingLayerExt::CreateHooks();
    MenuLayerExt::CreateHooks();
    CreatorLayerExt::CreateHooks();
    OptionsLayerExt::CreateHooks();//MappedHooksExample
    //geode console log (printf)
    ModUtils::log("Mod loaded");
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) 
        CreateThread(0, 0, PROCESS_ATTACH, hModule, 0, 0);
    return TRUE;
}
