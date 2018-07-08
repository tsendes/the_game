#pragma once
#include "Enemy.h"
#include "Knight.h"
#include "Lancer.h"

#define SPEED 3.0
#define HEALTH_HUMANOID 10
#define DMG_HUMANOID 2

class Humanoid : public Enemy
{
public:
	Humanoid();
	~Humanoid();
	void moveEnemy(float x, float y);
	void move(Knight* knight, Lancer* lancer);
};
