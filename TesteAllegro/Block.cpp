#include "Block.h"


void Block::create_field(int x)
{
	block = al_load_bitmap("Desert_Block.png");
	bouncer_x = x + 0;
	bouncer_y = 766 - 80;
}

Block::~Block()
{
	al_destroy_bitmap(block);
}
