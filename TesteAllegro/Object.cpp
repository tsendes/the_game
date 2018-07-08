#include "Object.h"

Object::Object()
{

}

Object::~Object()
{

}

void Object::create_Object()
{
	
}
void Object::collide(Knight* knight)
{ 
	if (colliderX(knight->getBouncer_x(), knight->getLarg(), bouncer_x, larg ))
	{
		knight->block = true;
		if (knight->getAtk())
		{
			health -= knight->getDamage();
			invencible = true;
			if (health <= 0)
			{
				is_present = false;
			}
		}
		else
		{
			if (invencible == true)
			{
				count_inv-= 1;
				if (count_inv == 0)
				{
					count_inv = 60;
					invencible = false;
				}
			}
		}
	}
}