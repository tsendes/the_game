#pragma once
//Class things and requirements
#include "Display.h"
#include "Block.h"
#include "Mouse.h"
#include "Background.h"
#include "Font.h"
#include "Keyboard.h"

//Control things
#include "Flags.h"
#include "Enum.h"

const float FPS = 60; //nao precisa explicar isso neh?
extern Flag flag;

class Game
{
public:
	void addon_init();
	Game();
	~Game();
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
	Block field;  //blocos do jogo
	bool key[4] = { false, false, false, false }; //funfa em combo com o MYKEYS

	
};