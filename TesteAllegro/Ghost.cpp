#include "Ghost.h"


Ghost::Ghost()
{
	create_Ghost();
}

Ghost::~Ghost()
{
	al_destroy_bitmap(walk_sprite);
}

void Ghost::create_Ghost()
{
	walk_sprite = al_load_bitmap("Enemy_Ghost.png");
	field = walk_sprite;
	cont = 0;
	coluna = 0;
	larg = 22; // padronizar esses parametros para todas as sprites
	alt = 20;
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 600;
	bouncer_y = pos_i = 766 - 260 - alt * SCALE;
	invert = -1;
	health = HEALTH_GHOST;
	damage = DMG_GHOST;
	is_present = true;
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
			bouncer_x += SPEED_GHOST;
		}
		else if (x < bouncer_x)
		{
			bouncer_x -= SPEED_GHOST;
		}
		if (y < bouncer_y)
		{
			bouncer_y -= SPEED_GHOST;
			pos_i -= SPEED_GHOST;
		}
		else if(y > bouncer_y)
		{
			bouncer_y += SPEED_GHOST;
			pos_i += SPEED_GHOST;
		}
	}
	else if(!hasVision(vision))
	{
		bouncer_y += SPEED_GHOST/2 * invert;
		if(bouncer_y <= pos_i / 1.12 || bouncer_y >= pos_i)
			invert *= -1;
	}
}