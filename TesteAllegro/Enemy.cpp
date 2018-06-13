#include "Enemy.h"
Enemy::Enemy()
{
	field = al_load_bitmap("Enemy_Ghost.png");
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
	bouncer_x = 25 * 3;
	bouncer_y = 766 - 65 - alt * 3;
	pos_i = 766 - 65 - alt * 3;
}
Enemy::~Enemy()
{

}

bool Enemy::has_vision(float vision)
{
	if (vision <= 1366 / 3)
	{
		return true;
	}
	else
		return false;
}