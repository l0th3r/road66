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
	/* display the main menu */
	temp = 2;

	while(temp != -1)
	{
		switch(temp)
		{
			case 0:
				/* play */
				temp = en_start_game();
				break;
			case 1:
				/* quit */
				temp = -1;
			break;
			case 2:
				/* main menu */
				temp = ui_refresh(1);
			break;
			case 666:
				temp = en_game_over();
			break;
		}
	}

	/* end the game */
	ui_end();

	/* end settings */
	se_end();

	/* end engine */
	en_end();

	return 0;
}