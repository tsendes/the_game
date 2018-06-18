#pragma once
#include <allegro5/allegro.h>
#include "Object.h"

class Block : public Object
{
public:
	ALLEGRO_BITMAP * block;
	ALLEGRO_BITMAP * desert;
	ALLEGRO_BITMAP * forest;
	ALLEGRO_BITMAP * boss;

	Block();
	~Block();
	void create_field(int x, int y = 0);

};