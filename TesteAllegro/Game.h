#pragma once

#include "Keyboard.h"
#include "Knight.h"
#include "Lancer.h"
#include "Banner.h"
#include "Ghost.h"
#include "Barbarian.h"
#include "Tribesman.h"
#include "Boss.h"
#include "Display.h"
#include "Background.h"
#include "Mouse.h"
#include "Font.h"
#include "Block.h"
#include "Stage1.h"
#include <time.h>
#include <stdio.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

//Class things and requirements


#define HEIGHT 16
#define FPS  60
#define BLOCK_W 800
#define NUM_ENEMIES rand()%5 + 10
class Game
{
private:
	void error_check();
	void register_interrupts();
	void draw_screen();
	void run_game();
	int stage = 1;
	int SCREEN_W = 1366;
	int SCREEN_H = 766;


	//Stranger things
	ALLEGRO_BITMAP* health_bar;
	ALLEGRO_BITMAP* off_bar;
	ALLEGRO_EVENT_QUEUE *event_queue; //inicia uma fila de eventos
	ALLEGRO_TIMER *tick_s; //temporizador

	Display *display = new Display; //telinha
	Background *environment = new Background; //plano de fundo da telinha
	Block *block = new Block; //bloco de areia

//Jogador--------------------------------------------------//
	Knight* knight = new Knight;
	Banner* banner = new Banner;
	Lancer* lancer = new Lancer;

//Inimigos--------------------------------------------------//
	static const int  num_ghost = /*NUM_ENEMIES*/5;
	Ghost* ghost[num_ghost];
	static const int num_bar = /*NUM_ENEMIES*/5;
	Barbarian* barbarian[num_bar];
	static const int num_trib = /*NUM_ENEMIES*/5;
	Tribesman* tribesman[num_trib];

	Boss boss;

	Mouse mouse; //coisas do mouse
	Font font; //fonte para escrita na telinha
	Keyboard keyboard; //coisas do teclado
	

public:
	Game();
	~Game();
	void setMouse(Mouse m)
	{
		mouse = m;
	}
	void setEnvironment(Background* dis)
	{
		environment = dis;
	}
	void setBlock(Block* bl)
	{
		block = bl;
	}
	void setKnight(Knight* kn)
	{
		knight = kn;
	}
	void setGhost(Ghost* gh, int i)
	{
		*ghost[i] = *gh;
	}
	void setBarbarian(Barbarian* bar)
	{
		*barbarian = bar;
	}
	void setStage(int s)
	{
		stage = s;
	}
	int getStage()
	{
		return stage;
	}
	uint8_t collider(float x1, float y1, int larg1,int alt1, float x2, float y2, int larg2, int alt2);
	void createGame(Game* stage);

	//retirar isso daqui depois
	//Stage1 s1;


	float cameraX;
	float worldW;
	ALLEGRO_SAMPLE* sample = al_load_sample("The_Opening.ogg");
struct Flag
{
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
};Flag flag;

enum MYKEYS
{
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, Z_KEY, X_KEY, I_KEY, K_KEY, J_KEY, L_KEY, ENTER_KEY
};
	bool key[11] = { false, false, false, false, false, false, false, false, false, false, false }; //funfa em combo com o MYKEYS
};