#include "Game.h"


Game::Game()
{
	al_init();
	al_init_image_addon(); 
	al_install_mouse();
	al_install_keyboard();
	al_init_font_addon(); //inicializa o addon de Fonts, checar propriedades do projeto -> Allegro 5 -> Add-Ons
	al_init_ttf_addon(); //inicializa o addon de TrueType Fonts, checar propriedades do projeto -> Allegro 5 -> Add-Ons

	srand(time(NULL));
	event_queue = al_create_event_queue();
	tick_s = al_create_timer(1.0 / FPS);
	display = new Display;
	knight = new Knight;
	lancer = new Lancer;
	banner = new Banner;
	environment = new Background;
	font = new Font;
	mouse = new Mouse;
	keyboard = new Keyboard;
	stage = 1;
	adjust1 = 1.0;
	adjust2 = 1.0;
	adjust3 = 1.0;
	register_interrupts();
	s1.buildStage(this);
	
	worldW = SCREEN_W * 3;
	al_hide_mouse_cursor(display->display); 
	play();
}

Game::~Game()
{
	delete (display);
	for (int i = 0; i < 6; i++)
		delete (block[i]);
	delete (environment);
	delete(knight);
	delete(lancer);
	delete(banner);
	delete(font);
	for (int i = 0; i < num_trib; i++)
		delete(tribesman[i]);
	for (int i = 0; i < num_ghost; i++)
		delete(barbarian[i]);
	for(int i = 0; i < num_bar; i++)
		delete(ghost[i]);
}


