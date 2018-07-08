#include "Humanoid.h"

Humanoid::Humanoid()
{

}

Humanoid::~Humanoid()
{

}
void Humanoid::moveEnemy(float x, float y)
{
	int vision = x - bouncer_x;
	if (vision < 0)
		vision *= -1;
	if (hasVision(vision))
	{
		if (x > bouncer_x)
		{
			bouncer_x += SPEED;
			idleN += SPEED;
			idleP += SPEED;
			cont++;
			left = true;
			if (cont == 8)
			{
				cont = 0;
				coluna++;
				x_atual += larg;

				if (coluna >= 4) //cuidado
				{
					coluna = 0;
					x_atual = 0;
				}
			}
		}
		else if (x < bouncer_x)
		{
			bouncer_x -= SPEED;
			idleN -= SPEED;
			idleP -= SPEED;
			cont++;
			left = false;
			if (cont == 8)
			{
				cont = 0;
				coluna++;
				x_atual += larg;

				if (coluna >= 4) //cuidado
				{
					coluna = 0;
					x_atual = 0;
				}
			}
		}
	}
	else if (!hasVision(vision))
	{
		bouncer_x += SPEED / 2 * invert;
		cont++;
		if (cont == 8)
		{
			cont = 0;
			coluna++;
			x_atual += larg;

			if (coluna >= 4) //cuidado
			{
				coluna = 0;
				x_atual = 0;
			}
		}
		if (bouncer_x <= idleN || bouncer_x >= idleP)
		{
			invert *= -1;
			if (bouncer_x == idleP)
				left = false;
			else if (bouncer_x == idleN)
				left = true;
		}

	}
}
void Humanoid::move(Knight* knight, Lancer* lancer)
{
	if (field == walk_sprite)
		al_draw_scaled_bitmap(field, x_atual, y_atual, larg, alt, bouncer_x + knight->getCameraX() * -1, bouncer_y, larg * 3, alt * 3, left ? 0 : ALLEGRO_FLIP_HORIZONTAL);
	else
		al_draw_scaled_bitmap(field, x_atk, getY_atk(), getLarg_atk(), getAlt_atk(), getBouncer_x(), getBouncer_y(), getLarg_atk() * 3, getAlt_atk() * 3, getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
	if (!colliderX(knight->getBouncer_x(), knight->getLarg(), getBouncer_x() + knight->getCameraX() * -1, getLarg()) && getInvencible() == false)
	{
		field = getWalk_sprite();
		moveEnemy(knight->getBouncer_x(), knight->getBouncer_y());
	}
	if (getHealth() <= 0)
	{
		knight->setScore(knight->getScore() + enemy_score * knight->getHealth() * 100);
		setisPresent(false);
	}
	if (colliderX(knight->getBouncer_x(), knight->getLarg(), getBouncer_x(), getLarg()) ||
		colliderX(lancer->getBouncer_x(), lancer->getLarg(), getBouncer_x(), getLarg()))
	{
		field = getAttack_sprite();
		attackEnemy();
		if (knight->getInvencible() == false)
		{
			knight->setHealth(knight->getHealth() - getDamage());
			knight->setInvencible(true);
		}
		if (knight->getAtk() && !lancer->getAtk() && getInvencible() == false && getInvencible() == false)
		{
			setHealth(getHealth() - knight->getDamage());
			setBouncer_x(getBouncer_x() + 10);
			setInvencible(true);
		}
		else if (!knight->getAtk() && lancer->getAtk() && getInvencible() == false && getInvencible() == false)
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
		if (getCount_inv() <= 0)
		{
			setCount_inv(60);
			setInvencible(false);
		}
	}
}