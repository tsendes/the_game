#include "Banner.h"

Banner::Banner():
	Player()
{
	
}
Banner::~Banner()
{

}
void Banner::create_Banner()
{
	field = al_load_bitmap("Walk_Sprite_Banner.png");
	cont = 0;
	coluna = 0;
	larg = 29; // padronizar esses parametros para todas as sprites
	alt = 60;
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 2;
	bouncer_y = 766 - 65 - alt * 3;
	pos_i = 766 - 65 - alt * 3;
}
void Banner::move(int* timer, float* adjust, int SCREEN_W, int SCREEN_H, bool* redraw, bool* exaust)
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
