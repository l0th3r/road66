/* 
	SETTINGS lib (header)
	settings / global variables
*/

#ifndef ROAD66_SE_LIB
#define ROAD66_SE_LIB


int se_init();
void se_end();

/* GLOBAL VARIABLES (default settings) */
extern char* s_cities_names[9];
extern int s_cities_miles[9];
extern char* s_main_chara_name;
extern int s_text_thread;
extern int s_mile_gap_time;

#endif
