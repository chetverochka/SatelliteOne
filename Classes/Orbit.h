#ifndef __ORBIT_H__
#define __ORBIT_H__

#include "cocos2d.h"
#include "Definitions.h"

class Orbit : public cocos2d::Node, public defs::PauseableProtocol {
public:
	static const float ROTATE_VELOCITY;
	CREATE_FUNC(Orbit);

	Orbit();
	bool init() override;
	void update(float deltaTime) override;
	void setPaused(bool paused) override;
	bool isPaused() override;

	virtual void setOrbitRotation(float rotation);
	virtual void setOrbitPosition(const cocos2d::Vec2& point);
	virtual void setOrbitRadius(float radius);
	virtual void setRotationReversed(bool reversed);

	float getOrbitRotation() const;
	cocos2d::Vec2 getOrbitPosition() const;
	float getOrbitRadius() const;
	bool isRotationReversed() const;
protected:
	//void redrawOrbitCircle(const float radius, const float offset, const float dottedGap, const unsigned int dottedCount);
	void redrawOrbitCircle(const float radius, const float offset, const cocos2d::Vec2& center, const float gap, const float dash);
	void redrawOrbitCircle();
private:
	cocos2d::DrawNode* _canvas;
	cocos2d::Vec2 _orbitPosition;
	float _orbitRotation;
	float _orbitRadius;
	bool _reversedRotating;
};

#endif //!__ORBIT_H__