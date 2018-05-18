#pragma once
#include <allegro5/allegro.h>

class Player
{
public:
	ALLEGRO_BITMAP * field; //gera o bloco, é Tatepon por agora
	
	float bouncer_x; //local de inicializaçao
	float bouncer_y; //local de inicializaçao
	Player();
	~Player();
};
