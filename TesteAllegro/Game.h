#pragma once

#include <inttypes.h>
#include <time.h>
#include <stdio.h>
#include "Stage.h"
#include "Stage1.h"
#include "Keyboard.h"
#include "Block.h"
#include "Mouse.h"
#include "Font.h"
#include "Knight.h"
#include "Lancer.h"
#include "Banner.h"
#include "Ghost.h"
#include "Barbarian.h"
#include "Tribesman.h"
#include "Bush.h"
#include "Rock.h"
#include "Boss.h"
#include "Barracks.h"
#include "Display.h"
#include "Menu.h"
#include "Background.h"




#define HEIGHT 16
#define FPS  60
#define BLOCK_W 800
#define NUM_ENEMIES rand()%5 + 10

class Game
{
protected:
	int stage = 1;
	int SCREEN_W = 1366;
	int SCREEN_H = 766;
	float adjust1;
	float adjust2;
	float adjust3;


	//Stranger things
	ALLEGRO_BITMAP* health_bar;
	ALLEGRO_BITMAP* off_bar;
	ALLEGRO_EVENT_QUEUE *event_queue; //inicia uma fila de eventos
	ALLEGRO_TIMER *tick_s; //temporizador

	Display *display = new Display; //telinha
	Background *environment = new Background; //plano de fundo da telinha
	Block *block[6]; //bloco de areia

//Jogador--------------------------------------------------//
	Knight* knight = new Knight;
	Banner* banner = new Banner;
	Lancer* lancer = new Lancer;

//Inimigos--------------------------------------------------//
	static const int  num_ghost = /*NUM_ENEMIES*/1;
	Ghost* ghost[num_ghost];
	static const int num_bar = /*NUM_ENEMIES*/1;
	Barbarian* barbarian[num_bar];
	static const int num_trib = /*NUM_ENEMIES*/1;
	Tribesman* tribesman[num_trib];

	Boss boss;

	Mouse mouse; //coisas do mous
	Font font; //fonte para escrita na telinha
	Keyboard keyboard; //coisas do teclado

	float cameraX;
	float worldW;

	Stage1* my_stage1;
		
	my_stage1 = new Stage1;

	uint8_t colliderX(float x1, int larg1, float x2, int larg2);
	uint8_t colliderY(float y1, int alt1, float y2, int alt2);

public:
	void error_check();
	void register_interrupts();
	void draw_screen();
	void run_game();
	Game();
	~Game();
	void setMouse(ALLEGRO_BITMAP* m)
	{
		mouse.mouse = m;
	}
	Mouse getMouse()
	{
		return mouse;
	}
	void setEnvironment(Background* dis)
	{
		environment = dis;
	}
	Background* getEnvironment()
	{
		return environment;
	}
	void setBlock(Block* bl)
	{
		block[0] = bl;
	}
	Block* getBlock(int i)
	{
		return block[i];
	}
	void setKnight(Knight* kn)
	{
		knight = kn;
	}
	Knight* getKnight()
	{
		return knight;
	}
	void setLancer(Lancer* ln)
	{
		lancer = ln;
	}
	Lancer* getLancer()
	{
		return lancer;
	}
	void setbanner(Banner* bn)
	{
		banner = bn;
	}
	Banner* getBanner()
	{
		return banner;
	}


	void setGhost(Ghost* gh, int i)
	{
		*ghost[i] = *gh;
	}
	Ghost* getGhost(int i)
	{
		return ghost[i];
	}
	void setBarbarian(Barbarian* bar, int i)
	{
		barbarian[i] = bar;
	}
	Barbarian* getBarbarian(int i)
	{
		return barbarian[i];
	}
	void setTribesman(Tribesman* tr, int i)
	{
		tribesman[i] = tr;
	}
	Tribesman* getTribesman(int i)
	{
		return tribesman[i];
	}
	int getNum_bar()
	{
		return num_bar;
	}

	void setStage(int s)
	{
		stage = s;
	}
	int getStage()
	{
		return stage;
	}
	void setCameraX(float cx)
	{
		cameraX = cx;
	}
	float getCameraX()
	{
		return cameraX;
	}
	void setWorldW(float ww)
	{
		worldW = ww;
	}
	float getWorldlW()
	{
		return worldW;
	}

	void createGame(Game* stage);

class Flag
{
public:
	bool doexit = true; //flag de fim do programa
	bool redraw = true; //flag de solicitação de atualizaçao da telinha
	bool atk = false; //flag de ação de ataque Knight
	bool atk_x = false; //falg de ação de ataque Lancer
	bool exaust = false;
	bool menu = true;
	bool finish = true;
	bool button1 = true;
	bool button2 = false;
	bool button3 = false;
};
Flag flag;

enum MYKEYS
{
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, Z_KEY, X_KEY, I_KEY, K_KEY, J_KEY, L_KEY, ENTER_KEY
};
	bool key[11] = { false, false, false, false, false, false, false, false, false, false, false }; //funfa em combo com o MYKEYS
};