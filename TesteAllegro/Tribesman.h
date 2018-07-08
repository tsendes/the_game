#pragma once
#include "Humanoid.h"
#include "Knight.h"
#include "Lancer.h"


class Tribesman : public Humanoid
{
protected:
	///
public:
	Tribesman();
	~Tribesman();
	void create_Tribesman();
	void attackEnemy();
	
};