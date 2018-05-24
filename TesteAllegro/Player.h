#pragma once
#include <allegro5/allegro.h>

class Player
{
public:
	ALLEGRO_BITMAP * field; //gera o bloco, é Tatepon por agora
	
	float bouncer_x; //local de inicializaçao
	float bouncer_y; //local de inicializaçao

	int larg; //largura de cada sprite no mapa
	int alt; //altura de cada sprite no mapa

	int cont; //contador de ql parte do sprite esta
	int coluna; //qntd de colunas do mapa sprite
	int x_atual; //x atual no mapa sprite
	int y_atual; //y atual no mapa sprite

	int larg_atk;
	int alt_atk;

	int count_atk;
	int coluna_atk;
	int x_atk; //posiçao x de ataque no mapa sprite
	int y_atk; // posição y de ataque no mapa sprite
	float pos_i;
	
	
	Player();
	~Player();
};
