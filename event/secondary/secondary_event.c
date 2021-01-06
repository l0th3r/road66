/*
    SE_EVENT LIBRARY
    secondary event lib /
*/

/* LIBS */
#include "../../includes.h"

void se_event_0();
void se_event_1();
void se_event_2();
void se_event_3();
void se_event_4();
void se_event_5();
void se_event_6();
void se_event_7();
void se_event_8();
void se_event_9();
void se_event_10();
void se_event_11();
void se_event_12();
void se_event_13();
/* */
void se_event_15();
void se_event_16();
void se_event_17();
void se_event_18();
void se_event_19();
void se_event_20();
void se_event_21();
void se_event_22();

void empty2() {}

/* creating event functions array */
void (*se_events[23])() =
{
    se_event_0,
    se_event_1,
    se_event_2,
    se_event_3,
    se_event_4,
    se_event_5,
    se_event_6,
    se_event_7,
    se_event_8,
    se_event_9,
    se_event_10,
    se_event_11,
    se_event_12,
    se_event_13,
    empty2,
    se_event_15,
    se_event_16,
    se_event_17,
    se_event_18,
    se_event_19,
    se_event_20,
    se_event_21,
    se_event_22
};

/* to check if the event have been played */
int se_event_check[23] = { 0 };

void se_event_drop()
{
    int i = 0;
    int temp;
    int is;

    se_event_check[13] = 1;
    se_event_check[14] = 1;
    se_event_check[15] = 1;
    se_event_check[16] = 1;
    se_event_check[17] = 1;

    /* check if there are event still available */
    is = 1;
    while (i < 23)
    {
        if (se_event_check[i] == 0)
            is = 0;
        i++;
    }

    if (is == 0)
    {
        while (is == 0)
        {
            temp = uf_random(22);
            if (se_event_check[temp] == 0)
                is = 1;
        }
        (*se_events[temp])();
    }
}

