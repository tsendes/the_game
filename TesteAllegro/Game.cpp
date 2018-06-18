#include "Game.h"


Game::Game()
{
	event_queue = al_create_event_queue();
	tick_s = al_create_timer(1.0 / FPS);
	register_interrupts();

	health_bar = al_create_bitmap(80, 10);
	al_set_target_bitmap(health_bar);
	al_clear_to_color(al_map_rgb(0, 255, 0));
	al_set_target_bitmap(al_get_backbuffer(display->display));

	off_bar = al_create_bitmap(82, 12);
	al_set_target_bitmap(off_bar);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_set_target_bitmap(al_get_backbuffer(display->display));

	adjust1 = 1.0;
	adjust2 = 1.0;
	adjust3 = 1.0;
	
	srand(time(NULL));

	
	for (int i = 0; i < num_bar; i++)
	{	
		ghost[i] = new Ghost;
		barbarian[i] = new Barbarian;
		barbarian[i]->setBouncer_x(barbarian[i]->getBouncer_x() + rand() % 948);
		ghost[i]->setBouncer_x(ghost[i]->getBouncer_x() + rand() % 1548);
	}
	for (int i = 0; i < 6; i++)
	{
		block[i] = new Block;
		block[i]->field = block[i]->desert;
		block[i]->setBouncer_x(800*i);
	}

	cameraX = 0;
	worldW = SCREEN_W * 3;
	

	al_hide_mouse_cursor(display->display); 
	al_start_timer(tick_s); 
	run_game();
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
		if (!block[0]->block)
		{
			al_show_native_message_box(display->display, "Error", "Error", "failed to create field block!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
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
	al_clear_to_color(al_map_rgb(0, 0, 0)); //fundo inicial preto
	al_set_window_title(display->display, "Knights of Pixel"); //da um nome para a janela do jogo
	al_draw_text(font.font, al_map_rgb(255, 255, 255), SCREEN_W / 2.0, SCREEN_H / 2.0, ALLEGRO_ALIGN_CENTER, "Carregando... Aguarde"); //printa na tela a msg

	//al_draw_bitmap(s1.getListEnt()->getNextE(0)->getpInfo()->field, 50, 120, 0);
	//al_draw_bitmap(s1.getListEnt()->getNextE(1)->getpInfo()->field, 100, 120, 0);

	al_flip_display(); //troca o display visual pelo modificavel
	al_rest(1); //aguarda X segundos ate continuar
}

void Game::run_game()
{
	//my_stage1->buildStage1(this);
	error_check();
	draw_screen();
	int timer = 0;
	while (flag.finish)
	{
		while (flag.menu)
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
					if (flag.button1 == true)
					{
						flag.button1 = false;
						flag.button2 = true;
					}
					else if (flag.button2 == true)
					{
						flag.button1 = true;
						flag.button2 = false;
					}
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_RIGHT] = true;
					if (flag.button1 == true)
					{
						flag.button1 = false;
						flag.button2 = true;
					}
					else if (flag.button2 == true)
					{
						flag.button1 = true;
						flag.button2 = false;
					}
					//else if (flag.button3 == true)
					//{
					//
					//}
					break;
				case ALLEGRO_KEY_Z:
					key[Z_KEY] = true;
					break;
				case ALLEGRO_KEY_X:
					key[X_KEY] = true;
					break;
				case ALLEGRO_KEY_ENTER:
					key[ENTER_KEY] = true;
					if (flag.button1 == true)
					{
						flag.menu = false;
						flag.doexit = true;
					}
					else if (flag.button2 == true)
					{
						flag.menu = flag.finish = flag.doexit = false;
					}
				}
			}
			else if (ev_menudo.type == ALLEGRO_EVENT_KEY_UP) //evento de tecla solta
			{
				switch (ev_menudo.keyboard.keycode)
				{
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
					flag.menu = false;
					flag.finish = true;
					break;
				}
			}

			if (flag.redraw && al_is_event_queue_empty(event_queue))
			{
				al_draw_scaled_bitmap(environment->imagev1, 0, 0, 900, 449, 0, 0, 1366, 768, 0);
				if(flag.button1 == true)
					al_draw_text(font.font2, al_map_rgb(255, 0, 0), 350, SCREEN_H / 1.5, ALLEGRO_ALIGN_CENTER, "Jogar");
				else
					al_draw_text(font.font2, al_map_rgb(255, 255, 255), 350, SCREEN_H / 1.5, ALLEGRO_ALIGN_CENTER, "Jogar");

				if (flag.button2 == true)
				{
					al_draw_text(font.font2, al_map_rgb(255, 0, 0), 950, SCREEN_H / 1.5, ALLEGRO_ALIGN_CENTER, "Sair");
				}
				else
					al_draw_text(font.font2, al_map_rgb(255, 255, 255), 950, SCREEN_H / 1.5, ALLEGRO_ALIGN_CENTER, "Sair");
				
				al_draw_text(font.font3, al_map_rgb(255, 255, 255), SCREEN_W / 2.1 - 70, SCREEN_H / 3, ALLEGRO_ALIGN_CENTER, "Knights of ");
				al_draw_text(font.font4, al_map_rgb(255, 255, 255), SCREEN_W / 1.5 - 70, SCREEN_H / 3, ALLEGRO_ALIGN_CENTER, "Pixel");
				al_flip_display();
			}
		}
		while (flag.doexit) //enquanto nao for decidido que é o fim do programa
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
				knight->move(&timer, &adjust1, SCREEN_W + cameraX, SCREEN_H, &flag.redraw, &flag.exaust, key);
				if(getStage() == 2 || getStage() == 3)
					lancer->move(&timer, &adjust2, SCREEN_W + cameraX, SCREEN_H, &flag.redraw, &flag.exaust, key);
				if(getStage() == 3)
					banner->move(&timer, &adjust3, SCREEN_W + cameraX, SCREEN_H, &flag.redraw, &flag.exaust, key);

				if (knight->getHealth() <= 0)
				{
					al_clear_to_color(al_map_rgb(0, 0, 0));
					al_flip_display();
					al_rest(1);
					al_draw_text(font.font, al_map_rgb(255, 0, 0), SCREEN_W / 2.0, SCREEN_H / 2.0, ALLEGRO_ALIGN_CENTER, "YOU DIED");
					al_flip_display();
					al_rest(3);

					flag.doexit = false;
					flag.menu = true;
					setStage(1);
					createGame(this);
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
					break;

				case ALLEGRO_KEY_RIGHT:
					key[KEY_RIGHT] = true;
					break;
				case ALLEGRO_KEY_Z:
					key[Z_KEY] = true;
					flag.atk = true;
					break;
				case ALLEGRO_KEY_X:
					if (stage >= 2)
					{
						key[X_KEY] = true;
						flag.atk_x = true;
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

				al_draw_scaled_bitmap(environment->imagev1, 0, 0, environment->w, environment->h, cameraX * -1, 0, 1366, 768, 0); //background em escala
				al_draw_scaled_bitmap(environment->imagev2, 0, 0, environment->w, environment->h, SCREEN_W + cameraX * -1, 0, 1366, 768, 0); //background em escala
				al_draw_scaled_bitmap(environment->imagev3, 0, 0, environment->w, environment->h, SCREEN_W * 2 + cameraX * -1, 0, 1366, 768, 0); //background em escala

				for (int i = 0; i < 6; i++)
					al_draw_bitmap(block[i]->field, block[i]->getBouncer_x() + cameraX * -1, block[i]->getBouncer_y(), 0);


				for (int i = 0; i < num_bar; i++)
				{
					if (getStage() == 1 || getStage() == 2)
					{
						// Ghost
						if (ghost[i]->getisPresent())
						{
							al_draw_scaled_bitmap(ghost[i]->getWalk_sprite(), ghost[i]->getX_atual(), ghost[i]->getY_atual(), ghost[i]->getLarg(), ghost[i]->getAlt(), ghost[i]->getBouncer_x() + cameraX * -1, ghost[i]->getBouncer_y(), ghost[i]->getLarg() * 2, ghost[i]->getAlt() * 2, knight->getBouncer_x() - ghost[i]->getBouncer_x() > 0 ? ALLEGRO_FLIP_HORIZONTAL : 0);
							if (!colliderY(knight->getBouncer_y(), HEIGHT, ghost[i]->getBouncer_y(), ghost[i]->getAlt()) || !colliderX(knight->getBouncer_x(), knight->getLarg(), ghost[i]->getBouncer_x(), ghost[i]->getLarg()))
							{
								ghost[i]->moveEnemy(knight->getBouncer_x(), knight->getBouncer_y());
							}
							if (ghost[i]->getHealth() <= 0)
							{
								ghost[i]->setisPresent(false);
							}

							if (colliderX(knight->getBouncer_x() + cameraX * -1, knight->getLarg(), ghost[i]->getBouncer_x() + cameraX * -1, ghost[i]->getLarg()) && colliderY(knight->getBouncer_y(),HEIGHT , ghost[i]->getBouncer_y(), ghost[i]->getAlt()) ||
								colliderX(lancer->getBouncer_x() + cameraX * -1, lancer->getLarg(), ghost[i]->getBouncer_x() + cameraX * -1, ghost[i]->getLarg()) && colliderY(lancer->getBouncer_y(), HEIGHT, ghost[i]->getBouncer_y(), ghost[i]->getAlt()))
							{
								knight->setHealth(knight->getHealth() - ghost[i]->getDamage()*.007);
								if (flag.atk && !flag.atk_x)
								{
									ghost[i]->setHealth(ghost[i]->getHealth() - knight->getDamage());
								}
								if (flag.atk_x && !flag.atk)
								{
									ghost[i]->setHealth(ghost[i]->getHealth() - lancer->getDamage());
								}
							}
						}
					}
					if (getStage() == 2)
					{
						// Tribesman
						if (tribesman[i]->getisPresent())
						{
							if (tribesman[i]->field == tribesman[i]->getWalk_sprite())
								al_draw_scaled_bitmap(tribesman[i]->field, tribesman[i]->getX_atual(), tribesman[i]->getY_atual(), tribesman[i]->getLarg(), tribesman[i]->getAlt(), tribesman[i]->getBouncer_x() + cameraX * -1, tribesman[i]->getBouncer_y(), tribesman[i]->getLarg() * 3, tribesman[i]->getAlt() * 3, tribesman[i]->getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
							else
								al_draw_scaled_bitmap(tribesman[i]->field, tribesman[i]->getX_atk(), tribesman[i]->getY_atk(), tribesman[i]->getLarg_atk(), tribesman[i]->getAlt_atk(), tribesman[i]->getBouncer_x() + cameraX * -1, tribesman[i]->getBouncer_y(), tribesman[i]->getLarg_atk() * 3, tribesman[i]->getAlt_atk() * 3, tribesman[i]->getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
							if (!colliderX(knight->getBouncer_x(), knight->getLarg(), tribesman[i]->getBouncer_x(), tribesman[i]->getLarg()))
							{
								tribesman[i]->field = tribesman[i]->getWalk_sprite();
								tribesman[i]->moveEnemy(knight->getBouncer_x(), knight->getBouncer_y());
							}
							if (tribesman[i]->getHealth() <= 0)
							{
								tribesman[i]->setisPresent(false);
							}
							if (colliderX(knight->getBouncer_x() + cameraX * -1, knight->getLarg(), tribesman[i]->getBouncer_x() + cameraX * -1, tribesman[i]->getLarg()) ||
								colliderX(lancer->getBouncer_x() + cameraX * -1, lancer->getLarg(), tribesman[i]->getBouncer_x() + cameraX * -1, tribesman[i]->getLarg()))
							{
								tribesman[i]->field = tribesman[i]->getAttack_sprite();
								tribesman[i]->attackEnemy();
								knight->setHealth(knight->getHealth() - tribesman[i]->getDamage()*.005);
								if (flag.atk && !flag.atk_x)
								{
									tribesman[i]->setHealth(tribesman[i]->getHealth() - knight->getDamage());
								}
								if (!flag.atk && flag.atk_x)
								{
									tribesman[i]->setHealth(tribesman[i]->getHealth() - lancer->getDamage());
								}
							}

						}
					}
					if (getStage() == 1)
					{
						// Barbarian
						if (barbarian[i]->getisPresent())
						{
							if (barbarian[i]->field == barbarian[i]->getWalk_sprite())
								al_draw_scaled_bitmap(barbarian[i]->field, barbarian[i]->getX_atual(), barbarian[i]->getY_atual(), barbarian[i]->getLarg(), barbarian[i]->getAlt(), barbarian[i]->getBouncer_x() + cameraX * -1, barbarian[i]->getBouncer_y(), barbarian[i]->getLarg() * 3, barbarian[i]->getAlt() * 3, barbarian[i]->getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
							else
								al_draw_scaled_bitmap(barbarian[i]->field, barbarian[i]->getX_atk(), barbarian[i]->getY_atk(), barbarian[i]->getLarg_atk(), barbarian[i]->getAlt_atk(), barbarian[i]->getBouncer_x() + cameraX * -1, barbarian[i]->getBouncer_y(), barbarian[i]->getLarg_atk() * 3, barbarian[i]->getAlt_atk() * 3, barbarian[i]->getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
							
							if (!colliderX(knight->getBouncer_x(), knight->getLarg(), barbarian[i]->getBouncer_x(), barbarian[i]->getLarg()) && barbarian[i]->getInvencible() == false)
							{
								barbarian[i]->field = barbarian[i]->getWalk_sprite();
								barbarian[i]->moveEnemy(knight->getBouncer_x(), knight->getBouncer_y());
							}
							if (barbarian[i]->getHealth() <= 0)
							{
								barbarian[i]->setisPresent(false);
							}
							if (colliderX(knight->getBouncer_x() + cameraX * -1, knight->getLarg(), barbarian[i]->getBouncer_x() + cameraX * -1, barbarian[i]->getLarg()) ||
								colliderX(lancer->getBouncer_x() + cameraX * -1, lancer->getLarg(), barbarian[i]->getBouncer_x() + cameraX * -1, barbarian[i]->getLarg()))
							{

								if (barbarian[i]->getInvencible() == false)
								{
									barbarian[i]->field = barbarian[i]->getAttack_sprite();
									barbarian[i]->attackEnemy();
									knight->setHealth(knight->getHealth() - barbarian[i]->getDamage()*.007);
								}
								if (flag.atk && !flag.atk_x && barbarian[i]->getInvencible() == false)
								{
									barbarian[i]->setHealth(barbarian[i]->getHealth() - knight->getDamage());
									barbarian[i]->setBouncer_x(barbarian[i]->getBouncer_x() + 100);
									barbarian[i]->setInvencible(true);
								}
								else if (!flag.atk && flag.atk_x && barbarian[i]->getInvencible() == false)
								{
									barbarian[i]->setHealth(barbarian[i]->getHealth() - lancer->getDamage());
									barbarian[i]->setBouncer_x(barbarian[i]->getBouncer_x() + 100);
									barbarian[i]->setInvencible(true);
								}
								
							}
							if(barbarian[i]->getInvencible() == true)
							{
								barbarian[i]->setCount_inv(barbarian[i]->getCount_inv() - 1);
								barbarian[i]->setBouncer_x(barbarian[i]->getBouncer_x() + 2); //bloquear movimento
								if (barbarian[i]->getCount_inv() <= 0)
								{
									barbarian[i]->setCount_inv(60);
									barbarian[i]->setInvencible(false);
								}
							}
						}
					}
				}
				if (getStage() == 3)
				{
					if (boss.getisPresent())
					{
						if (boss.field == boss.getWalk_sprite())
							al_draw_scaled_bitmap(boss.field, boss.getX_atual(), boss.getY_atual(), boss.getLarg(), boss.getAlt(), boss.getBouncer_x() + cameraX * -1, boss.getBouncer_y(), boss.getLarg() * 3, boss.getAlt() * 3, boss.getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
						else
							al_draw_scaled_bitmap(boss.field, boss.getX_atk(), boss.getY_atk(), boss.getLarg_atk(), boss.getAlt_atk(), boss.getBouncer_x() + cameraX * -1, boss.getBouncer_y(), boss.getLarg_atk() * 3, boss.getAlt_atk() * 3, boss.getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);

						if (!colliderX(knight->getBouncer_x() + cameraX * -1, knight->getLarg(), boss.getBouncer_x() + cameraX * -1, boss.getLarg()) && !colliderY(knight->getBouncer_y(), HEIGHT, boss.getBouncer_y(), boss.getAlt()))
						{
							if (boss.getHealth() >= 2500)
							{
								boss.field = boss.getWalk_sprite();
								boss.moveEnemy(knight->getBouncer_x(), knight->getBouncer_y());
							}
						}
						else
						{
							boss.field = boss.getAttack_sprite();
							boss.attackEnemy();
							knight->setHealth(knight->getHealth() - boss.getDamage()*.007);

							if (flag.atk && !flag.atk_x)
							{
								if (boss.getInvencible() == false)
								{
									boss.setHealth(boss.getHealth() - knight->getDamage());
									boss.setInvencible(true);
								}
								else
								{
									boss.setCount_inv(boss.getCount_inv() - 1);
									if (boss.getCount_inv() <= 0)
									{
										boss.setInvencible(false);
										boss.setCount_inv(30);
									}
								}
									
								
							}
							if (!flag.atk && flag.atk_x)
							{
								boss.setHealth(boss.getHealth() - lancer->getDamage());
							}
							
						}
						if (boss.getHealth() <= 2500)
						{
							boss.field = boss.getUlt_sprite();
							al_draw_scaled_bitmap(boss.field, boss.getX_atk(), boss.getY_atk(), boss.getLarg_atk(), boss.getAlt_atk(), boss.getBouncer_x(), boss.getBouncer_y(), boss.getLarg_atk() * 3, boss.getAlt_atk() * 3, boss.getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
							knight->setHealth(knight->getHealth() - boss.getDamage_Ult()*.003);
						}
						if (boss.getHealth() <= 0)
						{
							boss.setisPresent(false);
							al_clear_to_color(al_map_rgb(0, 0, 0));
							al_flip_display();
							al_rest(1);
							al_draw_text(font.font, al_map_rgb(184, 134, 11), SCREEN_W / 2.0, SCREEN_H / 2.0, ALLEGRO_ALIGN_CENTER, "VICTORY ACHIEVED");
							al_flip_display();
							al_rest(3);

							flag.doexit = false;
							flag.menu = true;
							setStage(1);
							createGame(this);
						}
					}

				}
				if (flag.atk == true && flag.atk_x == false) //Atk Knight
				{
					if (knight->getLeft())
					{
						if (getStage() == 3)
						{
							al_draw_scaled_bitmap(knight->getAttack_sprite(), knight->getX_atk(), knight->getY_atk(), knight->getLarg_atk(), knight->getAlt_atk(), banner->getBouncer_x() + cameraX * -1 - 35, knight->getBouncer_y(), knight->getLarg_atk() * 3, knight->getAlt_atk() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), knight->getBouncer_x() + cameraX * -1 - 35, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), knight->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						}
						else if (getStage() == 2)
						{
							al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), knight->getBouncer_x() + cameraX * -1 - 35, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(knight->getAttack_sprite(), knight->getX_atk(), knight->getY_atk(), knight->getLarg_atk(), knight->getAlt_atk(), lancer->getBouncer_x() + cameraX * -1 - 35, knight->getBouncer_y(), knight->getLarg_atk() * 3, knight->getAlt_atk() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						}
						else if(getStage() == 1)
						{
							al_draw_scaled_bitmap(knight->getAttack_sprite(), knight->getX_atk(), knight->getY_atk(), knight->getLarg_atk(), knight->getAlt_atk(), knight->getBouncer_x() + cameraX * -1 - 35, knight->getBouncer_y(), knight->getLarg_atk() * 3, knight->getAlt_atk() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						}
					}
					else
					{
						al_draw_scaled_bitmap(knight->getAttack_sprite(), knight->getX_atk(), knight->getY_atk(), knight->getLarg_atk(), knight->getAlt_atk(), knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg_atk() * 3, knight->getAlt_atk() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);

						if (getStage() > 1)
						{
							al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							if(getStage() > 2)
								al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), banner->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						}
					}
				}
				if (flag.atk_x == true && flag.atk == false && getStage() > 1) //atk Lancer
				{
					if (lancer->getLeft())
					{
						if (getStage() == 3)
						{
							al_draw_scaled_bitmap(lancer->getAttack_sprite(), lancer->getX_atk(), lancer->getY_atk(), lancer->getLarg_atk(), lancer->getAlt_atk(), lancer->getBouncer_x() + cameraX * -1 , lancer->getBouncer_y(), lancer->getLarg_atk() * 3, lancer->getAlt_atk() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), banner->getBouncer_x() + cameraX * -1 , knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), knight->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						}
						else if (getStage() == 2)
						{
							al_draw_scaled_bitmap(lancer->getAttack_sprite(), lancer->getX_atk(), lancer->getY_atk(), lancer->getLarg_atk(), lancer->getAlt_atk(), knight->getBouncer_x() + cameraX * -1 - 35, lancer->getBouncer_y(), lancer->getLarg_atk() * 3, lancer->getAlt_atk() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), lancer->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						}
					}
					else
					{
						al_draw_scaled_bitmap(lancer->getAttack_sprite(), lancer->getX_atk(), lancer->getY_atk(), lancer->getLarg_atk(), lancer->getAlt_atk(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg_atk() * 3, lancer->getAlt_atk() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						if(getStage() > 2)
							al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), banner->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
					}
				}
				knight->attack(&flag.atk, &flag.atk_x, key);

				if(getStage() > 1)
					lancer->attack(&flag.atk, &flag.atk_x, key);

				if ((flag.atk == false && flag.atk_x == false) || (flag.atk == true && flag.atk_x == true))
				{
					if (knight->getLeft())
					{
						if(getStage() == 1)
							al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						else if (getStage() == 2)
						{
							al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), lancer->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), knight->getBouncer_x() + cameraX * -1 - 35, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						}
						else
						{
							al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), banner->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), knight->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						}
					}
					else
					{
						if(getStage() == 1)
							al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						else if (getStage() == 2)
						{
							al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						}
						else
						{
							al_draw_scaled_bitmap(knight->getWalk_sprite(), knight->getX_atual(), knight->getY_atual(), knight->getLarg(), knight->getAlt(), knight->getBouncer_x() + cameraX * -1, knight->getBouncer_y(), knight->getLarg() * 3, knight->getAlt() * 3, knight->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(lancer->getWalk_sprite(), lancer->getX_atual(), lancer->getY_atual(), lancer->getLarg(), lancer->getAlt(), lancer->getBouncer_x() + cameraX * -1, lancer->getBouncer_y(), lancer->getLarg() * 3, lancer->getAlt() * 3, lancer->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
							al_draw_scaled_bitmap(banner->getWalk_sprite(), banner->getX_atual(), banner->getY_atual(), banner->getLarg(), banner->getAlt(), banner->getBouncer_x() + cameraX * -1, banner->getBouncer_y(), banner->getLarg() * 3, banner->getAlt() * 3, banner->getLeft() ? ALLEGRO_FLIP_HORIZONTAL : 0);
						}
					}
				}
				al_draw_bitmap(off_bar, 19, 99, 0);
				char health_counter[30];
				al_destroy_bitmap(health_bar);
				health_bar = al_create_bitmap((80 * knight->getHealth() / 100), 10);
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
			if (knight->getBouncer_x() >= (float)4000)
			{
				setStage(getStage() + 1/*++*/);
				createGame(this);
			}
		}
	}
}

uint8_t Game::colliderX(float x1, int larg1, float x2, int larg2)
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
	
	return 0;
}
uint8_t Game::colliderY(float y1, int alt1, float y2, int alt2)
{
	if (y2 < y1)
	{
		if (alt1 / 2 - alt2 / 2 <= y2 - y1)
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if (alt1 / 2 - alt2 / 2 <= y2 - y1)
		{
			return 1;
		}
		else
			return 0;
	}

	return 0;
}
void Game::createGame(Game* stage)
{
	if (stage->getStage() == 1)
	{
		//s1.buildStage1();
		srand(time(NULL));
		for (int i = 0; i < num_bar; i++)
		{
			
			ghost[i] = new Ghost;
			barbarian[i] = new Barbarian;

			barbarian[i]->setBouncer_x(barbarian[i]->getBouncer_x() + rand() % 1348);
			ghost[i]->setBouncer_x(ghost[i]->getBouncer_x() + rand() % 2348);
		}

		cameraX = 0;
		worldW = SCREEN_W * 3;
		knight->setBouncer_x(144);
		lancer->setBouncer_x(69);
		banner->setBouncer_x(5);
		knight->setHealth(100);

		for (int i = 0; i < 6; i++)
			block[i]->field = block[i]->desert;

		mouse.mouse = mouse.undead;
		environment->imagev1 = environment->image1;
		environment->imagev2 = environment->image2;
		environment->imagev3 = environment->image3;
		environment->w = 1920;
		environment->h = 1080;

		draw_screen();
		run_game();
	}
	else if (stage->getStage() == 2)
	{
		if (knight->getHealth() > 0)
		{
			for (int i = 0; i < num_ghost; i++)
				delete(barbarian[i]);
			for (int i = 0; i < num_bar; i++)
				delete(ghost[i]);
			for (int i = 0; i < 6; i++)
				block[i]->block = block[i]->forest;
		}
		mouse.mouse = mouse.orc;
		environment->imagev1 = environment->image4;
		environment->imagev2 = environment->image5;
		environment->imagev3 = environment->image6;
		environment->w = 900;
		environment->h = 449;

		//s1.buildStage1();

		for (int i = 0; i < num_bar; i++)
		{
			srand(time(NULL));
			ghost[i] = new Ghost;
			tribesman[i] = new Tribesman;

			tribesman[i]->setBouncer_x(tribesman[i]->getBouncer_x() + rand() % 1948);
			ghost[i]->setBouncer_x(ghost[i]->getBouncer_x() + rand() % 3948);
		}

		cameraX = 0;
		knight->setBouncer_x(35);
		lancer->setBouncer_x(5);
		worldW = SCREEN_W * 3;

		draw_screen();
		run_game();
	}
	else if(stage->getStage() == 3)
	{
		if (knight->getHealth() > 0)
		{
			for (int i = 0; i < num_trib; i++)
				delete(tribesman[i]);
			for (int i = 0; i < num_bar; i++)
				delete(ghost[i]);
		}
		//s1.buildStage1();

		boss.create_Boss();

		cameraX = 0;
		worldW = SCREEN_W;
		knight->setBouncer_x(40);
		lancer->setBouncer_x(10);
		for (int i = 0; i < 6; i++)
			block[i]->field = block[i]->boss;
		mouse.mouse = mouse.night_elf;
		environment->imagev1 = environment->image7;
		environment->imagev2 = environment->image7;
		environment->imagev3 = environment->image7;
		environment->w = 1920;
		environment->h = 1080;

		draw_screen();
		run_game();
	}
	else
	{
		flag.doexit = false;
		flag.finish = true;
		flag.menu = true;
	}
}