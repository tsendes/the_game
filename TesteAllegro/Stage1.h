#pragma once
#include "ListEnt.h"
#include "Stage.h"
#include "Knight.h"
#include "Lancer.h"

class Stage1 : public Stage
{
protected:
	//void addToList(Game* stage);
public:
	Stage1();
	~Stage1();
	void buildStage1();
	void destroyStage1();
};