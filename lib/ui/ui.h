/* 
	UI LIBRARY (header) 
	ncurses handle / UI handle
*/

#ifndef ROAD66_UI_LIB
#define ROAD66_UI_LIB


/* UI ENGINE */
void ui_init();
void ui_refresh(int is_menu);
void ui_end();

/* DISPLAY */
WINDOW * ui_new_win(char *name, int height, int width, int start_y, int start_x);

/* EVENT */
void ui_print_dial(WINDOW * win, int id, int ev_w, char* path, char* char0, char* char1, char* char2, char* char3, char* char4, char* char5);
void after_event_clear(WINDOW * win_ev, WINDOW * win_me);

/* PROGRESS */
void ui_update_progress(WINDOW * win, int height, int val);

/* MENU */
int ui_choice(WINDOW* win, char* choice1, char* choice2, char* choice3, char* choice4);
void ui_continu_choice(WINDOW * win_men);

/* GLOBAL WINDOWS */
extern WINDOW * win_start_menu;
extern WINDOW * win_map;
extern WINDOW * win_tra;
extern WINDOW * win_inv;
extern WINDOW * win_env;
extern WINDOW * win_men;

/* GLOBAL TERMINAL SIZE */
extern int y_max;
extern int x_max;

/* GLOBAL WINDOW SIZES */
extern int tra_h;
extern int tra_w;
extern int inv_h;
extern int inv_w;
extern int me_h;
extern int me_w;
extern int ev_h;
extern int ev_w;


#endif