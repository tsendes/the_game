#pragma once
#include "Entity.h"

#define SCALE 3

class Character : public Entity
{
protected:
	ALLEGRO_BITMAP * walk_sprite;
	ALLEGRO_BITMAP * attack_sprite;
	int larg_atk;
	int alt_atk;
	int x_atk; //posiçao x de ataque no mapa sprite
	int y_atk; // posição y de ataque no mapa sprite
	bool left = false;
	float damage;
	bool invencible;
	int count_inv;

public:
	int count_atk;
	int coluna_atk;
	Character();
	~Character();
	void setLarg_atk(int larg_atkN);
	int getLarg_atk();
	void setAlt_atk(int alt_atkN);
	int getAlt_atk();
	void setX_atk(int x_atkN);
	int getX_atk();
	void setY_atk(int y_atkN);
	int getY_atk();
	void setLeft(bool lf);
	bool getLeft();
	void setDamage(float dmg);
	float getDamage();
	ALLEGRO_BITMAP* getWalk_sprite();
	ALLEGRO_BITMAP* getAttack_sprite();
	void setInvencible(bool set);
	bool getInvencible();
	void setCount_inv(int i);
	int getCount_inv();
	virtual void move() { }

};