#pragma once
#include "Player.h"

class Enemy : public Character
{
protected:
	char name[30];
	int invert;
public:
	Enemy();
	~Enemy();

	virtual void moveEnemy(float x, float y) {}
	virtual void attackEnemy() = 0;
	bool has_vision(float vision);
};
