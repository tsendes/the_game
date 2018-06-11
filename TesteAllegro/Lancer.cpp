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
	bouncer_x = 2;
	bouncer_y = 766 - 30 - alt * 3;
	pos_i = 766 - 30 - alt * 3;
}