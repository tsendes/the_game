#pragma once
class Game;
class Stage;

class Stage3 : public Stage
{
public:
	Stage3();
	~Stage3();
	void buildStage(Game* const stage);
	void buildList();
};