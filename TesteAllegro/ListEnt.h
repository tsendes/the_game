#pragma once
#include "Chart.h"
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
	int incE;
	int incB;
public:
	ListEnt();
	~ListEnt();
	void setlEntity(Chart<Entity>* l);
	Chart<Entity>* getlEntity();
	void setlBlock(Chart<Block>* l);
	Chart<Block>* getlBlock();
	void destroyList();
	void setIncE(int i);
	int getIncE();
	void setIncB(int i);
	int getIncB();

	void includeEnt(Entity* info)
	{
		if (lEntity->getpFirst() != NULL)
		{
			lEntity->addToList(info);
			pCurrentE = pCurrentE->getpNext();
		}
		else
		{
			lEntity->addToList(info);
			pFirstE = lEntity->getpFirst();
			pCurrentE = lEntity->getpFirst();
		}
		incE++;
	}
	void includeBlock(Block* info)
	{
		if (lBlock->getpFirst() != NULL)
		{
			lBlock->addToList(info);
			pCurrentB = pCurrentB->getpNext();
		}
		else
		{
			lBlock->addToList(info);
			pFirstB = lBlock->getpFirst();
			pCurrentB = lBlock->getpFirst();
		}
		incB++;
	}
	Element<Entity>* getLastE()
	{
		return pCurrentE;
	}
	Element<Entity>* getNextE(int inc)
	{
		Element<Entity>* pAux = pFirstE;
		for (int i = 0; i < inc; i++)
		{
			pAux = pAux->getpNext();
		}
		return pAux;
	}

	Element<Block>* getLastB()
	{
		return pCurrentB;
	}
	Element<Block>* getNextB(int inc)
	{
		Element<Block>* pAux = pFirstB;
		for (int i = 0; i < inc; i++)
		{
			pAux = pAux->getpNext();
		}
		return pAux;
	}
};
