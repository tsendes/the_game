#include "Lancer.h"
Lancer::Lancer()
{

}

Lancer::~Lancer()
{
	al_destroy_bitmap(field);
}
void Lancer::create_Lancer()
{
	field = al_load_bitmap("Walk_Sprite_Lancer.png");
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
	bouncer_y = 766 - 30 - alt * 3;
	pos_i = 766 - 30 - alt * 3;
}

void Lancer::attack(bool* atk, bool* atk_x)
{
	if (*atk_x == true && *atk == false) //atk Lancer
	{
		al_destroy_bitmap(field);
		field = al_load_bitmap("Attack_Sprite_Lancer.png");
		al_draw_scaled_bitmap(field, x_atk, y_atk, larg_atk, alt_atk, bouncer_x, bouncer_y, larg_atk * 3, alt_atk * 3, 0);
		count_atk++;
		if (count_atk == 20)
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