#pragma once
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


class Font
{
public:
	ALLEGRO_FONT *font; //fonte de escrita na telinha
	ALLEGRO_FONT *font2; //fonte de escrita na telinha
	ALLEGRO_FONT *font3; //fonte de escrita na telinha
	ALLEGRO_FONT *font4; //fonte de escrita na telinha
	Font();
	~Font();
	void create_font();
};
