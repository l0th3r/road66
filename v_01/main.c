#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <unistd.h>
#include <ncurses.h>

/* LIBS */
#include "lib/config/settings.h"
#include "lib/fp/fp.h"
#include "lib/uf/uf.h"
#include "lib/ui/ui.h"


/* EVENT LIB */
#include "event/secondary/secondary_event.h"

int main(int ac, char **av)
{
	/*/* init settings */
	se_init();

	get();

	return 0;
}