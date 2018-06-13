#pragma once
#include "Humanoid.h"

class Barbarian : public Humanoid
{
protected:
	///algo
public:
	Barbarian();
	~Barbarian();
	void create_Barbarian();
	void moveEnemy(float x, float y);
	void attackEnemy();
};