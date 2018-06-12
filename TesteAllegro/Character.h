#pragma once
#include "Entity.h"


class Character : public Entity
{
protected:
	int larg_atk;
	int alt_atk;
	int x_atk; //posiçao x de ataque no mapa sprite
	int y_atk; // posição y de ataque no mapa sprite

	int damage;
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

	//virtual void move() = 0;
	virtual void attack(bool* atk, bool* atk_x) = 0;
	
};