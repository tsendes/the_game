#pragma once
#include "Player.h"

class Lancer : public Player
{
public:
	Lancer();
	~Lancer();
	void create_Lancer();
	void move(int* timer, float* adjust, int SCREEN_W, int SCREEN_H, bool* redraw, bool* exaust);
	void attack(bool* atk, bool* atk_x);
};
