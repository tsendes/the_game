#pragma once
#include "Enemy.h"

#define SPEED 3.0
#define LIMIT 75
#define HEALTH_HUMANOID 100
#define DMG_HUMANOID 25

class Humanoid : public Enemy
{
protected:
	float idleP;
	float idleN;
public:
	Humanoid();
	~Humanoid();
	void moveEnemy(float x, float y);
	//virtual void attack();
};
