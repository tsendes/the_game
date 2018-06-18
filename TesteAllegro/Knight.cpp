#include "Knight.h"

Knight::Knight():
	Player()
{
	create_Knight();
}

Knight::~Knight()
{
	al_destroy_bitmap(walk_sprite);
	al_destroy_bitmap(attack_sprite);
}
void Knight::create_Knight()
{
	walk_sprite = al_load_bitmap("Walk_Sprite_Knight.png");
	field = walk_sprite;
	attack_sprite = al_load_bitmap("Attack_Sprite_Knight.png");
	icon = al_load_bitmap("Icon_Knight.png");
	cont = 0;
	coluna = 0;
	larg = 20; // padronizar esses parametros para todas as sprites
	alt = 38; 
	x_atual = 0;
	y_atual = 0;
	x_atk = 0;
	y_atk = 0;
	coluna_atk = 0;
	larg_atk = alt_atk = 38;
	count_atk = 0;
	bouncer_x = 25 * SCALE + 23 * SCALE;
	bouncer_y = 700 - alt * SCALE;
	pos_i = 700 - alt * SCALE;
	left = false;
	health = 100;
	is_present = true;
	damage = 50;
}

void Knight::attack(bool* atk, bool* atk_x, bool* key)
{
	if (*atk == true && *atk_x == false) //Atk Knight
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
}