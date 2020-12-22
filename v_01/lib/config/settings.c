/* 
	SETTINGS lib
	settings / global variables
*/

#include "../../includes.h"

#include "../fp/fp.h"

/* global setting file */
config_t cf;

/* GLOBAL VARIABLES */
char* name;
int test;

int se_init()
{
	const char *na = NULL;

	config_init(&cf);

	if (!config_read_file(&cf, "./lib/config/config.cfg")) {
		fprintf(stderr, "%s:%d = %s\n",
			config_error_file(&cf),
			config_error_line(&cf),
			config_error_text(&cf));
		config_destroy(&cf);
		return(EXIT_FAILURE);
	}

	config_lookup_string(&cf, "name", &na);
	name = (char*)na;

	config_lookup_int(&cf, "teest", &test);

	
	return(EXIT_SUCCESS);
}

void se_end()
{
	printf("name = %d\n", test);
	config_destroy(&cf);
}