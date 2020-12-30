/* 
	ENGINE LIBRARY (header)
	engine functions /
*/

#ifndef ROAD66_EN_LIB
#define ROAD66_EN_LIB


/* inventory struct */
typedef struct {
	char* passengers[5];
	size_t fuel;
	size_t food;
	size_t capacity;
	size_t total;
} inv;
extern inv inventory;

void en_init();
void en_start_game();
int en_new_loop(int target);


#endif