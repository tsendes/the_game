#pragma once
#include "Player.h"

class Lancer : public Player
{
public:
	int cont; //contador de ql parte do sprite esta
	int coluna; //qntd de colunas do mapa sprite
	int larg; //largura de cada sprite no mapa
	int alt; //altura de cada sprite no mapa
	int x_atual; //x atual no mapa sprite
	int y_atual; //y atual no mapa sprite
	Lancer();
	~Lancer();
	void create_Lancer();
};
