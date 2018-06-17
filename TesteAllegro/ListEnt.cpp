#include "ListEnt.h"

ListEnt::ListEnt()
{
	lBlock = new Chart<Block>;
	//pFirstB = lBlock->getpFirst();
	//pCurrentB = lBlock->getpFirst();
	lEntity = new Chart<Entity>;
	//pFirstE = lEntity->getpFirst();
	//pCurrentE = lEntity->getpFirst();
	//incE = incB = 0;
}
ListEnt::~ListEnt()
{
	delete lBlock;
	delete lEntity;
}
void ListEnt::setlEntity(Chart<Entity>* l)
{
	lEntity = l;
}
Chart<Entity>* ListEnt::getlEntity()
{
	return lEntity;
}
void ListEnt::setlBlock(Chart<Block>* l)
{
	lBlock = l;
}
Chart<Block>* ListEnt::getlBlock()
{
	return lBlock;
}
void ListEnt::destroyList()
{
	for (int i = 0; i < incE; i++)
	{
		lEntity->removeFromList();
	}
	for (int i = 0; i < incB; i++)
	{
		lBlock->removeFromList();
	}
}
void ListEnt::setIncE(int i)
{
	incE = i;
}
int ListEnt::getIncE()
{
	return incE;
}
void ListEnt::setIncB(int i)
{
	incB = i;
}
int ListEnt::getIncB()
{
	return incB;
}