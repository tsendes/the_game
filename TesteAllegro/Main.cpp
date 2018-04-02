//Class things and requirements
#include "Display.h"
#include "Background.h"
#include "Font.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Block.h"

//Control things
#include "Flags.h"
#include "Enum.h"

//Global things
const float FPS = 60; //nao precisa explicar isso neh?
const int BOUNCER_SIZE = 32; //tamanho do mouse e block(por enquanto)
const int SCREEN_W = 1366; //resolu��o da telinha
const int SCREEN_H = 768;  //FON
Flag flag; //struct de flag, muito importante mais pra frente

void addon_init() //onde enfio essa jo�a?
{
	al_init(); //inicializa a allegro
	al_install_keyboard(); //inicializa o addon de Keyboard, checar propriedades do projeto -> Allegro 5 -> Add-Ons
	al_install_mouse(); //inicializa o addon de Mouse, checar propriedades do projeto -> Allegro 5 -> Add-Ons
	al_init_image_addon(); //inicializa o addon de Image, checar propriedades do projeto -> Allegro 5 -> Add-Ons 
	al_init_font_addon(); //inicializa o addon de Fonts, checar propriedades do projeto -> Allegro 5 -> Add-Ons
	al_init_ttf_addon(); //inicializa o addon de TrueType Fonts, checar propriedades do projeto -> Allegro 5 -> Add-Ons
}

int main(int argc, char **argv) 
{
	//addons initialize
	addon_init();

	//Stranger things
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue(); //inicia uma fila de eventos
	ALLEGRO_TIMER *tick_s = al_create_timer(1.0 / FPS); //temporizador
	Display display; //telinha
	Mouse mouse; //coisas do mouse
	Font font; //fonte para escrita na telinha
	Background environment; //plano de fundo da telinha
	Keyboard keyboard; //coisas do teclado
	Block field;  //blocos do jogo
	bool key[4] = { false, false, false, false }; //funfa em combo com o MYKEYS


	flag_init(); //inicializador de flags

	//em caso de emergencia, pau no seu cu
	if (!display.display) //display
	{
		al_show_native_message_box(display.display, "Error", "Error", "Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	if (!environment.image) //background
	{
		al_show_native_message_box(display.display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	if (!mouse.mouse) //mouse
	{
		al_show_native_message_box(display.display, "Error", "Error", "Failed to load bitmap!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	if (!font.font) //font
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to load font!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	if (!event_queue) //eventos
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to create event_queue!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	if (!tick_s) //timer
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to create timer!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	if (!field.field) //field block
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to create field block!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	
	al_register_event_source(event_queue, al_get_display_event_source(display.display)); //add display na fila de gera��o de eventos
	al_register_event_source(event_queue, al_get_timer_event_source(tick_s)); //add temporizador na fila de gera��o de eventos
	al_register_event_source(event_queue, al_get_mouse_event_source()); //add mouse na fila de gera��o de eventos
	al_register_event_source(event_queue, al_get_keyboard_event_source()); //add teclado na fila de gera��o de eventos

	al_clear_to_color(al_map_rgb(0, 0, 0)); //fundo inicial preto
	al_draw_text(font.font, al_map_rgb(255, 255, 255), SCREEN_W / 2.0, SCREEN_H / 2.0, ALLEGRO_ALIGN_CENTER, "A muito tempo atras, no meio do deserto..."); //printa na tela a msg

	al_flip_display(); //trocao display visual pelo modificavel
	al_rest(2); //aguarda X segundos ate continuar

	al_start_timer(tick_s); //starta o timer

	while(!flag.doexit) //enquanto nao for decidido que � o fim do programa
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)  //dps que a tecla � pressionada rola isso aqui
		{
			if (key[KEY_UP] && field.bouncer_y >= 4.0)
			{
				//field.bouncer_y -= 13.0;
			}

			if (key[KEY_DOWN] && field.bouncer_y <= SCREEN_H - 80 /*tamanho do bloco*/ - 4.0)
			{
				//field.bouncer_y += 13.0;
			}

			if (key[KEY_LEFT] && field.bouncer_x >= 4.0)
			{
				//field.bouncer_x -= 13.0;
			}

			if (key[KEY_RIGHT] && field.bouncer_x <= SCREEN_W - 80 /*tamanho do bloco*/ - 4.0)
			{
				//field.bouncer_x += 13.0;
			}

			flag.redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //evento de fechar a telinha
		{
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) //evento de movimenta�ao do mouse
		{
			mouse.bouncer_x = ev.mouse.x;
			mouse.bouncer_y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) //evento de tecla pressionada
		{
			switch (ev.keyboard.keycode) 
			{
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) //evento de tecla solta
		{
			switch (ev.keyboard.keycode) 
			{
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				flag.doexit = true;
				break;
			}
		}

		if (flag.redraw && al_is_event_queue_empty(event_queue)) //evento de nao tem nada na fila de eventos e foi solicitado a atualiza��o da telinha
		{
			flag.redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_hide_mouse_cursor(display.display);
			al_draw_bitmap(environment.image, 0, 0, 0);
			al_draw_bitmap(field.field, field.bouncer_x, field.bouncer_y, 0);
			al_draw_bitmap(mouse.mouse, mouse.bouncer_x, mouse.bouncer_y, 0);
			al_flip_display();
		}
	}
	return 0;
}