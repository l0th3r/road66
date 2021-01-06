/* 
	UI LIBRARY 
	ncurses handle / UI handle
*/

#include "../../includes.h"

/* UI ENGINE */
void ui_init();
void ui_end();
int ui_refresh(int is_menu);

/* DISPLAY */
WINDOW * ui_new_win(char *name, int height, int width, int start_y, int start_x);

/* EVENT */
void ui_print_dial(WINDOW * win, int id, int ev_w, char* path, char* char0, char* char1, char* char2, char* char3, char* char4, char* char5);
void after_event_clear(WINDOW * win_ev, WINDOW * win_me);

/* USER INFOS */
void ui_update_progress(int val, int end_value, int current_city);
void ui_update_inventory();

/* USER INTERACTIONS */
void ui_continu_choice();
void ui_log_choice(char* str);
void ui_log_inv(char* str, int value);
void ui_clear_inv_log(int val);
int ui_set_menu();
int ui_choice(char* choice1, char* choice2, char* choice3, char* choice4);


/* WINDOWS DEFINITIONS */
WINDOW * win_start_menu;
WINDOW * win_map;
WINDOW * win_tra;
WINDOW * win_inv;
WINDOW * win_env;
WINDOW * win_men;

/* TERMINAL SIZE */
int y_max;
int x_max;

/* WINDOW SIZES */
int tra_h;
int tra_w;
int inv_h;
int inv_w;
int me_h;
int me_w;
int ev_h;
int ev_w;

int is_inv_log = 0;


void ui_init()
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
}

/* called when resize */
int ui_refresh(int is_menu)
{
	int temp = -1;

	/* get terminal size and store into the variables */
	getmaxyx(stdscr, y_max, x_max);

	/* set responsive window sizes */
	tra_h = 10;
	tra_w = 35;
	inv_h = y_max - tra_h;
	inv_w = tra_w;
	me_h = 10;
	me_w = x_max - inv_w - 1;
	ev_h = y_max - me_h;
	ev_w = x_max - inv_w - 1;

	if(is_menu == 0)
	{
		delwin(win_start_menu);
		delwin(win_tra);
		delwin(win_inv);
		delwin(win_env);
		delwin(win_men);

		win_tra = ui_new_win(" Travel ", tra_h, tra_w, 0, 0);
		win_inv = ui_new_win(" Inventory ", inv_h, inv_w, tra_h, 0);
		win_env = ui_new_win(" Events ", ev_h, ev_w, 0, tra_w + 1);
		win_men = ui_new_win(" Menu ", me_h, me_w, ev_h, inv_w + 1);
		keypad(win_men, true);
	}
	else
	{
		delwin(win_start_menu);

		win_start_menu = ui_new_win(" start MENU ", y_max, x_max, 0, 0);
		keypad(win_start_menu, true);

		temp = ui_set_menu();
	}
	
	return temp;
}

void ui_log_choice(char* str)
{
	int i = 2;
	start_color();
	init_pair(5, COLOR_BLACK, COLOR_YELLOW);

	while(i < me_w - 2)
	{
		mvwaddch(win_men, 2, i, ' ');
		i++;
	}

	wattron(win_men, COLOR_PAIR(5));
	mvwprintw(win_men, 2, 2, "%s",str);
	wattroff(win_men, COLOR_PAIR(5));

	wrefresh(win_men);
}

void ui_log_inv(char* str, int value)
{
	int line = inv_h - (inventory->capacity - 5);
	char char_temp;

	if(value >= 0)
		char_temp = '+';
	else
		char_temp = ' ';

	start_color();
	init_color(COLOR_CYAN, 255, 168, 0);
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);

	/* change line for diffrent ressources */
	if(uf_strcmp(str, "Food") == 1)
	{
		/* clear food line */
		ui_clear_inv_log(2);
		line++;
	}
	else if(uf_strcmp(str, "Passenger") == 1)
	{
		/* clear passenger line */
		ui_clear_inv_log(0);
		line--;
	}
	else if(uf_strcmp(str, "Money") == 1)
	{
		/* clear money line */
		ui_clear_inv_log(3);
		line += 2;
	}
	else
		ui_clear_inv_log(1);

	is_inv_log = 1;

	/* clear with colors */
	wattron(win_inv, COLOR_PAIR(4));
	mvwprintw(win_inv, line, 3, " %s %c%d ", str, char_temp, value);
	wattroff(win_inv, COLOR_PAIR(4));

	wrefresh(win_inv);
}

