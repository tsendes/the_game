#include "Block.h"

Block::Block()
{
	//nothing
}

Block::~Block()
{
	al_destroy_bitmap(field);
}

Block::Block(int x, int y)
{
	field = al_load_bitmap("image.png");
	bouncer_x = x;
	bouncer_y = y;

}
void Block::create_block()
{
	field = al_load_bitmap("image.png");
	bouncer_x = 480;
	bouncer_y = 300;
}