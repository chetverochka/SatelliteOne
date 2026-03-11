#ifndef __PLAY_LAYER_H__
#define __PLAY_LAYER_H__

#include "cocos2d.h"

// my bad "god" class
class PlayLayer : public cocos2d::CCLayer {
public:
	struct InitialConfig {

	};
	static PlayLayer* createWithConfig(InitialConfig& config);
	CREATE_FUNC(PlayLayer);

	bool init() override;
	void update(float deltaTime) override;

	bool initWithConfig(InitialConfig& config);
private:
	cocos2d::Sprite* _planetSprite;
	cocos2d::DrawNode* _orbitsDraw;

	InitialConfig _initialConfig;
};

#endif // !__PLAY_LAYER_H__