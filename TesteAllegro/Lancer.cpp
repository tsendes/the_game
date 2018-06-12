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

void Lancer::move(int* timer, float* adjust, int SCREEN_W, int SCREEN_H, bool* redraw, bool* exaust)
{
	if (key[KEY_UP] && bouncer_y >= 4.0 && *exaust == false)
	{

		*timer += 1;
		if (*timer >= 5)
		{
			*timer = 0;
			*adjust /= 1.5;
		}
		bouncer_y -= 9.8 * (*adjust);
		if (*adjust <= 0.2)
		{
			*exaust = true;
			key[KEY_UP] = false;
			*adjust = 1.0;
			*timer = 0;
		}

	}

	if (key[KEY_LEFT] && bouncer_x >= 4.0)
	{
		bouncer_x -= 7.0;
		cont++;
		
		if (cont == 8)
		{
			cont = 0;
			coluna++;
			x_atual += larg;
			if (coluna >= 4)
			{
				coluna = 0;
				x_atual = 0;
			}
		}
	}

	if (key[KEY_RIGHT] && bouncer_x <= SCREEN_W - 20 * 3/*tamanho do bloco*/ - 4.0)
	{
		bouncer_x += 7.0;
		cont++;
		if (cont == 8)
		{
			cont = 0;
			coluna++;
			x_atual += larg;

			if (coluna >= 4) //cuidado
			{
				coluna = 0;
				x_atual = 0;
			}
		}
	}
	if (bouncer_y < pos_i && !key[KEY_UP])
	{
		*timer += 1;
		if (*timer >= 5)
		{
			*timer = 0;
			*adjust *= 1.5;
		}
		bouncer_y += 9.8 * (*adjust) / 2;
		if (pos_i <= bouncer_y)
		{
			*exaust = false;
			*adjust = 1.0;
			*timer = 0;
		}
		if (pos_i < bouncer_y)
		{
			bouncer_y = pos_i;
		}
	}
	*redraw = true;
}
void Lancer::attack(bool* atk, bool* atk_x)
{
	if (*atk_x == true && *atk == false) //atk Lancer
	{
		al_destroy_bitmap(field);
		field = al_load_bitmap("Attack_Sprite_Lancer.png");
		al_draw_scaled_bitmap(field, x_atk, y_atk, larg_atk, alt_atk, bouncer_x, bouncer_y, larg_atk * 3, alt_atk * 3, 0);
		count_atk++;
		if (count_atk == 8)
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