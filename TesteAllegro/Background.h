#pragma once
#include<allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"


class Background
{
public:
	ALLEGRO_BITMAP *image; //plano de fundo
	ALLEGRO_BITMAP *image2; //plano de fundo
	ALLEGRO_BITMAP *image3; //plano de fundo
	ALLEGRO_BITMAP *image4; //plano de fundo
	ALLEGRO_BITMAP *image5; //plano de fundo
	void create_background();
	Background();
	~Background();
};
