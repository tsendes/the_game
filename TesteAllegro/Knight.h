#pragma once
#include "Player.h"
#include "Display.h"
#include "Font.h"
#include <stdio.h>


class Knight : public Player
{
private:
	ALLEGRO_BITMAP * health_bar;
	ALLEGRO_BITMAP* off_bar;
	float cameraX;
public:
	bool block = false;
	Knight();
	~Knight();
	void create_Knight();
	void attack(bool atk_x, bool* key);
	void setCameraX(float cx);
	float getCameraX();
	void drawHUD(Display* display, Font* font);
};
