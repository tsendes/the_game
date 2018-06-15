#pragma once
#include "Character.h"
#include <string.h>

class Player : public Character
{
protected:
	char name[30];
	
public:
	void setName(char* nameN);
	char* getName();
	void move(int* timer, float* adjust, int SCREEN_W, int SCREEN_H, bool* redraw, bool* exaust, bool* key);
	virtual void attack(bool* atk, bool* atk_x, bool* key) = 0;
	Player();
	~Player();
};
