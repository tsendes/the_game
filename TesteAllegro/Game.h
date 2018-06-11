#pragma once
//Class things and requirements
#include "Display.h"
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

const float FPS = 60; //nao precisa explicar isso neh?


class Game
{

private:
	void error_check();
	void register_interrupts();
	void draw_screen();
	void run_game();
	
	//Stranger things
	ALLEGRO_EVENT_QUEUE *event_queue; //inicia uma fila de eventos
	ALLEGRO_TIMER *tick_s; //temporizador
	Display display; //telinha
	Mouse mouse; //coisas do mouse
	Font font; //fonte para escrita na telinha
	Font dialogo;
	Background environment; //plano de fundo da telinha
	Keyboard keyboard; //coisas do teclado
	Lancer Lancer;  //personagem do jogo
	Block block; //bloco de areia
	Block block2; // o segundo bloco
	Knight knight;
	

public:
	void addon_init();
	Game();
	~Game();
	
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