void se_event_0()
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "Unknown Man";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    se_event_check[0] = 1;


    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/0", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus. ", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            temp = ui_choice("Look around the car.", "Go back to the bus.", "/", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
                current = 4;
            break;
        case 3:
            temp = ui_choice("Talk to him.", "Grab your gun and threaten him.", "/", "/");
            if (temp == 0)
            {
                char1 = "Bils";
                current = 5;
            }
            if (temp == 1)
                current = 6;
            break;
        case 4:
            current = -1;
            ui_continu_choice();
            break;
        case 5:
            temp = ui_choice("Question him more. ", "Keep silent.", "/", "/");
            if (temp == 0)
                current = 7;
            if (temp == 1)
                current = 16;
            break;
        case 6:
            temp = ui_choice("Shoot at him.", "Keep your gun on him.", "/", "/");
            if (temp == 0)
                current = 8;
            if (temp == 1)
                current = 10;
            break;
        case 7:
            current = 19;
            ui_continu_choice();
            break;
        case 8:
            temp = ui_choice("Kill it.", "Let him alive.", "/", "/");
            if (temp == 0)
                current = 11;
            if (temp == 1)
                current = 12;
            break;
        case 9:
            current = -1;
            char1 = "Bils";
            en_add_passenger(char1, inventory->pa_count);
            en_mod_money(+20);
            ui_continu_choice();
            break;
        case 10:
            temp = ui_choice("Evade.", "Convince him to stop.", "/", "/");
            if (temp == 0)
                current = 18;
            if (temp == 1)
                current = 17;
            break;
        case 11:
            current = -1;
            en_mod_money(+20);
            en_mod_food(+2);
            ui_continu_choice();
            break;
        case 12:
            current = -1;
            en_mod_money(+20);
            en_mod_food(+2);
            ui_continu_choice();
            break;
        case 13:
            temp = ui_choice("Help him and give him 1 gas.", "Don't help him.", "/", "/");
            if (temp == 0)
                current = 14;
            if (temp == 1)
                current = 15;
            break;
        case 14:
            current = -1;
            en_mod_gas(-1);
            ui_continu_choice();
            break;
        case 15:
            current = -1;
            ui_continu_choice();
            break;
        case 16:
            temp = ui_choice("Help him and propose him a place on the bus.", "Give him one gas.", "/", "/");
            if (temp == 0)
                current = 9;
            if (temp == 1)
                current = 14;
            break;
        case 17:
            current = -1;
            ui_continu_choice();
            break;
        case 18:
            temp = ui_choice("Kill it.", "Let him alive.", "/", "/");
            if (temp == 0)
                current = 11;
            if (temp == 1)
                current = 12;
            break;
        case 19:
            temp = ui_choice("Propose him to come on the bus.", "Let him here.", "/", "/");
            if (temp == 0)
                current = 9;
            if (temp == 1)
                current = 13;
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

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

    se_event_check[1] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/1", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 2;
            break;
        case 1:
            temp = ui_choice("I'm sorry but it is not on my way.", "Yeah, come in! I'll drive you there", "Start up the engine and leave.", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
                current = 4;
            if (temp == 2)
                current = 2;
            break;
        case 2:
            current = -1;
            ui_continu_choice();
            break;
        case 3:
            temp = ui_choice("Alright, come in mate!", "Sorry, I have no time to waste.", "/", "/");
            if (temp == 0)
                current = 5;
            if (temp == 1)
                current = 2;
            break;
        case 4:
            char0 = "Robbert";
            en_add_passenger(char0, inventory->pa_count);
            current = -1;
            ui_continu_choice();
            break;
        case 5:
            current = 4;
            en_mod_money(+50);
            ui_continu_choice();
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

    se_event_check[2] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/2", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Drive faster. ", "Break suddenly.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 2;
            break;
        case 1:
            current = -1;
            ui_continu_choice();
            break;
        case 2:
            current = -1;
            ui_continu_choice();
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

    se_event_check[3] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/3", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            temp = ui_choice("Check the body.", "Open the truck.", "/", "/");
            if (temp == 0)
                current = 2;
            if (temp == 1)
                current = 3;
            break;
        case 2:
            temp = ui_choice("Throw the keys of your bus.", "Stay still and voiceless.", "/", "/");
            if (temp == 0)
                current = 14;
            if (temp == 1)
                current = 5;
            break;
        case 3:
            temp = ui_choice("Check the body.", "Go back to the bus and keep driving.", "/", "/");
            if (temp == 0)
                current = 2;
            if (temp == 1)
                current = -1;
            break;
        case 4:
            temp = ui_choice("Kill him.", "Search in the truck.", "/", "/");
            if (temp == 0)
                current = 13;
            if (temp == 1)
                current = 12;
            break;
        case 5:
            temp = ui_choice("If you had bullets, you would have killed me already!", "Punch the trucker.", "/", "/");
            if (temp == 0)
                current = 6;
            if (temp == 1)
                current = 7;
            break;
        case 6:
            current = -1; /* NEED GAME OVER (die) */
            ui_continu_choice();
            break;
        case 7:
            temp = ui_choice("Throw a kick in his nuts.", "Push him.", "/", "/");
            if (temp == 0)
                current = 8;
            if (temp == 1)
                current = 9;
            break;
        case 8:
            temp = ui_choice("Threaten him.", "Leave him.", "/", "/");
            if (temp == 0)
                current = 10;
            if (temp == 1)
                current = 11;
            break;
        case 9:
            temp = ui_choice("Threaten him.", "Leave him.", "/", "/");
            if (temp == 0)
                current = -1;
            if (temp == 1)
                current = 12;
            break;
        case 10:
            temp = ui_choice("Now dude, YOU give me your keys!", "Finish him! FATALITY!", "/", "/");
            if (temp == 0)
                current = 4;
            if (temp == 1)
                current = 15;
            break;
        case 11:
            temp = ui_choice("Leave.", "Kill him.", "/", "/");
            if (temp == 0)
                current = -1;
            if (temp == 1)
                current = 13;
            break;
        case 12:
            en_mod_food(+2);
            current = -1;
            ui_continu_choice();
            break;
        case 13:
            temp = ui_choice("Leave.", "Search in the truck.", "/", "/");
            if (temp == 0)
                current = -1;
            if (temp == 1)
                current = 12;
            break;
        case 14:
            temp = ui_choice("Grab your weapon and kill him.", "/", "/", "/");
            if (temp == 0)
                current = 13;
            break;
        case 15:
            temp = ui_choice("Leave.", "Search in the truck.", "/", "/");
            if (temp == 0)
                current = -1;
            if (temp == 1)
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

    se_event_check[4] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/4", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 2;
            break;
        case 1:
            temp = ui_choice("What the fuck?", "Trick!", "Treat!", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
                current = 4;
            if (temp == 2)
                current = 5;
            break;
        case 2:
            current = -1;
            ui_continu_choice();
            break;
        case 3:
            temp = ui_choice("Kill him.", "Trick.", "Treat.", "/");
            if (temp == 0)
                current = 6;
            if (temp == 1)
            {
                if (inventory->money > 0)
                    en_mod_money(-1);
                else if (inventory->food > 0)
                    en_mod_food(-1);
                else if (inventory->gas > 2)
                    en_mod_gas(-1);
                current = 4;
            }
            if (temp == 2)
                current = 5;
            break;
        case 4:
            char0 = "Curtis";
            temp = ui_choice("Okay... We will find a candy shop if you want.", "Sorry, man. I don't have candy!", "/", "/");
            if (temp == 0)
                current = 9;
            if (temp == 1)
                current = 5;
            break;
        case 5:
            temp = ui_choice("Grab your gun and kill him.", "Go back to the bus and leave.", "Okay... again, trick!", "/");
            if (temp == 0)
                current = 6;
            if (temp == 1)
                current = 10;
            if (temp == 2)
                current = 7;
            break;
        case 6:
            current = -1;
            ui_continu_choice();
            break;
        case 7:
            temp = ui_choice("Hold on! I know an amazing candy shop in the next city!", "Grab your gun and kill him.", "/", "/");
            if (temp == 0)
                current = 8;
            if (temp == 1)
                current = 6;
            break;
        case 8:
            current = -1;
            char1 = "Curtis";
            en_add_passenger(char1, inventory->pa_count);
            ui_continu_choice();
            break;
        case 9:
            current = -1;
            char1 = "Curtis";
            en_add_passenger(char1, inventory->pa_count);
            ui_continu_choice();
            break;
        case 10:
            current = -1;
            ui_continu_choice();
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

    se_event_check[5] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/5", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 2;
            break;
        case 1:
            temp = ui_choice("Stay in the bus.", "Leave the bus.", "/", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
                current = 7;
            break;
        case 2:
            current = -1;
            ui_continu_choice();
            break;
        case 3:
            temp = ui_choice("Stay in the bus.", "Leave the bus.", "/", "/");
            if (temp == 0)
                current = 4;
            if (temp == 1)
                current = 7;
            break;
        case 4:
            temp = ui_choice("Stay in the bus.", "Leave the bus.", "Start the bus and drive on one of them.", "/");
            if (temp == 0)
                current = 5;
            if (temp == 1)
                current = 7;
            if (temp == 2)
                current = 6;
            break;
        case 5:
            current = -1; /* NEED GAME OVER */
            ui_continu_choice();
            break;
        case 6:
            current = -1;
            ui_continu_choice();
            break;
        case 7:
            temp = ui_choice("Be obedient.", "Refuse.", "/", "/");
            if (temp == 0)
                current = 9;
            if (temp == 1)
            {
                if (inventory->pa_count > 0)
                {
                    en_rm_passenger(inventory->pa_count);
                    current = 8;
                }
                else
                    current = 11;
            }
            break;
        case 8:
            temp = ui_choice("Give up.", "Refuse one more time.", "/", "/");
            if (temp == 0)
                current = 9;
            if (temp == 1)
                current = 10;
            break;
        case 9:
            current = -1;
            ui_continu_choice();
            if (inventory->food >= 2)
                en_mod_food(-1);
            if (inventory->money >= 100)
                en_mod_money(-100);
            if (inventory->money >= 50)
                en_mod_money(-50);
            if (inventory->gas > 1)
                en_mod_gas(-1);
            break;
        case 10:
            current = -1; /* NEED GAME OVER */
            ui_continu_choice();
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

    se_event_check[6] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/6", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Go back to sleep.", "Walk a little.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 2;
            break;
        case 1:
            current = -1;
            ui_continu_choice();
            break;
        case 2:
            temp = ui_choice("Return to the bus.", "Go take a look.", "/", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
                current = 4;
            break;
        case 3:
            current = -1;
            ui_continu_choice();
            break;
        case 4:
            current = -1;
            en_mod_gas(+1);
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_7()
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    se_event_check[7] = 1;

    if (inventory->pa_count > 0)
        char0 = inventory->passengers[uf_random(inventory->pa_count)];

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/7", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 4;
            if (temp == 1)
                current = 1;
            break;
        case 1:
            if (inventory->pa_count > 0)
                current = 2;
            else
                current = 3;
            ui_continu_choice();
            break;
        case 2:
            current = -1;
            ui_continu_choice();
            break;
        case 3:
            current = -1;
            ui_continu_choice();
            break;
        case 4:
            en_mod_money(+50);
            current = -1;
            ui_continu_choice();
            break;
        }
        after_event_clear(win_env, win_men);
    }
}

void se_event_8()
{
    int current = 0;
    int temp;
    char* char0 = " Chief of Travellers";
    char* char1 = "/";
    char* char2 = "Paco";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    char* choice1_temp = NULL;

    se_event_check[8] = 1;

    if (inventory->pa_count > 0)
        char1 = inventory->passengers[uf_random(inventory->pa_count)];

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/8", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Insult them.", "Kindly ask to pass.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 5;
            break;
        case 1:
            temp = ui_choice("Grab your gun and kill him.", "Be friendly.", "/", "/");
            if (temp == 0)
            {
                if (inventory->pa_count > 0)
                    current = 2;
                else current = 3;
            }
            if (temp == 1)
                current = 4;
            break;
        case 2:
            current = -1;
            en_rm_passenger(uf_compare(char1));
            ui_continu_choice();
            break;
        case 3:
            if (inventory->food > 0)
                en_mod_food(-1);
            if (inventory->gas > 1)
                en_mod_food(-1);
            current = -1;
            ui_continu_choice();
            break;
        case 4:
            current = 5;
            ui_continu_choice();
            break;
        case 5:
            if (en_update_total() < inventory->capacity)
                choice1_temp = "Of course, tell him to get on the bus.";
            else choice1_temp = "/";
            temp = ui_choice("Sorry, I can't take him with me.", choice1_temp, "/", "/");
            if (temp == 0)
                current = 7;
            if (temp == 1)
                current = 6;
            break;
        case 6:
            current = -1;
            ui_continu_choice();
            en_add_passenger(char2, inventory->pa_count);
            break;
        case 7:
            current = -1;
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_9()
{
    int current = 0;
    int temp;
    char* char0 = "Big Guy";
    char* char1 = "Woman";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    se_event_check[9] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/9", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop at the restaurant.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            current = 2;
            ui_continu_choice();
            break;
        case 2:
            temp = ui_choice("Go to the toilet.", "Approach the bar.", "/", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
                current = 4;
            break;
        case 3:
            temp = ui_choice("Go to the kitchen.", "/", "/", "/");
            if (temp == 0)
                current = 4;
            break;
        case 4:
            temp = ui_choice("Calm down, who's gonna kill you?", "Untie her.", "/", "/");
            if (temp == 0)
                current = 7;
            if (temp == 1)
                current = 5;
            break;
        case 5:
            temp = ui_choice("Ok, let's get out of here.", "Who did that to you?", "/", "/");
            if (temp == 0)
                current = 6;
            if (temp == 1)
                current = 7;
            break;
        case 6:
            temp = ui_choice("Leave.", "/", "/", "/");
            if (temp == 0)
                current = -1;
            break;
        case 7:
            temp = ui_choice("Kill him.", "Run.", "/", "/");
            if (temp == 0)
                current = 8;
            if (temp == 1)
                current = 15;
            break;
        case 8:
            current = 17;
            ui_continu_choice();
            break;
        case 9:
            temp = ui_choice("Ask her if she wants to come with you.", "Leave her.", "/", "/");
            if (temp == 0)
                current = 10;
            if (temp == 1)
                current = 11;
            break;
        case 10:
            en_add_passenger(char1, inventory->pa_count);
            current = -1;
            ui_continu_choice();
            break;
        case 11:
            current = -1;
            ui_continu_choice();
            break;
        case 12:
            temp = ui_choice("Ask her if she wants to come with you.", "Leave her.", "/", "/");
            if (temp == 0)
                current = 13;
            if (temp == 1)
                current = 14;
            break;
        case 13:
            current = -1;
            ui_continu_choice();
            break;
        case 14:
            current = -1;
            ui_continu_choice();
            break;
        case 15:
            temp = ui_choice("Start the bus and leave.", "Kill him.", "/", "/");
            if (temp == 0)
                current = -1;
            if (temp == 1)
                current = 16;
            break;
        case 16:
            temp = ui_choice("Leave.", "Go back to the restaurant.", "/", "/");
            if (temp == 0)
                current = -1;
            if (temp == 1)
                current = 17;
            break;
        case 17:
            temp = ui_choice("Search the kitchen.", "Search the kitchen and open the cash register.", "/", "/");
            if (temp == 0)
                current = 9;
            if (temp == 1)
                current = 12;
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_10()
{
    int current = 0;
    int temp;
    char* char0 = "Cashier";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    char* choice1_temp = NULL;

    se_event_check[10] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/10", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            temp = ui_choice("Buy him something.", "Leave the gas station.", "/", "/");
            if (temp == 0)
                current = 2;
            if (temp == 1)
                current = 3;
            break;
        case 2:
            /* NEED if (bus is not full)*/
            if (inventory->money >= 45)
                choice1_temp = "Buy gasoline.";
            else choice1_temp = "/";

            temp = ui_choice("Leave the gas station.", choice1_temp, "/", "/");

            if (temp == 0)
                current = 5;
            if (temp == 1)
            {
                current = 3;
                en_mod_money(-45);
            }
            break;
        case 3:
            current = -1;
            ui_continu_choice();
            break;
        }
        after_event_clear(win_env, win_men);
    }
}

void se_event_11()
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    se_event_check[11] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/11", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            current = 2;
            ui_continu_choice();
            break;
        case 2:
            temp = ui_choice("Take a minute of silence.", "Leave.", "/", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
                current = 4;
            break;
        case 3:
            current = 2;
            ui_continu_choice();
            break;
        case 4:
            current = -1;
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_12()
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    se_event_check[12] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/12", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            temp = ui_choice("Run.", "Stay here.", "/", "/");
            if (temp == 0)
                current = 2;
            if (temp == 1)
                current = 3;
            break;
        case 2:
            temp = ui_choice("Leave.", "Stay here.", "/", "/");
            if (temp == 0)
                current = 4;
            if (temp == 1)
                current = 5;
            break;
        case 3:
            current = -1; /* NEED GAME OVER*/
            ui_continu_choice();
            break;
        case 4:
            current = -1;
            ui_continu_choice();
            break;
        case 5:
            current = -1; /* NEED GAME OVER*/
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_13()
{
    int current = 0;
    int temp;
    char* char0 = "Evelynn";
    char* char1 = "Rafe";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/13", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("It's possible.", "I don't think so, I'm alright.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 15;
            break;
        case 1:
            temp = ui_choice("Everything is gonna be alright.", "What's happening to me?", "/", "/");
            if (temp == 0)
                current = 2;
            if (temp == 1)
                current = 2;
            break;
        case 2:
            temp = ui_choice("Focus more.", "Focus on the road.", "/", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
                current = 4;
            break;
        case 3:
            current = 16;
            ui_continu_choice();
            break;
        case 4:
            current = -1;
            ui_continu_choice();
            break;
        case 5:
            temp = ui_choice("Fight the thing!", "Keep swiming!", "/", "/");
            if (temp == 0)
                current = 7;
            if (temp == 1)
                current = 8;
            break;
        case 6:
            temp = ui_choice("Found out what it is.", "Flee from this thing.", "/", "/");
            if (temp == 0)
                current = 11;
            if (temp == 1)
                current = 12;
            break;
        case 7:
            temp = ui_choice("Go on the surface!", "Keep fighting!", "/", "/");
            if (temp == 0)
                current = 9;
            if (temp == 1)
                current = 10;
            break;
        case 8:
            current = -1;
            ui_continu_choice();
            break;
        case 9:
            current = -1;
            ui_continu_choice();
            break;
        case 10:
            current = -1;
            ui_continu_choice();
            break;
        case 11:
            current = -1;
            ui_continu_choice();
            break;
        case 12:
            current = -1;
            ui_continu_choice();
            break;
        case 15:
            current = -1;
            ui_continu_choice();
            break;
        case 16:
            current = 17;
            ui_continu_choice();
            break;
        case 17:
            temp = ui_choice("Run away!", "Wait.", "/", "/");
            if (temp == 0)
                current = 5;
            if (temp == 1)
                current = 6;
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_15()
{
    int current = 0;
    int temp;
    char* char0 = "Shopkeeper";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    char* choice0_temp = NULL;
    char* choice1_temp = NULL;
    char* choice2_temp = NULL;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/15", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            current = 2;
            ui_continu_choice();
            break;
        case 2:
            if (inventory->money < 30)
                choice0_temp = "Sorry, I don't have money.";
            else choice0_temp = "Leave.";

            if (inventory->money >= 30)
                choice1_temp = "Buy one Food for 30$.";
            else choice1_temp = "/";

            if (inventory->money >= 40)
                choice2_temp = "Buy one Gas for 40$.";
            else choice2_temp = "/";

            temp = ui_choice(choice0_temp, choice1_temp, choice2_temp, "/");
            if (temp == 0)
            {
                if (inventory->money < 30)
                    current = 3;
                else
                    current = 4;
            }
            if (temp == 1)
            {
                en_mod_food(+1);
                en_mod_money(-30);
                current = 2;
            }
            if (temp == 2)
            {
                en_mod_gas(+1);
                en_mod_money(-40);
                current = 2;
            }
            break;
        case 3:
            current = 2;
            ui_continu_choice();
            break;
        case 4:
            current = 2;
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_16()
{
    int current = 0;
    int temp;
    char* char0 = "Shopkeeper";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    char* choice0_temp = NULL;
    char* choice1_temp = NULL;
    char* choice2_temp = NULL;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/16", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            current = 2;
            ui_continu_choice();
            break;
        case 2:
            if (inventory->money < 40)
                choice0_temp = "Sorry, I don't have money.";
            else choice0_temp = "Leave.";

            if (inventory->money >= 40)
                choice1_temp = "Buy one Food for 40$.";
            else choice1_temp = "/";

            if (inventory->money >= 50)
                choice2_temp = "Buy one Gas for 50$.";
            else choice2_temp = "/";

            temp = ui_choice(choice0_temp, choice1_temp, choice2_temp, "/");
            if (temp == 0)
            {
                if (inventory->money < 40)
                    current = 3;
                else
                    current = 4;
            }
            if (temp == 1)
            {
                en_mod_food(+1);
                en_mod_money(-40);
                current = 2;
            }
            if (temp == 2)
            {
                en_mod_gas(+1);
                en_mod_money(-50);
                current = 2;
            }
            break;
        case 3:
            current = 2;
            ui_continu_choice();
            break;
        case 4:
            current = 2;
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_17()
{
    int current = 0;
    int temp;
    char* char0 = "Shopkeeper";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    char* choice0_temp = NULL;
    char* choice1_temp = NULL;
    char* choice2_temp = NULL;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/17", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            current = 2;
            ui_continu_choice();
            break;
        case 2:
            if (inventory->money < 35)
                choice0_temp = "Sorry, I don't have money.";
            else choice0_temp = "Leave.";

            if (inventory->money >= 35)
                choice1_temp = "Buy one Food for 35$.";
            else choice1_temp = "/";

            if (inventory->money >= 45)
                choice2_temp = "Buy one Gas for 45$.";
            else choice2_temp = "/";

            temp = ui_choice(choice0_temp, choice1_temp, choice2_temp, "/");
            if (temp == 0)
            {
                if (inventory->money < 35)
                    current = 3;
                else
                    current = 4;
            }
            if (temp == 1)
            {
                en_mod_food(+1);
                en_mod_money(-35);
                current = 2;
            }
            if (temp == 2)
            {
                en_mod_gas(+1);
                en_mod_money(-45);
                current = 2;
            }
            break;
        case 3:
            current = 2;
            ui_continu_choice();
            break;
        case 4:
            current = 2;
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_18()
{
    int current = 0;
    int temp;
    char* char0 = "Shopkeeper";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    char* choice1_temp = NULL;
    char* choice2_temp = NULL;

    se_event_check[18] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/18", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            current = 2;
            ui_continu_choice();
            break;
        case 2:
            if (inventory->money >= 20)
                choice1_temp = "Buy on Food for 20$.";
            else choice1_temp = "/";
            if (inventory->money >= 40)
                choice2_temp = "Buy on Gas for 40$.";
            else choice2_temp = "/";

            temp = ui_choice("Leave.", choice1_temp, choice2_temp, "/");
            if (temp == 0)
                current = 5;
            if (temp == 1)
            {
                en_mod_money(-20);
                en_mod_food(+1);
                current = 4;
            }
            if (temp == 2)
            {
                en_mod_gas(+1);
                en_mod_money(-40);
                current = 3;
            }
            break;
        case 3:
            current = 2;
            ui_continu_choice();
            break;
        case 4:
            current = 2;
            ui_continu_choice();
            break;
        case 5:
            current = -1;
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}


void se_event_19()
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    se_event_check[19] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/19", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Take a look.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            en_mod_gas(+1);
            current = -1;
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_20()
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    se_event_check[20] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/20", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Take a look.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            en_mod_gas(+1);
            current = -1;
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_21()
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    char* choice1_temp = NULL;

    se_event_check[21] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/21", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            current = 2;
            ui_continu_choice();
            break;
        case 2:
            if (inventory->pa_count == 0)
                choice1_temp = "I don't have anybody to trade with you.";
            else choice1_temp = "Sell one of your mates for 100$.";
            temp = ui_choice(choice1_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                if (inventory->pa_count == 0)
                    current = 5;
                else current = 3;
            }
            if (temp == 1)
                current = -1;
            break;
        case 3:
            en_rm_passenger(uf_random(inventory->pa_count - 1));
            en_mod_money(+100);
            current = 2;
            ui_continu_choice();
            break;
        case 4:
            current = -1;
            ui_continu_choice();
            break;
        case 5:
            current = -1;
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void se_event_22()
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    se_event_check[22] = 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/secondary/22", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = -1;
            break;
        case 1:
            en_mod_food(+2);
            en_mod_gas(+1);
            current = -1;
            ui_continu_choice();
            break;
        }

        after_event_clear(win_env, win_men);
    }
}
