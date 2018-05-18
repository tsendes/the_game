#include "Knight.h"

Knight::Knight()
{

}

Knight::~Knight()
{
	al_destroy_bitmap(field);
}
void Knight::create_Knight()
{
	field = al_load_bitmap("Walk_Sprite_Knight.png");
	cont = 0;
	coluna = 0;
	larg = 20; //20
	alt = 35; //35
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 25 * 3;
	bouncer_y = 766 - 65 - alt * 3;
}