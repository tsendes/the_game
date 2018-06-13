#pragma once
#include "Player.h"

class Knight : public Player
{
public:
	Knight();
	~Knight();
	void create_Knight();
	void attack(bool* atk, bool* atk_x, bool* key);
};
