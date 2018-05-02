#include "Font.h"

Font::Font()
{
	//nothing
}
Font::~Font()
{
	al_destroy_font(font);
}
void Font::create_font()
{
	font = al_load_font("C:/Windows/Fonts/Calibri.ttf", 36, 0);
}