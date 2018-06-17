#include "Font.h"

Font::Font()
{
}
Font::~Font()
{
	al_destroy_font(font);
}
void Font::create_font()
{
	al_init_font_addon(); //inicializa o addon de Fonts, checar propriedades do projeto -> Allegro 5 -> Add-Ons
	al_init_ttf_addon(); //inicializa o addon de TrueType Fonts, checar propriedades do projeto -> Allegro 5 -> Add-Ons
	font = al_load_font("C:/Windows/Fonts/Calibri.ttf", 36, 0);
}
void Font::create_Dialogo()
{
	font = al_load_font("RAVIE.ttf", 24, 0);
}