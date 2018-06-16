#include "Banner.h"

Banner::Banner():
	Player()
{
	
}
Banner::~Banner()
{
	al_destroy_bitmap(walk_sprite);
}
void Banner::create_Banner()
{
	walk_sprite = al_load_bitmap("Walk_Sprite_Banner.png");
	cont = 0;
	coluna = 0;
	larg = 29; // padronizar esses parametros para todas as sprites
	alt = 60;
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 2;
	bouncer_y = 766 - 65 - alt * 3;
	pos_i = 766 - 65 - alt * 3;
	left = false;
}

void Banner::attack(bool* atk, bool* atk_x, bool* key)
{
	// nada acontece feijoada
}
