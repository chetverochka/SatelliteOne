#include "OrbitObject.h"
#include "Orbit.h"

USING_NS_CC;

OrbitObject::OrbitObject() :
	  _parentOrbit(NULL)
	, _orbitalAngle(0.f)
{}

bool OrbitObject::init() {
	if (!CCSprite::init())
		return false;

	return true;
}

void OrbitObject::onEnter() {
	CCSprite::onEnter();
	_parentOrbit = dynamic_cast<Orbit*>(getParent());
	scheduleUpdate();
}

void OrbitObject::onExit() {
	CCSprite::onExit();
	_parentOrbit = NULL;
	unscheduleUpdate();
}

void OrbitObject::update(float deltaTime) {
	CCSprite::update(deltaTime);

	if (_parentOrbit) {
		_orbitalAngle += _parentOrbit->ROTATE_VELOCITY * deltaTime;

		const float orbitRadius = _parentOrbit->getOrbitRadius();
		const Vec2 orbitCenter = _parentOrbit->getOrbitPosition();

		Vec2 orbitalPos;
		orbitalPos.x = orbitCenter.x + orbitRadius * cos(CC_DEGREES_TO_RADIANS(_orbitalAngle));
		orbitalPos.y = orbitCenter.y + orbitRadius * sin(CC_DEGREES_TO_RADIANS(_orbitalAngle));
		setPosition(orbitalPos);
		setRotation(_orbitalAngle);
	}
}

void OrbitObject::setPaused(bool paused) {
	if (isPaused() != paused) {
		if (paused)
			pause();
		else
			resume();
	}
}

void OrbitObject::setOrbitalAngle(float degrees) {
	if (_orbitalAngle != degrees) {
		_orbitalAngle = degrees;
	}
}

bool OrbitObject::isPaused() {
	return getScheduler()->isTargetPaused(this);
}

Orbit* OrbitObject::getParentOrbit() {
	return _parentOrbit;
}

float OrbitObject::getOrbitalAngle() const {
	return _orbitalAngle;
}