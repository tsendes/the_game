#pragma once
#include <allegro5/allegro.h>

class Block
{
public:
	ALLEGRO_BITMAP * field; //gera o bloco, é Flowey por agora
	float bouncer_x; //local de inicializaçao
	float bouncer_y; //local de inicializaçao
	Block();
	~Block();
	Block(int x, int y);
	void create_block();
};
