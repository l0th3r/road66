/* LIBS */
#include "../../includes.h"

void empty() {}

void pe_event_1();
void pe_event_2();

/* function to call for each city */
void (*city_event[9])() = 
{
    empty, /* city 0 = Los Angeles */
    empty, /* city 1 = Las Vegas */
    empty, /* city 2 = Henderson */
    empty,
    empty,
    empty,
    empty,
    empty,
    empty,
};




void pe_event_1()	/* Las Vegas */
{
    int current = 0;
    int temp;
    char* char0 = "Odd Guy";
    char* char1 = "Organizer";
    char* char2 = "Crowd";
    char* char3 = "Receptionist";
    char* char4 = "Foreman";
    char* char5 = "/";
	
    int moneyBet = 0;
	int lastLostMachineDial = 0;
	int unlockHostel = 0; 			/* 0 = false ; 1 = true */
	int unlockExitDoor = 0;			/* 0 = false ; 1 = true */
	int lockFightRoom = 0;			/* 0 = false ; 1 = true */
	int oweMoney = 0;				/* 0 = false ; 1 = true */
	char* fighterBet = NULL;

    while(current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/1", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				ui_continu_choice(win_men);
				current = 1;
			break;
			case 1:
				ui_continu_choice(win_men);
                current = 2;
			break;
			case 2:
				temp = ui_choice("Give him what he asks.", "Grab your gun and kill him.", "/", "/");                  
                if(temp == 0)
                    current = 4;
                if(temp == 1)
                    current = 3;
			break;
			case 3:
				/* NEED GAME OVER WINDOW */
			break;
			case 4:
				ui_continu_choice(win_men);
                current = 900;
			break;
			case 400:
				lockFightRoom = 1;
				ui_continu_choice(win_men);
                current = 402;
			break;
			case 401:
				ui_continu_choice(win_men);
                current = 901;
			break;
			break;
			case 402:
				temp = ui_choice("Ask information to the organizer.", "Leave." "/", "/");                  
                if(temp == 0)
                    current = 410;
                if(temp == 1)
                    current = 403;
			break;
			case 403:
				temp = ui_choice("Yes.", "No, I have ever been to Las Vegas." "/", "/");                  
                if(temp == 0)
                    current = 404;
                if(temp == 1)
                    current = 407;
			break;
			case 404:
				temp = ui_choice("I don't know.", "Play in a casino." "Maybe have a date with you.", "Something like tropical holidays, a house or whatever.");                  
                if(temp == 0)
                    current = 405;
                if(temp == 1)
                    current = 406;
				if(temp == 2)
                    current = 408;
                if(temp == 3)
                    current = 409;
			break;
			case 405:
				ui_continu_choice(win_men);
                current = 411;
			break;
			case 406:
				ui_continu_choice(win_men);
                current = 411;
			break;
				
				/* TO FINISH */
			}

        after_event_clear(win_env, win_men);
    }

