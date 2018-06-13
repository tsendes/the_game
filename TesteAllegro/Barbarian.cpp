#include "Barbarian.h"

Barbarian::Barbarian()
{

}

Barbarian::~Barbarian()
{

}
void Barbarian::create_Barbarian()
{
	field = al_load_bitmap("Enemy_Barbarian_Walk.png");
	cont = 0;
	coluna = 0;
	larg = 24; // padronizar esses parametros para todas as sprites
	alt = 39;
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 1000;
	bouncer_y = pos_i = 766 - 65 - alt * 3;
	invert = -1;
	idleP = bouncer_x + LIMIT;
	idleN = bouncer_x - LIMIT;
}

void Barbarian::moveEnemy(float x, float y)
{
	int vision = x - bouncer_x;
	if (vision < 0)
		vision *= -1;
	if (has_vision(vision))
	{
		if (x > bouncer_x)
		{
			bouncer_x += SPEED;
			idleN += SPEED;
			idleP += SPEED;
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
		else if (x < bouncer_x)
		{
			bouncer_x -= SPEED;
			idleN -= SPEED;
			idleP -= SPEED;
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
	}
	else if (!has_vision(vision))
	{
		bouncer_x += SPEED / 2 * invert;
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
		if (bouncer_x < idleN || bouncer_x > idleP)
		{
			invert *= -1;
		}

	}
}
void Barbarian::attackEnemy()
{

}