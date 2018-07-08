#include "Stage1.h"
#include "Game.h"
class Game;

Stage1::Stage1()
{
	lEnt = NULL;
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
}
void Stage1::destroyStage1()
{
	//delete(stage);
}

void Stage1::buildStage(Game* const stage)
{
	srand(time(NULL));
	stage->setStage(1);
	for (int i = 0; i < stage->getNum_bar(); i++)
	{
		stage->setBarbarian(new Barbarian, i);
		stage->setGhost(new Ghost, i);
		

		stage->getBarbarian(i)->setBouncer_x(stage->getBarbarian(i)->getBouncer_x() + rand() % 1348);
		stage->getGhost(i)->setBouncer_x(stage->getGhost(i)->getBouncer_x() + rand() % 2348);
	}

	for (int i = 0; i < 6; i++)
	{
		stage->setBlock(new Block, i);
		stage->getBlock(i)->field = stage->getBlock(i)->desert;
		stage->getBlock(i)->setBouncer_x(800 * i);
	}
	stage->barracks.createBarracks();
	stage->barracks.field = al_load_bitmap("Desert_Barracks.png");
	stage->rock.createRock();
	stage->rock.field = al_load_bitmap("Rock.png");

	stage->getKnight()->setCameraX(0);
	stage->setWorldW(1366 * 3);
	stage->getKnight()->setBouncer_x(144);
	stage->getLancer()->setBouncer_x(69);
	stage->getBanner()->setBouncer_x(5);
	stage->getKnight()->setHealth(100);

	for (int i = 0; i < 6; i++)
		stage->getBlock(i)->field = stage->getBlock(i)->desert;

	stage->setMouse(stage->getMouse()->undead);
	stage->getEnvironment()->imagev1 = stage->getEnvironment()->image1;
	stage->getEnvironment()->imagev2 = stage->getEnvironment()->image2;
	stage->getEnvironment()->imagev3 = stage->getEnvironment()->image3;
	stage->getEnvironment()->w = 1920;
	stage->getEnvironment()->h = 1080;

	stage->flag.pause = false;
	stage->draw_screen();
	stage->play();
}
