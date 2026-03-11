#include "Meteorite.h"

Meteorite* Meteorite::createSpecific(int typeId) {
	Meteorite* ret = Meteorite::create();

	switch (typeId) {
	default:
	case 1: // add more types
	case 2:
	case 3:
	case 4:
	case 5:
		ret->setTexture("CloseNormal.png");
		break;
	}

	return ret;
}


bool Meteorite::init() {
	if (!OrbitObject::init()) {
		return false;
	}

	return true;
}