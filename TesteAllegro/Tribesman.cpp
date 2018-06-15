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
	left = false;
	health = HEALTH_HUMANOID;
	damage = DMG_HUMANOID;
}

void Tribesman::attackEnemy()
{

}