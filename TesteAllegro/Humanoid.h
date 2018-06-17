#pragma once
#include "Enemy.h"

#define SPEED 3.0
#define HEALTH_HUMANOID 100
#define DMG_HUMANOID 25

class Humanoid : public Enemy
{
public:
	Humanoid();
	~Humanoid();
	void moveEnemy(float x, float y);
	//virtual void attack();
};
