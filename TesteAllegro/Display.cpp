#include "Display.h"

Display::Display()
{
	//nada
}
Display::~Display()
{
	al_destroy_display(display);
}

void Display::create_display()
{
	display = al_create_display(SCREEN_W, SCREEN_H);
}