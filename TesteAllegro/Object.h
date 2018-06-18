#pragma once
#include "Entity.h"

class Object : public Entity
{
private:
public:
	Object();
	~Object();
	void create_Object();
	void move();
};