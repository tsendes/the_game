#pragma once
#include "Character.h"

class Enemy : public Character
{
protected:
	char name[30];
	int invert;
	float enemy_score;
	

public:
	Enemy();
	~Enemy();

	virtual void moveEnemy(float x, float y) {}
	virtual void attackEnemy() { };
	bool hasVision(float vision);
	float getEnemy_score();
};
