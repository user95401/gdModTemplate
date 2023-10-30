#pragma once
#include "hooks.hpp"
#include "mod_utils.hpp"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;

class MenuLayerExt : public MenuLayer {
public:
    inline static MenuLayerExt* me;
    static void CreateHooks();
    void onChilipizdrik(CCObject* pSender);
    void onOptionBtn(CCObject* pSender);
};

