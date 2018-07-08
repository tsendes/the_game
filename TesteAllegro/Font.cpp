#include "Font.h"

Font::Font()
{
	create_font();
}
Font::~Font()
{
	al_destroy_font(font);
}
void Font::create_font()
{
	font = al_load_font("C:/Windows/Fonts/Arial.ttf", 30, 0);
	font2 = al_load_font("ROCK.ttf", 70, 0);
	font3 = al_load_font("ROCK2.ttf", 100, 0);
	font4 = al_load_font("Pixel.ttf", 140, 0);

}
