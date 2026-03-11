#include "Orbit.h"

USING_NS_CC;

const float Orbit::ROTATE_VELOCITY = 2.f;

Orbit::Orbit() {
	_orbitRotation = 0.f;
	_canvas = NULL;
}

bool Orbit::init() {
	if (!Node::init()) {
		return false;
	}

	setIgnoreAnchorPointForPosition(false);
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

	const float reversedSpeed = false;
	const float speedMultiplier = 1.f;
	const float orbitRotateSpeed = ROTATE_VELOCITY * speedMultiplier * deltaTime * (reversedSpeed ? -1 : 1);
	const float newOrbitRotation = getOrbitRotation() + orbitRotateSpeed;
	
	setOrbitRotation(newOrbitRotation);
}

void Orbit::setOrbitRotation(float rotation) {
	if (_orbitRotation != rotation) {

		const float orbitRadius = 300.f;
		redrawOrbitCircle(orbitRadius, _orbitRotation, Vec2(0,0), 20, 40);

		_orbitRotation = rotation;
	}
}

float Orbit::getOrbitRotation() const {
	return _orbitRotation;
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
