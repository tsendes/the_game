#pragma once
#include "Entity.h"
#include "Knight.h"

class Object : public Entity
{
private:
public:
	ALLEGRO_BITMAP * view;
	Object();
	~Object();
	int count_inv = 60;
	bool invencible = false;
	void create_Object();
	void collide(Knight* knight);
};