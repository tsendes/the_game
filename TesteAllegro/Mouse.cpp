#include "Mouse.h"

Mouse::Mouse()
{
	//nothing
}
Mouse::~Mouse()
{
	al_destroy_bitmap(mouse);
}
void Mouse::create_mouse()
{
	mouse = al_load_bitmap("Undead.png");
	bouncer_x = 1366 / 2.0 - BOUNCER_SIZE / 2.0;
	bouncer_y = 1366 / 2.0 - BOUNCER_SIZE / 2.0;
}