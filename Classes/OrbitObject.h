#ifndef __ORBIT_OBJECT_H__
#define __ORBIT_OBJECT_H__

#include "cocos2d.h"
#include "Definitions.h"

class Orbit;

class OrbitObject : public cocos2d::CCSprite, public defs::PauseableProtocol {
public:
	CREATE_FUNC(OrbitObject);

	OrbitObject();
	
	// override's
	bool init() override;
	void onEnter() override;
	void onExit() override;
	void update(float deltaTime) override;

	void setOrbit(Orbit* orbit);
	void setPaused(bool paused) override;
	void setOrbitalAngle(float degrees);

	bool isPaused() override;
	virtual Orbit* getParentOrbit();
	float getOrbitalAngle() const;

private:
	Orbit* _parentOrbit;
	float _orbitalAngle;
};

#endif //!__ORBIT_OBJECT_H__