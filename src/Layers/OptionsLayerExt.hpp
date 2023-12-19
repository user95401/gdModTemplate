#pragma once
#include "HooksUtils.hpp"
#include "ModUtils.hpp"
using namespace cocos2d;
using namespace extension;
using namespace gd;

class OptionsLayerExt : public OptionsLayer {
public:
    inline static OptionsLayerExt* me;
    static void CreateHooks();
};

