#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <random>
#include <cocos2d.h>
#include <gd.h>
#include "mod_utils.hpp"
#include "hooks.hpp"
#include <MinHook.h>
using namespace cocos2d;
using namespace gd;
using namespace cocos2d::extension;

inline bool(__thiscall* MenuLayer_init)(MenuLayer*);
bool __fastcall MenuLayer_init_H(MenuLayer* self) {
    if (!MenuLayer_init(self)) return false;
    //some shit or genius things here
    CCSprite* spr = ModUtils::createSprite("tutorial_01.png");
    spr->setPosition(ModUtils::getCenterPoint()); //idk why but CCMenu creates with center position 😏
    self->addChild(spr,10,666);
    return true;
}
inline void(__thiscall* MenuLayer_onCreator)(MenuLayer*, cocos2d::CCObject*);
void __fastcall MenuLayer_onCreator_H(MenuLayer* self, void*, cocos2d::CCObject* pSender) {
    //                                                 ^something that is incredibly important(void*) but forgettable
    //MenuLayer_onCreator(); //not needed if u dont want include original code
    FLAlertLayer* alert = FLAlertLayer::create(self, "No creaor layer", "Oh ok", nullptr, 500.0, std::string("Just for example)\n<cr>My lady came down, she was thinking no harm Long Lankin stood ready to catch her in his arm There's blood in the kitchen. There's blood in the hall There's blood in the parlour where my lady did fall You might also like Long Lankin Steeleye Span Immolation of Night Invent Animate Without a Whisper Invent Animate -O master, O master, don't lay the blame on me 'Twas the false nurse and Lankin that killed your lady. Long Lankin was hung on a gibbet so high And the false nurse was burnt in a fire close by</c>"));
    alert->show();
}
DWORD WINAPI thread_func(void* hModule) {
    
    //Trail Bug Fix (Fixes trail cutting on high refresh rates)
    ModUtils::write_bytes((DWORD)GetModuleHandleA("libcocos2d.dll") + 0xAE9BD, { 0xBB , 0xFF , 0x00 , 0x00 , 0x00 , 0x90 });
    //Verify Hack
    ModUtils::write_bytes(base + 0x71D48, { 0xEB });
    
    // initialize minhook
    MH_Initialize();

    //creating hooks
    /*
    here is templates with #define
    #define HOOK(base + 0x1907b0, MenuLayer_init, false)
         ^target          ^               ^
                          ^original and when hook with the suffix _H
                                          ^do hook immediately(without a random delay)? (for no conflict to other mods set it false)
    
    u can get offsets and other in
    https://github.com/matcool/re-scripts/blob/main/func_dump.txt
    https://github.com/geode-sdk/geode/blob/main/bindings/GeometryDash.bro
    */
    HOOK(base + 0x1907b0, MenuLayer_init, false);
    HOOK(base + 0x191cd0, MenuLayer_onCreator, false);

    // enable all hooks you've created with minhook
    MH_EnableHook(MH_ALL_HOOKS);

    return 0;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, thread_func, hModule, 0, 0);
    return TRUE;
}
