#include "Tribesman.h"

Tribesman::Tribesman()
{
	create_Tribesman();
}

Tribesman::~Tribesman()
{
	al_destroy_bitmap(walk_sprite);
	al_destroy_bitmap(attack_sprite);
}
void Tribesman::create_Tribesman()
{
	walk_sprite = al_load_bitmap("Enemy_Tribesman_Walk.png");
	field = walk_sprite;
	attack_sprite = al_load_bitmap("Enemy_Tribesman_Attack.png");
	cont = 0;
	coluna = 0;
	larg = alt = 38;
	x_atual = 0;
	y_atual = 0;
	count_atk = 0;
	larg_atk = 38;
	alt_atk = 23;
	x_atk = 0;
	y_atk = 0;
	bouncer_x = 800;
	bouncer_y = pos_i = 736 - alt * SCALE;
	invert = -1;
	idleP = bouncer_x + LIMIT;
	idleN = bouncer_x - LIMIT;
	left = false;
	health = HEALTH_HUMANOID;
	damage = DMG_HUMANOID;
	is_present = true;
}

void Tribesman::attackEnemy()
{
	count_atk++;
	if (count_atk == 10)
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