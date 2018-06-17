#include "Boss.h"

#define SPEED 5.0
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
	alt = 54;
	cont = 0;
	coluna = 0;
	x_atual = 0;
	y_atual = 0;
	x_atk = 0;
	y_atk = 0;
	coluna_atk = 0;
	larg_atk = alt_atk = 60;
	count_atk = 0;
	bouncer_x = 950;
	bouncer_y = 650 - alt * SCALE;
	pos_i = 736 - alt * SCALE;
	left = false;
	damage = 100;
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

void Boss::moveEnemy(float x, float y)
{
	int vision = x - bouncer_x;
	if (vision < 0)
		vision *= -1;
	if (hasVision(vision))
	{
		if (x > bouncer_x)
		{
			bouncer_x += SPEED;
			idleN += SPEED;
			idleP += SPEED;
			cont++;
			left = true;
			if (cont == 10)
			{
				cont = 0;
				coluna++;
				x_atual += larg;

				if (coluna >= 2) //cuidado
				{
					coluna = 0;
					x_atual = 0;
				}
			}
		}
		else if (x < bouncer_x)
		{
			bouncer_x -= SPEED;
			idleN -= SPEED;
			idleP -= SPEED;
			cont++;
			left = false;
			if (cont == 8)
			{
				cont = 0;
				coluna++;
				x_atual += larg;

				if (coluna >= 2) //cuidado
				{
					coluna = 0;
					x_atual = 0;
				}
			}
		}
	}
	else if (!hasVision(vision))
	{
		bouncer_x += SPEED / 2 * invert;
		cont++;
		if (cont == 10)
		{
			cont = 0;
			coluna++;
			x_atual += larg;

			if (coluna >= 2) //cuidado
			{
				coluna = 0;
				x_atual = 0;
			}
		}
		if (bouncer_x <= idleN || bouncer_x >= idleP)
		{
			invert *= -1;
			if (bouncer_x == idleP)
				left = false;
			else if (bouncer_x == idleN)
				left = true;
		}

	}
}