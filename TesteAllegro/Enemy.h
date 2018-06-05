#pragma once
#include "Player.h"

class Enemy : public Player
{
public:
	Enemy();
	~Enemy();
	char* name[30];
	int life;
	int damage;
	
};
