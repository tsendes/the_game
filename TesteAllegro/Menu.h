#pragma once
#include <allegro5/allegro.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

class Game;

class Menu
{
private:
	ALLEGRO_BITMAP * menu_picture;
public:
	Menu();
	~Menu();
	void drawMenu(Game* game);
	void buildRanking(float score);
};