#pragma once
#include "Enemy.h"
class Boss : public Enemy
{
private:
	//algo
	float damage_ult;
	int charge_bar;
	ALLEGRO_BITMAP* ult_sprite;
public:
	Boss();
	~Boss();
	void create_Boss();
	//void move();
	void boss_Ult();
	void attackEnemy() {}
	void moveEnemy(float x, float y);
	void setDamage_Ult(float dmg);
	float getDamage_Ult();
	void setCharge_Bar(int bar);
	int getCharge_Bar();
};