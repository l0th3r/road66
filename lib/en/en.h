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
	/* gas amount */
	size_t gas;
	/* food amount */
	size_t food;
	/* inventory capacity */
	size_t capacity;
	/* total of taken inventory slots */
	size_t total;
} inv;
extern inv* inventory;

void en_init();
void en_start_game();
int en_new_loop(int target);
void en_end();


#endif