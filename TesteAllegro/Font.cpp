#include "Font.h"

Font::Font()
{
	font = al_load_font("C:/Windows/Fonts/Calibri.ttf", 48, 0);
}
Font::~Font()
{
	al_destroy_font(font);
}