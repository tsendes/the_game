#include "Flags.h"

extern Flag flag;

void flag_init()
{
	flag.doexit = false;
	flag.redraw = true;
	flag.atk = false;
	flag.exaust = false;
}