#include "Orbit.h"
#include "Meteorite.h"
USING_NS_CC;

const float Orbit::ROTATE_VELOCITY = 2.f;

Orbit::Orbit() {
	_orbitRotation = 0.f;
	_canvas = NULL;
	_orbitPosition = ccp(0, 0);
	_orbitRadius = 300.f;
	_reversedRotating = false;
	_objects = {};
}

bool Orbit::init() {
	if (!Node::init()) {
		return false;
	}

	//setIgnoreAnchorPointForPosition(false);
	setCascadeColorEnabled(true);
	setCascadeOpacityEnabled(true);
	scheduleUpdate();

	_canvas = DrawNode::create();
	if (_canvas) {
		addChild(_canvas, 0);
	}
	else {
		return false;
	}

	return true;
}

void Orbit::update(float deltaTime) {
	Node::update(deltaTime);

	const float reversedSpeed = _reversedRotating;
	const float speedMultiplier = 1.f;
	const float orbitRotateSpeed = ROTATE_VELOCITY * speedMultiplier * deltaTime * (reversedSpeed ? -1 : 1);
	const float newOrbitRotation = getOrbitRotation() + orbitRotateSpeed;
	
	setOrbitRotation(newOrbitRotation);
}

void Orbit::setPaused(bool paused) {
	if (isPaused() != paused) {
		if (paused)
			pause();
		else
			resume();
	}
}

bool Orbit::isPaused() {
	return getScheduler()->isTargetPaused(this);
}

void Orbit::addOrbitObject(OrbitObject* object) {
	if (_objects.contains(object))
		return;
	object->setOrbit(this);
	_objects.pushBack(object);
}

void Orbit::removeOrbitObject(OrbitObject* object) {
	if (!_objects.contains(object))
		return;
	object->setOrbit(NULL);
	_objects.eraseObject(object);
}

void Orbit::setOrbitRotation(float rotation) {
	if (_orbitRotation != rotation) {
		_orbitRotation = rotation;
		redrawOrbitCircle();
	}
}

void Orbit::setOrbitPosition(const Vec2& point) {
	if (_orbitPosition != point) {
		_orbitPosition = point;
		redrawOrbitCircle();
	}
}

void Orbit::setOrbitRadius(float radius) {
	if (_orbitRadius != radius) {
		_orbitRadius = radius;
		redrawOrbitCircle();
	}
}

void Orbit::setRotationReversed(bool reversed) {
	if (_reversedRotating != reversed) {
		_reversedRotating = reversed;
	}
}


Vec2 Orbit::getOrbitPosition() const {
	return _orbitPosition;
}

float Orbit::getOrbitRotation() const {
	return _orbitRotation;
}

float Orbit::getOrbitRadius() const {
	return _orbitRadius;
}

Vector<OrbitObject*> Orbit::getOrbitObjects() {
	return _objects;
}

bool Orbit::isRotationReversed() const {
	return _reversedRotating;
}

//void Orbit::redrawOrbitCircle(const float radius, const float offset, const float dottedGap, const unsigned int dottedCount) {
//	_canvas->clear();
//
//	const float circumference = 2.f * M_PI * radius; // C = 2 * PI * R or C = PI * D
//	const float circumferenceSegment = (circumference / dottedCount);
//	
//	const float dottedTotalDeg = 360.f / dottedCount; // segment degrees
//	const float dottedDashDeg = (circumferenceSegment - dottedGap) / circumference * 360.f;
//
//	const Vec2 center(0.f, 0.f);
//
//	for (int i = 0; i < dottedCount; i++) {
//		float fromDegree, toDegree;
//
//		fromDegree = i * dottedTotalDeg + offset;
//		toDegree = fromDegree + dottedDashDeg;
//
//		Vec2 origin, destination;
//		origin.x = center.x + radius * cos(CC_DEGREES_TO_RADIANS(fromDegree));
//		origin.y = center.y + radius * sin(CC_DEGREES_TO_RADIANS(fromDegree));
//
//		destination.x = center.x + radius * cos(CC_DEGREES_TO_RADIANS(toDegree));
//		destination.y = center.y + radius * sin(CC_DEGREES_TO_RADIANS(toDegree));
//
//		_canvas->drawLine(origin, destination, Color4F::WHITE);
//	}
//}

void Orbit::redrawOrbitCircle(const float radius, const float offset, const cocos2d::Vec2& center, const float gap, const float dash) {
	const float circumference = 2.f * M_PI * radius; // C = 2 * PI * R or C = PI * D
	const float dashDeg = dash / circumference * 360.f; // dash size in degrees
	const float gapDeg = gap / circumference * 360.f; // gap size in degrees
	const float segmentDeg = dashDeg + gapDeg;
	const int segmentsCount = (int)std::floorf(360.f / segmentDeg);

	_canvas->clear();

	for (int i = 0; i < segmentsCount; i++) {
		float fromDegree, toDegree;

		fromDegree = i * segmentDeg + offset;
		toDegree = fromDegree + dashDeg;

		Vec2 origin, destination;
		origin.x = center.x + radius * cos(CC_DEGREES_TO_RADIANS(fromDegree));
		origin.y = center.y + radius * sin(CC_DEGREES_TO_RADIANS(fromDegree));

		destination.x = center.x + radius * cos(CC_DEGREES_TO_RADIANS(toDegree));
		destination.y = center.y + radius * sin(CC_DEGREES_TO_RADIANS(toDegree));

		_canvas->drawLine(origin, destination, Color4F::WHITE);
	}
}

void Orbit::redrawOrbitCircle() {
	redrawOrbitCircle(_orbitRadius, _orbitRotation, _orbitPosition, 30, 15);
}