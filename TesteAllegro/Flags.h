#pragma once

struct Flag
{
	bool doexit; //flag de fim do programa
	bool redraw; //flag de solicita��o de atualiza�ao da telinha
	bool atk; //flag de a��o de ataque
};

//prototypes
void flag_init();