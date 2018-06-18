#pragma once
#include "Character.h"
#include <string.h>

class Player : public Character
{
protected:
	ALLEGRO_BITMAP * icon;
	char name[30];
	float score;
public:
	void setName(char* nameN);
	char* getName();
	void setIcon(ALLEGRO_BITMAP* icone);
	ALLEGRO_BITMAP* getIcon();
	void move(int* timer, float* adjust, int SCREEN_W, int SCREEN_H, bool* redraw, bool* exaust, bool* key);
	virtual void attack(bool* atk, bool* atk_x, bool* key) = 0;
	void setScore(float sc);
	float getScore();
	Player();
	~Player();
};
