#pragma once
#include "Stage.h"

class Game;
class Stage2 : public Stage
{
public:
	Stage2();
	~Stage2();
	void buildStage(Game* const stage);
	void buildList();
};

