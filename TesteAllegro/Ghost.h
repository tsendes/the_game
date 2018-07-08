#pragma once
#include "Enemy.h"
#include "Knight.h"
#include "Lancer.h"

#define SPEED_GHOST 2.0
#define HEALTH_GHOST 5
#define DMG_GHOST 4
class Ghost : public Enemy
{
public:
	Ghost();
	~Ghost();
	void create_Ghost();
	void moveEnemy(float x, float y);
	void attackEnemy() { }
	void move(Knight* knight, Lancer* lancer);
	void attack() { }
};
