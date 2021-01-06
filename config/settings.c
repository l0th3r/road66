/* 
	SETTINGS lib
	settings / global variables
*/

#include "../includes.h"

/* global setting file */
config_t cf;
const config_setting_t* cities_names;
const config_setting_t* cities_miles;
const config_setting_t* cities_drops;

/* GLOBAL VARIABLES (default settings) */
char* s_cities_names[9];
int s_cities_miles[8];
int s_cities_drops[9];
char* s_main_chara_name = "main_chara_name";
int s_text_thread = 1;
int s_mile_gap_time = 0;
int s_maximum_size = 10;
int s_drop_per_mile = 100;
int s_start_money = 10;
int s_start_food;
int s_start_gas;
int s_city_start;

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
	cities_drops = config_lookup(&cf, "city_event_drop");

	while(i < 9)
	{
		s_cities_names[i] = (char*)config_setting_get_string_elem(cities_names, i);
		s_cities_miles[i] = config_setting_get_int_elem(cities_miles, i);
		s_cities_drops[i] = config_setting_get_int_elem(cities_drops, i);
		i++;
	}

	/* getting params */
	config_lookup_string(&cf, "main_char_name", &c_char_temp);
	s_main_chara_name = (char*)c_char_temp;

	config_lookup_bool (&cf, "text_thread", &s_text_thread);
	config_lookup_int(&cf, "mile_gap_time", &s_mile_gap_time);
	config_lookup_int(&cf, "maximum_size", &s_maximum_size);
	config_lookup_int(&cf, "drop_per_mile", &s_drop_per_mile);
	config_lookup_int(&cf, "start_money", &s_start_money);
	config_lookup_int(&cf, "start_food", &s_start_food);
	config_lookup_int(&cf, "start_gas", &s_start_gas);
	config_lookup_int(&cf, "city_start", &s_city_start);

	return(EXIT_SUCCESS);
}

void se_end()
{
	config_destroy(&cf);
}