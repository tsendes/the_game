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