#pragma once
#include <allegro5/allegro.h>

class Block
{
public:
	ALLEGRO_BITMAP * field; //gera o bloco, � Flowey por agora
	float bouncer_x; //local de inicializa�ao
	float bouncer_y; //local de inicializa�ao
	Block();
	~Block();
	Block(int x, int y);
	void create_block();
};
