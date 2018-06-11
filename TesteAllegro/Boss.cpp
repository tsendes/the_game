#include "Boss.h"

Boss::Boss()
{

}

Boss::~Boss()
{

}

void Boss::create_Boss()
{
	field = al_load_bitmap("Enemy_Boss.png");
}
//void Character::move()
//{
//
//}
void Boss::boss_Ult()
{

}
//void Character::attack()
//{
//
//}
void Boss::setDamage_Ult(float dmg)
{
	damage_ult = dmg;
}
float Boss::getDamage_Ult()
{
	return damage_ult;
}
void Boss::setCharge_Bar(int bar)
{
	charge_bar = bar;
}
int Boss::getCharge_Bar()
{
	return charge_bar;
}