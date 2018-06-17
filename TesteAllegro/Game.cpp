#include <string>
#include <inttypes.h>
#include <stdio.h>
#include "ListEnt.h"
//#include "Stage.h"
#include "Game.h"


Game::Game()
{
	event_queue = al_create_event_queue();
	tick_s = al_create_timer(1.0 / FPS);
	register_interrupts();

	font.create_font();
	dialogo.create_Dialogo();

	health_bar = al_create_bitmap(80, 10);
	al_set_target_bitmap(health_bar);
	al_clear_to_color(al_map_rgb(0, 255, 0));
	al_set_target_bitmap(al_get_backbuffer(display->display));

	off_bar = al_create_bitmap(82, 12);
	al_set_target_bitmap(off_bar);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_set_target_bitmap(al_get_backbuffer(display->display));
	s1.buildStage1();

	cameraX = 0;
	worldW = SCREEN_W * 3;

	al_hide_mouse_cursor(display->display); 
	draw_screen();
	al_start_timer(tick_s); 
	run_game();
}

Game::~Game()
{
	delete (display);
	delete (block);
	delete (environment);
	delete(knight);
	delete(lancer);
	delete(banner);
	delete(tribesman);
	delete(barbarian);
	delete(ghost);
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
		if (!environment->image) //background
		{
			al_show_native_message_box(display->display, "Error", "Error", "Failed to load image!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!mouse.mouse) //mouse
		{
			al_show_native_message_box(display->display, "Error", "Error", "Failed to load bitmap!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!font.font) //font
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
		if (!block->block)
		{
			al_show_native_message_box(display->display, "Error", "Error", "failed to create field block!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
		if (!dialogo.font)
		{
			al_show_native_message_box(display->display, "Error", "Error", "failed to load dialogo!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
			throw 1;
		}
	}
	catch (int error)
	{
		flag.doexit = true;
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
	al_clear_to_color(al_map_rgb(0, 0, 255)); //fundo inicial preto
	al_set_window_title(display->display, "Knights of Pixel"); //da um nome para a janela do jogo
	al_draw_text(dialogo.font, al_map_rgb(255, 255, 255), SCREEN_W / 2.0, SCREEN_H / 2.0, ALLEGRO_ALIGN_CENTER, "Carregando... Aguarde"); //printa na tela a msg

	al_draw_bitmap(s1.getListEnt()->getNextE()->getpFirst()->getpInfo()->field, 50, 120, 0);
	al_draw_bitmap(s1.getListEnt()->getNextE()->getpNext()->getpInfo()->field, 100, 120, 0);

	al_flip_display(); //troca o display visual pelo modificavel
	al_rest(1); //aguarda X segundos ate continuar
}

void Game::run_game()
{
	error_check();
	int timer = 0;
	float adjust = 1.0;
	/*while (flag.menu)
	{
		ALLEGRO_EVENT ev_menudo;
		al_wait_for_event(event_queue, &ev_menudo);
		if (ev_menudo.type == ALLEGRO_EVENT_MOUSE_AXES || ev_menudo.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) //evento de movimentaçao do mouse
		{
			mouse.bouncer_x = ev_menudo.mouse.x;
			mouse.bouncer_y = ev_menudo.mouse.y;
		}
		else if (ev_menudo.type == ALLEGRO_EVENT_TIMER)
		{

		}
		else if (ev_menudo.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //evento de fechar a telinha
		{
			break;
		}
		else if (ev_menudo.type == ALLEGRO_EVENT_KEY_DOWN) //evento de tecla pressionada
		{
			switch (ev_menudo.keyboard.keycode)
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
			case ALLEGRO_KEY_Z:
				key[Z_KEY] = true;
				break;
			case ALLEGRO_KEY_X:
				key[X_KEY] = true;
				break;
			}
		}
		else if (ev_menudo.type == ALLEGRO_EVENT_KEY_UP) //evento de tecla solta
		{
			switch (ev_menudo.keyboard.keycode)
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

		if (flag.redraw && al_is_event_queue_empty(event_queue))
		{
			al_flip_display();
		}
	}*/
	while (!flag.doexit) //enquanto nao for decidido que é o fim do programa
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES || ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) //evento de movimentaçao do mouse
		{
			mouse.bouncer_x = ev.mouse.x;
			mouse.bouncer_y = ev.mouse.y;
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)  //dps que a tecla é pressionada rola isso aqui
		{
			knight->move(&timer, &adjust, SCREEN_W + cameraX , SCREEN_H, &flag.redraw, &flag.exaust, key);
			lancer->move(&timer, &adjust, SCREEN_W + cameraX , SCREEN_H, &flag.redraw, &flag.exaust, key);
			banner->move(&timer, &adjust, SCREEN_W + cameraX , SCREEN_H, &flag.redraw, &flag.exaust, key);

		///colidiu, tomou dano e voa pra tras um pouco perdendo a capacidade de andar ate ele cair no chao direito
			if (collider(knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg(), knight->getAlt(), ghost->getBouncer_x() + cameraX * -1, ghost->getBouncer_y(), ghost->getLarg(), ghost->getAlt()) ||
				collider(lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg(), lancer->getAlt(), ghost->getBouncer_x() + cameraX * -1, ghost->getBouncer_y(), ghost->getLarg(), ghost->getAlt()) ||
				collider(banner->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg(), banner->getAlt(), ghost->getBouncer_x() + cameraX * -1, ghost->getBouncer_y(), ghost->getLarg(), ghost->getAlt()))
			{
				knight->setHealth(knight->getHealth() - ghost->getDamage()*.007);
				//knight.setBouncer_x(knight.getBouncer_x() - SCREEN_W * .05);
			}
			if (collider(knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg(), knight->getAlt(), barbarian->getBouncer_x() + cameraX * -1, barbarian->getBouncer_y(), barbarian->getLarg(), barbarian->getAlt()) ||
				collider(lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg(), lancer->getAlt(), barbarian->getBouncer_x() + cameraX * -1, barbarian->getBouncer_y(), barbarian->getLarg(), barbarian->getAlt()) ||
				collider(banner->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg(), banner->getAlt(), barbarian->getBouncer_x() + cameraX * -1, barbarian->getBouncer_y(), barbarian->getLarg(), barbarian->getAlt()))
			{
				barbarian->field = barbarian->getAttack_sprite();
				barbarian->attackEnemy();
				knight->setHealth(knight->getHealth() - barbarian->getDamage()*.007);
				//knight.setBouncer_x(knight.getBouncer_x() - SCREEN_W * .05);
			}
			if (collider(knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg(), knight->getAlt(), tribesman->getBouncer_x() + cameraX * -1, tribesman->getBouncer_y(), tribesman->getLarg(), tribesman->getAlt()) ||
				collider(lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg(), lancer->getAlt(), tribesman->getBouncer_x() + cameraX * -1, tribesman->getBouncer_y(), tribesman->getLarg(), tribesman->getAlt()) ||
				collider(banner->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg(), banner->getAlt(), tribesman->getBouncer_x() + cameraX * -1, tribesman->getBouncer_y(), tribesman->getLarg(), tribesman->getAlt()))
			{
				tribesman->field = tribesman->getAttack_sprite();
				tribesman->attackEnemy();
				knight->setHealth(knight->getHealth() - tribesman->getDamage()*.005);
				//char dano[4];
			}
			if (knight->getHealth() <= 0)
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_flip_display();
				al_rest(1);
				al_draw_text(font.font, al_map_rgb(255, 0, 0), SCREEN_W / 2.0, SCREEN_H / 2.0, ALLEGRO_ALIGN_CENTER, "YOU DIED");
				al_flip_display();
				al_rest(3);
				

				flag.doexit = true;
			}
			// A MESMA COISA SÓ Q PRO BOSS
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) //evento de fechar a telinha
		{
			break;
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
			
			cameraX = knight->getBouncer_x() - SCREEN_W / 2 + knight->getLarg() / 2;
			if (cameraX < 0) cameraX = 0;
			if (cameraX > worldW - SCREEN_W) cameraX = worldW - SCREEN_W;

			al_draw_scaled_bitmap(environment->image, 0, 0, 1920, 1080, cameraX * -1, 0, 1366, 768, 0); //background em escala
			al_draw_scaled_bitmap(environment->image, 0, 0, 1920, 1080, SCREEN_W + cameraX * -1, 0, 1366, 768, 0); //background em escala
			al_draw_scaled_bitmap(environment->image2, 0, 0, 1920, 1080, SCREEN_W * 2 + cameraX * -1, 0, 1366, 768, 0); //background em escala
			
			al_draw_bitmap(block->block, block->bouncer_x + cameraX * -1, block->bouncer_y, 0);
			al_draw_bitmap(block->block, block->bouncer_x + cameraX * -1 + BLOCK_W * 1, block->bouncer_y, 0);
			al_draw_bitmap(block->block, block->bouncer_x + cameraX * -1 + BLOCK_W * 2, block->bouncer_y, 0);
			al_draw_bitmap(block->block, block->bouncer_x + cameraX * -1 + BLOCK_W * 3, block->bouncer_y, 0);
			al_draw_bitmap(block->block, block->bouncer_x + cameraX * -1 + BLOCK_W * 4, block->bouncer_y, 0);
			al_draw_bitmap(block->block, block->bouncer_x + cameraX * -1 + BLOCK_W * 5, block->bouncer_y, 0);


			
			al_draw_scaled_bitmap(ghost->getWalk_sprite(), ghost->getX_atual(), ghost->getY_atual(), ghost->getLarg(), ghost->getAlt(), ghost->getBouncer_x() + cameraX * -1, ghost->getBouncer_y(), ghost->getLarg() * 2, ghost->getAlt() * 2, knight->getBouncer_x() - ghost->getBouncer_x() > 0 ? ALLEGRO_FLIP_HORIZONTAL : 0);
			// Tribesman print walk or attack
			if(tribesman->field == tribesman->getWalk_sprite())
				al_draw_scaled_bitmap(tribesman->field, tribesman->getX_atual(), tribesman->getY_atual(), tribesman->getLarg(), tribesman->getAlt(), tribesman->getBouncer_x() + cameraX * -1, tribesman->getBouncer_y(), tribesman->getLarg() * 3, tribesman->getAlt() * 3, tribesman->getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
			else
				al_draw_scaled_bitmap(tribesman->field, tribesman->getX_atk(), tribesman->getY_atk(), tribesman->getLarg_atk(), tribesman->getAlt_atk(), tribesman->getBouncer_x() + cameraX * -1, tribesman->getBouncer_y(), tribesman->getLarg_atk() * 3, tribesman->getAlt_atk() * 3, tribesman->getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
			// Barbarian print walk or attack
			if(barbarian->field == barbarian->getWalk_sprite())
				al_draw_scaled_bitmap(barbarian->field, barbarian->getX_atual(), barbarian->getY_atual(), barbarian->getLarg(), barbarian->getAlt(), barbarian->getBouncer_x() + cameraX * -1, barbarian->getBouncer_y(), barbarian->getLarg() * 3, barbarian->getAlt() * 3, barbarian->getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
			else
				al_draw_scaled_bitmap(barbarian->field, barbarian->getX_atk(), barbarian->getY_atk(), barbarian->getLarg_atk(), barbarian->getAlt_atk(), barbarian->getBouncer_x() + cameraX * -1, barbarian->getBouncer_y(), barbarian->getLarg_atk() * 3, barbarian->getAlt_atk() * 3, barbarian->getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
			
			// Barbarian walk load
			if (!collider(knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg(), HEIGHT, barbarian->getBouncer_x() + cameraX * -1, barbarian->getBouncer_y(), barbarian->getLarg(), barbarian->getAlt()))
			{
				barbarian->field = barbarian->getWalk_sprite();
				barbarian->moveEnemy(knight->getBouncer_x(), knight->getBouncer_y());
			}
			// Tribesman walk load
			if (!collider(knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg(), HEIGHT, tribesman->getBouncer_x() + cameraX * -1, tribesman->getBouncer_y(), tribesman->getLarg(), tribesman->getAlt()))
			{
				tribesman->field = tribesman->getWalk_sprite();
				tribesman->moveEnemy(knight->getBouncer_x(), knight->getBouncer_y());
			}
			// Ghost
			if (!collider(knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg(), HEIGHT, ghost->getBouncer_x() + cameraX * -1, ghost->getBouncer_y(), ghost->getLarg(), ghost->getAlt()))
			{
				ghost->moveEnemy(knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y());
			}

			if (flag.atk_x == true && flag.atk == false) //atk Lancer
			{
				if (lancer->getLeft())
				{
					al_draw_scaled_bitmap(lancer->getAttack_sprite(), lancer->getX_atk(), lancer->getY_atk(), lancer->getLarg_atk(), lancer->getAlt_atk(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg_atk() * 3, lancer->getAlt_atk() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
					al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), banner->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				}
				else
				{
					al_draw_scaled_bitmap(lancer->getAttack_sprite(), lancer->getX_atk(), lancer->getY_atk(), lancer->getLarg_atk(), lancer->getAlt_atk(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg_atk() * 3, lancer->getAlt_atk() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
					al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				}
			}
			if (flag.atk == true && flag.atk_x == false) //Atk Knight
			{
				if (knight->getLeft())
				{
					al_draw_scaled_bitmap(knight->getAttack_sprite(), knight->getX_atk(), knight->getY_atk(), knight->getLarg_atk(), knight->getAlt_atk(), banner->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg_atk() * 3, knight->getAlt_atk() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
					al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				}
				else
				{
					al_draw_scaled_bitmap(knight->getAttack_sprite(), knight->getX_atk(), knight->getY_atk(), knight->getLarg_atk(), knight->getAlt_atk(), knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg_atk() * 3, knight->getAlt_atk() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
					al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				}
			}
			if (flag.atk == true || flag.atk_x == true)
			{
				if (banner->getLeft())
					al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), knight->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				else
					al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), banner->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
			}
			knight->attack(&flag.atk, &flag.atk_x, key);
			lancer->attack(&flag.atk, &flag.atk_x, key);
			banner->attack(&flag.atk, &flag.atk_x, key);
			
			if ((flag.atk == false && flag.atk_x == false) || (flag.atk == true && flag.atk_x == true))
			{
				if (knight->getLeft())
				{
					
					al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
					al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), banner->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
					al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), knight->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				}
				else
				{
					al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
					al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
					al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), banner->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
				}
			}
			al_draw_bitmap(off_bar, 19, 99, 0);
			char health_counter[30];
			al_destroy_bitmap(health_bar);
			health_bar = al_create_bitmap((80*knight->getHealth()/100), 10);
			al_set_target_bitmap(health_bar);
			al_clear_to_color(al_map_rgb(0, 255, 0));
			al_set_target_bitmap(al_get_backbuffer(display->display));

			al_draw_bitmap(health_bar, 20, 100, 0);
			sprintf_s(health_counter, "%.2f", knight->getHealth());
			al_draw_bitmap(knight->getIcon(), 15, 20, 0);
			al_draw_text(font.font, al_map_rgb(0, 255, 0), 60, 60, ALLEGRO_ALIGN_CENTER, health_counter);
			al_draw_bitmap(mouse.mouse, mouse.bouncer_x, mouse.bouncer_y, 0); //mouse
			al_flip_display();
		}
	}
}

uint8_t Game::collider(float x1, float y1, int larg1, int alt1, float x2, float y2, int larg2, int alt2)
{
	//Y É INVERTIDO SEU BURRO
	if (x2 > x1)
	{
		if (larg1 / 1.5 + larg2 / 1.5 >= x2 - x1)
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if (larg1 / 1.5 + larg2 / 1.5 <= x2 - x1)
		{
			return 1;
		}
		else
			return 0;
	}
	if (y2 < y1)
	{
		if (alt1 / 2 + alt2 / 2 <= y2 - y1)
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if (alt1 / 2 + alt2 / 2 <= y2 - y1)
		{
			return 1;
		}
		else
			return 0;
	}
	
	return 0;
}