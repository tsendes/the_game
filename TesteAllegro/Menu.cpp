#include "Menu.h"

Menu::Menu()
{
	create_menu();
}
Menu::~Menu()
{
	al_destroy_bitmap(menu_picture);
}
void Menu::create_menu()
{
	menu_picture = al_load_bitmap("Desert.png");
}
void Menu::setMenu_picture(ALLEGRO_BITMAP* picture)
{
	menu_picture = picture;
}
ALLEGRO_BITMAP* Menu::getMenu_picture()
{
	return menu_picture;
}