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
int Entity::getHealth()
{
	return health;
}
uint8_t Entity::colliderX(float x1, int larg1, float x2, int larg2)
{
	//Y É INVERTIDO SEU BURRO
	if (x2 > x1)
	{
		if (larg1 / 1.5 + larg2 / 1.5 >= x2 - x1)
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if (larg1 / 1.5 + larg2 / 1.5 <= x2 - x1)
		{
			return 1;
		}
		else
			return 0;
	}

	return 0;
}
uint8_t Entity::colliderY(float y1, int alt1, float y2, int alt2)
{
	if (y2 < y1)
	{
		if (alt1 / 2 - alt2 / 2 <= y2 - y1)
		{
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if (alt1 / 2 - alt2 / 2 <= y2 - y1)
		{
			return 1;
		}
		else
			return 0;
	}

	return 0;
}
bool Entity::getisPresent()
{
	return is_present;
}
void Entity::setisPresent(bool pr)
{
	is_present = pr;
}