#pragma once
#include <allegro5/allegro.h>

extern const int BOUNCER_SIZE;
extern const int SCREEN_W;
extern const int SCREEN_H;

class Block
{
public:
	ALLEGRO_BITMAP * field; //gera o bloco, é um mouse por agora
	float bouncer_x; //local de inicializaçao
	float bouncer_y; //local de inicializaçao
	Block();
	~Block();

private:

};
