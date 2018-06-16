#include "Lancer.h"
Lancer::Lancer()
{
	//walk_sprite = al_load_bitmap("Walk_Sprite_Lancer.png");
	//attack_sprite = al_load_bitmap("Attack_Sprite_lancer");
}

Lancer::~Lancer()
{
	al_destroy_bitmap(walk_sprite);
	al_destroy_bitmap(attack_sprite);
}
void Lancer::create_Lancer()
{
	walk_sprite = al_load_bitmap("Walk_Sprite_Lancer.png");
	attack_sprite = al_load_bitmap("Attack_Sprite_Lancer.png");
	cont = 0;
	coluna = 0;
	larg = 38;
	alt = 38;
	x_atual = 0;
	y_atual = 0;
	x_atk = 0;
	y_atk = 0;
	coluna_atk = 0;
	larg_atk = 38;
	alt_atk = 38;
	count_atk = 0;
	bouncer_x = 23 * 3;
	bouncer_y = 766 - 30 - alt * SCALE;
	pos_i = 766 - 30 - alt * 3;
	left = false;
}

void Lancer::attack(bool* atk, bool* atk_x, bool* key)
{
	if (*atk_x == true && *atk == false) //atk Lancer
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
}