#pragma once
#include "Player.h"

class Lancer : public Player
{
public:
	ALLEGRO_BITMAP* walk_sprite;
	ALLEGRO_BITMAP* attack_sprite;
	Lancer();
	~Lancer();
	void create_Lancer();
	void attack(bool* atk, bool* atk_x, bool* key);
};
