#include "Knight.h"

Knight::Knight():
	Player()
{
	create_Knight();
}

Knight::~Knight()
{
	al_destroy_bitmap(walk_sprite);
	al_destroy_bitmap(attack_sprite);
}
void Knight::create_Knight()
{
	walk_sprite = al_load_bitmap("Walk_Sprite_Knight.png");
	field = walk_sprite;
	attack_sprite = al_load_bitmap("Attack_Sprite_Knight.png");
	icon = al_load_bitmap("Icon_Knight.png");
	cont = 0;
	coluna = 0;
	larg = 20;
	alt = 38; 
	x_atual = 0;
	y_atual = 0;
	x_atk = 0;
	y_atk = 0;
	coluna_atk = 0;
	larg_atk = alt_atk = 38;
	count_atk = 0;
	bouncer_x = 25 * SCALE + 23 * SCALE;
	bouncer_y = 700 - alt * SCALE;
	pos_i = 700 - alt * SCALE;
	left = false;
	health = 100;
	is_present = true;
	damage = 5;
	cameraX = 0;
}

void Knight::attack(bool atk_x, bool* key)
{
	if (atk == true && atk_x == false) //Atk Knight
	{
		count_atk++;
		if (count_atk == 5)
		{
			count_atk = 0;
			coluna_atk++;
			x_atk += larg_atk;
			if (coluna_atk >= 3)
			{
				coluna_atk = 0;
				x_atk = 0;
			}
		}
	}
}
void Knight::setCameraX(float cx)
{
	cameraX = cx;
}
float Knight::getCameraX()
{
	return cameraX;
}
void Knight::drawHUD(Display* display, Font* font)
{
	//health bar
	

	health_bar = al_create_bitmap((80 * getHealth() / 100), 10);
	al_set_target_bitmap(health_bar);
	al_clear_to_color(al_map_rgb(0, 255, 0));
	al_set_target_bitmap(al_get_backbuffer(display->display));
	off_bar = al_create_bitmap(82, 12);
	al_set_target_bitmap(off_bar);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_set_target_bitmap(al_get_backbuffer(display->display));

	char health_counter[5];

	al_draw_bitmap(off_bar, 19, 99, 0);
	al_draw_bitmap(health_bar, 20, 100, 0);
	sprintf_s(health_counter, "%d", getHealth());

	al_destroy_bitmap(health_bar);
	al_destroy_bitmap(off_bar);
	//end of health bar
	al_draw_bitmap(getIcon(), 15, 20, 0);
	al_draw_text(font->font, al_map_rgb(0, 255, 0), 60, 60, ALLEGRO_ALIGN_CENTER, health_counter);
}
