#pragma once
#include "Enemy.h"

class Ghost : public Enemy
{
protected:
	//algo
public:
	Ghost();
	~Ghost();
	void create_Ghost();
	void move();
};
