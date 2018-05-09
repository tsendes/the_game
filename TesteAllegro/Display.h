#pragma once
#include <allegro5/allegro.h>

const int SCREEN_W = 640;
const int SCREEN_H = 320;

class Display
{
public:
	ALLEGRO_DISPLAY *display; //telinha do jogo
	Display();
	~Display();
	void create_display();
};