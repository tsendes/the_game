#include "Boss.h"

#define SPEED 5.0
Boss::Boss()
{
	create_Boss();
}

Boss::~Boss()
{

}

void Boss::create_Boss()
{
	walk_sprite = al_load_bitmap("Boss_Walk_Sprite.png");
	field = walk_sprite;
	attack_sprite = al_load_bitmap("Boss_Attack_Sprite.png");
	ult_sprite = al_load_bitmap("Boss_Ultimate.png");
	larg = 50;
	alt = 54;
	cont = 0;
	coluna = 0;
	x_atual = 0;
	y_atual = 0;
	x_atk = 0;
	y_atk = 0;
	coluna_atk = 0;
	larg_atk = alt_atk = 60;
	count_atk = 0;
	bouncer_x = 950;
	bouncer_y = 650 - alt * SCALE;
	pos_i = 736 - alt * SCALE;
	left = false;
	damage = 5;
	damage_ult = 2;
	health = 50;
	is_present = true;
	enemy_score = 50;
	count_inv = 30;
	invencible = false;
	//falta coisas para iniciar
}

void Boss::boss_Ult()
{
	bouncer_x = 1366 / 2;
	bouncer_y = 766 / 2;
	count_atk++;
	if (count_atk == 6)
	{
		count_atk = 0;
		coluna_atk++;
		x_atk += larg_atk;
		if (coluna_atk >= 6)
		{
			coluna_atk = 0;
			x_atk = 0;
		}
	}
}

void Boss::setDamage_Ult(float dmg)
{
	damage_ult = dmg;
}
float Boss::getDamage_Ult()
{
	return damage_ult;
}
void Boss:: setUlt_sprite(ALLEGRO_BITMAP* sp)
{
	ult_sprite = sp;
}
ALLEGRO_BITMAP* Boss:: getUlt_sprite()
{
	return ult_sprite;
}

void Boss::moveEnemy(float x, float y)
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
			if (cont == 10)
			{
				cont = 0;
				coluna++;
				x_atual += larg;

				if (coluna >= 2) //cuidado
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

				if (coluna >= 2) //cuidado
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
		if (cont == 10)
		{
			cont = 0;
			coluna++;
			x_atual += larg;

			if (coluna >= 2) //cuidado
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
void Boss::attackEnemy()
{
	count_atk++;
	if (count_atk == 6)
	{
		count_atk = 0;
		coluna_atk++;
		x_atk += larg_atk;
		if (coluna_atk >= 6)
		{
			coluna_atk = 1;
			x_atk = 0;
		}
	}
}
void Boss::move(Knight* knight, Lancer* lancer)
{
	if (field == getWalk_sprite())
		al_draw_scaled_bitmap(field, getX_atual(), getY_atual(), getLarg(), getAlt(), getBouncer_x(), getBouncer_y(), getLarg() * 3, getAlt() * 3, getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
	else
		al_draw_scaled_bitmap(field, getX_atk(), getY_atk(), getLarg_atk(), getAlt_atk(), getBouncer_x(), getBouncer_y(), getLarg_atk() * 3, getAlt_atk() * 3, getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);

	if (!colliderX(knight->getBouncer_x(), knight->getLarg(), getBouncer_x(), getLarg()) && !colliderY(knight->getBouncer_y(), 16 /*HEIGHT*/, getBouncer_y(), getAlt()))
	{
		if (getHealth() >= 30)
		{
			field = getWalk_sprite();
			moveEnemy(knight->getBouncer_x(), knight->getBouncer_y());
		}
	}
	else
	{
		field = getAttack_sprite();
		attackEnemy();
		if (knight->getInvencible() == false)
		{
			knight->setHealth(knight->getHealth() - getDamage()*.5);
			knight->setInvencible(true);
		}

		if (knight->getAtk() && !lancer->getAtk())
		{
			if (getInvencible() == false)
			{
				setHealth(getHealth() - knight->getDamage());
				setInvencible(true);
			}
		}
		if (!knight->getAtk() && lancer->getAtk())
		{
			if (getInvencible() == false)
			{
				setHealth(getHealth() - lancer->getDamage());
				setInvencible(true);
			}
		}

	}
	if (getInvencible() == true)
	{
		setCount_inv(getCount_inv() - 1);
		if (getCount_inv() <= 0)
		{
			setInvencible(false);
			setCount_inv(60);
		}
	}
	if (getHealth() <= 8)
	{
		field = getUlt_sprite();
		al_draw_scaled_bitmap(field, getX_atk(), getY_atk(), getLarg_atk(), getAlt_atk(), getBouncer_x(), getBouncer_y(), getLarg_atk() * 3, getAlt_atk() * 3, getLeft() ? 0 : ALLEGRO_FLIP_HORIZONTAL);
		knight->setHealth(knight->getHealth() - getDamage_Ult()*.003);
	}
	
}