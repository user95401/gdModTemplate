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
    srand((unsigned int)time(NULL));
    return s[rand() % int(sizeof(s) / sizeof(s[0]))];
}

bool (__thiscall* LoadingLayer_init)(LoadingLayer*, bool);//0x18c080
bool __fastcall LoadingLayer_init_H(LoadingLayer* self, void*, bool fromReload) {
    LoadingLayer_init(self, fromReload);
    twoTimesBoolCallEscapeByParrentNode(self);
    //CCLayerGradient for idk
    CCLayerGradient* pCCLayerGradient = CCLayerGradient::create({ 90,190,255,110 }, { 0,0,0,0 });
    pCCLayerGradient->setBlendFunc({ GL_SRC_ALPHA, GL_ONE });//additive
    self->addChild(pCCLayerGradient);
    return true;
}

void LoadingLayerExt::CreateHooks() {
    HOOK(base + 0x18cf40, LoadingLayer_getString);
    HOOK(base + 0x18c080, LoadingLayer_init);
}