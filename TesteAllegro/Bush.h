#pragma once
#include "Object.h"
class Bush : public Object
{
private:
	ALLEGRO_BITMAP * view;

public:
	Bush();
	~Bush();
	void createBush();
};