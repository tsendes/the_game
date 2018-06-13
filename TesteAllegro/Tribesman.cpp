#include "Tribesman.h"

Tribesman::Tribesman()
{

}

Tribesman::~Tribesman()
{

}
void Tribesman::create_Tribesman()
{
	field = al_load_bitmap("Enemy_Tribesman_Walk.png");
	cont = 0;
	coluna = 0;
	larg = 38; // padronizar esses parametros para todas as sprites
	alt = 38;
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 800;
	bouncer_y = pos_i = 766 - 30 - alt * 3;
	invert = -1;
	idleP = bouncer_x + LIMIT;
	idleN = bouncer_x - LIMIT;
}
void Tribesman::moveEnemy(float x, float y)
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
void Tribesman::attackEnemy()
{

}