#include "Stage1.h"

Stage1::Stage1()
{
	
}
Stage1::~Stage1()
{

}
void Stage1::buildList()
{
	lEnt = new ListEnt;
	lEnt->setlEntity(new Chart<Entity>);
	lEnt->setlBlock(new Chart<Block>);
	lEnt->includeEnt(new Knight);
	lEnt->includeEnt(new Lancer);
}
void Stage1::destroyStage1()
{
	//delete(stage); //mexer nisso dps
}
/*void Stage1::addToList(Game* stage)
{
	stage->setEnvironment(new Background); //plano de fundo da telinha

	stage->setBlock(new Block); //bloco de areia

//Jogador--------------------------------------------------//
	stage->setKnight(new Knight);
	//Banner banner;
	//Lancer lancer;

//Inimigos--------------------------------------------------//
	stage->setGhost(new Ghost);
	stage->setBarbarian(new Barbarian);
	//Tribesman tribesman;
}*/
/*void Stage1::buildStage1(Game* stage)
{
	*health_bar = al_create_bitmap(80, 10);
	al_set_target_bitmap(health_bar);
	al_clear_to_color(al_map_rgb(0, 255, 0));
	al_set_target_bitmap(al_get_backbuffer(display->display));

	off_bar = al_create_bitmap(82, 12);
	al_set_target_bitmap(off_bar);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_set_target_bitmap(al_get_backbuffer(display->display));
	//s1.buildStage1();

	for (int i = 0; i < num_bar; i++)
	{
		srand(time(NULL));
		ghost[i] = new Ghost;
		barbarian[i] = new Barbarian;
		//tribesman[i] = new Tribesman;
		barbarian[i]->setBouncer_x(barbarian[i]->getBouncer_x() + rand() % 1948);
		//al_rest(1);
		//tribesman[i]->setBouncer_x(tribesman[i]->getBouncer_x() + rand() % 948);
		//al_rest(1);
		ghost[i]->setBouncer_x(ghost[i]->getBouncer_x() + rand() % 3948);
		//al_rest(1);
	}

	cameraX = 0;
	worldW = SCREEN_W * 3;

	al_hide_mouse_cursor(display->display);
	draw_screen();
	al_start_timer(tick_s);
	run_game();
}*/
