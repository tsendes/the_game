#pragma once
#include <allegro5/allegro.h>

extern const int BOUNCER_SIZE;
extern const int SCREEN_W;
extern const int SCREEN_H;

class Block
{
public:
	ALLEGRO_BITMAP * field; //gera o bloco, � um mouse por agora
	float bouncer_x; //local de inicializa�ao
	float bouncer_y; //local de inicializa�ao
	Block();
	~Block();

private:

};
