#ifndef __ORBIT_H__
#define __ORBIT_H__

#include "cocos2d.h"

class Orbit : public cocos2d::Node {
public:
	static const float ROTATE_VELOCITY;
	CREATE_FUNC(Orbit);

	Orbit();
	bool init() override;
	void update(float deltaTime) override;

	virtual void setOrbitRotation(float rotation);
	float getOrbitRotation() const;
protected:
	//void redrawOrbitCircle(const float radius, const float offset, const float dottedGap, const unsigned int dottedCount);
	void redrawOrbitCircle(const float radius, const float offset, const cocos2d::Vec2& center, const float gap, const float dash);
private:
	cocos2d::DrawNode* _canvas;

	float _orbitRotation;
};

#endif //!__ORBIT_H__