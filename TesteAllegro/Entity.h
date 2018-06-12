#pragma once
#include <allegro5/allegro.h>

class Entity
{
protected:
	float bouncer_x; //local de inicializaçao
	float bouncer_y; //local de inicializaçao
	int larg; //largura de cada sprite no mapa
	int alt; //altura de cada sprite no mapa
	int x_atual; //x atual no mapa sprite
	int y_atual; //y atual no mapa sprite
	float pos_i;
	float life;

public:
	ALLEGRO_BITMAP * field; //gera o bloco, é Tatepon por agora
	int cont; //contador de ql parte do sprite esta
	int coluna; //qntd de colunas do mapa sprite
	Entity();
	~Entity();
	void setBouncer_x(float x);
	float getBouncer_x();
	void setBouncer_y(float y);
	float getBouncer_y();
	void setLarg(int larg);
	int getLarg();
	void setAlt(int alt);
	int getAlt();
	void setX_atual(int pos_x);
	int getX_atual();
	void setY_atual(int pos_y);
	int getY_atual();
	void setPos_i(float pos_i);
	float getPos_i();
	void setLife(float life);
	float getLife();
	virtual void move() = 0;

	enum MYKEYS
	{
		KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, Z_KEY, X_KEY, I_KEY, K_KEY, J_KEY, L_KEY
	};
	bool key[10] = { false, false, false, false, false, false, false, false, false, false }; //funfa em combo com o MYKEYS
};