int ui_choice(char* choice1, char* choice2, char* choice3, char* choice4)
{
	int is_good = 0;
	int choice;
	int selected = 0;
	int i = 0;
	int end = 4;

	char* arr[4];

	arr[0] = choice1;
	arr[1] = choice2;
	arr[2] = choice3;
	arr[3] = choice4;

	/* clear inv logs */
	ui_clear_inv_log(0);
	ui_clear_inv_log(1);
	ui_clear_inv_log(2);
	ui_clear_inv_log(3);

	/* put the selected marker */
	while(arr[selected][0] == '/')
		selected++;

	while(is_good == 0)
	{
		i = 0;

		while(i < end)
		{
			/* put the selecte one in reverse */
			if(i == selected)
				wattron(win_men, A_REVERSE);

			/* only print when choice is usable */
			if(arr[i][0] != '/')
				mvwprintw(win_men, i + 3, 2, "%d: %s", i + 1, arr[i]);

			wattroff(win_men, A_REVERSE);
			mvwprintw(win_men, me_h - 3, 2, "^ and v arrows to navigate.");
			mvwprintw(win_men, me_h - 2, 2, "enter key to select.");

			wrefresh(win_men);
			i++;	
		}
		choice = wgetch(win_men);

		/* loop is to prevent all not usable choices */
		switch(choice)
		{
			case 259:
				do
				{
					if(selected > 0)
						selected--;
					else
						selected = end - 1;
				} while(arr[selected][0] == '/');
				break;
			case 258:
				do
				{
					if(selected < end - 1)
						selected++;
					else
						selected = 0;
				}while(arr[selected][0] == '/');
				break;
		}
		if(choice == 10)
			is_good = 1;
	}

	wclear(win_men);
	box(win_men, 0, 0);
	mvwprintw(win_men, 0, 2, " Choice ");
	wrefresh(win_men);

	return selected;
}

