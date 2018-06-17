#include "Entity.h"
Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::setBouncer_x(float x)
{
	bouncer_x = x;
	idleN = x - LIMIT;
	idleP = x + LIMIT;
}
float Entity::getBouncer_x()
{
	return bouncer_x;
}
void Entity::setBouncer_y(float y)
{
	bouncer_y = y;
}
float Entity::getBouncer_y()
{
	return bouncer_y;
}
void Entity::setLarg(int largN)
{
	larg = largN;
}
int Entity::getLarg()
{
	return larg;
}
void Entity::setAlt(int altN)
{
	alt = altN;
}
int Entity::getAlt()
{
	return alt;
}
void Entity::setX_atual(int pos_x)
{
	x_atual = pos_x;
}
int Entity::getX_atual()
{
	return x_atual;
}
void Entity::setY_atual(int pos_y)
{
	y_atual = pos_y;
}
int Entity::getY_atual()
{
	return y_atual;
}
void Entity::setPos_i(float pos_iN)
{
	pos_i = pos_iN;
}
float Entity::getPos_i()
{
	return pos_i;
}
void Entity::setHealth(float lifeN)
{
	health = lifeN;
}
float Entity::getHealth()
{
	return health;
}
