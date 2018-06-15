#pragma once
//Class things and requirements
#include "Display.h"
#include <inttypes.h>
#include "Mouse.h"
#include "Background.h"
#include "Font.h"
#include "Keyboard.h"
#include "Block.h"
#include "Lancer.h"
#include "Knight.h"
#include "Banner.h"
#include "Entity.h"
#include "Enemy.h"
#include "Character.h"
#include "Humanoid.h"
#include "Ghost.h"
#include "Barbarian.h"
#include "Tribesman.h"
#include "Object.h"
#include <string.h>
#include <stdio.h>

#define HEIGHT 16
#define FPS  60
class Game
{
private:
	void error_check();
	void register_interrupts();
	void draw_screen();
	void run_game();
	int SCREEN_W = 1366;
	int SCREEN_H = 766;

	//Stranger things
	ALLEGRO_EVENT_QUEUE *event_queue; //inicia uma fila de eventos
	ALLEGRO_TIMER *tick_s; //temporizador
	Display display; //telinha
	Mouse mouse; //coisas do mouse
	Font font; //fonte para escrita na telinha
	Font dialogo;
	Background environment; //plano de fundo da telinha
	Keyboard keyboard; //coisas do teclado
	Block block; //bloco de areia
	Block block2; // o segundo bloco

//Jogador--------------------------------------------------//
	Knight knight;
	Banner banner;
	Lancer lancer;

//Inimigos--------------------------------------------------//
	Ghost ghost;
	Barbarian barbarian;
	Tribesman tribesman;
	

public:
	void addon_init();
	Game();
	~Game();
	uint8_t collider(float x1, float y1, int larg1,int alt1, float x2, float y2, int larg2, int alt2);
	
struct Flag
{
	bool doexit = false; //flag de fim do programa
	bool redraw = true; //flag de solicitação de atualizaçao da telinha
	bool atk = false; //flag de ação de ataque Knight
	bool atk_x = false; //falg de ação de ataque Lancer
	bool exaust = false;
};
	Flag flag;

enum MYKEYS
{
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, Z_KEY, X_KEY, I_KEY, K_KEY, J_KEY, L_KEY
};
	bool key[10] = { false, false, false, false, false, false, false, false, false, false }; //funfa em combo com o MYKEYS
};