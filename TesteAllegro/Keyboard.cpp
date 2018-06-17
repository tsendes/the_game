#include "Keyboard.h"

Keyboard::Keyboard()
{
	create_keyboard();
}
Keyboard::~Keyboard()
{
	//imagine algo legal aqui
}
void Keyboard::create_keyboard()
{
	al_install_keyboard(); //inicializa o addon de Keyboard, checar propriedades do projeto -> Allegro 5 -> Add-Ons
}