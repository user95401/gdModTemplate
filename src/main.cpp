#include "mod_utils.hpp"
#include "hooks.hpp"
using namespace cocos2d;
using namespace gd;
using namespace cocos2d::extension;

#include "Layers/MenuLayerExt.hpp"
#include "Layers/CreatorLayerExt.hpp"

DWORD WINAPI thread_func(void* hModule) {
    
    //Trail Bug Fix (Fixes trail cutting on high refresh rates)
    ModUtils::write_bytes(libcocos2d + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });
    //Verify Hack
    ModUtils::write_bytes(base + 0x71D48, { 0xEB });
    
    // initialize minhook
    MH_SafeInitialize();

    //creating hooks
    /*
    u can get targets and other in
    https://github.com/matcool/re-scripts/blob/main/func_dump.txt
    https://github.com/geode-sdk/geode/blob/main/bindings/GeometryDash.bro
    */
    MenuLayerExt::CreateHooks();
    CreatorLayerExt::CreateHooks();
    // enable all hooks you've created with minhook
    MH_EnableHook(MH_ALL_HOOKS);

    return 0;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, thread_func, hModule, 0, 0);
    return TRUE;
}
