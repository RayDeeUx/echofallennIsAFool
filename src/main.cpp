#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();
		auto buttonMenu = getChildByID("left-side-menu");
		if (!buttonMenu) buttonMenu = getChildByID("left-button-menu");
		if (!buttonMenu) buttonMenu = getChildByID("right-side-menu");
		if (!buttonMenu) buttonMenu = getChildByID("right-button-menu");
		if (!buttonMenu) return;
		auto rstSprite = CCSprite::createWithSpriteFrameName("GJ_updateBtn_001.png");
		rstSprite->setScale(.7f);
		auto restartButton = CCMenuItemSpriteExtra::create(
			rstSprite, this, menu_selector(MyPauseLayer::onEchofallenn)
		);
		restartButton->setID("echofallenn's-restart-button"_spr);
		restartButton->setZOrder(INT_MIN / 2);
		buttonMenu->addChild(restartButton);
		buttonMenu->updateLayout();
	}
	void onEchofallenn(CCObject* sender) {
		if (CCScene::get()->getChildByID("echofallenn's-restart-popup"_spr)) return;
		geode::createQuickPopup(
			"Restart Game",
			"Are you sure you want to <cg>restart your game</c>?",
			"Cancel", "Yes",
			[](auto, bool btn2) {
				if (btn2) game::restart();
			}
		)->setID("echofallenn's-restart-popup"_spr);
	}
};