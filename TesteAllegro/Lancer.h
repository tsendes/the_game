#pragma once
#include "Player.h"

#define SCALE 3

class Lancer : public Player
{
public:
	Lancer();
	~Lancer();
	void create_Lancer();
	void attack(bool* atk, bool* atk_x, bool* key);
};
