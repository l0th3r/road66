/* 
	SETTINGS lib
	settings / global variables
*/
#include <stdio.h>
#include <stdlib.h>

#include <libconfig.h>

#include "../fp/fp.h"

/* GLOBAL VARIABLES */
const config_setting_t* g_cities;
char* name;

int se_init()
{
	config_t cfg, *cf;
	const char *na = NULL;
	int count, n, enabled;

	cf = &cfg;
	config_init(cf);

	if (!config_read_file(cf, "./lib/config/config.cfg")) {
		fprintf(stderr, "%s:%d = %s\n",
			config_error_file(cf),
			config_error_line(cf),
			config_error_text(cf));
		config_destroy(cf);
		return(EXIT_FAILURE);
	}

	config_lookup_string(cf, "name", &na);

	printf("before = %s\n", na);

	name = (char*)na;

	config_destroy(cf);
	return 0;
}

void get()
{
	printf("after = %s\n", name);
}