#pragma once
#include "hooks.hpp"
#include "mod_utils.hpp"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;

class OptionsLayerExt : public OptionsLayer {
public:
    inline static OptionsLayerExt* me;
    static void CreateHooks();
};