void pe_event_2()
{
    int current = 0;
    int temp;
    char* char0 = "Jackson";
    char* char1 = "Man";
    char* char2 = "Rafe";
    char* char3 = "Apu";
    char* char4 = NULL;
    char* char5 = "/";

    if(inventory->pa_count > 0)
        char4 = inventory->passengers[uf_random(inventory->pa_count)];

    while(current >= 0)
    {
        /* 2 = id d'event  */
        ui_print_dial(win_env, current, ev_w, "event/principal/2", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				if(uf_compare("Maxence") == 1)
                {
                    temp = ui_choice("Knock again.", "Go back to the bus.", "/", "/");
                    if(temp == 0)
                        current = 37;
                }
                else
                {
                    ui_continu_choice(win_men);
                    current = 38;
                }
			break;
            case 1:
                temp = ui_choice("Knock again.", "Go back to the bus.", "/", "/");                  
                if(temp == 0)
                    current = 2;
                if(temp == 1)
                    current = 3;
			break;
            case 2:
                current = 7;
                ui_continu_choice(win_men);
			break;
            case 3:
                temp = ui_choice("Go into the house.", "Say him goodbye.", "/", "/");                  
                if(temp == 0)
                    current = 7;
                if(temp == 1)
                    current = 19;
			break;
            case 4:
                temp = ui_choice("Peace.", "Chaos?", "/", "/");                  
                if(temp == 0)
                    current = 5;
                if(temp == 1)
                    current = 6;
			break;
            case 5:
                temp = ui_choice("Where are you going?", "/", "/", "/");                  
                if(temp == 0)
                    current = 8;
			break;
            case 6:
                temp = ui_choice("Where are you going?", "/", "/", "/");                  
                if(temp == 0)
                    current = 8;
			break;
            case 7:
                temp = ui_choice("Do you wanna come with me?", "I am here to say goodbye to my old friend.", "/", "/");                  
                if(temp == 0)
                    current = 4;
                if(temp == 1)
                    current = 4;
			break;
            case 8:
                ui_continu_choice(win_men);
                if(inventory->pa_count == 1)
                    current = 9;
                if(inventory->pa_count >= 2)
                    current = 10;
                if(inventory->pa_count == 0)
                    current = 11;
			break;
            case 9:
                temp = ui_choice("Follow Jackson.", "/", "/", "/");                  
                if(temp == 0)
                    current = 11;
			break;
            case 10:
                temp = ui_choice("Follow Jackson.", "/", "/", "/");                  
                if(temp == 0)
                    current = 11;
			break;
            case 11:
                ui_continu_choice(win_men);
                current = 12;
            break;
            case 12:
                ui_continu_choice(win_men);
                en_mod_food(+1);
                current = 13;
            break;
            case 13:
                temp = ui_choice("How much for the gasoline barrel?", "No, thank you.", "/", "/");                  
                if(temp == 0)
                    current = 14;
                if(temp == 1)
                    current = 17;
            break;
            case 14:
                if(inventory->money >= 50)
                {
                    temp = ui_choice("I take it.", "It's more than twice in a gas station!", "/", "/");                  
                    if(temp == 0)
                    {
                        en_mod_gas(+1);
                        current = 16;
                    }
                    if(temp == 1)
                        current = 15;
                } else
                {
                    temp = ui_choice("I don't have enough money.", "/", "/", "/");                  
                    if(temp == 0)
                        current = 17;
                }
            break;
            case 15:
                temp = ui_choice("Yes.", "No, thanks.", "/", "/");                  
                if(temp == 0)
                {
                    en_mod_gas(+1);
                    current = 16;
                }
                if(temp == 1)
                    current = 17;
            break;
            case 16:
                temp = ui_choice("Keep driving in Henderson.", "/", "/", "/");                  
                if(temp == 0)
                    current = 20;
            break;
            case 17:                
                temp = ui_choice("Keep driving in Henderson.", "/", "/", "/");                  
                if(temp == 0)
                    current = 20;
            break;
            case 18:                
                temp = ui_choice("Keep driving in Henderson.", "/", "/", "/");                  
                if(temp == 0)
                    current = 20;
            break;
            case 19:
                ui_continu_choice(win_men);
                current = 7;
            break;
            case 20:                
                temp = ui_choice("Stop the bus next to the building.", "Keep driving.", "/", "/");                  
                if(temp == 0)
                    current = 22;
                if(temp == 1)
                    current = 21;
            break;
            case 21:
                /* NEEDS STATISTICS */
                ui_continu_choice(win_men);
                current = 32;
            break;
            case 22:                
                temp = ui_choice("Hey dude! Don't do that!", "Jump coward!", "Look at him.", "/");                  
                if(temp == 0)
                    current = 25;
                if(temp == 1)
                    current = 23;
                if(temp == 2)
                    current = 26;
            break;
            case 23:                
                temp = ui_choice("Do you smoke?", "Of course life is shit! And we all have to fight it!", "Holy shit you are right! And when I see your big ass, I pity you even more!", "/");                  
                if(temp == 0)
                    current = 27;
                if(temp == 1)
                    current = 28;
                if(temp == 2)
                    current = 31;
            break;
            case 24:                
                ui_continu_choice(win_men);
                current = 32;
            break;
            case 25:                
                temp = ui_choice("Ask him if he's a smoker.", "You try a joke and propose.", "/", "/");                  
                if(temp == 0)
                    current = 27;
                if(temp == 1)
                    current = 30;
            break;
            case 26:                
                temp = ui_choice("Don't answer.", "You big fat ass! Are you gonna jump?", "/", "/");                  
                if(temp == 0)
                    current = 24;
                if(temp == 1)
                    current = 23;
            break;
            case 27:                
                temp = ui_choice("What’s your name?", "/", "/", "/");                  
                if(temp == 0)
                {
                    char1 = "Bob";
                    current = 29;
                }
            break;
            case 28:                
                ui_continu_choice(win_men);
                current = 32;
            break;
            case 29:                
                temp = ui_choice("Propose him to come with you.", "Suggest him to leave this city.", "/", "/");                  
                if(temp == 0)
                    current = 33;
                if(temp == 1)
                    current = 34;
            break;
            case 30:                
                temp = ui_choice("Propose him to come with you.", "Suggest him to leave this city.", "/", "/");                  
                if(temp == 0)
                    current = 35;
                if(temp == 1)
                    current = 36;
            break;
            case 31:                
                ui_continu_choice(win_men);
                current = 32;
            break;
            case 32:                
                ui_continu_choice(win_men);
                current = -1;
            break;
            case 33:                
                temp = ui_choice("Keep driving.", "/", "/", "/");                  
                if(temp == 0)
                {
                    en_add_passenger(char1, inventory->pa_count);
                    current = 32;
                }
            break;
            case 34:                
                temp = ui_choice("Keep driving.", "/", "/", "/");                  
                if(temp == 0)
                    current = 32;
            break;
            case 35:                
                ui_continu_choice(win_men);
                en_add_passenger(char1, inventory->pa_count);
                current = 32;
            break;
            case 36:                
                ui_continu_choice(win_men);
                current = 24;
            break;
            case 37:                
                ui_continu_choice(win_men);
                current = 38;
            break;
            case 38:                
                ui_continu_choice(win_men);
                current = 1;
            break;
        }

        after_event_clear(win_env, win_men);
    }
}
