#pragma once
#include <allegro5/allegro.h>

class Player
{
public:
	ALLEGRO_BITMAP * field; //gera o bloco, � Tatepon por agora
	
	float bouncer_x; //local de inicializa�ao
	float bouncer_y; //local de inicializa�ao
	Player();
	~Player();
};
