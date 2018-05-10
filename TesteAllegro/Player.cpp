#include "Player.h"

Player::Player()
{
	//nadegas
}

Player::~Player()
{
	al_destroy_bitmap(field);
}

Player::Player(int x, int y)
{
	field = al_load_bitmap("Walk_Sprite_Knight.png");
	bouncer_x = x;
	bouncer_y = y;

}
void Player::create_player()
{
	field = al_load_bitmap("Walk_Sprite_Knight.png");
	cont = 0;
	coluna = 0;
	larg = 20;
	alt = 35;
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 2;
	bouncer_y = 766/2;
}