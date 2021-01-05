/* 
	ENGINE LIBRARY
	engine functions /
*/

/* help, to call an event do: (*se_events[EVENT NUMBER])(); */

#include "../../includes.h"

/* define inventory */
inv* inventory;

int en_loop(int target);
int en_update_total();

void en_init();
void en_start_game();
void en_add_passenger(char* name, int pos);
void en_rm_parrenger(int position);
void en_mod_food(int val);
void en_mod_gas(int val);
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

void en_init()
{
	inventory = malloc(sizeof(inv));

	/* import the setting into the struct */
	inventory->pa_count = 0;
	inventory->gas = 0;
	inventory->food = 0;
	inventory->capacity = s_maximum_size;
	/* allocate passengers array */
	inventory->passengers = malloc(sizeof(char*) * s_maximum_size);
	en_update_total();
}

void en_start_game()
{
	/* set capacity */
	inventory->capacity = s_maximum_size;
	while(els_is_exit == 0) {
		ui_refresh(0);
		els_is_exit = en_loop(els_current_city);
	}
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
	if(position > -1)
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
}

void en_mod_food(int val)
{
	/* NEEDS INVENTORY LOGS */
	inventory->food += val;
}

void en_mod_money(int val)
{
	/* NEEDS INVENTORY LOGS */
	inventory->money += val;
}

void en_mod_gas(int val)
{
	/* NEEDS INVENTORY LOGS */
	inventory->gas += val;
}

/*	target = targetted city 
	0 = first city = Las vegas
*/
int en_loop(int target)
{
	/* if stop game */
	int to_return = 0;
	int start_mile = els_miles_counter;

	/* load the targetted miles */
	int mile_target = s_cities_miles[target];

	/* play the event of the city */
	(*city_event[target])();

	/* ============== TEST ============== */

	/* test add */
	en_add_passenger("yeee", inventory->pa_count);
	en_add_passenger("1111", inventory->pa_count);

	/* test delete */
	en_add_passenger("SHOULD NOT DISPLAY", inventory->pa_count);
	en_rm_parrenger(uf_compare("SHOULD NOT PLAY"));

	/* test Gas and gas */
	en_mod_gas(+5);
	en_mod_food(+6);

	en_mod_gas(-1);
	en_mod_food(-1);

	/* test money */
	en_mod_money(+100);
	en_mod_money(-100);

	/* ============== TEST ============== */

	/* check if user stille have gas */
	if(inventory->gas == 0)
		to_return = 1;

	while(els_miles_counter <= mile_target && to_return == 0)
	{
		/* display progress */
		if(els_is_update)
			ui_update_progress(els_miles_counter, mile_target, els_current_city);
		
		/* display inventory */
		if(els_is_inventory)
			ui_update_inventory();


		/* random event */
		/* if(uf_random(s_city_drops[target] * (mile_target - start_mile)) == 0) */
		if((els_miles_counter % 10) == 0 && s_cities_drops[target] <= uf_random(100))
		{
			(*se_events[uf_random(6) + 1])();
		}
		
		/* check if half of jurney */
		if(els_miles_counter == (mile_target - start_mile) / 2)
		{
			en_mod_food(-(inventory->pa_count + 1));
			en_mod_gas(-1);
		}
		
		els_miles_counter++;
		uf_wait(10000 * s_mile_gap_time);
	}

	/* go to the next city at the end */
	els_current_city += 1;
	return to_return;
}

int en_update_total()
{
	return inventory->total = inventory->gas + inventory->food + inventory->pa_count;
}

void en_end()
{
	int i = 0;

	while(i < inventory->pa_count) {
		free(inventory->passengers[i]);
		i++;
	}
	free(inventory->passengers);
	free(inventory);

	/* TEST */

	/* printf("res = %d\n", uf_strcmp("Cosom", "Cosmo")); */

	/* TEST */
}