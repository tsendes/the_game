#pragma once
#include "Player.h"

class Banner : public Player
{
public:
	bool is_present;
	float buff;

	Banner();
	~Banner();
	void create_Banner();
};