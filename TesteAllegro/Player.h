#pragma once
#include <allegro5/allegro.h>

class Player
{
public:
	ALLEGRO_BITMAP * field; //gera o bloco, Ú Tatepon por agora
	
	float bouncer_x; //local de inicializašao
	float bouncer_y; //local de inicializašao
	Player();
	~Player();
};
