#include "Rock.h"

Rock::Rock()
{

}
Rock::~Rock()
{

}
void Rock::createRock()
{
	view = al_load_bitmap("Rock.png");
	bouncer_x = 1500;
	bouncer_y = 766 - 90 * 3;
	larg = 80;
	alt = 96;
	health = 20;
	is_present = true;

}