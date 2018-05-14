#pragma once

struct Flag
{
	bool doexit; //flag de fim do programa
	bool redraw; //flag de solicitação de atualizaçao da telinha
	bool atk; //flag de ação de ataque
};

//prototypes
void flag_init();