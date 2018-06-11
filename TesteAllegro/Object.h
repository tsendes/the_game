#pragma once
#include "Entity.h"

class Object : public Entity
{
private:
	int damage_obj;
	int armor;
public:
	Object();
	~Object();
	void create_Object();
	void move();
	void setDamage_Obj(int dmg);
	int getDamage_Obgj();
	void setArmor(int arm);
	int getArmor();
};