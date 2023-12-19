#include "CocosHeadersOnlyHookExample.hpp"

//and also MappedHooks lol

/*
*  here I'll show you how to write a layer hook without gd.h
*/

//if u want, u cant make extension of CCMenuItemLabel to add animations ant other stuff
class CCMenuItemLabelExt : public CCMenuItemLabel {
public:
    float m_fOriginalSize;
    static CCMenuItemLabelExt* create(CCNode* label, CCObject* target, SEL_MenuHandler selector) {
        CCMenuItemLabelExt* pRet = new CCMenuItemLabelExt();
        if (pRet && pRet->initWithLabel(label, target, selector)) { pRet->autorelease(); return pRet; }
        else { delete pRet; pRet = NULL; return NULL; }
    }
    virtual void selected() {
        if (this->m_fOriginalSize < 0.001) this->m_fOriginalSize = this->getScale();
        CCScaleTo* pCCScaleTo = CCScaleTo::create(0.300f, m_fOriginalSize * 1.26f);
        CCAction* pScaleAction = CCEaseBounceOut::create(pCCScaleTo);
        this->runAction(pScaleAction);
    }
    virtual void unselected() {
        if (this->m_fOriginalSize < 0.001) this->m_fOriginalSize = this->getScale();
        CCScaleTo* pCCScaleTo = CCScaleTo::create(0.300f, m_fOriginalSize);
        CCAction* pScaleAction = CCEaseBounceOut::create(pCCScaleTo);
        this->runAction(pScaleAction);
    }
};

#include <shellapi.h>
void GJGarageLayerSkit::onSomeBtn(CCObject* pSender) {
    //member by offset
    CCSprite* mbo_pColorSelector1 = MBO(CCSprite*, this, 0x140);
    mbo_pColorSelector1->setPosition(TheObjOrSomeObj(CCNode*, pSender)->getPosition());
    //totay we abit change CRAZY SHIT that maked before in _CustomLayer
    // - notify with powershell
    std::string title = std::format("hi from {}!", ModUtils::GetModName());//here, because no gd.h callenge
    std::string msg = "nothing else, thanks for click on this btn.";
    std::string command(
        "powershell -Command \"& {"
        "Add-Type -AssemblyName System.Windows.Forms; "
        "Add-Type -AssemblyName System.Drawing; "
        "$notify = New-Object System.Windows.Forms.NotifyIcon; "
        "$notify.Icon = [System.Drawing.SystemIcons]::Information; "
        "$notify.Visible = $true; "
        "$notify.ShowBalloonTip(0, '" + title + "', '" + msg + "', [System.Windows.Forms.ToolTipIcon]::None) "
        "}\" "
    );
    //ModUtils::log(command);
    ShellExecuteA(NULL, NULL, "cmd", std::format("/c {}", command).c_str(), NULL, 0);
}
#include <gd.h>

void __fastcall GJGarageLayer_init(GJGarageLayerSkit* self) {
    MappedHooks::getOriginal(GJGarageLayer_init)(self);
    self->me = self;
    twoTimesVoidCallEscapeByParrentNode(self);//fucking works

    //soo lets just copy stuff from custom layer

    CCMenu* Menu = CCMenu::create();
    Menu->setPosition(CCPoint());
    self->addChild(Menu, 100, 5940);//do u know that exists addChild(node, index) and addChild(node, index, tag)???

    //onSomeBtn
    //we don't have robtop addons, so take CCMenuItemLabel because it have some animation at least
    //but we can make own item and i writed some exxamle as CCMenuItemLabelExt
    CCMenuItemLabelExt* btn_chatHistory_001 = CCMenuItemLabelExt::create(
        ModUtils::createSprite("btn_chatHistory_001.png"),
        self,
        menu_selector(GJGarageLayerSkit::onSomeBtn)
    );
    btn_chatHistory_001->setPositionX(CCDirector::sharedDirector()->getWinSize().width - 42);
    btn_chatHistory_001->setPositionY(48.000f);
    Menu->addChild(btn_chatHistory_001);

    //particle for btn_chatHistory_001
    CCParticleSystemQuad* keyEffect = CCParticleSystemQuad::create("keyEffect.plist");
    CC_SAFE_RELEASE(keyEffect);
    keyEffect->setPosition(btn_chatHistory_001->getContentSize()/2);
    keyEffect->setPositionType(kCCPositionTypeFree);
    btn_chatHistory_001->addChild(keyEffect, -1);

    //member by offset
    CCLayer* mbo_pNameInput = MBO(CCLayer*, self, 0x130);
    CCSprite* mbo_pPlayerPreview = MBO(CCSprite*, self, 0x134);

    //sucks jump anim
    int jumps = (rand() % 9);
    mbo_pNameInput->runAction(CCJumpBy::create(0.5f * jumps, { 0.f, 1.0f }, 12, jumps));
    mbo_pPlayerPreview->runAction(CCJumpBy::create(0.5f * jumps, { 0.f, 1.0f }, 12, jumps));

    //particle for player prev
    CCParticleSystemQuad* dragEffect = CCParticleSystemQuad::create("dragEffect.plist");
    CC_SAFE_RELEASE(dragEffect);
    dragEffect->setPosition({ -15.000f, -15.000f });
    dragEffect->setPositionType(kCCPositionTypeRelative);
    mbo_pPlayerPreview->addChild(dragEffect, -1);

    //fix somethings for scroll
    mbo_pPlayerPreview->setTag(5829);
    self->removeChildByTag(5829, false);
    CCNode* container = CCNode::create();
    container->setPosition({ -9999.f,-9999.f });
    self->addChild(container);
    container->addChild(mbo_pPlayerPreview);
    //scroll layer
    CCScrollView* pCCScrollView = CCScrollView::create(CCDirector::sharedDirector()->getWinSize());
    pCCScrollView->addChild(mbo_pPlayerPreview);
    pCCScrollView->setDirection(CCScrollViewDirection::kCCScrollViewDirectionHorizontal);
    self->addChild(pCCScrollView);
}

void GJGarageLayerSkit::CreateHooks() {
    //gd::base it is reinterpret_cast<uintptr_t>(GetModuleHandle(0))
    MappedHooks::registerHook((DWORD)GetModuleHandle(0) + 0x1255d0, GJGarageLayer_init);
}