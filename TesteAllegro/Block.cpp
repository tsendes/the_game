#include "Block.h"

Block::Block()
{
	field = al_load_bitmap("Block.png");
	bouncer_x = 1286;
	bouncer_y = 688;
}

Block::~Block()
{
	al_destroy_bitmap(field);
}

Block::Block(int x, int y)
{
	field = al_load_bitmap("Block.png");
	bouncer_x = x;
	bouncer_y = y;

}