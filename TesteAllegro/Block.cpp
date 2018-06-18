#include "Block.h"

Block::Block()
{
	create_field(0, 0);
}

void Block::create_field(int x, int y)
{
	forest = al_load_bitmap("Forest_Block.png");
	desert = al_load_bitmap("Desert_Block.png");
	boss = al_load_bitmap("Boss_Block.png");
	block = desert;
	bouncer_x = x + 0;
	bouncer_y = 686 - y;
}

Block::~Block()
{
	al_destroy_bitmap(block);
}
