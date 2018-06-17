#pragma once
#include <allegro5/allegro.h>

const int BOUNCER_SIZE = 32;

class Mouse
{
public:
	ALLEGRO_BITMAP * mouse; //sprite do mouse
	ALLEGRO_BITMAP * undead; //sprite do mouse
	ALLEGRO_BITMAP * night_elf; //sprite do mouse
	ALLEGRO_BITMAP * orc; //sprite do mouse
	float bouncer_x; //local de inicializa�ao
	float bouncer_y; //local de inicializa�ao
	Mouse();
	~Mouse();
	void create_mouse();
};