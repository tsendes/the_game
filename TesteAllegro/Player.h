#pragma once
#include <allegro5/allegro.h>

class Player
{
public:
	ALLEGRO_BITMAP * field; //gera o bloco, � Tatepon por agora
	int cont; //contador de ql parte do sprite esta
	int coluna; //qntd de colunas do mapa sprite
	int larg; //largura de cada sprite no mapa
	int alt; //altura de cada sprite no mapa
	int x_atual; //x atual no mapa sprite
	int y_atual; //y atual no mapa sprite
	float bouncer_x; //local de inicializa�ao
	float bouncer_y; //local de inicializa�ao
	Player();
	~Player();
	Player(int x, int y);
	void create_player();
};