void ui_print_dial(WINDOW * win, int id, int ev_w, char* path, char* char0, char* char1, char* char2, char* char3, char* char4, char* char5)
{
	char* raw;
	char* file_path = malloc((uf_str_len(path) + 10) * sizeof(char));
	char* temp;
	char* main = s_main_chara_name;
	char* radio = "radio";

	int fp = 0;
	int ch = 2;
	int line = 0;

	/* loop variables */
	int i;
	int j;

	/* clear box */
	wclear(win);
	start_color();
	
	init_color(COLOR_MAGENTA, 249, 249, 249);

	/* create path */
	sprintf(file_path, "%s/%d.dial%c", path, id, '\0');

	/* charge content */
	raw = fp_read_file(file_path);

	while(raw[fp] != '\0')
	{
		if(raw[fp] == '/' && raw[fp + 1] == '/')
		{
			while(raw[fp] != '\n')
				fp++;
			fp++;
		}
		else
		{
			/* conditions to jump a line */
			if(raw[fp - 1] == '\n' || ch == ev_w - 2
			|| raw[fp - 1] == ']' || raw[fp] == '[')
			{			
				line++;
				ch = 2;
			}

			if(raw[fp] == '[' || raw[fp] == '<')
			{
				temp = malloc(10 * sizeof(char));
				if(raw[fp] == '[')
					line++;

				i = 0;
				j = fp + 1;

				while(raw[j] != ']' && raw[j] != '>')
					temp[i++] = raw[j++];

				temp[i] = '\0';


				if(raw[fp] == '[' && strcmp(temp, "narr") != 0)
					mvwprintw(win, line, ch++, "[");

				if(strcmp(temp, "narr") == 0)
					fp = j + 1;
				else if(strcmp(temp, "main") == 0)
				{
					init_pair(1, COLOR_CYAN, COLOR_BLACK);
					wattron(win, COLOR_PAIR(1));

					i = 0;
					while(main[i])
						mvwprintw(win, line, ch++, "%c", main[i++]);
					fp = j;
				}
				else if(strcmp(temp, "radio") == 0)
				{
					init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
					wattron(win, COLOR_PAIR(2));

					i = 0;
					while(radio[i])
						mvwprintw(win, line, ch++, "%c", radio[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char0") == 0)
				{
					i = 0;
					while(char0[i])
						mvwprintw(win, line, ch++, "%c", char0[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char1") == 0)
				{
					i = 0;
					while(char1[i])
						mvwprintw(win, line, ch++, "%c", char1[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char2") == 0)
				{
					i = 0;
					while(char2[i])
						mvwprintw(win, line, ch++, "%c", char2[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char3") == 0)
				{
					i = 0;
					while(char3[i])
						mvwprintw(win, line, ch++, "%c", char3[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char4") == 0)
				{
					i = 0;
					while(char4[i])
						mvwprintw(win, line, ch++, "%c", char4[i++]);
					fp = j;
				}
				else if(strcmp(temp, "char5") == 0)
				{
					i = 0;
					while(char5[i])
						mvwprintw(win, line, ch++, "%c", char5[i++]);
					fp = j;
				}
				free(temp);
			}
	
			if(raw[fp] == ']' || raw[fp] == '>')
			{
				wattroff(win, COLOR_PAIR(1));
				wattroff(win, COLOR_PAIR(3));
			}

			if(raw[fp] == '>' || raw[fp] == '\r')
				fp++;

			mvwprintw(win, line, ch++, "%c", raw[fp++]);

			box(win, 0, 0);
			mvwprintw(win, 0, 2, " Event ");
			wrefresh(win);

			if(s_text_thread == 1)
				uf_wait(25000);
		}
	}	

	free(raw);
	free(file_path);
}

WINDOW * ui_new_win(char *name, int height, int width, int start_y, int start_x)
{
	WINDOW * win = newwin(height, width, start_y, start_x);
	refresh();

	box(win, 0, 0);
	mvwprintw(win, 0, 2, name);
	wrefresh(win);

	return win;
}

void ui_update_progress(int val, int end_value, int current_city)
{
	mvwprintw(win_tra, 2, 4, "%s to %s", s_cities_names[current_city], s_cities_names[current_city + 1]);
	mvwprintw(win_tra, 3, 4, "=> %d miles remaining.", end_value - val);

    mvwprintw(win_tra, 5, (val % 5) + 2, "      _____________      ");
    mvwprintw(win_tra, 6, (val % 5) + 2, "     | [][][][][]|_\\_       ");
    mvwprintw(win_tra, 7, (val % 5) + 2, "     |               )      ");
	mvwprintw(win_tra, 8, (val % 5) + 2, " ~~ =--(O)------(O)--=      ");

	wrefresh(win_tra);
}

void ui_update_inventory()
{
	int gas_start = 5;
	int food_start = 20;
	/* lines */
	int i = 6;
	/* loop variable */
	int j = 0;

	start_color();
	init_color(COLOR_RED, 255, 0, 0);
	init_pair(2, COLOR_RED, COLOR_BLACK);

	/* print inventory slots, in red if full */
	if(en_update_total() == inventory->capacity)
		wattron(win_inv, COLOR_PAIR(2));
	
	mvwprintw(win_inv, 2, 4, "Inventory slots %d/%d", en_update_total(), inventory->capacity);
	wattroff(win_inv, COLOR_PAIR(2));

	/* print money */
	mvwprintw(win_inv, 3, 4, "Wallet %d$", inventory->money);

	/* print passengers if there is more than 0 */
	if(inventory->pa_count > 0)
	{
		mvwprintw(win_inv, 5, 4, "%d Passengers:", inventory->pa_count);
		while(j < inventory->pa_count)
		{
			mvwprintw(win_inv, i, 4, "- %s", inventory->passengers[j]);
			i++;
			j++;
		}
	}

	/* generate gas and food bar */
	i = inventory->capacity / 2;

	while(i >= 0)
	{
		/* gas */
		mvwprintw(win_inv, inv_h - 3, gas_start, "Gas");
		if(i < inventory->gas / 2)
		{
			mvwaddch(win_inv, (inv_h - i) - 4, gas_start, ACS_CKBOARD);
			mvwaddch(win_inv, (inv_h - i) - 4, gas_start + 1, ACS_CKBOARD);
			mvwaddch(win_inv, (inv_h - i) - 4, gas_start + 2, ACS_CKBOARD);
			mvwaddch(win_inv, (inv_h - i) - 4, gas_start + 3, ' ');
		}
		else
		{
			mvwaddch(win_inv, (inv_h - i) - 4, gas_start, ACS_LTEE);
			mvwaddch(win_inv, (inv_h - i) - 4, gas_start + 1, ' ');
			mvwaddch(win_inv, (inv_h - i) - 4, gas_start + 2, ' ');
			mvwaddch(win_inv, (inv_h - i) - 4, gas_start + 3, ' ');
		}

		if(i == inventory->gas / 2)
			mvwprintw(win_inv, (inv_h - i) - 4, gas_start + 2, "%d   ", inventory->gas);

		/* food */
		mvwprintw(win_inv, inv_h - 3, food_start - 1, "Food");
		if(i < inventory->food / 2)
		{
			if(inventory->food < inventory->pa_count + 1)
				wattron(win_inv, COLOR_PAIR(2));

			mvwaddch(win_inv, (inv_h - i) - 4, food_start, ACS_CKBOARD);
			mvwaddch(win_inv, (inv_h - i) - 4, food_start + 1, ACS_CKBOARD);
			mvwaddch(win_inv, (inv_h - i) - 4, food_start + 2, ACS_CKBOARD);
			mvwaddch(win_inv, (inv_h - i) - 4, food_start + 3, ' ');
			wattroff(win_inv, COLOR_PAIR(2));
		}
		else
		{
			mvwaddch(win_inv, (inv_h - i) - 4, food_start, ACS_LTEE);
			mvwaddch(win_inv, (inv_h - i) - 4, food_start + 1, ' ');
			mvwaddch(win_inv, (inv_h - i) - 4, food_start + 2, ' ');
			mvwaddch(win_inv, (inv_h - i) - 4, food_start + 3, ' ');
		}

		if(i == inventory->food / 2)
		{
			if(inventory->food < inventory->pa_count + 1)
				wattron(win_inv, COLOR_PAIR(2));
			mvwprintw(win_inv, (inv_h - i) - 4, food_start + 2, "%d  ", inventory->food);
			
			wattroff(win_inv, COLOR_PAIR(2));
		}
		i--;
	}

	/* remove inv log if its from too long time */
	if(is_inv_log != 0)
	{
		if(is_inv_log == 50)
		{
			ui_clear_inv_log(0);
			ui_clear_inv_log(1);
			ui_clear_inv_log(2);
			ui_clear_inv_log(3);
		}
		else
			is_inv_log++;
	}

	wrefresh(win_inv);
}

/* val = 0 = clear passenger line */
/* val = 1 = clear Gas line */
/* val = 0 = clear Food line */
void ui_clear_inv_log(int val)
{
	int i = 2;
	int line = ((inv_h - (inventory->capacity - 5)) - 1) + val;

	while(i < inv_w - 2)
	{
		mvwaddch(win_inv, line, i, ' ');
		i++;
	}
	is_inv_log = 0;
}

void ui_continu_choice()
{
	ui_choice("Continue", "/", "/", "/");
}

void after_event_clear(WINDOW * win_ev, WINDOW * win_me)
{
    wclear(win_me);
    box(win_me, 0, 0);
    mvwprintw(win_me, 0, 2, " Choice ");
 
    wclear(win_ev);
    box(win_ev, 0, 0);
    mvwprintw(win_ev, 0, 2, " Event ");

    wrefresh(win_me);
    wrefresh(win_ev);
}

int ui_set_menu()
{
	/*int to_return = -1;*/
	int is_good = 0;
	int choice;
	int selected = 0;
	int i = 0;

	/* number of choices in total */
	int end = 4;

	char* arr[4];

	arr[0] = "Start"; /* NEVER MAKE THIS "/" */
	arr[1] = "Quit";
	arr[2] = "/";
	arr[3] = "/";

	/* CHANGE IN MAIN.C THE RESPONSE */

	while(is_good == 0)
	{
		i = -1;
		end = 0;

		/* exclude "/" choices */
		while(i < end)
		{
			if(arr[end][0] != '/')
				end++;
			i++;			
		}

		i = 0;

		while(i < end)
		{
			if(i == selected)
				wattron(win_start_menu, A_REVERSE);
			
			mvwprintw(win_start_menu, y_max / 2 - end / 2 + i, x_max / 2 - 7, "%d: %s", i + 1, arr[i]);
			wattroff(win_start_menu, A_REVERSE);
			i++;		
		}
		wrefresh(win_start_menu);

		choice = wgetch(win_start_menu);
		switch(choice)
		{
			case 259:
				if(selected > 0)
					selected--;
				else
					selected = end - 1;
				break;
			case 258:
				if(selected < end - 1)
					selected++;
				else
					selected = 0;
				break;
			default:
				break;
		}
		if(choice == 10) {
			wrefresh(win_start_menu);
			is_good = 1;
		}
		else if(choice == 410)
			ui_refresh(1);
		
	}

	return selected;
}

void ui_end()
{
	endwin();
}