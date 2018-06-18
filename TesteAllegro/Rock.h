#pragma once
#include "Object.h"
class Rock : public Object
{
private:
	ALLEGRO_BITMAP * view;

public:
	Rock();
	~Rock();
	void createRock();
};