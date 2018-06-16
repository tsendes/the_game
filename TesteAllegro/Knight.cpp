#include "Knight.h"

Knight::Knight():
	Player()
{

}

Knight::~Knight()
{
	al_destroy_bitmap(walk_sprite);
	al_destroy_bitmap(attack_sprite);
}
void Knight::create_Knight()
{
	walk_sprite = al_load_bitmap("Walk_Sprite_Knight.png");
	attack_sprite = al_load_bitmap("Attack_Sprite_Knight.png");
	cont = 0;
	coluna = 0;
	larg = 20; // padronizar esses parametros para todas as sprites
	alt = 38; 
	x_atual = 0;
	y_atual = 0;
	x_atk = 0;
	y_atk = 0;
	coluna_atk = 0;
	larg_atk = 38;
	alt_atk = 38;
	count_atk = 0;
	bouncer_x = 25 * 3 + 23 * 3;
	bouncer_y = 766 - 65 - alt * 3;
	pos_i = 766 - 65 - alt * 3;
	left = false;
	health = 100;
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