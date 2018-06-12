#pragma once
#include "Player.h"

class Enemy : public Character
{
protected:
	char name[30];
	bool has_vision;
public:
	Enemy();
	~Enemy();

	virtual void attackEnemmy() = 0;
};
