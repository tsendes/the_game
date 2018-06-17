#include "Mouse.h"

Mouse::Mouse()
{
	create_mouse();
}
Mouse::~Mouse()
{
	al_destroy_bitmap(mouse);
}
void Mouse::create_mouse()
{
	al_install_mouse(); //inicializa o addon de Mouse, checar propriedades do projeto -> Allegro 5 -> Add-Ons
	undead = al_load_bitmap("Undead.png");
	orc = al_load_bitmap("Orc.png");
	night_elf = al_load_bitmap("Night-Elf.png");
	mouse = undead;
	bouncer_x = 1366 / 2.0 - BOUNCER_SIZE / 2.0;
	bouncer_y = 1366 / 2.0 - BOUNCER_SIZE / 2.0;
}