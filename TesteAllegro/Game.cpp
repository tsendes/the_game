#include "Game.h"

Game::Game()
{
	addon_init();

	event_queue = al_create_event_queue();
	tick_s = al_create_timer(1.0 / FPS);
	display.create_display();
	mouse.create_mouse();
	font.create_font();
	environment.create_background();
	keyboard.create_keyboard();
	block.create_field(0);
	block2.create_field(800);
	dialogo.create_Dialogo();
	knight.create_Knight();
	banner.create_Banner();
	error_check();
	register_interrupts();
	draw_screen();
	al_start_timer(tick_s); //starta o timer
	run_game();
}

Game::~Game()
{
	// delete this;
}

void Game::addon_init()
{
	al_init(); //inicializa a allegro
	al_install_keyboard(); //inicializa o addon de Keyboard, checar propriedades do projeto -> Allegro 5 -> Add-Ons
	al_install_mouse(); //inicializa o addon de Mouse, checar propriedades do projeto -> Allegro 5 -> Add-Ons
	al_init_image_addon(); //inicializa o addon de Image, checar propriedades do projeto -> Allegro 5 -> Add-Ons 
	al_init_font_addon(); //inicializa o addon de Fonts, checar propriedades do projeto -> Allegro 5 -> Add-Ons
	al_init_ttf_addon(); //inicializa o addon de TrueType Fonts, checar propriedades do projeto -> Allegro 5 -> Add-Ons
}

void Game::error_check()
{
	//em caso de emergencia, pau no seu cu
	if (!display.display) //display
	{
		al_show_native_message_box(display.display, "Error", "Error", "Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!environment.image) //background
	{
		al_show_native_message_box(display.display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!mouse.mouse) //mouse
	{
		al_show_native_message_box(display.display, "Error", "Error", "Failed to load bitmap!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!font.font) //font
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to load font!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!event_queue) //events
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to create event_queue!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!tick_s) //timer
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to create timer!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!lancer.field) //Character
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to create character!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!knight.field) //Character
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to create character!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!banner.field) //Character
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to create character!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!block.block)
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to create field block!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!block2.block)
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to create field block2!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	if (!dialogo.font)
	{
		al_show_native_message_box(display.display, "Error", "Error", "failed to load dialogo!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
}

void Game::register_interrupts()
{
	al_register_event_source(event_queue, al_get_display_event_source(display.display)); //add display na fila de geração de eventos
	al_register_event_source(event_queue, al_get_timer_event_source(tick_s)); //add temporizador na fila de geração de eventos
	al_register_event_source(event_queue, al_get_mouse_event_source()); //add mouse na fila de geração de eventos
	al_register_event_source(event_queue, al_get_keyboard_event_source()); //add teclado na fila de geração de eventos
}

void Game::draw_screen()
{
	al_clear_to_color(al_map_rgb(0, 0, 0)); //fundo inicial preto
	al_set_window_title(display.display, "Knights of Pixel"); //da um nome para a janela do jogo
	al_draw_text(font.font, al_map_rgb(255, 255, 255), SCREEN_W / 2.0, SCREEN_H / 2.0, ALLEGRO_ALIGN_CENTER, "Carregando... Aguarde"); //printa na tela a msg

	al_flip_display(); //troca o display visual pelo modificavel
	al_rest(1); //aguarda X segundos ate continuar
}

void Game::run_game()
{
	int timer = 0;
	float adjust = 1.0;
	while (!flag.doexit) //enquanto nao for decidido que é o fim do programa
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)  //dps que a tecla é pressionada rola isso aqui
		{
			knight.move(&timer, &adjust, SCREEN_W, SCREEN_H, &flag.redraw, &flag.exaust);
			lancer.move(&timer, &adjust, SCREEN_W, SCREEN_H, &flag.redraw, &flag.exaust);
			banner.move(&timer, &adjust, SCREEN_W, SCREEN_H, &flag.redraw, &flag.exaust);
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //evento de fechar a telinha
		{
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) //evento de movimentaçao do mouse
		{
			mouse.bouncer_x = ev.mouse.x;
			mouse.bouncer_y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) //evento de tecla pressionada
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				if (flag.exaust == false)
				{
					key[KEY_UP] = true;
				}
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
			case ALLEGRO_KEY_Z:
				key[Z_KEY] = true;
				flag.atk = true;
				break;
			case ALLEGRO_KEY_X:
				key[X_KEY] = true;
				flag.atk_x = true;
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
			case ALLEGRO_KEY_Z:
				key[Z_KEY] = false;
				flag.atk = false;
				break;
			case ALLEGRO_KEY_X:
				key[X_KEY] = false;
				flag.atk_x = false;
			}
		}

		if (flag.redraw && al_is_event_queue_empty(event_queue)) //evento de nao tem nada na fila de eventos e foi solicitado a atualização da telinha
		{
			flag.redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_hide_mouse_cursor(display.display); //nome sugestivo
			al_draw_scaled_bitmap(environment.image, 0, 0, 1920, 1080, 0, 0, 1366, 768, 0); //background em escala
			al_draw_bitmap(block.block, block.bouncer_x, block.bouncer_y, 0);
			al_draw_bitmap(block2.block, block2.bouncer_x, block2.bouncer_y, 0);
			al_draw_bitmap(mouse.mouse, mouse.bouncer_x, mouse.bouncer_y, 0); //mouse

			knight.attack(&flag.atk, &flag.atk_x);
			lancer.attack(&flag.atk, &flag.atk_x);
			//banner.attack();
			
			if ((flag.atk == false && flag.atk_x == false) || (flag.atk == true && flag.atk_x == true))
			{
				al_destroy_bitmap(knight.field);
				al_destroy_bitmap(lancer.field);
				al_destroy_bitmap(banner.field);
				lancer.field = al_load_bitmap("Walk_Sprite_Lancer.png");
				al_draw_scaled_bitmap(lancer.field, lancer.getX_atual(), lancer.getY_atual(), lancer.getLarg(), lancer.getAlt(), lancer.getBouncer_x(), lancer.getBouncer_y(), lancer.getLarg() * 3, lancer.getAlt() * 3, 0);
				knight.field = al_load_bitmap("Walk_Sprite_Knight.png");
				al_draw_scaled_bitmap(knight.field, knight.getX_atual(), knight.getY_atual(), knight.getLarg(), knight.getAlt(), knight.getBouncer_x(), knight.getBouncer_y(), knight.getLarg() * 3, knight.getAlt() * 3, 0);
				banner.field = al_load_bitmap("Walk_Sprite_Banner.png");
				al_draw_scaled_bitmap(banner.field, banner.getX_atual(), banner.getY_atual(), banner.getLarg(), banner.getAlt(), banner.getBouncer_x(), banner.getBouncer_y(), banner.getLarg() * 3, banner.getAlt() * 3, 0);
			}
			al_flip_display();
		}
	}
}