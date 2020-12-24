/* LIBS */
#include "../../includes.h"
#include "../../config/settings.h"
#include "../../lib/fp/fp.h"
#include "../../lib/uf/uf.h"
#include "../../lib/ui/ui.h"

void secondary_event_1()
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
				temp = ui_choice(win_men, "Stop the bus.", "Keep driving", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
				temp = ui_choice(win_men, "I'm sorry but it is not on my way.", "Yeah, come in! I'll drive you there", "Start up the engine and leave.", "/");
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
				temp = ui_choice(win_men, "Alright, come in mate!", "Sorry, I have no time to waste.", "/", "/");
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

void secondary_event_4()
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
				temp = ui_choice(win_men, "Stop the bus.", "Keep driving", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
				temp = ui_choice(win_men, "What the fuck?", "Trick!", "Treat!", "/");
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
				temp = ui_choice(win_men, "Kill him.", "Trick.", "Treat.", "/");
                if(temp == 0)
                    current = 6;
                if(temp == 1)
                    current = 4;
                if(temp == 2)
                    current = 5;
			break;
            case 4:
                char0 = "Curtis";
                temp = ui_choice(win_men, "Okay... We will find a candy shop if you want.", "Sorry, man. I don't have candy!", "/", "/");
                if(temp == 0)
                    current = 9;
                if(temp == 1)
                    current = 5;
			break;
            case 5:
                temp = ui_choice(win_men, "Grab your gun and kill him.", "Go back to the bus and leave.", "Okay... again, trick!", "/");
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
                temp = ui_choice(win_men, "Hold on! I know an amazing candy shop in the next city!", "Grab your gun and kill him.", "/", "/");
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

void secondary_event_2()
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
				temp = ui_choice(win_men, "Drive faster. ", "Break suddenly.", "/", "/");
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

void secondary_event_3()
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
				temp = ui_choice(win_men, "Stop the bus.", "Keep driving", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1){
                    current = -1;
                }
			break;
            case 1:
				temp = ui_choice(win_men, "Check the body.", "Open the truck.", "/", "/");
                if(temp == 0)
                    current = 2;
                if(temp == 1)
                    current = 3;
			break;
            case 2:
                temp = ui_choice(win_men, "Throw the keys of your bus.", "Stay still and voiceless.", "/", "/");
                if(temp == 0)
                    current = 14;
                if(temp == 1)
                    current = 5;
			break;
            case 3:
				temp = ui_choice(win_men, "Check the body.", "Go back to the bus and keep driving.", "/", "/");
                if(temp == 0)
                    current = 2;
                if(temp == 1){
                    current = -1;
                    ui_continu_choice(win_men);
                }
			break;
            case 4:
                temp = ui_choice(win_men, "Kill him.", "Search in the truck.", "/", "/");
                if(temp == 0)
                    current = 13;
                if(temp == 1)
                    current = 12;
			break;
            case 5:
                temp = ui_choice(win_men, "If you had bullets, you would have killed me already!", "Punch the trucker.", "/", "/");
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
                temp = ui_choice(win_men, "Throw a kick in his nuts.", "Push him.", "/", "/");
                if(temp == 0)
                    current = 8;
                if(temp == 1)
                    current = 9;
			break;
            case 8:
                temp = ui_choice(win_men, "Threaten him.", "Leave him.", "/", "/");
                if(temp == 0)
                    current = 10;
                if(temp == 1)
                    current = 11;
			break;
            case 9:
                temp = ui_choice(win_men, "Threaten him.", "Leave him.", "/", "/");
                if(temp == 0){
                    current= -1;
                    ui_continu_choice(win_men);
                }
                if(temp == 1)
                    current = 12;
			break;
            case 10:
                temp = ui_choice(win_men, "Now dude, YOU give me your keys!", "Finish him! FATALITY!", "/", "/");
                if(temp == 0)
                    current= 4;
                if(temp == 1)
                    current = 15;
			break;
            case 11:
                temp = ui_choice(win_men, "Leave.", "Kill him.", "/", "/");
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
                temp = ui_choice(win_men, "Leave.", "Search in the truck.", "/", "/");
                if(temp == 0){
                    current= -1;
                    ui_continu_choice(win_men);
                }
                if(temp == 1)
                    current = 12;
			break;
            case 14:
                temp = ui_choice(win_men, "Grab your weapon and kill him.", "/", "/", "/");
                if(temp == 0)
                    current = 13;
			break;
            case 15:
                temp = ui_choice(win_men, "Leave.", "Search in the truck.", "/", "/");
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

void secondary_event_5()
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
				temp = ui_choice(win_men, "Stop the bus.", "Keep driving.", "/", "/");
                if(temp == 0)
                    current = 1;
                if(temp == 1)
                    current = 2;
			break;
            case 1:
                temp = ui_choice(win_men, "Stay in the bus.", "Leave the bus.", "/", "/");
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
                temp = ui_choice(win_men, "Stay in the bus.", "Leave the bus.", "/", "/");
                if(temp == 0)
                    current = 4;
                if(temp == 1)
                    current = 7;
			break;
            case 4:
                temp = ui_choice(win_men, "Stay in the bus.", "Leave the bus.", "Start the bus and drive on one of them.", "/");
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
                temp = ui_choice(win_men, "Be obedient", "Refuse", "/", "/");
                if(temp == 0)
                    current = 9;
                if(temp == 1)
                    current = 8;
			break;
            case 8:
                temp = ui_choice(win_men, "Give up", "Refuse one more / last(?) time", "/", "/");
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

void secondary_event_6()
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
				temp = ui_choice(win_men, "Go back to sleep.", "Walk a little.", "/", "/");
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
                temp = ui_choice(win_men, "Return to the bus.", "Go take a look.", "/", "/");
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

void secondary_event_7()
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
				temp = ui_choice(win_men, "Stop the bus.", "Keep driving.", "/", "/");
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