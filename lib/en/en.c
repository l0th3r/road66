/* 
	ENGINE LIBRARY
	engine functions /
*/

/* help, to call an event do: (*se_events[EVENT NUMBER])(); */

#include "../../includes.h"

void en_start_game();
int en_new_loop(int target);

/* ENGINE LOCALS VARIABLES */

/* check if the user want to quit */
int els_is_exit = 0;
/* ids of the current and next city */
int els_current_city = 0;
/* condition to try to drop random event */
int els_is_random_events = 0;
/* mile counter */
int els_miles_counter = 0;
/* condition to display the progress */
int els_is_update = 1;
/* condition to update progress */
int els_is_inventory = 0;


void en_start_game()
{
	while(els_is_exit == 0) {
		ui_refresh(0);
		els_is_exit = en_new_loop(els_current_city);
	}
}

/*	target = targetted city 
	0 = first city = Las vegas
*/
int en_new_loop(int target)
{
	/* if stop game */
	int to_return = 0;

	/* load the targetted miles */
	int mile_target = s_cities_miles[target];

	/* play the event of the city */
	(*city_start[0])();

	while(els_miles_counter <= mile_target)
	{
		if(els_is_update)
			ui_update_progress(els_miles_counter, mile_target, els_current_city);

		els_miles_counter++;
		uf_wait(10000 * s_mile_gap_time);
	}

	if(els_current_city == 0) {
		els_is_update = 0;
	}
	
	/* go to the next city at the end */
	els_current_city += 1;

	return to_return;
}