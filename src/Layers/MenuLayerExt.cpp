#include "MenuLayerExt.hpp"

void MenuLayerExt::onChilipizdrik(cocos2d::CCObject* pSender) {
    //create Scene!!!!
    CCScene* Scene = CCScene::create();
    Scene->addChild(CreatorLayer::create());//add CreatorLayer yoo
    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5, Scene));//push Scene
    //small code mode^
}

inline bool(__thiscall* MenuLayer_init)(MenuLayerExt*);
bool __fastcall MenuLayer_init_H(MenuLayerExt* self) {
    MenuLayer_init(self);
    MenuLayerExt::me = self;
    twoTimesLayerInitHookEscape(self);//fucking works

    //some shit or genius things here
    CCSprite* spr = ModUtils::createSprite("tutorial_01.png");
    spr->setPosition(ModUtils::getCenterPoint());
    self->addChild(spr, 10, 666);

    CCMenu* Menu = CCMenu::create();
    Menu->setPosition(CCPoint());
    self->addChild(Menu);

    CCMenuItemSpriteExtra* logoItem = CCMenuItemSpriteExtra::create(
        ModUtils::createSprite("Chilipizdrik.png", 1),//(name, IgnoreScaleFactor)
        self,
        menu_selector(MenuLayerExt::onChilipizdrik)
    );
    logoItem->setPosition({ 
        CCDirector::sharedDirector()->getScreenRight() - 35.f, 
        CCDirector::sharedDirector()->getScreenTop() - 35.f 
        });
    logoItem->m_bAnimationEnabled = false;
    logoItem->m_bColorEnabled = true;
    logoItem->gd::CCMenuItemSpriteExtra::setScale(0.7f);
    Menu->addChild(logoItem);

    return true;
}

inline void(__thiscall* MenuLayer_onCreator)(MenuLayerExt*, cocos2d::CCObject*);
void __fastcall MenuLayer_onCreator_H(MenuLayerExt* self, void*, cocos2d::CCObject* pSender) {
    //                                                 ^something that is incredibly important(void*) but forgettable
    //MenuLayer_onCreator(); //not needed if u dont want include original code
    FLAlertLayer* alert = FLAlertLayer::create(self, "No creaor layer", "Oh ok", nullptr, 490.0, std::string("Just for example)\n<cr>My lady came down, she was thinking no harm Long Lankin stood ready to catch her in his arm There's blood in the kitchen. There's blood in the hall There's blood in the parlour where my lady did fall You might also like Long Lankin Steeleye Span Immolation of Night Invent Animate Without a Whisper Invent Animate -O master, O master, don't lay the blame on me 'Twas the false nurse and Lankin that killed your lady. Long Lankin was hung on a gibbet so high And the false nurse was burnt in a fire close by</c>"));
    alert->m_pLayer->runAction(
        CCRepeatForever::create(
            CCSequence::create(
                CCEaseSineInOut::create(CCMoveBy::create(1.0f, CCPoint(0, 3))),
                CCEaseSineInOut::create(CCMoveBy::create(2.0f, CCPoint(0, -3))),
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