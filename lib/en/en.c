/* 
	ENGINE LIBRARY
	engine functions /
*/

/* help, to call an event do: (*se_events[EVENT NUMBER])(); */

#include "../../includes.h"

/* define inventory */
inv* inventory;

int en_loop(int target);

void en_init();
void en_start_game();
void en_update_total();
void en_end();

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
int els_is_inventory = 1;


void en_start_game()
{
	while(els_is_exit == 0) {
		ui_refresh(0);
		els_is_exit = en_loop(els_current_city);
	}
}

void en_init()
{
	inventory = malloc(sizeof(inv));

	/* import the setting into the struct */
	inventory->pa_count = 0;
	inventory->gas = 0;
	inventory->food = 0;
	inventory->capacity = s_maximum_size;
	en_update_total();

	/* allocate passengers array */
	inventory->passengers = malloc(sizeof(char*) * inventory->capacity);
}

void en_add_passenger(char* name, int pos)
{
	int i = 0;
	int len = uf_str_len(name);
	
	/* allocate memory for the new passenger*/
	inventory->passengers[pos] = realloc(inventory->passengers[pos], (sizeof(char) * len) + 1);

	while(i < len + 1)
	{
		inventory->passengers[pos][i] = name[i];
		i++;
	}
	inventory->passengers[pos][i] = '\0';
	
	/* add 1 to the number of passengers */
	inventory->pa_count += 1;
}

void en_rm_parrenger(int position)
{
	int i = position;

	while(i < inventory->pa_count - 1)
	{
		free(inventory->passengers[i]);
		en_add_passenger(inventory->passengers[i + 1], i);

		/* i know its dirty :/ */
		inventory->pa_count -= 1;
		i++;
	}

	free(inventory->passengers[i]);

	inventory->pa_count -= 1;
}

/*	target = targetted city 
	0 = first city = Las vegas
*/
int en_loop(int target)
{
	/* if stop game */
	int to_return = 0;

	/* load the targetted miles */
	int mile_target = s_cities_miles[target];

	/* play the event of the city */
	(*city_event[target])();

	en_add_passenger("Yes", inventory->pa_count);
	en_add_passenger("Oliver", inventory->pa_count);

	en_rm_parrenger(0);

	while(els_miles_counter <= mile_target)
	{
		if(els_is_update)
			ui_update_progress(els_miles_counter, mile_target, els_current_city);
		
		if(els_is_inventory)
			ui_update_inventory();

		els_miles_counter++;
		uf_wait(10000 * s_mile_gap_time);
	}

	/* go to the next city at the end */
	els_current_city += 1;

	return to_return;
}

void en_update_total()
{
	inventory->total = inventory->gas + inventory->food + inventory->pa_count;
}

void en_end()
{
	int i = 0;
	while(i < inventory->capacity) {
		free(inventory->passengers[i]);
	}
	free(inventory->passengers);
}