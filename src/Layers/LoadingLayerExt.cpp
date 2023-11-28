#include "LoadingLayerExt.hpp"

const char* (__thiscall* LoadingLayer_getString)(LoadingLayer*);//0x18cf40
const char* __fastcall LoadingLayer_getString_H(LoadingLayer* self, void*) {
    LoadingLayer_getString(self);
    //geting stringfdd
    const char* s[5] = {
        "<cg>Loading speedrun...</c>",
        "<cr>user666 was here</c>",
        "Counting to lEET",
        "Pro tip: <cr>Don't crash</c>"
    };
    srand(time(NULL));
    return s[rand() % int(sizeof(s) / sizeof(s[0]))];
}

bool(__thiscall* LoadingLayer_init)(LoadingLayer* self, bool fromReload);
bool __fastcall LoadingLayer_init_H(LoadingLayer* self, void* unk, bool fromReload) {
    if (!LoadingLayer_init(self, fromReload)) return false;
    twoTimesBoolCallEscapeByParrentNode(self);

    return true;
}

void LoadingLayerExt::CreateHooks() {
    HOOK(base + 0x18cf40, LoadingLayer_getString);
    HOOK(base + 0x18C080, LoadingLayer_init);
}