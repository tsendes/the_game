#pragma once
#include "Enemy.h"

#define SPEED 3.0
#define LIMIT 75

class Humanoid : public Enemy
{
protected:
	float idleP;
	float idleN;
public:
	Humanoid();
	~Humanoid();
	//virtual void move();
	//virtual void attack();
};
