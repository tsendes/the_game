#include "Display.h"

Display::Display()
{

	al_init(); //inicializa a allegro
	al_init_image_addon(); //inicializa o addon de Image, checar propriedades do projeto -> Allegro 5 -> Add-Ons 
	create_display();
}
Display::~Display()
{
	al_destroy_display(display);
}

void Display::create_display()
{
	display = al_create_display(SCREEN_W, SCREEN_H);
}