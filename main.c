/* 
	MAIN 
	main file /
*/

/* LIBS */
#include "includes.h"
#include "config/settings.h"
#include "lib/fp/fp.h"
#include "lib/uf/uf.h"
#include "lib/ui/ui.h"

/* EVENT LIB */
#include "event/secondary/secondary_event.h"

int main(int ac, char **av)
{
	/* init settings lib */
	se_init(); 

	/* init useful lib */
	uf_init();

	/* init ui lib */
	ui_init();

	/* GAME */
	ui_refresh(1);

	getch();

	/* end the game */
	ui_end();

	/* end settings */
	se_end(); 

	return 0;
}