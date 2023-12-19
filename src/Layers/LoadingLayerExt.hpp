#pragma once
#include "HooksUtils.hpp"
#include "ModUtils.hpp"
using namespace cocos2d;
using namespace extension;
using namespace gd;
using namespace std;

class LoadingLayerExt : public LoadingLayer {
public:
    static void CreateHooks();
};
