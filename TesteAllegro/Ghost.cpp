#include "Ghost.h"


Ghost::Ghost()
{

}

Ghost::~Ghost()
{

}

void Ghost::create_Ghost()
{
	field = al_load_bitmap("Enemy_Ghost.png");
	cont = 0;
	coluna = 0;
	larg = 22; // padronizar esses parametros para todas as sprites
	alt = 20;
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 600;
	bouncer_y = pos_i = 766 - 260 - alt * 3;
	invert = -1;
	health = HEALTH_GHOST;
	damage = DMG_GHOST;
}

void Ghost::moveEnemy(float x, float y)
{
	int vision = x - bouncer_x;
	if (vision < 0)
		vision *= -1;
	if (hasVision(vision))
	{
		if (x > bouncer_x)
		{
			bouncer_x += SPEED;
		}
		else if (x < bouncer_x)
		{
			bouncer_x -= SPEED;
		}
		if (y < bouncer_y)
		{
			bouncer_y -= SPEED;
			pos_i -= SPEED;
		}
		else if(y > bouncer_y)
		{
			bouncer_y += SPEED;
			pos_i += SPEED;
		}
	}
	else if(!hasVision(vision))
	{
		bouncer_y += SPEED/2 * invert;
		if(bouncer_y <= pos_i / 1.12 || bouncer_y >= pos_i)
			invert *= -1;
	}
}