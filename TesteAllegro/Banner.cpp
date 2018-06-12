#include "Banner.h"

Banner::Banner():
	Player()
{
	
}
Banner::~Banner()
{

}
void Banner::create_Banner()
{
	field = al_load_bitmap("Walk_Sprite_Banner.png");
	cont = 0;
	coluna = 0;
	larg = 29; // padronizar esses parametros para todas as sprites
	alt = 60;
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 2;
	bouncer_y = 766 - 65 - alt * 3;
	pos_i = 766 - 65 - alt * 3;
}

void Banner::attack(bool* atk, bool* atk_x)
{
	if (*atk == false || atk_x == false || *atk == true || *atk_x == true)
	{
		al_destroy_bitmap(field);
		field = al_load_bitmap("Walk_Sprite_Banner.png");
		al_draw_scaled_bitmap(field, x_atual, y_atual, larg, alt, bouncer_x, bouncer_y, larg * 3, alt * 3, 0);
	}
	// nada acontece feijoada
}
