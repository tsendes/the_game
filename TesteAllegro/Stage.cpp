#include "Stage.h"

Stage::Stage()
{

}
Stage::~Stage()
{

}
void Stage::setListEnt(ListEnt* l)
{
	lEnt = l;
}
ListEnt* Stage::getListEnt()
{
	return lEnt;
}