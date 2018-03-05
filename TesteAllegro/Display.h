#pragma once
#include <allegro5/allegro.h>

extern const int SCREEN_W;
extern const int SCREEN_H;

class Display
{
	public:
		ALLEGRO_DISPLAY *display; //telinha do jogo
		Display();
		~Display();
};