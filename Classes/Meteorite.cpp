#include "Meteorite.h"

Meteorite* Meteorite::createSpecific(int typeId) {
	Meteorite* ret = Meteorite::create();

	switch (typeId) {
	default:
	case 1:
		ret->setSpriteFrame("SO_Meteorite_1.png");
		break;
	case 2:
		ret->setSpriteFrame("SO_Meteorite_2.png");
		break;
	case 3:
		ret->setSpriteFrame("SO_Meteorite_3.png");
		break;
	case 4:
		ret->setSpriteFrame("SO_Meteorite_4.png");
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