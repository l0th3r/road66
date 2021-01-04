/* 
	MAIN 
	main file /
*/

/* LIBS */
#include "includes.h"

int main(int ac, char **av)
{
	int temp;

	/* init engine lib */
	en_init();

	/* init settings lib */
	se_init(); 

	/* init useful lib */
	uf_init();

	/* init ui lib */
	ui_init();

	/* GAME */
	temp = ui_refresh(1);

	switch(temp)
	{
		case 0:
			en_start_game();
			break;
		case 1:
			/* quit */
			break;
		default:
			break;
	}

	/* end the game */
	ui_end();

	/* end settings */
	se_end();

	/* end engine */
	en_end();

	return 0;
}