#pragma once
#include "Character.h"
#include <string.h>

class Player : public Character
{
private:
	char name[30];
public:
	void setName(char* nameN);
	char* getName();
	//virtual void move();
	//virtual void attack();
	Player();
	~Player();
};
