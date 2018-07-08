#include "Menu.h"
#include "Game.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

Menu::Menu()
{
	menu_picture = al_load_bitmap("Desert.png");
}
Menu::~Menu()
{
	al_destroy_bitmap(menu_picture);
}


void Menu::drawMenu(Game* game)
{
	ALLEGRO_EVENT ev_menudo;
	al_wait_for_event(game->getEvent_queue(), &ev_menudo);
	if (ev_menudo.type == ALLEGRO_EVENT_MOUSE_AXES || ev_menudo.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) //evento de movimentaçao do mouse
	{
		game->getMouse()->bouncer_x = ev_menudo.mouse.x;
		game->getMouse()->bouncer_y = ev_menudo.mouse.y;
	}
	else if (ev_menudo.type == ALLEGRO_EVENT_TIMER)  //dps que a tecla é pressionada rola isso aqui
	{

	}
	if (ev_menudo.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		game->flag.menu = game->flag.finish = game->flag.doexit = false;
	}
	else if (ev_menudo.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (ev_menudo.keyboard.keycode)
		{
		case ALLEGRO_KEY_LEFT:
			game->key[game->KEY_LEFT] = true;
			if (game->flag.button1 == true)
			{
				game->flag.button1 = false;
				game->flag.button2 = false;
				game->flag.button3 = true;
			}
			else if (game->flag.button2 == true)
			{
				game->flag.button1 = true;
				game->flag.button2 = false;
				game->flag.button3 = false;
			}
			else if (game->flag.button3 == true)
			{
				game->flag.button3 = false;
				game->flag.button2 = true;
				game->flag.button1 = false;
			}
			break;

		case ALLEGRO_KEY_RIGHT:
			game->key[game->KEY_RIGHT] = true;
			if (game->flag.button1 == true)
			{
				game->flag.button1 = false;
				game->flag.button2 = true;
				game->flag.button3 = false;
			}
			else if (game->flag.button2 == true)
			{
				game->flag.button1 = false;
				game->flag.button2 = false;
				game->flag.button3 = true;
			}
			else if (game->flag.button3 == true)
			{
				game->flag.button3 = false;
				game->flag.button2 = false;
				game->flag.button1 = true;
			}
			break;
		case ALLEGRO_KEY_ENTER:
			game->key[game->ENTER_KEY] = true;
			if (game->flag.button1 == true)
			{
				game->flag.menu = false;
				game->flag.doexit = true;
			}
			else if (game->flag.button2 == true)
			{
				game->setStage(2);
				game->flag.menu = false;
				game->flag.doexit = true;
				game->flag.stage1 = false;
				game->flag.stage2 = true;
				game->flag.stage3 = false;
				game->s2.buildStage(game);
			}
			else if (game->flag.button3 == true)
			{
				game->flag.menu = game->flag.finish = game->flag.doexit = false;
			}
		}
	}
	else if (ev_menudo.type == ALLEGRO_EVENT_KEY_UP) //evento de tecla solta
	{
		switch (ev_menudo.keyboard.keycode)
		{
		case ALLEGRO_KEY_LEFT:
			game->key[game->KEY_LEFT] = false;
			break;

		case ALLEGRO_KEY_RIGHT:
			game->key[game->KEY_RIGHT] = false;
			break;

		case ALLEGRO_KEY_ESCAPE:
			game->flag.menu = false;
			game->flag.finish = false;
			game->flag.doexit = false;
			break;
		}
	}

	if (game->flag.redraw && al_is_event_queue_empty(game->getEvent_queue()))
	{
		al_draw_scaled_bitmap(game->getEnvironment()->imagev1, 0, 0, 900, 449, 0, 0, 1366, 768, 0);
		if (game->flag.button1 == true)
			al_draw_text(game->getFont()->font2, al_map_rgb(255, 0, 0), 250, 768 / 1.5, ALLEGRO_ALIGN_CENTER, "Jogar");
		else
			al_draw_text(game->getFont()->font2, al_map_rgb(255, 255, 255), 250, 768 / 1.5, ALLEGRO_ALIGN_CENTER, "Jogar");

		if (game->flag.button2 == true)
		{
			al_draw_text(game->getFont()->font2, al_map_rgb(255, 0, 0), 700, 768 / 1.5, ALLEGRO_ALIGN_CENTER, "Fase 2");
		}
		else
			al_draw_text(game->getFont()->font2, al_map_rgb(255, 255, 255), 700, 768 / 1.5, ALLEGRO_ALIGN_CENTER, "Fase 2");

		if (game->flag.button3 == true)
		{
			al_draw_text(game->getFont()->font2, al_map_rgb(255, 0, 0), 1100, 768 / 1.5, ALLEGRO_ALIGN_CENTER, "Sair");
		}
		else
		{
			al_draw_text(game->getFont()->font2, al_map_rgb(255, 255, 255), 1100, 768 / 1.5, ALLEGRO_ALIGN_CENTER, "Sair");
		}
		al_draw_text(game->getFont()->font3, al_map_rgb(255, 255, 255), 550, 256, ALLEGRO_ALIGN_CENTER, "Knights of ");
		al_draw_text(game->getFont()->font4, al_map_rgb(255, 255, 255), 830, 256, ALLEGRO_ALIGN_CENTER, "Pixel");
		al_flip_display();
	}

}
void Menu::buildRanking(float score)
{
	string name;
	ofstream outFile;

	outFile.open("Ranking.txt");
	if (!outFile)
	{
		cout << "erro test.txt" << endl;
		abort();
	}

	cout << "Name: ";
	cin >> name;
	outFile << "Score: " <<  score << " Nome: " << name << '\n';
	cout << "Salvo com sucesso! ";

	outFile.close();
}