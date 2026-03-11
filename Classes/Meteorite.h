#ifndef __METEORITE_H__
#define __METEORITE_H__

#include "OrbitObject.h"

class Meteorite : public OrbitObject {
public:
	CREATE_FUNC(Meteorite);

	static Meteorite* createSpecific(int typeId);

	bool init() override;
};

#endif //!__METEORITE_H__