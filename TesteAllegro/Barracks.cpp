#include "Barracks.h"

Barracks::Barracks()
{
	view = al_load_bitmap("Desert_Barracks.png");
	bouncer_x = 1600;
	bouncer_y = 766 - 90 * 3;
	larg = 175;
	alt = 110;
}
Barracks::~Barracks()
{

}
void Barracks::createBarracks()
{
	view = al_load_bitmap("Desert_Barracks.png");
	bouncer_x = 600;
	bouncer_y = 766 - 120 * 2;
	larg = 175;
	alt = 110;
	health = 20;
	is_present = true;
}