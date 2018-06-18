#include "Player.h"

Player::Player():
	Character()
{
	//nadegas
}

Player::~Player()
{
	//nadegas tbem
}
void Player::setName(char* nameN)
{
	strcpy_s(name, nameN);
}
char* Player::getName()
{
	return name;
}
void Player::setIcon(ALLEGRO_BITMAP* icone)
{
	icon = icone;
}
ALLEGRO_BITMAP* Player::getIcon()
{
	return icon;
}
void Player::setScore(float sc)
{
	score = sc;
}
float Player::getScore()
{
	return score;
}
void Player::move(int* timer, float* adjust, int SCREEN_W, int SCREEN_H, bool* redraw, bool* exaust, bool* key)
{
	if (key[KEY_UP] && bouncer_y >= 4.0 && *exaust == false)
	{

		*timer += 1;
		if (*timer >= 10)
		{	
			*timer = 0;
			*adjust /= 1.9;
		}
		bouncer_y -= 9.8 * (*adjust);
		if (*adjust <= 0.5)
		{
			*exaust = true;
			key[KEY_UP] = false;
			*adjust = 1.0;
			*timer = 0;
		}

	}

	if (key[KEY_LEFT] && bouncer_x >= 4.0)
	{
		bouncer_x -= 7.0;
		cont++;
		left = true;
		if (cont == 8)
		{
			cont = 0;
			coluna++;
			x_atual += larg;
			if (coluna >= 4)
			{
				coluna = 0;
				x_atual = 0;
			}
		}
	}

	if (key[KEY_RIGHT] && bouncer_x <= SCREEN_W - 20 * 3/*tamanho do bloco*/ - 4.0)
	{
		bouncer_x += 7.0;
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
	if (bouncer_y < pos_i && !key[KEY_UP])
	{
		*timer += 1;
		if (*timer >= 15)
		{
			*timer = 0;
			*adjust *= 1.5;
		}
		bouncer_y += 9.8 * (*adjust) / 2;
		if (pos_i <= bouncer_y)
		{
			*exaust = false;
			*adjust = 1.0;
			*timer = 0;
		}
		if (pos_i < bouncer_y)
		{
			bouncer_y = pos_i;
		}
	}
	*redraw = true;
}
