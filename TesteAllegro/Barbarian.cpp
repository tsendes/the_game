#include "Barbarian.h"

Barbarian::Barbarian()
{
	create_Barbarian();
}

Barbarian::~Barbarian()
{

}
void Barbarian::create_Barbarian()
{
	walk_sprite = al_load_bitmap("Enemy_Barbarian_Walk.png");
	field = walk_sprite;
	attack_sprite = al_load_bitmap("Enemy_Barbarian_Attack.png");
	cont = 0;
	coluna = 0;
	larg = 24; // padronizar esses parametros para todas as sprites
	alt = 39;
	x_atual = 0;
	y_atual = 0;
	count_atk = 0;
	larg_atk = alt_atk = 38;
	x_atk = 0;
	y_atk = 0;
	bouncer_x = 1000;
	bouncer_y = pos_i = 700 - alt * 3;
	invert = -1;
	idleP = bouncer_x + LIMIT;
	idleN = bouncer_x - LIMIT;
	left = false;
	health = HEALTH_HUMANOID;
	damage = DMG_HUMANOID;
	is_present = true;
}

void Barbarian::attackEnemy()
{
	count_atk++;
	if (count_atk == 6)
	{
		count_atk = 0;
		coluna_atk++;
		x_atk += larg_atk;
		if (coluna_atk >= 3)
		{
			coluna_atk = 0;
			x_atk = 0;
		}
	}
}