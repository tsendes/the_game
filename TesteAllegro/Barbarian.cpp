#include "Barbarian.h"

Barbarian::Barbarian()
{

}

Barbarian::~Barbarian()
{

}
void Barbarian::create_Barbarian()
{
	walk_sprite = al_load_bitmap("Enemy_Barbarian_Walk.png");
	attack_sprite = al_load_bitmap("Enemy_Barbarian_Attack.png");
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
	left = false;
	health = HEALTH_HUMANOID;
	damage = DMG_HUMANOID;
}

void Barbarian::attackEnemy()
{

}