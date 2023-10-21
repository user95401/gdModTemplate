#pragma once
#include "hooks.hpp"
#include "mod_utils.hpp"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;
using namespace std;

class LoadingLayerExt : public LoadingLayer {
public:
    static void CreateHooks();
};
