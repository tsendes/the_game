#pragma once
#include <allegro5/allegro.h>

class Block
{
public:
	ALLEGRO_BITMAP * block;
	float bouncer_x; //local de inicializašao
	float bouncer_y; //local de inicializašao

	//Block();
	~Block();
	void create_field(int x, int y = 0);

};