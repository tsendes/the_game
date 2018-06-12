#pragma once
#include "Player.h"

class Knight : public Player
{
public:
	Knight();
	~Knight();
	void create_Knight();
	void move(int* timer, float* adjust, int SCREEN_W, int SCREEN_H, bool* redraw, bool* exaust);
	void attack(bool* atk, bool* atk_x);
};
