#pragma once
#include "Chart.h"
#include "Entity.h"
#include "Block.h"

class ListEnt
{
private:
	Chart <Entity>* lEntity;
	Element<Entity>* pFirstE;
	Element<Entity>* pCurrentE;

	Chart <Block>* lBlock;
	Element <Block>* pFirstB;
	Element <Block>* pCurrentB;
public:
	ListEnt();
	~ListEnt();
	void setlEntity(Chart<Entity>* l);
	Chart<Entity>* getlEntity();
	void setlBlock(Chart<Block>* l);
	Chart<Block>* getlBlock();

	void includeEnt(Entity* info)
	{
		if (lEntity->getpFirst() != NULL)
		{
			lEntity->addToList(info);
			pCurrentE = pCurrentE->getpNext();
		}
		else
			lEntity->addToList(info);
	}
	void includeBlock(Chart<Block> blk)
	{

	}
	Chart<Entity>* getNextE()
	{
		
		return ;
	}
};
