#pragma once

#include <inttypes.h>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "Stage.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Menu.h"
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
#include "Stage3.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>



#define HEIGHT 16
#define FPS  60
#define BLOCK_W 800
#define NUM_ENEMIES rand()%5 + 10

class Game
{
protected:
	ALLEGRO_EVENT_QUEUE *event_queue; //inicia uma fila de eventos
	ALLEGRO_TIMER *tick_s; //temporizador

	Display *display; //telinha
	Background *environment; //plano de fundo da telinha
	Block *block[6]; //bloco de areia

//Jogador--------------------------------------------------//
	Knight* knight;
	Banner* banner;
	Lancer* lancer;

//Inimigos--------------------------------------------------//
	static const int  num_ghost = /*NUM_ENEMIES*/1;
	Ghost* ghost[num_ghost];
	static const int num_bar = /*NUM_ENEMIES*/1;
	Barbarian* barbarian[num_bar];
	static const int num_trib = /*NUM_ENEMIES*/1;
	Tribesman* tribesman[num_trib];
	Boss boss;

	Mouse *mouse;
	Font *font;
	Keyboard *keyboard;

	int stage;
	const int SCREEN_W = 1366;
	const int SCREEN_H = 766;
	float adjust1;
	float adjust2;
	float adjust3;
	int timer = 0;
	float worldW;

public:
	Menu menu;
	Stage1 s1;
	Stage2 s2;
	Stage3 s3;

	Bush bush;
	Barracks barracks;
	Rock rock;

	Game();
	~Game();
	void error_check();
	void register_interrupts();
	void draw_screen();
	void drawImages();
	void run_game();
	void play();
	void setMouse(ALLEGRO_BITMAP* m);
	Mouse* getMouse();
	void setEnvironment(Background* dis);
	Background* getEnvironment();
	void setBlock(Block* bl, int i);
	Block* getBlock(int i);
	void setKnight(Knight* kn);
	Knight* getKnight();
	void setLancer(Lancer* ln);
	Lancer* getLancer();
	void setbanner(Banner* bn);
	Banner* getBanner();
	void setGhost(Ghost* gh, int i);
	Ghost* getGhost(int i);
	void setBarbarian(Barbarian* bar, int i);
	Barbarian* getBarbarian(int i);
	void setTribesman(Tribesman* tr, int i);
	Tribesman* getTribesman(int i);
	int getNum_bar();
	int getNum_ghost();
	int getNum_trib();
	void setStage(int s);
	int getStage();
	void setWorldW(float ww);
	float getWorldlW();
	Font* getFont();
	ALLEGRO_EVENT_QUEUE* getEvent_queue();
	Boss* getBoss();

class Flag
{
public:
	bool doexit = true; //flag de fim do programa
	bool redraw = true; //flag de solicitação de atualizaçao da telinha
	bool exaust = false;
	bool menu = true;
	bool finish = true;
	bool button1 = true;
	bool button2 = false;
	bool button3 = false;
	bool pause = false;
	bool stage1 = true;
	bool stage2 = false;
	bool stage3 = false;
};
Flag flag;

enum MYKEYS
{
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, Z_KEY, X_KEY, ENTER_KEY
};
	bool key[7] = { false, false, false, false, false, false, false }; //funfa em combo com o MYKEYS
};