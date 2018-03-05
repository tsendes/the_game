#pragma once
#include <allegro5/allegro.h>

extern const int BOUNCER_SIZE;
extern const int SCREEN_W;
extern const int SCREEN_H;

class Mouse
{
	public:
		ALLEGRO_BITMAP * mouse; //sprite do mouse
		float bouncer_x; //local de inicializašao
		float bouncer_y; //local de inicializašao
		Mouse();
		~Mouse();
};