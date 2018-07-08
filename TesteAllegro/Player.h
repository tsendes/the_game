#pragma once
#include "Character.h"
#include <string.h>

class Player : public Character
{
protected:
	ALLEGRO_BITMAP * icon;
	char name[30];
	float score;
	bool atk;

public:
	void setName(char* nameN);
	char* getName();
	void setIcon(ALLEGRO_BITMAP* icone);
	ALLEGRO_BITMAP* getIcon();
	void move(int* timer, float* adjust, int SCREEN_W, int SCREEN_H, bool* redraw, bool* exaust, bool* key);
	virtual void attack() { }
	void setScore(float sc);
	float getScore();
	void setAtk(bool a);
	bool getAtk();
	Player();
	~Player();
};
