#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <random>
#include <cocos2d.h>
#include <gd.h>
#include "mod_utils.hpp"
#include "mapped-hooks.hpp"
#include <MinHook.h>
using namespace cocos2d;
using namespace gd;
using namespace cocos2d::extension;

bool __fastcall MenuLayer_init(MenuLayer* self) {
    if (!MHook::getOriginal(MenuLayer_init)(self)) return false;
    //some shit or genius things here
    CCSprite* spr = ModUtils::createSprite("tutorial_01.png");
    spr->setPosition(CCMenu::create()->getPosition()); //idk why but CCMenu creates with center position 😏
    self->addChild(spr,10,666);
    return true;
}
void __fastcall MenuLayer_onCreator(MenuLayer* self, void* a, cocos2d::CCObject* pSender) {
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

    std::random_device os_seed;
    const unsigned int seed = os_seed();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribute(250, 1000);
    int sleepMs = distribute(generator);
    Sleep(sleepMs);

    MHook::registerHook(base + 0x1907b0, MenuLayer_init);
    MHook::registerHook(base + 0x191cd0, MenuLayer_onCreator);

    // enable all hooks you've created with minhook
    MH_EnableHook(MH_ALL_HOOKS);

    return 0;
}
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, thread_func, hModule, 0, 0);
    return TRUE;
}
