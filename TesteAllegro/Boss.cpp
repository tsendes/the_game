#include "Boss.h"

Boss::Boss()
{
	create_Boss();
}

Boss::~Boss()
{

}

void Boss::create_Boss()
{
	walk_sprite = al_load_bitmap("Boss_Walk_Sprite.png");
	field = walk_sprite;
	attack_sprite = al_load_bitmap("Boss_Attack_Sprite.png");
	ult_sprite = al_load_bitmap("Boss_Ultimate.png");
	larg = 50;
	alt = 53;
	//falta coisas para iniciar
}

void Boss::boss_Ult()
{

}

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