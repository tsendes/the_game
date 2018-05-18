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
	larg = 21; //20
	alt = 35; //35
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 2;
	bouncer_y = 766 - 65 - alt * 3;
}