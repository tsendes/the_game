#pragma once
#include "Stage.h"

class Game;

class Stage1 : public Stage
{
protected:
	//void addToList(Game* stage);
public:
	Stage1();
	~Stage1();
	void buildList();
	void destroyStage1();
	void buildStage(Game* const stage);
};