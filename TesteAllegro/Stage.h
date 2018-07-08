#pragma once
#include "ListEnt.h"

class Stage
{
protected:
	ListEnt* lEnt;

public:
	Stage();
	~Stage();
	void setListEnt(ListEnt* l);
	ListEnt* getListEnt();
	virtual void buildStage();
};