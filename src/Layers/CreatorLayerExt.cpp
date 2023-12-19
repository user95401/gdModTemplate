#include "CreatorLayerExt.hpp"

void CreatorLayerExt::onSomeBtn(CCObject* pSender) {
    //or reinterpret_cast<CCLayer*>(pSender) instead this->me
    this->runAction(CCEaseExponentialOut::create(CCRotateBy::create(1.0, 60)));
}

void CreatorLayerExt::onSomeBtn2(CCObject* pSender) {
    //or reinterpret_cast<CCLayer*>(pSender) instead this->me
    this->runAction(CCEaseExponentialOut::create(CCScaleTo::create(1.0, this->getScale() - 0.1f)));//CCScaleBy is imposter
}

void CreatorLayerExt::onSomeBtn3(CCObject* pSender) {
    this->removeChild(reinterpret_cast<CCNode*>(this->getChildren()->objectAtIndex(0)));
    reinterpret_cast<CCNode*>(this->getChildren()->objectAtIndex(0))->runAction(CCTintTo::create(0.1f, 180, 80, 80));
}

//0x4de40
bool __fastcall CreatorLayer_init(CreatorLayerExt* self) {
    MappedHooks::getOriginal(CreatorLayer_init)(self);
    CreatorLayerExt::me = self;
    twoTimesBoolCallEscapeByParrentNode(self);//fucking works

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
    MappedHooks::registerHook(base + 0x4de40, CreatorLayer_init);
}