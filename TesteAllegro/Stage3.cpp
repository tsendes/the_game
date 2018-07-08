#include "Game.h"
#include "Stage3.h"
#include "Stage.h"


Stage3::Stage3()
{

}
Stage3::~Stage3()
{

}

void Stage3::buildStage(Game* const stage)
{
	if (stage->getStage() == 2)
	{
		stage->setStage(3);
		if (stage->getKnight()->getHealth() > 0)
		{
			for (int i = 0; i < stage->getNum_trib(); i++)
				delete(stage->getTribesman(i));
			for (int i = 0; i < stage->getNum_bar(); i++)
				delete(stage->getGhost(i));
		}

		stage->getBoss()->create_Boss();
		srand(time(NULL));
		stage->getKnight()->setCameraX(0);
		stage->setWorldW(1366 * 3);
		stage->getKnight()->setBouncer_x(85);
		stage->getLancer()->setBouncer_x(25);
		stage->getBanner()->setBouncer_x(5);



		for (int i = 0; i < 6; i++)
			stage->getBlock(i)->field = stage->getBlock(i)->boss;

		stage->setWorldW(1366);
		stage->setMouse(stage->getMouse()->night_elf);
		stage->getEnvironment()->imagev1 = stage->getEnvironment()->image7;
		stage->getEnvironment()->imagev2 = stage->getEnvironment()->image7;
		stage->getEnvironment()->imagev3 = stage->getEnvironment()->image7;
		stage->getEnvironment()->w = 1920;
		stage->getEnvironment()->h = 1080;
		
		stage->draw_screen();
		stage->play();
	}
}
void Stage3::buildList()
{

}