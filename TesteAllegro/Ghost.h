#pragma once
#include "Enemy.h"

#define SPEED_GHOST 2.0
#define HEALTH_GHOST 15
#define DMG_GHOST 50
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
