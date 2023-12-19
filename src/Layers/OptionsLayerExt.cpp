#include "OptionsLayerExt.hpp"
#include "MenuLayerExt.hpp"//for Chilipizdrik

void __fastcall OptionsLayer_customSetup(OptionsLayerExt* self) {
    MappedHooks::getOriginal(OptionsLayer_customSetup)(self);
    self->me = self;
    twoTimesVoidCallEscapeByParrentNode(self);//fucking works

    CCMenuItemSpriteExtra* logoItem = CCMenuItemSpriteExtra::create(
        ModUtils::createSprite("Chilipizdrik.png", true),//(name, IgnoreScaleFactor)
        self,
        menu_selector(MenuLayerExt::onChilipizdrik)
    );
    //lets do cool slide anim)
    logoItem->runAction(CCSequence::create(
        CCMoveTo::create(0.000f,
            CCPoint(//corner top
                (CCDirector::sharedDirector()->getScreenRight() / 2) - 35.f,
                (CCDirector::sharedDirector()->getScreenTop() / 2) - 35.f
            )
        ),
        CCEaseExponentialOut::create(
            CCMoveTo::create(1.000f,
                CCPoint(//to corner bottom
                    (CCDirector::sharedDirector()->getScreenRight() / 2) - 35.f,
                    -(CCDirector::sharedDirector()->getScreenTop() / 2) + 35.f
                )
            )
        ),//CCEaseExponentialOut
        nullptr //!!!!
    ));
    logoItem->m_bAnimationEnabled = false;
    logoItem->m_bColorEnabled = true;
    logoItem->gd::CCMenuItemSpriteExtra::setScale(0.7f);
    self->m_pLayer->addChild(CCMenu::createWithItem(logoItem));
}

void OptionsLayerExt::CreateHooks() {
    MappedHooks::registerHook(base + 0x1dd420, OptionsLayer_customSetup);
}