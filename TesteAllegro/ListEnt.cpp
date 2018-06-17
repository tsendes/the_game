#include "ListEnt.h"

ListEnt::ListEnt()
{
	lBlock = new Chart<Block>;
	pFirstB = lBlock->getpFirst();
	pCurrentB = lBlock->getpFirst();
	lEntity = new Chart<Entity>;
	pFirstE = lEntity->getpFirst();
	pCurrentE = lEntity->getpFirst();
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