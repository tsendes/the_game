#pragma once
#include <allegro5/allegro.h>

class Block
{
public:
	ALLEGRO_BITMAP * block;
	ALLEGRO_BITMAP * desert;
	ALLEGRO_BITMAP * forest;
	ALLEGRO_BITMAP * boss;
	float bouncer_x; //local de inicializaçao
	float bouncer_y; //local de inicializaçao

	Block(int x, int y);
	Block();
	~Block();
	void create_field(int x, int y = 0);

};