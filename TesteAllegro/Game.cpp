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
	lancer.create_Lancer();
	ghost.create_Ghost();
	barbarian.create_Barbarian();
	tribesman.create_Tribesman();
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
			knight.move(&timer, &adjust, SCREEN_W, SCREEN_H, &flag.redraw, &flag.exaust, key);
			lancer.move(&timer, &adjust, SCREEN_W, SCREEN_H, &flag.redraw, &flag.exaust, key);
			banner.move(&timer, &adjust, SCREEN_W, SCREEN_H, &flag.redraw, &flag.exaust, key);
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

			al_draw_scaled_bitmap(ghost.field, ghost.getX_atual(), ghost.getY_atual(), ghost.getLarg(), ghost.getAlt(), ghost.getBouncer_x(), ghost.getBouncer_y(), ghost.getLarg() * 2, ghost.getAlt() * 2, knight.getBouncer_x() - ghost.getBouncer_x() > 0 ? ALLEGRO_FLIP_HORIZONTAL : 0);
			ghost.moveEnemy(knight.getBouncer_x(), knight.getBouncer_y());
			al_draw_scaled_bitmap(tribesman.field, tribesman.getX_atual(), tribesman.getY_atual(), tribesman.getLarg(), tribesman.getAlt(), tribesman.getBouncer_x(), tribesman.getBouncer_y(), tribesman.getLarg() * 3, tribesman.getAlt() * 3, knight.getBouncer_x() - tribesman.getBouncer_x() > 0 ? 0 : ALLEGRO_FLIP_HORIZONTAL);
			tribesman.moveEnemy(knight.getBouncer_x(), knight.getBouncer_y());
			al_draw_scaled_bitmap(barbarian.field, barbarian.getX_atual(), barbarian.getY_atual(), barbarian.getLarg(), barbarian.getAlt(), barbarian.getBouncer_x(), barbarian.getBouncer_y(), barbarian.getLarg() * 3, barbarian.getAlt() * 3, knight.getBouncer_x() - barbarian.getBouncer_x() > 0 ? 0 : ALLEGRO_FLIP_HORIZONTAL);
			barbarian.moveEnemy(knight.getBouncer_x(), knight.getBouncer_y());

			if (flag.atk_x == true && flag.atk == false) //atk Lancer
			{
				al_destroy_bitmap(knight.field);
				al_destroy_bitmap(lancer.field);
				lancer.field = al_load_bitmap("Attack_Sprite_Lancer.png");
				al_draw_scaled_bitmap(lancer.field, lancer.getX_atk(), lancer.getY_atk(), lancer.getLarg_atk(), lancer.getAlt_atk(), lancer.getBouncer_x(), lancer.getBouncer_y(), lancer.getLarg_atk() * 3, lancer.getAlt_atk() * 3, 0);
				knight.field = al_load_bitmap("Walk_Sprite_Knight.png");
				al_draw_scaled_bitmap(knight.field, knight.getX_atual(), knight.getY_atual(), knight.getLarg(), knight.getAlt(), knight.getBouncer_x(), knight.getBouncer_y(), knight.getLarg() * 3, knight.getAlt() * 3, key[KEY_LEFT] ? ALLEGRO_FLIP_HORIZONTAL : 0);
				lancer.count_atk++;
				if (lancer.count_atk == 8)
				{
					lancer.count_atk = 0;
					lancer.coluna_atk++;
					lancer.setX_atk(lancer.getX_atk() + lancer.getLarg_atk());
					if (lancer.coluna_atk >= 3)
					{
						lancer.coluna_atk = 0;
						lancer.setX_atk(0);
					}
				}
			}
			if (flag.atk == true && flag.atk_x == false) //Atk Knight
			{
				al_destroy_bitmap(knight.field);
				al_destroy_bitmap(lancer.field);
				knight.field = al_load_bitmap("Attack_Sprite_Knight.png");
				al_draw_scaled_bitmap(knight.field, knight.getX_atk(), knight.getY_atk(), knight.getLarg_atk(), knight.getAlt_atk(), knight.getBouncer_x(), knight.getBouncer_y(), knight.getLarg_atk() * 3, knight.getAlt_atk() * 3, key[KEY_LEFT] ? ALLEGRO_FLIP_HORIZONTAL : 0);
				lancer.field = al_load_bitmap("Walk_Sprite_Lancer.png");
				al_draw_scaled_bitmap(lancer.field, lancer.getX_atual(), lancer.getY_atual(), lancer.getLarg(), lancer.getAlt(), lancer.getBouncer_x(), lancer.getBouncer_y(), lancer.getLarg() * 3, lancer.getAlt() * 3, key[KEY_LEFT] ? ALLEGRO_FLIP_HORIZONTAL : 0);
				knight.count_atk++;
				if (knight.count_atk == 4) //velocidade de ataque
				{
					knight.count_atk = 0;
					knight.coluna_atk++;
					knight.setX_atk(knight.getX_atk() + knight.getLarg_atk());
					if (knight.coluna_atk >= 3)
					{
						knight.coluna_atk = 0;
						knight.setX_atk(0);
					}
				}
			}

			knight.attack(&flag.atk, &flag.atk_x, key);
			lancer.attack(&flag.atk, &flag.atk_x, key);
			banner.attack(&flag.atk, &flag.atk_x, key);
			
			if ((flag.atk == false && flag.atk_x == false) || (flag.atk == true && flag.atk_x == true))
			{
				al_destroy_bitmap(knight.field);
				al_destroy_bitmap(lancer.field);
				al_destroy_bitmap(banner.field);
				lancer.field = al_load_bitmap("Walk_Sprite_Lancer.png");
				al_draw_scaled_bitmap(lancer.field, lancer.getX_atual(), lancer.getY_atual(), lancer.getLarg(), lancer.getAlt(), lancer.getBouncer_x(), lancer.getBouncer_y(), lancer.getLarg() * 3, lancer.getAlt() * 3, key[KEY_LEFT] ? ALLEGRO_FLIP_HORIZONTAL : 0);
				knight.field = al_load_bitmap("Walk_Sprite_Knight.png");
				al_draw_scaled_bitmap(knight.field, knight.getX_atual(), knight.getY_atual(), knight.getLarg(), knight.getAlt(), knight.getBouncer_x(), knight.getBouncer_y(), knight.getLarg() * 3, knight.getAlt() * 3, key[KEY_LEFT] ? ALLEGRO_FLIP_HORIZONTAL : 0);
				banner.field = al_load_bitmap("Walk_Sprite_Banner.png");
				al_draw_scaled_bitmap(banner.field, banner.getX_atual(), banner.getY_atual(), banner.getLarg(), banner.getAlt(), banner.getBouncer_x(), banner.getBouncer_y(), banner.getLarg() * 3, banner.getAlt() * 3, key[KEY_LEFT] ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
			al_flip_display();
		}
	}
}