#include "Block.h"

Block::Block()
{
	field = al_load_bitmap("Human.png");
	bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	bouncer_y = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
}

Block::~Block()
{
	al_destroy_bitmap(field);
}