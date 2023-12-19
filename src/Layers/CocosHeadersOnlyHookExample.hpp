#pragma once
#include "HooksUtils.hpp"
#include "ModUtils.hpp"
using namespace cocos2d;
using namespace extension;

class GJGarageLayerSkit : public CCLayer {//you should use the class that your target inherits
public:
    inline static GJGarageLayerSkit* me;
    static void CreateHooks();
    void onSomeBtn(CCObject* pSender);
};

