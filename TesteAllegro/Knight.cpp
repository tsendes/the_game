#include "Knight.h"

Knight::Knight():
	Player()
{

}

Knight::~Knight()
{
	al_destroy_bitmap(field);
}
void Knight::create_Knight()
{
	field = al_load_bitmap("Walk_Sprite_Knight.png");
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
}

void Knight::attack(bool* atk, bool* atk_x, bool* key)
{
	if (*atk == true && *atk_x == false) //Atk Knight
	{
		al_destroy_bitmap(field);
		field = al_load_bitmap("Attack_Sprite_Knight.png");
		al_draw_scaled_bitmap(field, x_atk, y_atk, larg_atk, alt_atk, bouncer_x, bouncer_y, larg_atk * 3, alt_atk * 3, key[KEY_LEFT] ? ALLEGRO_FLIP_HORIZONTAL : 0);
		count_atk++;
		if (count_atk == 12)
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