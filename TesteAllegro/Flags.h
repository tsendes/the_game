#pragma once

struct Flag
{
	bool doexit; //flag de fim do programa
	bool redraw; //flag de solicitação de atualizaçao da telinha
};

//prototypes
void flag_init();