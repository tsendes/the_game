#pragma once
#include "Enemy.h"

#define SPEED 2.0
class Ghost : public Enemy
{
public:
	Ghost();
	~Ghost();
	void create_Ghost();
	void moveEnemy(float x, float y);
	void attackEnemy() { }
	void move() { }
	void attack() { }
};
