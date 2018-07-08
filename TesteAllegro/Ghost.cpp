#include "Ghost.h"


Ghost::Ghost()
{
	create_Ghost();
}

Ghost::~Ghost()
{
	//al_destroy_bitmap(walk_sprite);
}

void Ghost::create_Ghost()
{
	walk_sprite = al_load_bitmap("Enemy_Ghost.png");
	field = walk_sprite;
	cont = 0;
	coluna = 0;
	larg = 22;
	alt = 20;
	x_atual = 0;
	y_atual = 0;
	bouncer_x = 600;
	bouncer_y = pos_i = 766 - 260 - alt * SCALE;
	invert = -1;
	health = HEALTH_GHOST;
	damage = DMG_GHOST;
	is_present = true;
	enemy_score = 5;
	count_inv = 30;
	invencible = false;
}

void Ghost::moveEnemy(float x, float y)
{
	int vision = x - bouncer_x;
	if (vision < 0)
		vision *= -1;
	if (hasVision(vision))
	{
		if (x > bouncer_x)
		{
			bouncer_x += SPEED_GHOST;
		}
		else if (x < bouncer_x)
		{
			bouncer_x -= SPEED_GHOST;
		}
		if (y < bouncer_y)
		{
			bouncer_y -= SPEED_GHOST;
			pos_i -= SPEED_GHOST;
		}
		else if(y > bouncer_y)
		{
			bouncer_y += SPEED_GHOST;
			pos_i += SPEED_GHOST;
		}
	}
	else if(!hasVision(vision))
	{
		bouncer_y += SPEED_GHOST/2 * invert;
		if(bouncer_y <= pos_i / 1.12 || bouncer_y >= pos_i)
			invert *= -1;
	}
}
void Ghost:: move(Knight* knight, Lancer* lancer)
{
	al_draw_scaled_bitmap(getWalk_sprite(), getX_atual(), getY_atual(), getLarg(), getAlt(), getBouncer_x() + knight->getCameraX() * -1, getBouncer_y(), getLarg() * 2, getAlt() * 2, knight->getBouncer_x() - getBouncer_x() > 0 ? ALLEGRO_FLIP_HORIZONTAL : 0);
	if ((!colliderY(knight->getBouncer_y(), 16/*HEIGHT*/, getBouncer_y(), getAlt()) || !colliderX(knight->getBouncer_x(), knight->getLarg(), getBouncer_x(), getLarg())) && getInvencible() == false)
	{
		moveEnemy(knight->getBouncer_x(), knight->getBouncer_y());
	}
	if (getHealth() <= 0)
	{
		knight->setScore(knight->getScore() + enemy_score * knight->getHealth() * 100);
		setisPresent(false);
	}

	if (colliderX(knight->getBouncer_x() /*+ cameraX * -1*/, knight->getLarg(), getBouncer_x(), getLarg()) && colliderY(knight->getBouncer_y(), 16 /*HEIGHT*/, getBouncer_y(), getAlt()) ||
		colliderX(lancer->getBouncer_x() + knight->getCameraX() * -1 /*+ cameraX * -1*/, lancer->getLarg(), getBouncer_x(), getLarg()) && colliderY(lancer->getBouncer_y(), 16 /*HEIGHT*/, getBouncer_y(), getAlt()))
	{
		if (knight->getInvencible() == false)
		{
			knight->setHealth(knight->getHealth() - getDamage());
			knight->setInvencible(true);
		}

		if (knight->getAtk() && !lancer->getAtk() && getInvencible() == false)
		{
			setHealth(getHealth() - knight->getDamage());
			setBouncer_x(getBouncer_x());
			setInvencible(true);
		}
		if (!knight->getAtk() && lancer->getAtk() && getInvencible() == false)
		{
			setHealth(getHealth() - lancer->getDamage());
			setBouncer_x(getBouncer_x() + 10);
			setInvencible(true);
		}
	}
	if (getInvencible() == true)
	{
		setCount_inv(getCount_inv() - 1);
		setBouncer_x(getBouncer_x() + 1); //bloquear movimento
		setBouncer_x(getBouncer_y() - 1); //bloquear movimento

		if (getCount_inv() <= 0)
		{
			setCount_inv(60);
			setInvencible(false);
		}
	}
}