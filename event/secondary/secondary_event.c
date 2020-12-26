/* 
	SE_EVENT LIBRARY
	secondary event lib /
*/

/* LIBS */
#include "../../includes.h"

void se_event_1();
void se_event_2();
void se_event_3();
void se_event_4();
void se_event_5();
void se_event_6();
void se_event_7();

/* creating event functions array */
void (*se_events[7])() = 
{
    se_event_1,
    se_event_2,
    se_event_3,
    se_event_4,
    se_event_5,
    se_event_6,
    se_event_7
};

void se_event_1()
{
    int current = 0;
    int temp;
    char* char0 = "Hitchhiker";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/1", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = ui_choice("Stop the bus.", "Keep driving", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
				temp = ui_choice("I'm sorry but it is not on my way.", "Yeah, come in! I'll drive you there", "Start up the engine and leave.", "/");
                if(temp == 0)
                    current = 3;
                if(temp == 1)
                    current = 4;
                if(temp == 2)
                    current = 2;
			break;
            case 2:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 3:
				temp = ui_choice("Alright, come in mate!", "Sorry, I have no time to waste.", "/", "/");
                if(temp == 0)
                    current = 5;
                if(temp == 1)
                    current = 2;
			break;
            case 4:
                char0 = "Robbert";
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 5:
                current = 4;
                ui_continu_choice(win_men);
			break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_2()
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/2", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = ui_choice("Drive faster. ", "Break suddenly.", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 2:
                current = -1;
                ui_continu_choice(win_men);
			break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_3()
{
    int current = 0;
    int temp;
    char* char0 = "Trucker";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/3", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = ui_choice("Stop the bus.", "Keep driving", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1){
                    current = -1;
                }
			break;
            case 1:
				temp = ui_choice("Check the body.", "Open the truck.", "/", "/");
                if(temp == 0)
                    current = 2;
                if(temp == 1)
                    current = 3;
			break;
            case 2:
                temp = ui_choice("Throw the keys of your bus.", "Stay still and voiceless.", "/", "/");
                if(temp == 0)
                    current = 14;
                if(temp == 1)
                    current = 5;
			break;
            case 3:
				temp = ui_choice("Check the body.", "Go back to the bus and keep driving.", "/", "/");
                if(temp == 0)
                    current = 2;
                if(temp == 1){
                    current = -1;
                    ui_continu_choice(win_men);
                }
			break;
            case 4:
                temp = ui_choice("Kill him.", "Search in the truck.", "/", "/");
                if(temp == 0)
                    current = 13;
                if(temp == 1)
                    current = 12;
			break;
            case 5:
                temp = ui_choice("If you had bullets, you would have killed me already!", "Punch the trucker.", "/", "/");
                if(temp == 0)
                    current = 6;
                if(temp == 1)
                    current = 7;
			break;
            case 6:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 7:
                temp = ui_choice("Throw a kick in his nuts.", "Push him.", "/", "/");
                if(temp == 0)
                    current = 8;
                if(temp == 1)
                    current = 9;
			break;
            case 8:
                temp = ui_choice("Threaten him.", "Leave him.", "/", "/");
                if(temp == 0)
                    current = 10;
                if(temp == 1)
                    current = 11;
			break;
            case 9:
                temp = ui_choice("Threaten him.", "Leave him.", "/", "/");
                if(temp == 0){
                    current= -1;
                    ui_continu_choice(win_men);
                }
                if(temp == 1)
                    current = 12;
			break;
            case 10:
                temp = ui_choice("Now dude, YOU give me your keys!", "Finish him! FATALITY!", "/", "/");
                if(temp == 0)
                    current= 4;
                if(temp == 1)
                    current = 15;
			break;
            case 11:
                temp = ui_choice("Leave.", "Kill him.", "/", "/");
                if(temp == 0) {
                    current= -1;
                    ui_continu_choice(win_men);
                }
                if(temp == 1)
                    current = 13;
			break;
            case 12:
                /* - 1 Food - 1 Medical Kit  */
                current= -1;
                ui_continu_choice(win_men);
			break;
            case 13:
                temp = ui_choice("Leave.", "Search in the truck.", "/", "/");
                if(temp == 0){
                    current= -1;
                    ui_continu_choice(win_men);
                }
                if(temp == 1)
                    current = 12;
			break;
            case 14:
                temp = ui_choice("Grab your weapon and kill him.", "/", "/", "/");
                if(temp == 0)
                    current = 13;
			break;
            case 15:
                temp = ui_choice("Leave.", "Search in the truck.", "/", "/");
                if(temp == 0){
                    current = -1;
                    ui_continu_choice(win_men);
                }
                if(temp == 1)
                    current = 12;
			break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_4()
{
    int current = 0;
    int temp;
    char* char0 = "Dwarf";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/4", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = ui_choice("Stop the bus.", "Keep driving", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
				temp = ui_choice("What the fuck?", "Trick!", "Treat!", "/");
                if(temp == 0)
                    current = 3;
                if(temp == 1)
                    current = 4;
                if(temp == 2)
                    current = 5;
			break;
            case 2:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 3:
				temp = ui_choice("Kill him.", "Trick.", "Treat.", "/");
                if(temp == 0)
                    current = 6;
                if(temp == 1)
                    current = 4;
                if(temp == 2)
                    current = 5;
			break;
            case 4:
                char0 = "Curtis";
                temp = ui_choice("Okay... We will find a candy shop if you want.", "Sorry, man. I don't have candy!", "/", "/");
                if(temp == 0)
                    current = 9;
                if(temp == 1)
                    current = 5;
			break;
            case 5:
                temp = ui_choice("Grab your gun and kill him.", "Go back to the bus and leave.", "Okay... again, trick!", "/");
                if(temp == 0)
                    current = 6;
                if(temp == 1)
                    current = 10;
                if(temp == 2)
                    current = 7;
			break;
            case 6:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 7:
                temp = ui_choice("Hold on! I know an amazing candy shop in the next city!", "Grab your gun and kill him.", "/", "/");
                if(temp == 0)
                    current = 8;
                if(temp == 1)
                    current = 6;
			break;
            case 8:
                char0 = "Curtis";
                current= -1;
                /* GET CURTIS IN UR BUS */
                ui_continu_choice(win_men);
			break;
            case 9:
                char0 = "Curtis";
                current= -1;
                /* GET CURTIS IN UR BUS */
                ui_continu_choice(win_men);
			break;
            case 10:
                current= -1;
                ui_continu_choice(win_men);
			break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_5()
{
    int current = 0;
    int temp;
    char* char0 = "The bad guy";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/5", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
                temp = ui_choice("Stay in the bus.", "Leave the bus.", "/", "/");
                if(temp == 0)
                    current = 3;
                if(temp == 1)
                    current = 7;
			break;
            case 2:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 3:
                temp = ui_choice("Stay in the bus.", "Leave the bus.", "/", "/");
                if(temp == 0)
                    current = 4;
                if(temp == 1)
                    current = 7;
			break;
            case 4:
                temp = ui_choice("Stay in the bus.", "Leave the bus.", "Start the bus and drive on one of them.", "/");
                if(temp == 0)
                    current = 5;
                if(temp == 1)
                    current = 7;
                if(temp == 2)
                    current = 6;
			break;
            case 5:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 6:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 7:
                temp = ui_choice("Be obedient", "Refuse", "/", "/");
                if(temp == 0)
                    current = 9;
                if(temp == 1)
                    current = 8;
			break;
            case 8:
                temp = ui_choice("Give up", "Refuse one more / last(?) time", "/", "/");
                if(temp == 0)
                    current = 9;
                if(temp == 1)
                    current = 10;
			break;
            case 9:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 10:
                current = -1;
                ui_continu_choice(win_men);
			break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_6()
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/6", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = ui_choice("Go back to sleep.", "Walk a little.", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 2:
                temp = ui_choice("Return to the bus.", "Go take a look.", "/", "/");
                if(temp == 0)
                    current = 3;
                if(temp == 1)
                    current = 4;
			break;
            case 3:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 4:
                current = -1;
                ui_continu_choice(win_men);
			break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_7()
{
    int current = 0;
    int temp;
    char* char0 = "a random passenger";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while(current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/7", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
                if(temp == 0)
                    current = 4;
                if(temp == 1)
                    current = 1;
			break;
            case 1:
                /* if there is someone in the bus */
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 2:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 3:
                current = -1;
                ui_continu_choice(win_men);
			break;
            case 4:
                current = -1;
                ui_continu_choice(win_men);
			break;
        }

        after_event_clear(win_env, win_men);
    }
}