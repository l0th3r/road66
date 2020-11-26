#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <unistd.h>
#include <ncurses.h>

/* LIBS */
#include "lib/fp/fp.h"
#include "lib/uf/uf.h"
#include "lib/ui/ui.h"


/* EVENT LIB */
#include "event/secondary/secondary_events.h"

int main(int ac, char **av)
{
	uf_init();
	ui_init();

	for(;;)
	{
		int input = wgetch(stdscr);
		if(input == 410)
			ui_refresh(0);
	}

	ui_end();
	return 0;
}