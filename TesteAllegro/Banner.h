#pragma once
#include "Player.h"

class Banner : public Player
{
public:
	bool is_present;
	float buff;

	Banner();
	~Banner();
	void create_Banner();
	void move(int* timer, float* adjust, int SCREEN_W, int SCREEN_H, bool* redraw, bool* exaust);
};