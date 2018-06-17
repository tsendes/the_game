#include "Stage1.h"

Stage1::Stage1()
{
	
}
Stage1::~Stage1()
{

}
void Stage1::buildStage1()
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