/* 
	SETTINGS lib
	settings / global variables
*/

#include "../includes.h"

/* global setting file */
config_t cf;

/* GLOBAL VARIABLES (default settings) */
char* s_main_chara_name = "main_chara_name";
int s_text_thread = 1;
int s_mile_gap_time = 0;

int se_init()
{
	const char *char_temp = NULL;

	/* init libconfig */
	config_init(&cf);
	if (!config_read_file(&cf, "./config/config.cfg")) {
		fprintf(stderr, "%s:%d = %s\n",
			config_error_file(&cf),
			config_error_line(&cf),
			config_error_text(&cf));
		config_destroy(&cf);
		return(EXIT_FAILURE);
	}


	/* getting params */
	config_lookup_string(&cf, "main_char_name", &char_temp);
	s_main_chara_name = (char*)char_temp;

	config_lookup_bool (&cf, "text_thread", &s_text_thread);
	config_lookup_int(&cf, "mile_gap_time", &s_mile_gap_time);
	
	
	return(EXIT_SUCCESS);
}

void se_end()
{
	config_destroy(&cf);
}