#include "Stage1.h"

Stage1::Stage1()
{
	
}
Stage1::~Stage1()
{

}
/*void Stage1::buildList()
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
void Stage1::buildStage1(Game* const stage)
{
	srand(time(NULL));
	for (int i = 0; i < stage->getNum_bar(); i++)
	{

		stage->setGhost(new Ghost, i);
		stage->setBarbarian(new Barbarian, i);

		stage->getBarbarian(i)->setBouncer_x(stage->getBarbarian(i)->getBouncer_x() + rand() % 1348);
		stage->getGhost(i)->setBouncer_x(stage->getGhost(i)->getBouncer_x() + rand() % 2348);
	}

	stage->setCameraX(0);
	stage->setWorldW(1366 * 3);
	stage->getKnight()->setBouncer_x(144);
	stage->getLancer()->setBouncer_x(69);
	stage->getBanner()->setBouncer_x(5);
	stage->getKnight()->setHealth(100);

	for (int i = 0; i < 6; i++)
		stage->getBlock(i)->field = stage->getBlock(i)->desert;

	stage->setMouse(stage->getMouse().undead);
	stage->getEnvironment()->imagev1 = stage->getEnvironment()->image1;
	stage->getEnvironment()->imagev2 = stage->getEnvironment()->image2;
	stage->getEnvironment()->imagev3 = stage->getEnvironment()->image3;
	stage->getEnvironment()->w = 1920;
	stage->getEnvironment()->h = 1080;
}
