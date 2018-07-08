	#pragma once
#include "Enemy.h"
#include "Knight.h"
#include "Lancer.h"

class Boss : public Enemy
{
private:
	//algo
	float damage_ult;
	ALLEGRO_BITMAP* ult_sprite;
public:
	Boss();
	~Boss();
	void create_Boss();
	void move(Knight* knight, Lancer* lancer);
	void boss_Ult();
	void attackEnemy();
	void moveEnemy(float x, float y);
	void setDamage_Ult(float dmg);
	float getDamage_Ult();
	void setUlt_sprite(ALLEGRO_BITMAP* sp);
	ALLEGRO_BITMAP* getUlt_sprite();
};