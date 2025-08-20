#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
	void customSetup() {
		PauseLayer::customSetup();
		auto rightSideMenu = getChildByID("right-side-menu");
		if (!rightSideMenu) return;
		auto restartButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_updateBtn_001.png"),
			this, menu_selector(MyPauseLayer::onEchofallenn)
		);
		restartButton->setID("echofallenn's-restart-button"_spr);
		restartButton->setZOrder(INT_MIN / 2);
		rightSideMenu->addChild(restartButton);
		rightSideMenu->updateLayout();
	}
	void onEchofallenn(CCObject* sender) {
		if (CCScene::get()->getChildByID("echofallenn's-restart-popup"_spr)) return;
		geode::createQuickPopup(
			"Restart Game",
			"Are you sure you want to <cg>restart your game</c>?",
			"Cancel", "Yes",
			[](auto, bool btn2) {
				if (!btn2) return;
				if (auto pl = PlayLayer::get(); pl) pl->onQuit();
				Loader::get()->queueInMainLoader([](){
					game::restart();
				});
			}
		)->setID("echofallenn's-restart-popup"_spr);
	}
};