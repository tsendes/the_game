#include "Stage2.h"
#include "Game.h"


Stage2::Stage2()
{
	lEnt = NULL;
}
Stage2::~Stage2()
{

}
void Stage2::buildStage(Game* stage)
{
	srand(time(NULL));
	stage->setStage(2);
	if (stage->getKnight()->getHealth() > 0)
	{
		for (int i = 0; i < stage->getNum_trib(); i++)
			delete(stage->getTribesman(i));
		for (int i = 0; i < stage->getNum_ghost(); i++)
			delete(stage->getGhost(i));
		for (int i = 0; i < 6; i++)
			stage->getBlock(i)->field = stage->getBlock(i)->forest;
	}

	for (int i = 0; i < stage->getNum_bar(); i++)
	{
		stage->setGhost(new Ghost, i);
		stage->setTribesman(new Tribesman, i);

		stage->getTribesman(i)->setBouncer_x(stage->getTribesman(i)->getBouncer_x() + rand() % 1348);
		stage->getGhost(i)->setBouncer_x(stage->getGhost(i)->getBouncer_x() + rand() % 2348);
	}

	stage->getKnight()->setCameraX(0);
	stage->setWorldW(1366 * 3);
	stage->getKnight()->setBouncer_x(144);
	stage->getLancer()->setBouncer_x(69);
	stage->bush.createBush();
	stage->bush.field = al_load_bitmap("Bush.png");

	stage->getLancer()->field = stage->getLancer()->getWalk_sprite();

	for (int i = 0; i < 6; i++)
		stage->getBlock(i)->field = stage->getBlock(i)->forest;

	stage->setMouse(stage->getMouse()->orc);
	stage->getEnvironment()->imagev1 = stage->getEnvironment()->image4;
	stage->getEnvironment()->imagev2 = stage->getEnvironment()->image5;
	stage->getEnvironment()->imagev3 = stage->getEnvironment()->image6;
	stage->getEnvironment()->w = 900;
	stage->getEnvironment()->h = 440;
	stage->draw_screen();
	stage->play();
}
void Stage2::buildList()
{
	lEnt = new ListEnt;
	lEnt->setlEntity(new Chart<Entity>);
	lEnt->setlBlock(new Chart<Block>);
	lEnt->includeEnt(new Knight);
	lEnt->includeEnt(new Lancer);
}