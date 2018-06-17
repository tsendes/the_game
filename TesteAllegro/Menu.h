#pragma once
#include "Game.h"
#include <allegro5/allegro.h>

class Menu
{
private:
	ALLEGRO_BITMAP * menu_picture;
public:
	Menu();
	~Menu();
	void create_menu();
	void setMenu_picture(ALLEGRO_BITMAP* picture);
	ALLEGRO_BITMAP* getMenu_picture();
};