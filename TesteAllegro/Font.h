#pragma once
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


class Font
{
	public:
		ALLEGRO_FONT *font; //fonte de escrita na telinha
		Font();
		~Font();
};
