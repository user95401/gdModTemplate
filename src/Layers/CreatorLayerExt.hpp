﻿#pragma once
#include "HooksUtils.hpp"
#include "ModUtils.hpp"
using namespace cocos2d;
using namespace extension;
using namespace gd;

class CreatorLayerExt : public CreatorLayer {
public:
    inline static CreatorLayerExt* me;
    static void CreateHooks();
    void onSomeBtn(CCObject* pSender);
    void onSomeBtn2(CCObject* pSender);
    void onSomeBtn3(CCObject* pSender);
};
