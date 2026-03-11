#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "cocos2d.h"

class PlayLayer;

class PlayScene : public cocos2d::Scene {
public:
	bool init() override;

	CREATE_FUNC(PlayScene);
private:
	PlayLayer* _playLayer;
};

#endif // !__PLAY_SCENE_H__