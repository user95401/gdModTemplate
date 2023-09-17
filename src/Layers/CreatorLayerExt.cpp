#include "CreatorLayerExt.hpp"

void CreatorLayerExt::onSomeBtn(cocos2d::CCObject* pSender) {
    //or reinterpret_cast<CCLayer*>(pSender) instead this->me
    this->me->runAction(CCEaseExponentialOut::create(CCRotateBy::create(1.0, 60)));
}

void CreatorLayerExt::onSomeBtn2(cocos2d::CCObject* pSender) {
    //or reinterpret_cast<CCLayer*>(pSender) instead this->me
    this->me->runAction(CCEaseExponentialOut::create(CCScaleTo::create(1.0, this->me->getScale() - 0.1f)));//CCScaleBy is imposter
}

void CreatorLayerExt::onSomeBtn3(cocos2d::CCObject* pSender) {
    this->me->removeChild(reinterpret_cast<CCNode*>(this->me->getChildren()->objectAtIndex(0)));
    reinterpret_cast<CCNode*>(this->me->getChildren()->objectAtIndex(0))->runAction(CCTintTo::create(0.1f, 180, 80, 80));
}

inline bool(__thiscall* CreatorLayer_init)(CreatorLayerExt*);
bool __fastcall CreatorLayer_init_H(CreatorLayerExt* self) {
    CreatorLayer_init(self);
    CreatorLayerExt::me = self;
    twoTimesLayerInitHookEscape(self);//fucking works

    //some shit or genius things here

    CCMenu* Menu = CCMenu::create();
    Menu->setPosition(CCPoint());
    self->addChild(Menu, 999);

    CCSprite* edit_ccwBtn_001 = ModUtils::createSprite("edit_ccwBtn_001.png");
    CCMenuItemSpriteExtra* edit_ccwBtn_001Item = CCMenuItemSpriteExtra::create(edit_ccwBtn_001, self, menu_selector(CreatorLayerExt::onSomeBtn));
    edit_ccwBtn_001Item->setPosition({ CCDirector::sharedDirector()->getScreenRight() - 85.f, CCDirector::sharedDirector()->getScreenTop() - 75.f });
    Menu->addChild(edit_ccwBtn_001Item);

    CCSprite* GJ_zoomOutBtn_001 = ModUtils::createSprite("GJ_zoomOutBtn_001.png");
    CCMenuItemSpriteExtra* GJ_zoomOutBtn_001Item = CCMenuItemSpriteExtra::create(GJ_zoomOutBtn_001, self, menu_selector(CreatorLayerExt::onSomeBtn2));
    GJ_zoomOutBtn_001Item->setPosition({ CCDirector::sharedDirector()->getScreenRight() - 35.f, CCDirector::sharedDirector()->getScreenTop() - 75.f });
    Menu->addChild(GJ_zoomOutBtn_001Item);

    CCSprite* GJ_resetBtn_001 = ModUtils::createSprite("GJ_resetBtn_001.png");
    CCMenuItemSpriteExtra* GJ_resetBtn_001Item = CCMenuItemSpriteExtra::create(GJ_resetBtn_001, self, menu_selector(CreatorLayerExt::onSomeBtn3));
    GJ_resetBtn_001Item->setPosition({ CCDirector::sharedDirector()->getScreenRight() - 60.f, CCDirector::sharedDirector()->getScreenTop() - 110.f });
    Menu->addChild(GJ_resetBtn_001Item);

    return true;
}

void CreatorLayerExt::CreateHooks() {
    HOOK(base + 0x4de40, CreatorLayer_init);
}