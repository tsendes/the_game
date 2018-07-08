#include "Character.h"


Character::Character()
{
	
}

Character::~Character()
{

}
void Character::setLarg_atk(int larg_atkN)
{
	larg_atk = larg_atkN;
}
int Character::getLarg_atk()
{
	return larg_atk;
}
void Character::setAlt_atk(int alt_atkN)
{
	alt_atk = alt_atkN;
}
int Character::getAlt_atk()
{
	return alt_atk;
}
void Character::setX_atk(int x_atkN)
{
	x_atk = x_atkN;
}
int Character::getX_atk()
{
	return x_atk;
}
void Character::setY_atk(int y_atkN)
{
	y_atk = y_atkN;
}
int Character::getY_atk()
{
	return y_atk;
}

void Character::setLeft(bool lf)
{
	left = lf;
}
bool Character::getLeft()
{
	return left;
}

void Character::setDamage(float dmg)
{
	damage = dmg;
}
float Character::getDamage()
{
	return damage;
}
ALLEGRO_BITMAP* Character::getWalk_sprite()
{
	return walk_sprite;
}
ALLEGRO_BITMAP* Character::getAttack_sprite()
{
	return attack_sprite;
}
void Character::setInvencible(bool set)
{
	invencible = set;
}
bool Character::getInvencible()
{
	return invencible;
}
void Character::setCount_inv(int i)
{
	count_inv = i;
}
int Character::getCount_inv()
{
	return count_inv;
}