void Game::error_check()
{
	try
	{
		if (!display->display) //display
		{
			al_show_native_message_box(display->display, "Error", "Error", "Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!environment->imagev1) //background
		{
			al_show_native_message_box(display->display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!mouse->mouse) //mouse
		{
			al_show_native_message_box(display->display, "Error", "Error", "Failed to load mouse!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!font->font) //font
		{
			al_show_native_message_box(display->display, "Error", "Error", "failed to load font!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!event_queue) //events
		{
			al_show_native_message_box(display->display, "Error", "Error", "failed to create event_queue!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!tick_s) //timer
		{
			al_show_native_message_box(display->display, "Error", "Error", "failed to create timer!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!lancer->getWalk_sprite()) //Character
		{
			al_show_native_message_box(display->display, "Error", "Error", "failed to create character!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!knight->getWalk_sprite()) //Character
		{
			al_show_native_message_box(display->display, "Error", "Error", "failed to create character!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!banner->getWalk_sprite()) //Character
		{
			al_show_native_message_box(display->display, "Error", "Error", "failed to create character!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		for (int i = 0; i < 6; i++)
		{
			if (!block[i]->block)
			{
				al_show_native_message_box(display->display, "Error", "Error", "failed to create field block!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
				throw 1;
			}
		}
		for (int i = 0; i < num_bar; i++)
		{
			if (getStage() == 2)
			{
				if (!tribesman[i]->field)
				{
					al_show_native_message_box(display->display, "Error", "Error", "failed to create tribesman block!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					throw 1;
				}
			}
			if (getStage() == 1)
			{
				if (!barbarian[i]->field)
				{
					al_show_native_message_box(display->display, "Error", "Error", "failed to create barbarian block!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					throw 1;
				}
			}
			if (getStage() <= 2)
			{
				if (!ghost[i]->field)
				{
					al_show_native_message_box(display->display, "Error", "Error", "failed to create ghost block!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
					throw 1;
				}
			}
		}
	}
	catch (int error)
	{
		flag.doexit = false;
		flag.finish = false;
		flag.menu = false;
	}
}

void Game::register_interrupts()
{
	al_register_event_source(event_queue, al_get_display_event_source(display->display)); //add display na fila de geração de eventos
	al_register_event_source(event_queue, al_get_timer_event_source(tick_s)); //add temporizador na fila de geração de eventos
	al_register_event_source(event_queue, al_get_mouse_event_source()); //add mouse na fila de geração de eventos
	al_register_event_source(event_queue, al_get_keyboard_event_source()); //add teclado na fila de geração de eventos
}

void Game::draw_screen()
{
	al_clear_to_color(al_map_rgb(0, 0, 0)); //fundo inicial preto
	al_set_window_title(display->display, "Knights of Pixel"); //da um nome para a janela do jogo
	al_draw_text(font->font, al_map_rgb(255, 255, 255), SCREEN_W / 2.0, SCREEN_H / 2.0, ALLEGRO_ALIGN_CENTER, "Carregando... Aguarde"); //printa na tela a msg

	//al_draw_bitmap(s1.getListEnt()->getNextE(0)->getpInfo()->field, 50, 120, 0);
	//al_draw_bitmap(s1.getListEnt()->getNextE(1)->getpInfo()->field, 100, 120, 0);

	al_flip_display(); //troca o display visual pelo modificavel
	al_rest(1); //aguarda X segundos ate continuar
}

void Game::play()
{
	error_check();
	al_start_timer(tick_s);
	al_hide_mouse_cursor(display->display);

	while (flag.finish)
	{
		while (flag.menu)
		{
			//run_menu();
			menu.drawMenu(this);
		}
		//jogo começa a rodar aqui
		while (flag.doexit) //enquanto nao for decidido que é o fim do programa
		{
			run_game();
		}
	}
}

void Game::drawImages()
{
	if (knight->getAtk() == true && lancer->getAtk() == false) //Atk Knight
	{
		if (knight->getLeft())
		{
			if (getStage() == 3)
			{
				al_draw_scaled_bitmap(knight->getAttack_sprite(), knight->getX_atk(), knight->getY_atk(), knight->getLarg_atk(), knight->getAlt_atk(), banner->getBouncer_x() + knight->getCameraX() * -1 - 35, knight->getBouncer_y(), knight->getLarg_atk() * 3, knight->getAlt_atk() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + knight->getCameraX() * -1 - 35, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), knight->getBouncer_x() + knight->getCameraX() * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
			else if (getStage() == 2)
			{
				al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), knight->getBouncer_x() + knight->getCameraX() * -1 - 35, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(knight->getAttack_sprite(), knight->getX_atk(), knight->getY_atk(), knight->getLarg_atk(), knight->getAlt_atk(), lancer->getBouncer_x() + knight->getCameraX() * -1 - 35, knight->getBouncer_y(), knight->getLarg_atk() * 3, knight->getAlt_atk() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
			else if (getStage() == 1)
			{
				al_draw_scaled_bitmap(knight->getAttack_sprite(), knight->getX_atk(), knight->getY_atk(), knight->getLarg_atk(), knight->getAlt_atk(), knight->getBouncer_x() + knight->getCameraX() * -1 - 35, knight->getBouncer_y(), knight->getLarg_atk() * 3, knight->getAlt_atk() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
		}
		else
		{
			al_draw_scaled_bitmap(knight->getAttack_sprite(), knight->getX_atk(), knight->getY_atk(), knight->getLarg_atk(), knight->getAlt_atk(), knight->getBouncer_x() + knight->getCameraX() * -1, knight->getBouncer_y(), knight->getLarg_atk() * 3, knight->getAlt_atk() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);

			if (getStage() > 1)
			{
				al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + knight->getCameraX() * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				if (getStage() > 2)
					al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), banner->getBouncer_x() + knight->getCameraX() * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
		}
	}
	if (lancer->getAtk() == true && knight->getAtk() == false && getStage() > 1) //Atk Lancer
	{
		if (lancer->getLeft())
		{
			if (getStage() == 3)
			{
				al_draw_scaled_bitmap(lancer->getAttack_sprite(), lancer->getX_atk(), lancer->getY_atk(), lancer->getLarg_atk(), lancer->getAlt_atk(), lancer->getBouncer_x() + knight->getCameraX() * -1, lancer->getBouncer_y(), lancer->getLarg_atk() * 3, lancer->getAlt_atk() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), banner->getBouncer_x() + knight->getCameraX() * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), knight->getBouncer_x() + knight->getCameraX() * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
			else if (getStage() == 2)
			{
				al_draw_scaled_bitmap(lancer->getAttack_sprite(), lancer->getX_atk(), lancer->getY_atk(), lancer->getLarg_atk(), lancer->getAlt_atk(), knight->getBouncer_x() + knight->getCameraX() * -1 - 35, lancer->getBouncer_y(), lancer->getLarg_atk() * 3, lancer->getAlt_atk() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), lancer->getBouncer_x() + knight->getCameraX() * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
		}
		else
		{
			al_draw_scaled_bitmap(lancer->getAttack_sprite(), lancer->getX_atk(), lancer->getY_atk(), lancer->getLarg_atk(), lancer->getAlt_atk(), lancer->getBouncer_x() + knight->getCameraX() * -1, lancer->getBouncer_y(), lancer->getLarg_atk() * 3, lancer->getAlt_atk() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + knight->getCameraX() * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			if (getStage() > 2)
				al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), banner->getBouncer_x() + knight->getCameraX() * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
		}
	}
	if ((knight->getAtk() == false && lancer->getAtk() == false) || (knight->getAtk() == true && lancer->getAtk() == true))
	{
		if (knight->getLeft())
		{
			if (getStage() == 1)
				al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + knight->getCameraX() * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			else if (getStage() == 2)
			{
				al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), lancer->getBouncer_x() + knight->getCameraX() * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), knight->getBouncer_x() + knight->getCameraX() * -1 - 35, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
			else
			{
				al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), banner->getBouncer_x() + knight->getCameraX() * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + knight->getCameraX() * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), knight->getBouncer_x() + knight->getCameraX() * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
		}
		else
		{
			if (getStage() == 1)
				al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + knight->getCameraX() * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			else if (getStage() == 2)
			{
				al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + knight->getCameraX() * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + knight->getCameraX() * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
			else
			{
				al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + knight->getCameraX() * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + knight->getCameraX() * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), banner->getBouncer_x() + knight->getCameraX() * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
		}
	}
}

void Game::run_game()
{
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) //evento de movimentaçao do mouse
	{
		mouse->bouncer_x = ev.mouse.x;
		mouse->bouncer_y = ev.mouse.y;
	}
	else if (ev.type == ALLEGRO_EVENT_TIMER && !flag.pause)  //dps que a tecla é pressionada rola isso aqui
	{
		knight->move(&timer, &adjust1, SCREEN_W + knight->getCameraX(), SCREEN_H, &flag.redraw, &flag.exaust, key); //tem forma melhor de fazer isso
		if (getStage() == 2 || getStage() == 3)
			lancer->move(&timer, &adjust2, SCREEN_W + knight->getCameraX(), SCREEN_H, &flag.redraw, &flag.exaust, key);
		if (getStage() == 3)
			banner->move(&timer, &adjust3, SCREEN_W + knight->getCameraX(), SCREEN_H, &flag.redraw, &flag.exaust, key);

		if (knight->getHealth() <= 0)
		{
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_flip_display();
			al_rest(1);
			al_draw_text(font->font, al_map_rgb(255, 0, 0), SCREEN_W / 2.0, SCREEN_H / 2.0, ALLEGRO_ALIGN_CENTER, "YOU DIED");
			al_flip_display();
			al_rest(3);

			flag.doexit = false;
			flag.menu = true;
			setStage(1);
			menu.buildRanking(knight->getScore());
			//createGame(this);
			s1.buildStage(this);

		}
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //evento de fechar a telinha
	{
		flag.doexit = false;
		flag.finish = false;
		flag.menu = false;
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
			knight->block = false;
			break;

		case ALLEGRO_KEY_RIGHT:
			if(knight->block == false)
				key[KEY_RIGHT] = true;
			break;
		case ALLEGRO_KEY_Z:
			key[Z_KEY] = true;
			knight->setAtk(true);
			break;
		case ALLEGRO_KEY_X:
			if (stage >= 2)
			{
				key[X_KEY] = true;
				lancer->setAtk(true);
			}
			break;
		case ALLEGRO_KEY_ESCAPE:
			flag.doexit = false;
			flag.menu = true;
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
		case ALLEGRO_KEY_LEFT:
			key[KEY_LEFT] = false;
			break;
		case ALLEGRO_KEY_RIGHT:
			key[KEY_RIGHT] = false;
			break;
		case ALLEGRO_KEY_ESCAPE:
			flag.menu = true;
			flag.doexit = false;
			break;
		case ALLEGRO_KEY_Z:
			key[Z_KEY] = false;
			knight->setAtk(false);
			break;
		case ALLEGRO_KEY_X:
			key[X_KEY] = false;
			lancer->setAtk(false);
			break;
		case ALLEGRO_KEY_P:
			if (flag.pause)
			{
				flag.pause = false;
			}
			else
			{
				flag.pause = true;
			}
			break;
		}
	}

	if (flag.redraw && al_is_event_queue_empty(event_queue) && !flag.pause) //evento de nao tem nada na fila de eventos e foi solicitado a atualização da telinha
	{
		flag.redraw = false;

		knight->setCameraX(knight->getBouncer_x() - SCREEN_W / 2 + knight->getLarg() / 2);
		if (knight->getCameraX() < 0)
			knight->setCameraX(0);
		if (knight->getCameraX() > worldW - SCREEN_W)
			knight->setCameraX(worldW - SCREEN_W);

		environment->drawBackground(knight);

		if (getStage() == 1)
		{
			if (barracks.getisPresent() == true)
			{
				al_draw_scaled_bitmap(barracks.field, 0, 0, barracks.getLarg(), barracks.getAlt(), barracks.getBouncer_x() + knight->getCameraX() * -1, barracks.getBouncer_y(), barracks.getLarg() * 2, barracks.getAlt() * 2, 0);
				barracks.collide(knight);
			}
			else
			{
				knight->block = false;
			}
			if (rock.getisPresent() == true)
			{
				al_draw_scaled_bitmap(rock.field, 0, 0, rock.getLarg(), rock.getAlt(), rock.getBouncer_x() + knight->getCameraX() * -1, rock.getBouncer_y(), rock.getLarg() * 2, rock.getAlt() * 2, 0);
				rock.collide(knight);
			}
			else
			{
				knight->block = false;
			}
		}
		else if (getStage() == 2)
		{
			if (bush.getisPresent() == true)
			{
				al_draw_scaled_bitmap(bush.field, 0, 0, bush.getLarg(), bush.getAlt(), bush.getBouncer_x() + knight->getCameraX() * -1, bush.getBouncer_y(), bush.getLarg() * 2, bush.getAlt() * 2, 0);
				bush.collide(knight);
			}
		}
		else
		{
			knight->block = false;
		}
		
		knight->drawHUD(display, font);
		al_draw_bitmap(mouse->mouse, mouse->bouncer_x, mouse->bouncer_y, 0); //mouse
		for (int i = 0; i < 6; i++)
			al_draw_bitmap(block[i]->field, block[i]->getBouncer_x() + knight->getCameraX() * -1, block[i]->getBouncer_y(), 0);

		knight->attack(lancer->getAtk(), key);
		if (getStage() > 1)
			lancer->attack(knight->getAtk(), key);

		for (int i = 0; i < num_bar; i++)
		{
			if (getStage() == 1 || getStage() == 2)// Ghost
			{
				if (ghost[i]->getisPresent())
				{
					ghost[i]->move(knight, lancer);
				}
			}
			if (getStage() == 2) // Tribesman
			{
				if (tribesman[i]->getisPresent())
				{
					tribesman[i]->move(knight, lancer);
				}
			}
			if (getStage() == 1) // Barbarian
			{
				if (barbarian[i]->getisPresent())
				{
					barbarian[i]->move(knight, lancer);
				}
			}
		}

		if (getStage() == 3) //Boss
		{
			boss.setBouncer_x(boss.getBouncer_x() + knight->getCameraX() * -1);
			if (boss.getisPresent())
			{
				boss.move(knight, lancer);

				if (boss.getHealth() <= 0)
				{
					boss.setisPresent(false);
					al_clear_to_color(al_map_rgb(0, 0, 0));
					al_flip_display();
					al_rest(1);
					al_draw_text(font->font, al_map_rgb(184, 134, 11), SCREEN_W / 2.0, SCREEN_H / 2.0, ALLEGRO_ALIGN_CENTER, "VICTORY ACHIEVED");
					al_flip_display();
					al_rest(3);

					flag.doexit = false;
					flag.menu = true;
					setStage(1);
					flag.stage1 = true;
					flag.stage2 = false;
					flag.stage3 = false;
					s1.buildStage(this);
				}
			}
		}

		if (knight->getInvencible() == true)
		{
			knight->setCount_inv(knight->getCount_inv() - 1);
			if (knight->getCount_inv() <= 0)
			{
				knight->setCount_inv(60);
				knight->setInvencible(false);
			}
		}
	
		drawImages();
		al_flip_display();
	}
	if (knight->getBouncer_x() >= (float)4000)
	{
		if (flag.stage1)
		{
			flag.stage1 = false;
			flag.stage2 = true;
			setStage(2);
			s2.buildStage(this);
		}
		else if (flag.stage2)
		{
			flag.stage2 = false;
			setStage(2);
			flag.stage3 = true;
			s3.buildStage(this);
		}
		else if(flag.stage3)
		{
			flag.stage3 = false;
			flag.stage1 = true;
			setStage(1);
			s1.buildStage(this);
		}
	}
}

void Game::setMouse(ALLEGRO_BITMAP* m)
{
	mouse->mouse = m;
}
Mouse* Game::getMouse()
{
	return mouse;
}
void Game::setEnvironment(Background* dis)
{
	environment = dis;
}
Background* Game::getEnvironment()
{
	return environment;
}
void Game::setBlock(Block* bl, int i)
{
	block[i] = bl;
}
Block* Game::getBlock(int i)
{
	return block[i];
}
void Game::setKnight(Knight* kn)
{
	knight = kn;
}
Knight* Game::getKnight()
{
	return knight;
}
void Game::setLancer(Lancer* ln)
{
	lancer = ln;
}
Lancer* Game::getLancer()
{
	return lancer;
}
void Game::setbanner(Banner* bn)
{
	banner = bn;
}
Banner* Game::getBanner()
{
	return banner;
}

void Game::setGhost(Ghost* gh, int i)
{
	ghost[i] = gh;
}
Ghost* Game::getGhost(int i)
{
	return ghost[i];
}
void Game::setBarbarian(Barbarian* bar, int i)
{
	barbarian[i] = bar;
}
Barbarian* Game::getBarbarian(int i)
{
	return barbarian[i];
}
void Game::setTribesman(Tribesman* tr, int i)
{
	tribesman[i] = tr;
}
Tribesman* Game::getTribesman(int i)
{
	return tribesman[i];
}
int Game::getNum_bar()
{
	return num_bar;
}
int Game::getNum_ghost()
{
	return num_ghost;
}
int Game::getNum_trib()
{
	return num_trib;
}

void Game::setStage(int s)
{
	stage = s;
}
int Game::getStage()
{
	return stage;
}
void Game::setWorldW(float ww)
{
	worldW = ww;
}
float Game::getWorldlW()
{
	return worldW;
}
Font* Game::getFont()
{
	return font;
}
ALLEGRO_EVENT_QUEUE* Game::getEvent_queue()
{
	return event_queue;
}
Boss* Game::getBoss()
{
	return &boss;
}