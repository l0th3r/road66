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

void en_init();
void en_start_game();
void en_add_passenger(char* name, int pos);
void en_rm_parrenger(int position);
void en_mod_food(int val);
void en_mod_gas(int val);
void en_end();

#endif