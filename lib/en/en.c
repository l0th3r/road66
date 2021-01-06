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
void en_rm_passenger(int position);
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

	/* ============== TEST ============== */

	

	/* ============== TEST ============== */

	/* START VALUE */
	en_mod_money(+s_start_money);
	en_mod_gas(+s_start_gas);
	en_mod_food(+s_start_food);

	ui_refresh(0);

	while(els_is_exit == 0)
		els_is_exit = en_loop(els_current_city);
}

/*	target = targetted city 
	0 = first city = Las vegas
*/
int en_loop(int target)
{
	/* loop */
	int i = 0;

	/* if stop game */
	int to_return = 0;
	int start_mile = els_miles_counter;
	int current_mile_counter = 0;

	/* load the targetted miles */
	int mile_target = s_cities_miles[target];

	/* play the event of the city */
	(*city_events[target])();

	if(els_is_update)
		ui_update_progress(els_miles_counter, mile_target, els_current_city);
	
	if(els_is_inventory)
		ui_update_inventory();

	/* check if user stille have gas */
	if(inventory->gas == 0 || inventory->food == 0)
		to_return = 1;

	while(els_miles_counter <= mile_target && to_return == 0)
	{
		/* display progress */
		if(els_is_update)
			ui_update_progress(els_miles_counter, mile_target, els_current_city);
		
		/* display inventory */
		if(els_is_inventory)
			ui_update_inventory();

		/* generate random event */
		if((els_miles_counter % s_drop_per_mile) == 0 && s_cities_drops[target] <= uf_random(100))
			(*se_events[uf_random(6) + 1])();
		
		/* check if half of jurney */
		if(current_mile_counter == (mile_target - start_mile) / 2)
		{
			/* remove gas from the trip */
			en_mod_gas(-1);

			/* remove food from the trip */
			if(inventory->food > 0)
			{
				/* remove food for main character */
				en_mod_food(-1);
				
				/* remove food per passenger */
				while(inventory->food > 0 && i < inventory->pa_count)
				{
					en_mod_food(-1);
					i++;
				}
				/* remove passenger who could't eat */
				while(i < inventory->pa_count)
					en_rm_passenger(i);
			}
			else
				to_return = 1;
		}

		/* MAIN QUEST AND EVENTS */

		if(els_miles_counter == 280)
		{
			
		}

		/* MAIN QUEST AND EVENTS */

		els_miles_counter++;
		current_mile_counter++;
		uf_wait(10000 * s_mile_gap_time);
	}

	/* go to the next city at the end */
	els_current_city += 1;
	return to_return;
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

void en_rm_passenger(int position)
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

		if(inventory->gas < 1)
			en_mod_food(-1);
		else
			en_mod_gas(-1);
		inventory->pa_count -= 1;
	}

	wclear(win_inv);
	box(win_inv, 0, 0);
	mvwprintw(win_inv, 0, 2, " Inventory ");
	ui_update_inventory();
}

void en_mod_food(int val)
{
	int temp;
	char* choice_0 = "Replace 1 Passenger?";
	char* choice_1 = "Replace 1 Gas?";

	if(en_update_total() + val > inventory->capacity)
	{
		while(en_update_total() < inventory->capacity && val > 0)
		{
			inventory->food += 1;
			val--;
		}
		while(val > 0)
		{
			ui_update_inventory();
			if(inventory->pa_count < 1)
				choice_0 = "/";
			if(inventory->gas < 1)
				choice_1 = "/";

			/* ask the user whith what he want to switch ressources */
			ui_log_choice("You have to many things, select what you want to sacrifice one by one:");
			temp = ui_choice(choice_0, choice_1, "/", "/");
			if(temp == 0 && inventory->pa_count > 0)
			{
				en_rm_passenger(0);
				inventory->food += 1;
				val--;
			}
			if(temp == 1 && inventory->gas > 0)
			{
				en_mod_gas(-1);
				inventory->food += 1;
				val--;
			}
		}
	}
	ui_update_inventory();
	inventory->food += val;
}

void en_mod_money(int val)
{
	/* NEEDS INVENTORY LOGS */
	inventory->money += val;
}

void en_mod_gas(int val)
{
	int temp;
	char* choice_0 = "Replace 1 Passenger?";
	char* choice_1 = "Replace 1 Food?";

	if(en_update_total() + val > inventory->capacity)
	{
		while(en_update_total() < inventory->capacity && val > 0)
		{
			inventory->gas += 1;
			val--;
		}
		while(val > 0)
		{
			ui_update_inventory();
			if(inventory->pa_count < 1)
				choice_0 = "/";
			if(inventory->food < 1)
				choice_1 = "/";

			/* ask the user whith what he want to switch ressources */
			ui_log_choice("You have to many things, select what you want to sacrifice one by one:");
			temp = ui_choice(choice_0, choice_1, "/", "/");
			if(temp == 0 && inventory->pa_count > 0)
			{
				en_rm_passenger(0);
				inventory->gas += 1;
				val--;
			}
			if(temp == 1 && inventory->food > 0)
			{
				en_mod_food(-1);
				inventory->gas += 1;
				val--;
			}
		}
	}
	ui_update_inventory();
	inventory->gas += val;
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