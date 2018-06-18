#pragma once
#include "Object.h"

class Barracks : public Object
{
private:
	ALLEGRO_BITMAP * view;

public:
	Barracks();
	~Barracks();
	void createBarracks();
};