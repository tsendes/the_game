#include "Bush.h"

Bush::Bush()
{

}
Bush::~Bush()
{

}
void Bush::createBush()
{
	view = al_load_bitmap("Bush.png");
	bouncer_x = 800;
	bouncer_y = 766 - 90 * 3;
	larg = 80;
	alt = 100;
	health = 20;
	is_present = true;
}