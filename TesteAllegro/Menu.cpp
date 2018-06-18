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
