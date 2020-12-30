/* 
	SETTINGS lib
	settings / global variables
*/

#include "../includes.h"

/* global setting file */
config_t cf;
const config_setting_t* cities_names;
const config_setting_t* cities_miles;

/* GLOBAL VARIABLES (default settings) */
char* s_cities_names[9];
int s_cities_miles[9];
char* s_main_chara_name = "main_chara_name";
int s_text_thread = 1;
int s_mile_gap_time = 0;

int se_init()
{
	const char* c_char_temp = NULL;
	int i;

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
	
	/* load cities_names names */
	i = 0;

	/* get city array from config file*/
	cities_names = config_lookup(&cf, "city_names");
	cities_miles = config_lookup(&cf, "city_miles");

	/* create the receiver array */
	
	while(i < 9)
	{
		s_cities_names[i] = (char*)config_setting_get_string_elem(cities_names, i);
		s_cities_miles[i] = config_setting_get_int_elem(cities_miles, i);
		i++;
	}

	i = 0;

	/* getting params */
	config_lookup_string(&cf, "main_char_name", &c_char_temp);
	s_main_chara_name = (char*)c_char_temp;

	config_lookup_bool (&cf, "text_thread", &s_text_thread);
	config_lookup_int(&cf, "mile_gap_time", &s_mile_gap_time);
	
	
	return(EXIT_SUCCESS);
}

void se_end()
{
	/* int i = 0;
	while(i < 9)
	{
		printf("%s = %d\n", s_cities_names[i], s_cities_miles[i]);
		i++;
	} */
	config_destroy(&cf);
}