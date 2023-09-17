#pragma once
#include "hooks.hpp"
#include "mod_utils.hpp"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;

class CreatorLayerExt : public CreatorLayer {
public:
    inline static CreatorLayerExt* me;
    static void CreateHooks();
    void onSomeBtn(cocos2d::CCObject* pSender);
    void onSomeBtn2(cocos2d::CCObject* pSender);
    void onSomeBtn3(cocos2d::CCObject* pSender);
};

