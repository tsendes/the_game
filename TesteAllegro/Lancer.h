#pragma once
#include "Player.h"

class Lancer : public Player
{
public:
	Lancer();
	~Lancer();
	void create_Lancer();
	void attack(bool atk_x, bool* key);
};
