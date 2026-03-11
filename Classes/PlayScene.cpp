#include "PlayScene.h"
#include "PlayLayer.h"

USING_NS_CC;

bool PlayScene::init() {
	if (!Scene::init()) {
		return false;
	}

	_playLayer = PlayLayer::create();
	addChild(_playLayer, 1, 1);

	return true;
}