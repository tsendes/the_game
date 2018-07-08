#pragma once
#include<allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "Knight.h"


class Background
{
public:
	ALLEGRO_BITMAP * imagev1; //plano de fundo
	ALLEGRO_BITMAP * imagev2; //plano de fundo
	ALLEGRO_BITMAP * imagev3; //plano de fundo

	ALLEGRO_BITMAP *image1; //plano de fundo
	ALLEGRO_BITMAP *image2; //plano de fundo
	ALLEGRO_BITMAP *image3; //plano de fundo
	ALLEGRO_BITMAP *image4; //plano de fundo
	ALLEGRO_BITMAP *image5; //plano de fundo
	ALLEGRO_BITMAP *image6; //plano de fundo
	ALLEGRO_BITMAP *image7; //plano de fundo
	int w;
	int h;
	void create_background();
	void drawBackground(Knight* knight);
	Background();
	~Background();
};
