#include "Mouse.h"

Mouse::Mouse()
{
	mouse = al_load_bitmap("Orc.png");
	bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	bouncer_y = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
}
Mouse::~Mouse()
{
	al_destroy_bitmap(mouse);
}