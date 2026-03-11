#include "PlayLayer.h"
#include "Orbit.h"

USING_NS_CC;

PlayLayer* PlayLayer::createWithConfig(InitialConfig& config) {
	PlayLayer* layer = new (std::nothrow) PlayLayer();
	if (layer && layer->initWithConfig(config)) {
		layer->autorelease();
		return layer;
	}

	CC_SAFE_DELETE(layer);
	return NULL;
}

bool PlayLayer::init() {
	return initWithConfig(InitialConfig());
}

void PlayLayer::update(float deltaTime) {
	CCLayer::update(deltaTime);
	
	const Size visibleSize = Director::getInstance()->getVisibleSize();

	const float planetRotationSpeed = 2.f * deltaTime;
	_planetSprite->setRotation(_planetSprite->getRotation() - planetRotationSpeed);
}

// main constructor
bool PlayLayer::initWithConfig(InitialConfig& config) {
	if (!Layer::init()) {
		return false;
	}

	_initialConfig = config;

	scheduleUpdate();
	
	const Size visibleSize = Director::getInstance()->getVisibleSize();

	_planetSprite = Sprite::createWithSpriteFrameName("SO_Planet_1.png");
	if (!_planetSprite) {
		return false;
	}
	_planetSprite->setPosition(Vec2(
		visibleSize.width/2,
		visibleSize.height/2
	));
	addChild(_planetSprite);

	_orbitsDraw = DrawNode::create();
	if (!_orbitsDraw) {
		return false;
	}
	addChild(_orbitsDraw, 1);

	Orbit* orbit = Orbit::create();
	addChild(orbit, 10);
	orbit->setPosition(_planetSprite->getPosition());

	return true;
}

