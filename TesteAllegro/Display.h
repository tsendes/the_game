#pragma once
#include <allegro5/allegro.h>

class Display
{
public:
	ALLEGRO_DISPLAY *display; //telinha do jogo
	Display();
	~Display();
	void create_display();
	const int SCREEN_W = 1366;
	const int SCREEN_H = 766;
};