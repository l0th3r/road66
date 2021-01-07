/* 
	ENGINE LIBRARY (header)
	engine functions /
*/

#ifndef ROAD66_EN_LIB
#define ROAD66_EN_LIB


/* inventory struct */
typedef struct {
	/* list of passangers names */
	char **passengers;
	/* total of passangers */
	size_t pa_count;
	/* money amount */
	size_t money;
	/* food amount */
	size_t food;
	/* gas amount */
	size_t gas;
	/* inventory capacity */
	size_t capacity;
	/* total of taken inventory slots */
	size_t total;
} inv;
extern inv* inventory;

int en_loop(int target);
int en_update_total();
int en_start_game();
int en_game_over();

void en_init();
void en_add_passenger(char* name, int pos);
void en_rm_passenger(int position);
void en_mod_food(int val);
void en_mod_gas(int val);
void en_mod_money(int val);
void en_end();

/* ENGINE VARIABLES */
extern char* els_go_ms;
/* check if the user want to quit */
extern int els_is_exit;
/* ids of the current and next city */
extern int els_current_city;
/* condition to try to drop random event */
extern int els_is_random_events;
/* mile counter */
extern int els_miles_counter;
/* condition to display the progress */
extern int els_is_update;
/* condition to update progress */
extern int els_is_inventory;

#endif