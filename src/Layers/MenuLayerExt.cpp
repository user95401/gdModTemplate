#include "MenuLayerExt.hpp"

void MenuLayerExt::onChilipizdrik(cocos2d::CCObject* pSender) {
    //create Scene!!!!
    CCScene* Scene = CCScene::create();
    Scene->addChild(CreatorLayer::create());//add CreatorLayer yoo
    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5, Scene));//push Scene
    //small code mode^
}

void MenuLayerExt::onOptionBtn(cocos2d::CCObject* pSender) {
    //glad to show u a ValueSetupPopup that included in c-e
    //lets create it for some_boolean_value from _main.cpp
    ValueSetupPopup::create("some_boolean_value", "MAIN_SECTION", "geode/config/your_mod_cfg.ini", "Verify Hack if true")
        ->isBoolean()//yea u can set some options so, also exists noElasticity() vanillaFadeOut()
        ->show();//show up
}

bool(__thiscall* MenuLayer_init)(MenuLayerExt*);
bool __fastcall MenuLayer_init_H(MenuLayerExt* self) {
    MenuLayer_init(self);
    self->me = self;
    twoTimesBoolCallEscapeByParrentNode(self);//fucking works

    //some shit or genius things here

    //snow.
    CCParticleSnow* pCCParticleSnow = CCParticleSnow::create();
    pCCParticleSnow->setBlendAdditive(true);
    self->addChild(pCCParticleSnow, 100, 2024);

    CCSprite* spr = ModUtils::createSprite("tutorial_05.png");
    spr->setPosition(ModUtils::getCenterPoint());
    spr->setPositionY(31.000f);
    spr->setOpacity(19);
    self->addChild(spr, 0, 666);

    CCMenu* Menu = CCMenu::create();
    Menu->setPosition(CCPoint());
    self->addChild(Menu, 100, 5940);//do u know that exists addChild(node, index) and addChild(node, index, tag)???

    CCMenuItemSpriteExtra* logoItem = CCMenuItemSpriteExtra::create(
        ModUtils::createSprite("Chilipizdrik.png", true),//(name, IgnoreScaleFactor)
        self,
        menu_selector(MenuLayerExt::onChilipizdrik)
    );
    logoItem->setPosition({ 
        CCDirector::sharedDirector()->getScreenRight() - 35.000f, 
        CCDirector::sharedDirector()->getScreenTop() - 35.000f 
        });
    logoItem->m_bAnimationEnabled = false;
    logoItem->m_bColorEnabled = true;
    logoItem->gd::CCMenuItemSpriteExtra::setScale(0.700f);
    Menu->addChild(logoItem);

    CCMenuItemSpriteExtra* onMyProfileItem = ModUtils::createTextButton(
        self, //cocos2d::CCLayer* parent
        "openup parental control XD", //const char* text
        menu_selector(MenuLayer::onMyProfile), //cocos2d::SEL_MenuHandler handler
        CCLabelTTF::create("openup mine profile", "Arial", (32) - 0.600f)->getContentSize().width, //int width (silly auto calculation)
        0.000f, //float height
        0.600f //float scale (of text)
    );
    onMyProfileItem->gd::CCMenuItemSpriteExtra::setScale(0.500f);
    onMyProfileItem->setPosition(ModUtils::getCenterPoint());
    Menu->addChild(onMyProfileItem);

    CCMenuItemSpriteExtra* GJ_optionsBtn_001 = CCMenuItemSpriteExtra::create(
        ModUtils::createSprite("GJ_optionsBtn_001.png"),
        self,
        menu_selector(MenuLayerExt::onOptionBtn)
    );
    GJ_optionsBtn_001->setPosition({
        CCDirector::sharedDirector()->getScreenRight() - 125.000f, 
        CCDirector::sharedDirector()->getScreenTop() - 35.000f 
        });
    GJ_optionsBtn_001->gd::CCMenuItemSpriteExtra::setScale(0.800f);
    Menu->addChild(GJ_optionsBtn_001);
    return true;
}

void(__thiscall* MenuLayer_onCreator)(MenuLayerExt*, cocos2d::CCObject*);
void __fastcall MenuLayer_onCreator_H(MenuLayerExt* self, void*, cocos2d::CCObject* pSender) {
    //                                                 ^something that is incredibly important(void*) but forgettable
    //MenuLayer_onCreator(); //not needed if u dont want include original code
    FLAlertLayer* alert = FLAlertLayer::create(self, "No creaor layer", "Oh ok", nullptr, 490.000f, std::string("Just for example)\n<cr>My lady came down, she was thinking no harm Long Lankin stood ready to catch her in his arm There's blood in the kitchen. There's blood in the hall There's blood in the parlour where my lady did fall You might also like Long Lankin Steeleye Span Immolation of Night Invent Animate Without a Whisper Invent Animate -O master, O master, don't lay the blame on me 'Twas the false nurse and Lankin that killed your lady. Long Lankin was hung on a gibbet so high And the false nurse was burnt in a fire close by</c>"));
    alert->m_pLayer->runAction(
        CCRepeatForever::create(
            CCSequence::create(
                CCEaseSineInOut::create(CCMoveBy::create(1.000f, CCPoint(0.000f, 3.000f))),
                CCEaseSineInOut::create(CCMoveBy::create(2.000f, CCPoint(0.000f, -3.000f))),
                nullptr
            )
        )
    ); //for fun xdd
    alert->show();
}

void MenuLayerExt::CreateHooks() {
    HOOK(base + 0x1907b0, MenuLayer_init);
    HOOK(base + 0x191cd0, MenuLayer_onCreator);
}