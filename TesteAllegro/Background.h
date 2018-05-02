#pragma once
#include<allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"


class Background
{
public:
	ALLEGRO_BITMAP *image; //plano de fundo
	void create_background();
	Background();
	~Background();
};
