#pragma once
#include <allegro5/allegro.h>

class Block
{
public:
	ALLEGRO_BITMAP * block;
	ALLEGRO_BITMAP * desert;
	ALLEGRO_BITMAP * forest;
	ALLEGRO_BITMAP * boss;
	float bouncer_x; //local de inicializa�ao
	float bouncer_y; //local de inicializa�ao

	Block(int x, int y);
	Block();
	~Block();
	void create_field(int x, int y = 0);

};