#pragma once
#include "Humanoid.h"



class Tribesman : public Humanoid
{
protected:
	///algo
public:
	Tribesman();
	~Tribesman();
	void create_Tribesman();
	void moveEnemy(float x, float y);
	void attackEnemy();
};