/* 
	ENGINE LIBRARY
	engine functions /
*/

/* help, to call an event do: (*se_events[EVENT NUMBER])(); */

#include "../../includes.h"

void en_new_loop(int start, int end);

/* engine local settings */
int els_miles_counter = 0;
int els_try_random_events = 0;
char* els_current_city = "Curr CITY";
char* els_next_city = "Next CITY";

void en_start_game()
{
	ui_refresh(0);
	en_new_loop(0, 105);
}

void en_new_loop(int start, int end)
{
	int temp = start;

	while(temp <= end)
	{
		/* exe, event here */

		ui_update_progress(temp, end, els_current_city, els_next_city);
		temp++;
		els_miles_counter++;
		uf_wait(10000 * s_mile_gap_time);
	}
}