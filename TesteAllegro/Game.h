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

//Control things
#include "Flags.h"
#include "Enum.h"

const float FPS = 60; //nao precisa explicar isso neh?
extern Flag flag; //nem isso

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
	Background environment; //plano de fundo da telinha
	Keyboard keyboard; //coisas do teclado
	Lancer field;  //personagem do jogo
	Block block; //bloco de areia
	Block block2;
	Knight knight;
	bool key[9] = { false, false, false, false, false, false, false, false, false }; //funfa em combo com o MYKEYS

public:
	void addon_init();
	Game();
	~Game();
	
};