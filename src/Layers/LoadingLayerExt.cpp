#include "LoadingLayerExt.hpp"

//0x18cf40
const char* __fastcall LoadingLayer_getString(LoadingLayer* self, void* edx) {
    MappedHooks::getOriginal(LoadingLayer_getString)(self, edx);
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

//0x18c080
bool __fastcall LoadingLayer_init(LoadingLayer* self, void* edx, bool fromReload) {
    MappedHooks::getOriginal(LoadingLayer_init)(self, edx, fromReload);
    LoadingLayer_init;
    twoTimesBoolCallEscapeByParrentNode(self);
    //CCLayerGradient for idk
    CCLayerGradient* pCCLayerGradient = CCLayerGradient::create({ 90,190,255,110 }, { 0,0,0,0 });
    pCCLayerGradient->setBlendFunc({ GL_SRC_ALPHA, GL_ONE });//additive
    self->addChild(pCCLayerGradient);
    return true;
}

void LoadingLayerExt::CreateHooks() {
    MappedHooks::registerHook(base + 0x18cf40, LoadingLayer_getString);
    MappedHooks::registerHook(base + 0x18c080, LoadingLayer_init);
}