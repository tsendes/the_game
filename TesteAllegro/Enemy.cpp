#include "Enemy.h"
Enemy::Enemy()
{
	
}
Enemy::~Enemy()
{

}

bool Enemy::hasVision(float vision)
{
	if (vision <= 1366 / 3)
	{
		return true;
	}
	else
		return false;
}
float Enemy::getEnemy_score()
{
	return enemy_score;
}

