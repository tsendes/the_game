#pragma once
#include <allegro5/allegro.h>

const int BOUNCER_SIZE = 32;

class Mouse
{
public:
	ALLEGRO_BITMAP * mouse; //sprite do mouse
	float bouncer_x; //local de inicializaçao
	float bouncer_y; //local de inicializaçao
	Mouse();
	~Mouse();
	void create_mouse();
};