#include "Display.h"

Display::Display()
{
	display = al_create_display(SCREEN_W, SCREEN_H);
}
Display::~Display()
{
	al_destroy_display(display);
}