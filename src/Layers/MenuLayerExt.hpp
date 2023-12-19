#pragma once
#include "HooksUtils.hpp"
#include "ModUtils.hpp"
using namespace cocos2d;
using namespace extension;
using namespace gd;

class MenuLayerExt : public MenuLayer {
public:
    inline static MenuLayerExt* me;
    static void CreateHooks();
    void onChilipizdrik(CCObject* pSender);
    void onOptionBtn(CCObject* pSender);
};

