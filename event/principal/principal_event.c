/* LIBS */
#include "../../includes.h"

void empty() {}

void pe_event_0();
void pe_event_1();
void pe_event_2();
void pe_event_3();
void pe_event_4();
void pe_event_7();

void pe_event_100();
void pe_event_101();
void pe_event_103();
void pe_event_106();

int who_is_alive = 0; /* 0 = Rafe   1 = Evelynn */
int start_gas = 5;
int start_food = 6;

/* function to call for each city */
void (*city_events[9])() =
{
    pe_event_0,     /* city 0 = Los Angeles */
    pe_event_1,     /* city 1 = Las Vegas */
    pe_event_2,     /* city 2 = Henderson */
    pe_event_3,     /* city 3 = Kingman */
    pe_event_4,     /* city 4 = Phoenix City */
    pe_event_5,     /* city 5 = Flagstaff */
    empty,          /* city 6 = Albuquerque */
    pe_event_7,     /* city 7 = Dallas */
    empty,          /* city 8 = Oklahoma */
};

/* function to call for each city */
void (*main_events[7])() =
{
    pe_event_100,   /* Maxence */
    pe_event_101,   /* Axel F */
    empty,          /* Axel D */
    pe_event_103,   /* Cosmo */
    empty,          /* Damien */
    empty,          /* Theo */
    pe_event_106,   /* Road blocked */
};


void pe_event_0()
{
    int current = 0;
    int temp;
    char* char0 = "Rafe";
    char* char1 = "Evelynn";
    char* char2 = "The patient";
    char* char3 = "The security guard";
    char* char4 = "Young man";
    char* char5 = "Assaillant";

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/0", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            current = -1;
            ui_continu_choice();
            /* temp = ui_choice("Answer the call.", "/", "/", "/");
             if (temp == 0)
             {
                 en_mod_food(+start_food);
                 els_is_inventory = 1;
                 current = 1;*/
        }
        break;
        case 1:
            temp = ui_choice("Leave your apartment.", "Check one last time for your stuff.", "/", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
            {
                en_mod_food(+1);
                current = 2;
            }
            break;
        case 2:
            temp = ui_choice("Leave your apartment.", "/", "/", "/");
            if (temp == 0)
                current = 3;
            break;
        case 3:
            current = 4;
            ui_continu_choice();
            break;
        case 4:
            temp = ui_choice("Turn around.", "Honk.", "/", "/");
            if (temp == 0)
                current = 5;
            if (temp == 1)
                current = 6;
            break;
        case 5:
            current = 7;
            ui_continu_choice();
            break;
        case 6:
            current = 5;
            ui_continu_choice();
            break;
        case 7:
            temp = ui_choice("Try to convince your brother to drop his weapon.", "Try to convince the guard that your brother doesn't mean to hurt anybody.", "/", "/");
            if (temp == 0)
            {
                who_is_alive = 0; /* Rafe */
                current = 8;
            }
            if (temp == 1)
            {
                who_is_alive = 1; /* Evelynn */
                current = 9;
            }
            break;
        case 8:
            temp = ui_choice("Leave the hospital by the main entrance door.", "Find another exit.", "/", "/");
            if (temp == 0)
                current = 10;
            if (temp == 1)
                current = 11;
            break;
        case 9:
            temp = ui_choice("Listen to me. He's dead and we can't stay here.", "Shut up! Is there a safe exit door?", "Listen, Evelynn. Right now, I am completely lost, just like you. But we need to get out of here.", "/");
            if (temp == 0)
                current = 17;
            if (temp == 1)
                current = 19;
            if (temp == 2)
                current = 20;
            break;
        case 10:
            temp = ui_choice("Leave.", "Stay to help your brother.", "/", "/");
            if (temp == 0)
                current = 14;
            if (temp == 1)
                current = 12;
            break;
        case 11:
            temp = ui_choice("Stay with your brother to help him.", "Leave him.", "/", "/");
            if (temp == 0)
                current = 12;
            if (temp == 1)
                current = 13;
            break;
        case 12:
            current = 14;
            ui_continu_choice();
            break;
        case 13:
            current = 14;
            ui_continu_choice();
            break;
        case 14:
            current = 15;
            ui_continu_choice();
            break;
        case 15:
            current = 16;
            ui_continu_choice();
            en_mod_gas(+start_gas);
            break;
        case 16:
            temp = ui_choice("Drive faster.", "Stop at the light.", "/", "/");
            if (temp == 0)
                current = 22;
            if (temp == 1)
                current = 23;
            break;
        case 17:
            current = 18;
            ui_continu_choice();
            break;
        case 18:
            current = 15;
            ui_continu_choice();
            break;
        case 19:
            current = 21;
            ui_continu_choice();
            break;
        case 20:
            current = 21;
            ui_continu_choice();
            break;
        case 21:
            current = 15;
            ui_continu_choice();
            break;
        case 22:
            temp = ui_choice("Stop the bus.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 25;
            if (temp == 1)
                current = 26;
            break;
        case 23:
            current = 24;
            ui_continu_choice();
            break;
        case 24:
            temp = ui_choice("Open the door.", "Drive away.", "/", "/");
            if (temp == 0)
                current = 27;
            if (temp == 1)
                current = 28;
            break;
        case 25:
            current = 24;
            ui_continu_choice();
            break;
        case 26:
            current = 24;
            ui_continu_choice();
            break;
        case 27:
            char4 = "Tim";
            en_add_passenger(char4, inventory->pa_count);
            current = 29;
            ui_continu_choice();
            break;
        case 28:
            current = 29;
            ui_continu_choice();
            break;
        case 29:
            current = 30;
            ui_continu_choice();
            break;
        case 30:
            current = -1;
            ui_continu_choice();
            break;
    }

    after_event_clear(win_env, win_men);
}
}

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

    int money_bet = -1;
    int last_lost_machine_dial = 0;
    int unlock_hostel = 0;
    int unlock_exit_door = 0;
    int locked_fight_room = 0;
    int owe_money = 0;

    char* fighter_bet = NULL;
    char* choice0_temp = NULL;
    char* choice1_temp = NULL;
    char* choice2_temp = NULL;
    char* choice3_temp = NULL;

    money_bet += 1;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/1", char0, char1, char2, char3, char4, char5);

        switch (current)
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
            if (temp == 0)
                current = 4;
            if (temp == 1)
                current = 3;
            break;
        case 3:
            /* NEED GAME OVER */
            ui_continu_choice(win_men);
            current = -1;
            els_is_exit = 666;
            break;
        case 4:
            ui_continu_choice(win_men);
            current = 900;
            break;
        case 400:
            locked_fight_room = 1;
            ui_continu_choice(win_men);
            current = 402;
            break;
        case 401:
            ui_continu_choice(win_men);
            current = 901;
            break;
            break;
        case 402:
            temp = ui_choice("Ask information to the organizer.", "Leave.", "/", "/");
            if (temp == 0)
                current = 410;
            if (temp == 1)
                current = 403;
            break;
        case 403:
            temp = ui_choice("Yes.", "No, I have ever been to Las Vegas.", "/", "/");
            if (temp == 0)
                current = 404;
            if (temp == 1)
                current = 407;
            break;
        case 404:
            temp = ui_choice("I don't know.", "Play in a casino.", "Maybe have a date with you.", "Something like tropical holidays, a house or whatever.");
            if (temp == 0)
                current = 405;
            if (temp == 1)
                current = 406;
            if (temp == 2)
                current = 408;
            if (temp == 3)
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
        case 407:
            ui_continu_choice(win_men);
            current = 411;
            break;
        case 408:
            ui_continu_choice(win_men);
            current = 411;
            break;
        case 409:
            ui_continu_choice(win_men);
            current = 411;
            break;
        case 410:
            ui_continu_choice(win_men);
            current = 411;
            break;
        case 411:
            temp = ui_choice("What if I fight?", "What if I bet?", "I'm not interested.", "/");
            if (temp == 0)
                current = 412;
            if (temp == 1)
                current = 414;
            if (temp == 2)
                current = 423;
            break;
        case 412:
            temp = ui_choice("Let's fight.", "Negotiate.", "It sounds shit. Thank you, still.", "/");
            if (temp == 0)
            {
                money_bet = 100;
                current = 600;
            }
            if (temp == 1)
                current = 602;
            if (temp == 2)
                current = 413;
            break;
        case 413:
            if (inventory->money > 0)
                choice3_temp = "Bet.";
            else
                choice3_temp = "/";
            temp = ui_choice("Leave the room.", "Stay.", "Let's fight.", choice3_temp);
            if (temp == 0)
                current = 900;
            if (temp == 1)
                current = 611;
            if (temp == 2)
            {
                money_bet = 100;
                current = 600;
            }
            if (temp == 3)
                current = 414;
            break;
        case 414:
            temp = ui_choice("Angel.", "Tyler.", "/", "/");
            if (temp == 0)
            {
                fighter_bet = "Angel";
                current = 415;
            }
            if (temp == 1)
            {
                fighter_bet = "Tyler";
                current = 416;
            }
            break;
        case 415:   /* identique au 416 */
            if (inventory->money == 0)
                choice0_temp = "Fuck, I'm ruined.";
            else if (inventory->money < 50)
                choice0_temp = "Bet the rest of your money.";
            else if (inventory->money >= 50)
                choice0_temp = "50$";
            else choice0_temp = "/";

            if (inventory->money >= 100)
                choice1_temp = "100$";
            else choice1_temp = "/";

            if (inventory->money > 0)
                choice2_temp = "Finally, I don't want to bet.";
            else choice2_temp = "/";

            temp = ui_choice(choice0_temp, choice1_temp, choice2_temp, "/");
            if (temp == 0)
            {
                if (inventory->money <= 0)
                    current = 418;
                else if (inventory->money < 50)
                {
                    current = 417;
                    money_bet = inventory->money;
                }
                else if (inventory->money >= 50)
                {
                    current = 417;
                    money_bet = 50;
                }
            }

            if (temp == 1)
            {
                current = 417;
                money_bet = 100;
            }
            if (temp == 2)
                current = 418;

            en_mod_money(-money_bet);
            break;
        case 416:    /* identique au 415 */
            if (inventory->money == 0)
                choice0_temp = "Fuck, I'm ruined.";
            else if (inventory->money < 50)
                choice0_temp = "Bet the rest of your money.";
            else if (inventory->money >= 50)
                choice0_temp = "50$";
            else choice0_temp = "/";

            if (inventory->money >= 100)
                choice1_temp = "100$";
            else choice1_temp = "/";

            if (inventory->money > 0)
                choice2_temp = "Finally, I don't want to bet.";
            else choice2_temp = "/";

            temp = ui_choice(choice0_temp, choice1_temp, choice2_temp, "/");
            if (temp == 0)
            {
                if (inventory->money <= 0)
                    current = 418;
                else if (inventory->money < 50)
                {
                    current = 417;
                    money_bet = inventory->money;
                }
                else if (inventory->money >= 50)
                {
                    current = 417;
                    money_bet = 50;
                }
            }

            if (temp == 1)
            {
                current = 417;
                money_bet = 100;
            }
            if (temp == 2)
                current = 418;

            en_mod_money(-money_bet);
            break;
        case 417:
            ui_continu_choice(win_men);
            current = 500;
            break;
        case 418:
            temp = ui_choice("Yes explain me please.", "No, I don't want to fight.", "/", "/");
            if (temp == 0)
                current = 414;
            if (temp == 1)
                current = 413;
            break;
        case 419:
            temp = ui_choice("Let's fight.", "Negociate.", "It sounds shit. Thank you, still.", "/");
            if (temp == 0)
                current = 600;
            if (temp == 1)
                current = 602;
            if (temp == 2)
                current = 413;
            break;
        case 420:
            temp = ui_choice("Leave the room.", "Stay.", "Let's fight.", "/");
            if (temp == 0)
                current = 900;
            if (temp == 1)
                current = 611;
            if (temp == 2)
                current = 600;
            break;
        case 423:
            ui_continu_choice(win_men);
            current = 900;
            break;
        case 500:
            if (uf_strcmp(fighter_bet, "Tyler") == 1)
                choice0_temp = "Encourage Tyler.";
            if (uf_strcmp(fighter_bet, "Angel") == 1)
                choice0_temp = "Encourage Angel.";

            temp = ui_choice(choice0_temp, "/", "/", "/");
            if (uf_strcmp(fighter_bet, "Tyler") == 1)
                current = 501;
            if (uf_strcmp(fighter_bet, "Angel") == 1)
                current = 502;
            break;
        case 501:
            temp = ui_choice("Punch this motherfucker!", "You can do it!", "Wait for his right hook!", "Wait for his left hook!");
            if (temp == 0 || temp == 1 || temp == 2)
                current = 503;
            if (temp == 3)
            {
                en_mod_money(+(money_bet * 2));
                current = 504;
            }
            break;
        case 502:
            temp = ui_choice("Stay in touch!", "Take him away!", "Raise your guard!", "You can do it!");
            if (temp == 0 || temp == 1 || temp == 3)
                current = 505;
            if (temp == 2)
            {
                en_mod_money(+(money_bet * 2));
                current = 506;
            }
            break;
        case 503:
            temp = ui_choice("Leave the fight room.", "Stay.", "/", "/");
            if (temp == 0)
                current = 900;
            if (temp == 1)
                current = 507;
            break;
        case 504:
            ui_continu_choice(win_men);
            en_mod_money(+(money_bet * 2));
            current = 900;
            break;
        case 505:
            temp = ui_choice("Leave the fight room.", "Stay.", "/", "/");
            if (temp == 0)
                current = 900;
            if (temp == 1)
                current = 507;
            break;
        case 506:
            ui_continu_choice(win_men);
            current = 900;
            break;
        case 507:
            ui_continu_choice(win_men);
            current = 900;
            break;
        case 600:
            ui_continu_choice(win_men);
            current = 601;
            break;
        case 601:
            temp = ui_choice("Gimme this shit.", "No thanks.", "/", "/");
            if (temp == 0)
                current = 604;
            if (temp == 1)
                current = 605;
            break;
        case 602:
            temp = ui_choice("Let's fight for two hundred bucks.", "Four hundred bucks.", "/", "/");
            if (temp == 0)
            {
                money_bet = 200;
                current = 606;
            }
            if (temp == 1)
                current = 608;
            break;
        case 603:
            ui_continu_choice(win_men);
            current = 613;
            break;
        case 604:
            ui_continu_choice(win_men);
            current = 700;
            break;
        case 605:
            ui_continu_choice(win_men);
            current = 612;
            break;
        case 606:
            ui_continu_choice(win_men);
            current = 601;
            break;
        case 607:
            ui_continu_choice(win_men);
            current = 601;
            break;
        case 608:
            temp = ui_choice("Two hundred bucks is a good price, I will fight.", "Never mind, I don't fight.", "/", "/");
            if (temp == 0)
            {
                money_bet = 200;
                current = 606;
            }
            if (temp == 1)
                current = 609;
            break;
        case 609:
            temp = ui_choice("I take the risk.", "Two hundred bucks is a good price finally.", "No, I said that I don't fight.", "/");
            if (temp == 0)
            {
                owe_money = 1;
                current = 607;
            }
            if (temp == 1)
            {
                money_bet = 200;
                current = 606;
            }
            if (temp == 2)
                current = 610;
            break;
        case 610:
            temp = ui_choice("I want to bet on a fighter.", "No thanks.", "/", "/");
            if (temp == 0)
                current = 414;
            if (temp == 1)
                current = 611;
            break;
        case 611:
            ui_continu_choice(win_men);
            current = 900;
            break;
        case 612:
            temp = ui_choice("Actually, I'm shitting my pants.", "Ready.", "/", "/");
            if (temp == 0)
                current = 615;
            if (temp == 1)
                current = 616;
            break;
        case 613:
            temp = ui_choice("Go go go! Where is pussy Foreman?!", "/", "/", "/");
            current = 616;
            break;
        case 615:
            ui_continu_choice(win_men);
            current = 617;
            break;
        case 616:
            ui_continu_choice(win_men);
            current = 617;
            break;
        case 617:
            temp = ui_choice("Knock him on the chin with a striking uppercut.", "Fold elbow up and block.", "Try to knock him with a lead punch right in his face.", "/");
            if (temp == 0)
                current = 619;
            if (temp == 1)
                current = 618;
            if (temp == 2)
                current = 619;
            break;
        case 618:
            temp = ui_choice("You step back, gain momentum and try to double dropkick.", "Clinch Foreman and stamp his thoracic cavity.", "Arch your leg behind him and use your shoulder to strike his chest.", "/");
            if (temp == 0)
                current = 623;
            if (temp == 1)
                current = 621;
            if (temp == 2)
                current = 622;
            break;
        case 619:
            temp = ui_choice("You try a short sequence of low-kick and high.", "Arch your leg behind him and use your shoulder to strike his chest.", "You step back, gain momentum and try to double dropkick.", "/");
            if (temp == 0)
                current = 624;
            if (temp == 1)
                current = 622;
            if (temp == 2)
                current = 623;
            break;
        case 620:
            temp = ui_choice("You try a short sequence of low-kick and high.", "You step back, gain momentum and try to double dropkick.", "Get closer and grab him to clinch.", "/");
            if (temp == 0)
                current = 624;
            if (temp == 1)
                current = 623;
            if (temp == 2)
                current = 625;
            break;
        case 621:
            temp = ui_choice("You try a short sequence of low-kick and high.", "You step back, gain momentum and try to double dropkick.", "Get closer and grab him to clinch.", "/");
            if (temp == 0)
                current = 624;
            if (temp == 1)
                current = 623;
            if (temp == 2)
                current = 625;
            break;
        case 622:
            temp = ui_choice("Smashing his head against the floor.", "Extending the leg and hooking the leg back to strike the head.", "/", "/");
            if (temp == 0)
                current = 631;
            if (temp == 1)
                current = 627;
            break;
        case 623:
            temp = ui_choice("Low-kick in targeting the diaphragm and follow-up with a jumping knee-kick right in his face.", "Underhand riposte of the back arm followed by an uppercut.", "Extending the leg and and hooking the leg back to strike the head.", "/");
            if (temp == 0)
                current = 626;
            if (temp == 1)
                current = 628;
            if (temp == 2)
                current = 633;
            break;
        case 624:
            temp = ui_choice("Bridge and pull right on top.", "Attempt to place knee blows.", "Try to free your arm to arch it around Foreman's neck.", "/");
            if (temp == 0)
                current = 650;
            if (temp == 1)
                current = 651;
            if (temp == 2)
                current = 649;
            break;
        case 625:
            temp = ui_choice("Attempt bust removal to distance his hooks.", "Force contact and attempt a back thigh sweep technique.", "Bend down and make a rotary dodge followed by an undercut.", "/");
            if (temp == 0)
                current = 660;
            if (temp == 1)
                current = 664;
            if (temp == 2)
                current = 662;
            break;
        case 626:
            temp = ui_choice("Charge your superman-punch and finish him.", "Grab his head and hammer it with your fist.", "Taking a short run-up, you propel yourself by jumping and dropping your leg on Foreman's temple.", "/");
            if (temp == 0)
                current = 630;
            if (temp == 1)
                current = 634;
            if (temp == 2)
                current = 635;
            break;
        case 627:
            temp = ui_choice("Grab his head and deliver a series of knee blows.", "Strike the chin with the palm of the hand and give a backward kick to the head.", "Asserting a front-kick to the belly and grabbing his neck to execute a suplex.", "/");
            if (temp == 0)
                current = 663;
            if (temp == 1)
                current = 632;
            if (temp == 2)
                current = 652;
            break;
        case 628:
            temp = ui_choice("Start the jab to exhaust him.", "Place a front-kick on the chest and follow with a jump-punch.", "Grab Foreman and headbutt him in the face.", "/");
            if (temp == 0)
                current = 637;
            if (temp == 1)
                current = 639;
            if (temp == 2)
                current = 638;
            break;
        case 629:
            temp = ui_choice("Grab his head and hammer it with your fist.", "Taking a short run-up, you propel yourself by jumping and dropping your leg on Foreman's temple.", "Grab him firmly by the neck and suggest that he gives up now.", "/");
            if (temp == 0)
                current = 634;
            if (temp == 1)
                current = 635;
            if (temp == 2)
                current = 636;
            break;
        case 630:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 631:
            temp = ui_choice("Start the jab to exhaust him.", "Grab Foreman and headbutt him in the face.", "Place a front-kick on the chest and follow with a jump-punch.", "/");
            if (temp == 0)
                current = 637;
            if (temp == 1)
                current = 638;
            if (temp == 2)
                current = 639;
            break;
        case 632:
            temp = ui_choice("Grab Foreman firmly and swing him into the centre of the ring.", "Rush to Foreman and place a dropkick.", "Chain Foreman with a series of hooks.", "/");
            if (temp == 0)
                current = 642;
            if (temp == 1)
                current = 640;
            if (temp == 2)
                current = 641;
            break;
        case 633:
            temp = ui_choice("Bridge and pull right on top.", "Try to free your arm to arch it around Foreman's neck.", "Attempt to place knee blows.", "/");
            if (temp == 0)
                current = 650;
            if (temp == 1)
                current = 652;
            if (temp == 2)
                current = 651;
            break;
        case 634:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 635:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 636:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 637:
            temp = ui_choice("Strangle him firmly.", "Give up the fight.", "Attempt to overkill your foot to end the fight.", "/");
            if (temp == 0)
                current = 644;
            if (temp == 1)
                current = 645;
            if (temp == 2)
                current = 643;
            break;
        case 638:
            temp = ui_choice("Give up and refuse to execute.", "Break Foreman's neck.", "Beat him to death.", "/");
            if (temp == 0)
                current = 648;
            if (temp == 1)
                current = 646;
            if (temp == 2)
                current = 647;
            break;
        case 639:
            temp = ui_choice("Chain Foreman with a series of hooks.", "Grab Foreman firmly and swing him into the centre of the ring.", "Rush to Foreman and place a dropkick.", "/");
            if (temp == 0)
                current = 641;
            if (temp == 1)
                current = 642;
            if (temp == 2)
                current = 640;
            break;
        case 640:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 641:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 642:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 643:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 644:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 645:
            ui_continu_choice(win_men);
            current = 798;
            break;
        case 646:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 647:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 648:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 649:
            temp = ui_choice("Bridge and pull right on top.", "Attempt to place knee blows.", "/", "/");
            if (temp == 0)
                current = 656;
            if (temp == 1)
                current = 657;
            break;
        case 650:
            temp = ui_choice("Try to free your arm to arch it around Foreman's neck.", "Attempt to place knee blows.", "/", "/");
            if (temp == 0)
                current = 652;
            if (temp == 1)
                current = 655;
            break;
        case 651:
            temp = ui_choice("Try to free your arm to arch it around Foreman's neck.", "Bridge and pull right on top.", "/", "/");
            if (temp == 0)
                current = 652;
            if (temp == 1)
                current = 653;
            break;
        case 652:
            temp = ui_choice("Bridge and pull right on top.", "Attempt to place knee blows.", "/", "/");
            if (temp == 0)
                current = 658;
            if (temp == 1)
                current = 661;
            break;
        case 653:
            ui_continu_choice(win_men);
            current = 799;
            break;
        case 654:
            temp = ui_choice("Give up and refuse to execute.", "Beat him to death.", "Break Foreman's neck.", "/");
            if (temp == 0)
                current = 648;
            if (temp == 1)
                current = 647;
            if (temp == 2)
                current = 646;
            break;
        case 655:
            ui_continu_choice(win_men);
            current = 799;
            break;
        case 656:
            temp = ui_choice("Attempt to place knee blows.", "/", "/", "/");
            if (temp == 0)
                current = 659;
            break;
        case 657:
            temp = ui_choice("Bridge and pull right on top.", "/", "/", "/");
            if (temp == 0)
                current = 658;
            break;
        case 658:
            temp = ui_choice("Attempt to place knee blows.", "/", "/", "/");
            if (temp == 0)
                current = 659;
            break;
        case 659:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 660:
            temp = ui_choice("Bridge and pull right on top.", "Attempt to place knee blows.", "Try to free your arm to arch it around Foreman's neck.", "/");
            if (temp == 0)
                current = 653;
            if (temp == 1)
                current = 661;
            if (temp == 2)
                current = 652;
            break;
        case 661:
            ui_continu_choice(win_men);
            current = 799;
            break;
        case 662:
            temp = ui_choice("Grab Foreman and headbutt him in the face.", "Start the jab to exhaust him.", "Place a front-kick on the chest and follow with a jump-punch.", "/");
            if (temp == 0)
                current = 638;
            if (temp == 1)
                current = 637;
            if (temp == 2)
                current = 639;
            break;
        case 663:
            temp = ui_choice("Attempt to overkill your foot to end the fight.", "Give up the fight.", "Strangle him firmly.", "/");
            if (temp == 0)
                current = 643;
            if (temp == 1)
                current = 645;
            if (temp == 2)
                current = 644;
            break;
        case 664:
            temp = ui_choice("arch your leg behind him and use your shoulder to strike his chest.", "You step back, gain momentum and try to double dropkick.", "Clinch Foreman and stamp his thoracic cavity.", "/");
            if (temp == 0)
                current = 622;
            if (temp == 1)
                current = 623;
            if (temp == 2)
                current = 621;
            break;
        case 700:
            temp = ui_choice("Move quickly from left to right to confuse him.", "Roll on the side and low kick.", "/", "/");
            if (temp == 0)
                current = 701;
            if (temp == 1)
                current = 703;
            break;
        case 701:
            temp = ui_choice("TAZ ATTACK! You turn on yourself to punch him.", "BACKFLIP! Foot kick with a backflip.", "Take momentum and punch him.", "/");
            if (temp == 0)
                current = 702;
            if (temp == 1)
                current = 709;
            if (temp == 2)
                current = 644;
            break;
        case 702:
            temp = ui_choice("Abandon.", "Stand up and do a kamehameha.", "/", "/");
            if (temp == 0)
                current = 712;
            if (temp == 1)
                current = 711;
            break;
        case 703:
            temp = ui_choice("Abandon.", "Try to struggle.", "/", "/");
            if (temp == 0)
                current = 712;
            if (temp == 1)
                current = 715;
            break;
        case 704:
            temp = ui_choice("Contract all your muscles and stand guard.", "Unleash all your energy to jab him.", "/", "/");
            if (temp == 0)
                current = 716;
            if (temp == 1)
                current = 710;
            break;
        case 705:
            temp = ui_choice("Push him and twist kick.", "Push him and come off to the side.", "TAZ ATTACK! You turn on yourself to punch him.", "/");
            if (temp == 0)
                current = 706;
            if (temp == 1)
                current = 707;
            if (temp == 2)
                current = 702;
            break;
        case 706:
            temp = ui_choice("Abandon.", "Stand up and do a kamehameha.", "/", "/");
            if (temp == 0)
                current = 712;
            if (temp == 1)
                current = 711;
            break;
        case 707:
            temp = ui_choice("Unleash all your energy to jab him.", "BACKFLIP! Foot kick with a backflip.", "/", "/");
            if (temp == 0)
                current = 710;
            if (temp == 1)
                current = 708;
            break;
        case 708:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 709:
            ui_continu_choice(win_men);
            current = 798;
            break;
        case 710:
            temp = ui_choice("Headbutt.", "Nutkick.", "/", "/");
            if (temp == 0)
                current = 713;
            if (temp == 1)
                current = 714;
            break;
        case 711:
            ui_continu_choice(win_men);
            current = 799;
            break;
        case 712:
            ui_continu_choice(win_men);
            current = 798;
            break;
        case 713:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 714:
            ui_continu_choice(win_men);
            current = 797;
            break;
        case 715:
            ui_continu_choice(win_men);
            current = 798;
            break;
        case 716:
            ui_continu_choice(win_men);
            current = 799;
            break;
        case 789:
            ui_continu_choice(win_men);
            current = 901;
            break;
        case 790:
            ui_continu_choice(win_men);
            current = 901;
            break;
        case 791:
            ui_continu_choice(win_men);
            current = -1; /* NEED GAME OVER (die) */
            ui_continu_choice();
            break;
        case 792:
            if (inventory->money >= 100)
                choice1_temp = "Give him the money.";
            else if (inventory->money > 0 && inventory->money < 100)
                choice1_temp = "I don't have enough...";
            else if (inventory->money == 0)
                choice1_temp = "/";

            temp = ui_choice("Spit in his face.", choice1_temp, "/", "/");
            if (temp == 0)
                current = 791;
            if (temp == 1)
            {
                if (inventory->money >= 100)
                {
                    current = 790;
                    en_mod_money(-100);
                }
                if (inventory->money > 0 && inventory->money < 100)
                {
                    current = 789;
                    en_mod_money(-inventory->money);
                }
            }
            break;
        case 793:
            ui_continu_choice(win_men);
            current = 901;
            break;
        case 794:
            ui_continu_choice(win_men);
            current = 901;
            break;
        case 795:
            temp = ui_choice("Leave the room.", "/", "/", "/");
            if (temp == 0)
                current = 901;
            break;
        case 796:
            if (inventory->money >= 100)
                choice1_temp = "Give him the money.";
            else if (inventory->money > 0 && inventory->money < 100)
                choice1_temp = "I don't have enough...";
            else if (inventory->money == 0)
                choice1_temp = "/";

            temp = ui_choice("Fuck you.", choice1_temp, "/", "/");
            if (temp == 0)
                current = 792;
            if (temp == 1)
            {
                if (inventory->money >= 100)
                {
                    current = 794;
                    en_mod_money(-100);
                }
                if (inventory->money > 0 && inventory->money < 100)
                {
                    current = 793;
                    en_mod_money(-inventory->money);
                }
            }
            break;
        case 797:
            ui_continu_choice(win_men);
            if (owe_money == 1)
                en_mod_money(+300);
            else
                en_mod_money(+money_bet);

            current = 901;
            break;
        case 798:
            ui_continu_choice(win_men);
            if (owe_money == 0)
                current = 795;
            if (owe_money == 1)
                current = 796;
            break;
        case 799:
            temp = ui_choice("Go to the reception.", "/", "/", "/");
            if (owe_money == 1)
            {
                if (inventory->money >= 100)
                    en_mod_money(-100);
                if (inventory->money < 0)
                    en_mod_money(-inventory->money);
            }
            if (temp == 0)
                current = 901;
            break;
        case 800:
            unlock_exit_door = 1;
            ui_continu_choice(win_men);
            current = 801;
            break;
        case 801:
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                if (last_lost_machine_dial == 0)
                {
                    unlock_exit_door = 1;
                    current = 802;
                    en_mod_money(-10);
                }
                else
                    current = last_lost_machine_dial;
            }
            if (temp == 1)
                current = 900;
            break;
        case 802:
            en_mod_money(+10);
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 803;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 803:
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 804;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 804:
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 805;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 805:
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 806;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 806:
            en_mod_money(+10);
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 807;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 807:
            en_mod_money(+50);
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 808;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 808:
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 809;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 809:
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 810;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 810:
            en_mod_money(+10);
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 811;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 811:
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 812;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 812:
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 813;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 813:
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 814;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 814;
            break;
        case 814:
            en_mod_money(+400);
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 815;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 815:
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 816;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 816:
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 817;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 817:
            en_mod_money(+10);
            last_lost_machine_dial = (current + 1);
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 818;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 818:
            last_lost_machine_dial = 815;
            if (inventory->money > 10)
                choice0_temp = "Insert 10$";
            else
                choice0_temp = "/";
            temp = ui_choice(choice0_temp, "Leave.", "/", "/");
            if (temp == 0)
            {
                current = 815;
                en_mod_money(-10);
            }
            if (temp == 1)
                current = 900;
            break;
        case 900:
            temp = ui_choice("Go to the reception.", "Play on a slot machine.", "Go to the fight room.", "/");
            if (temp == 0)
                current = 901;
            if (temp == 1)
                current = 800;
            if (temp == 2)
            {
                if (locked_fight_room == 0)
                    current = 400;
                if (locked_fight_room == 1)
                    current = 401;
            }
            break;
        case 901:
            if (unlock_exit_door == 1)
                choice1_temp = "Leave the casino.";
            else if (unlock_hostel == 0 && inventory->money >= 20)
                choice1_temp = "I want to sleep one night. Cost: 20$.";
            else choice1_temp = "/";

            temp = ui_choice("Enter the main room.", choice1_temp, "/", "/");
            if (temp == 0)
            {
                unlock_hostel = 1;
                current = 900;
            }
            else if (temp == 1)
            {
                if (unlock_exit_door == 1)
                    current = 999;
                else
                {
                    en_mod_money(-20);
                    unlock_exit_door = 1;
                    current = 998;
                }
            }
            break;
        case 998:
            ui_continu_choice(win_men);
            current = 901;
            break;
        case 999:
            ui_continu_choice(win_men);
            current = -1;
            break;
        }
        after_event_clear(win_env, win_men);
    }

}


void pe_event_2()   /* Henderson */
{
    int current = 0;
    int temp;
    char* char0 = "Jackson";
    char* char1 = "Man"; /* Bob */
    char* char2 = "Rafe";
    char* char3 = "Apu";
    char* char4 = "/";
    char* char5 = "Maxence";

    if (inventory->pa_count > 0)
        char4 = inventory->passengers[uf_random(inventory->pa_count)];

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/2", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            if (uf_compare("Maxence") != -1)
            {
                temp = ui_choice("Drop Maxence in Henderson City.", "/", "/", "/");
                if (temp == 0)
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
            if (temp == 0)
                current = 2;
            if (temp == 1)
                current = 3;
            break;
        case 2:
            current = 7;
            ui_continu_choice(win_men);
            break;
        case 3:
            temp = ui_choice("Go into the house.", "Say him goodbye.", "/", "/");
            if (temp == 0)
                current = 7;
            if (temp == 1)
                current = 19;
            break;
        case 4:
            temp = ui_choice("Peace.", "Chaos?", "/", "/");
            if (temp == 0)
                current = 5;
            if (temp == 1)
                current = 6;
            break;
        case 5:
            temp = ui_choice("Where are you going?", "/", "/", "/");
            if (temp == 0)
                current = 8;
            break;
        case 6:
            temp = ui_choice("Where are you going?", "/", "/", "/");
            if (temp == 0)
                current = 8;
            break;
        case 7:
            temp = ui_choice("Do you wanna come with me?", "I am here to say goodbye to my old friend.", "/", "/");
            if (temp == 0)
                current = 4;
            if (temp == 1)
                current = 4;
            break;
        case 8:
            ui_continu_choice(win_men);
            if (inventory->pa_count == 1)
                current = 9;
            if (inventory->pa_count >= 2)
                current = 10;
            if (inventory->pa_count == 0)
                current = 11;
            break;
        case 9:
            temp = ui_choice("Follow Jackson.", "/", "/", "/");
            if (temp == 0)
                current = 11;
            break;
        case 10:
            temp = ui_choice("Follow Jackson.", "/", "/", "/");
            if (temp == 0)
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
            if (temp == 0)
                current = 14;
            if (temp == 1)
                current = 17;
            break;
        case 14:
            if (inventory->money >= 50)
            {
                temp = ui_choice("I take it.", "It's more than twice in a gas station!", "/", "/");
                if (temp == 0)
                {
                    en_mod_gas(+1);
                    en_mod_money(-50);
                    current = 16;
                }
                if (temp == 1)
                    current = 15;
            }
            else
            {
                temp = ui_choice("I don't have enough money.", "/", "/", "/");
                if (temp == 0)
                    current = 17;
            }
            break;
        case 15:
            temp = ui_choice("Yes.", "No, thanks.", "/", "/");
            if (temp == 0)
            {
                en_mod_gas(+1);
                en_mod_money(-50);
                current = 16;
            }
            if (temp == 1)
                current = 17;
            break;
        case 16:
            temp = ui_choice("Keep driving in Henderson.", "/", "/", "/");
            if (temp == 0)
                current = 20;
            break;
        case 17:
            temp = ui_choice("Keep driving in Henderson.", "/", "/", "/");
            if (temp == 0)
                current = 20;
            break;
        case 18:
            temp = ui_choice("Keep driving in Henderson.", "/", "/", "/");
            if (temp == 0)
                current = 20;
            break;
        case 19:
            ui_continu_choice(win_men);
            current = 7;
            break;
        case 20:
            temp = ui_choice("Stop the bus next to the building.", "Keep driving.", "/", "/");
            if (temp == 0)
                current = 22;
            if (temp == 1)
                current = 21;
            break;
        case 21:
            ui_continu_choice(win_men);
            current = 32;
            break;
        case 22:
            temp = ui_choice("Hey dude! Don't do that!", "Jump coward!", "Look at him.", "/");
            if (temp == 0)
                current = 25;
            if (temp == 1)
                current = 23;
            if (temp == 2)
                current = 26;
            break;
        case 23:
            temp = ui_choice("Do you smoke?", "Of course life is shit! And we all have to fight it!", "Holy shit you are right! And when I see your big ass, I pity you even more!", "/");
            if (temp == 0)
                current = 27;
            if (temp == 1)
                current = 28;
            if (temp == 2)
                current = 31;
            break;
        case 24:
            ui_continu_choice(win_men);
            current = 32;
            break;
        case 25:
            temp = ui_choice("Ask him if he's a smoker.", "You try a joke and propose.", "/", "/");
            if (temp == 0)
                current = 27;
            if (temp == 1)
                current = 30;
            break;
        case 26:
            temp = ui_choice("Don't answer.", "You big fat ass! Are you gonna jump?", "/", "/");
            if (temp == 0)
                current = 24;
            if (temp == 1)
                current = 23;
            break;
        case 27:
            temp = ui_choice("What's your name?", "/", "/", "/");
            if (temp == 0)
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
            if (temp == 0)
            {
                en_add_passenger(char1, inventory->pa_count);
                current = 33;
            }
            if (temp == 1)
                current = 34;
            break;
        case 30:
            temp = ui_choice("Propose him to come with you.", "Suggest him to leave this city.", "/", "/");
            if (temp == 0)
                current = 35;
            if (temp == 1)
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
            if (temp == 0)
                current = 32;
            break;
        case 34:
            temp = ui_choice("Keep driving.", "/", "/", "/");
            if (temp == 0)
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
            en_rm_passenger(uf_compare("Maxence"));
            en_mod_money(+3);
            en_mod_food(+2);
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

void pe_event_3()	/* Kingman */
{
    int current = 0;
    int temp;
    char* char0 = "Mysterious Woman";
    char* char1 = "Caitlyn";
    char* char2 = "Clifford";
    char* char3 = "Claire";
    char* char4 = "Caitlyn's minion";
    char* char5 = "Clifford's minion";

    int lock_picking = 0;
    int guard_clothes = 0;
    int armed = 0;
    int know_truth = 0;
    int repaired_bus = 0;
    int suspicion = 0;
    int child_affection = 0;

    char* choice1_temp = NULL;
    char* choice2_temp = NULL;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/3", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Run without looking back.", "Turn around.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 2;
            break;
        case 1:
            temp = ui_choice("What are you going to do with me? I'm alone and I have nothing to give you.", "I don't give a fuck about that, I just want to know if you have a good reason to do this to me!", "/", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
                current = 4;
            break;
        case 2:
            temp = ui_choice("What are you going to do with me? I'm alone and I have nothing to give you.", "I don't give a fuck about that, I just want to know if you have a good reason to do this to me!", "/", "/");
            if (temp == 0)
                current = 3;
            if (temp == 1)
                current = 4;
            break;
        case 3:
            temp = ui_choice("Are you the one who put the city in this state?", "Yeah so it's not your city at all.", "/", "/");
            if (temp == 0)
                current = 5;
            if (temp == 1)
                current = 6;
            break;
        case 4:
            temp = ui_choice("Are you the one who put the city in this state?", "Yeah so it's not your city at all.", "/", "/");
            if (temp == 0)
                current = 5;
            if (temp == 1)
                current = 6;
            break;
        case 5:
            temp = ui_choice("But you're crazy, that sounds really dangerous! Find yourself someone else!", "Mmmm... I'm up for it, but you better keep your promise!", "/", "/");
            if (temp == 0)
                current = 7;
            if (temp == 1)
                current = 8;
            break;
        case 6:
            temp = ui_choice("But you're crazy, that sounds really dangerous! Find yourself someone else!", "Mmmm... I'm up for it, but you better keep your promise!", "/", "/");
            if (temp == 0)
                current = 7;
            if (temp == 1)
                current = 8;
            break;
        case 7:
            temp = ui_choice("Accept.", "Accept.", "/", "/");
            if (temp == 0)
                current = 8;
            if (temp == 1)
                current = 8;
            break;
        case 8:
            temp = ui_choice("Go talk to the man at your right.", "Go talk to the man at your left.", "Go to Clifford repair.", "/");
            if (temp == 0)
            {
                lock_picking = 1;
                current = 9;
            }
            if (temp == 1)
                current = 10;
            if (temp == 2)
                current = 13;
            break;
        case 9:
            temp = ui_choice("Go talk to the other guy.", "Go to Clifford repair.", "/", "/");
            if (temp == 0)
                current = 11;
            if (temp == 1)
                current = 13;
            break;
        case 10:
            temp = ui_choice("Go talk to the other guy.", "Go to Clifford repair.", "/", "/");
            if (temp == 0)
            {
                lock_picking = 1;
                current = 12;
            }
            if (temp == 1)
                current = 13;
            break;
        case 11:
            temp = ui_choice("Go to Clifford repair", "/", "/", "/");
            if (temp == 0)
                current = 13;
            break;
        case 12:
            temp = ui_choice("Go to Clifford repair", "/", "/", "/");
            if (temp == 0)
                current = 13;
            break;
        case 13:
            temp = ui_choice("Approach the guards and call them out.", "Go to the back of the building.", "/", "/");
            if (temp == 0)
                current = 14;
            if (temp == 1)
                current = 15;
            break;
        case 14:
            ui_continu_choice(win_men);
            current = -1;
            els_is_exit = 666;
            break;
        case 15:
            if (lock_picking == 1)
                choice1_temp = "Try to crochet the door.";
            else choice1_temp = "/";

            temp = ui_choice("Knock him down and take his clothes.", choice1_temp, "/", "/");
            if (temp == 0)
            {
                guard_clothes = 1;
                armed = 1;
                suspicion += 2;
                current = 16;
            }
            if (temp == 1)
                current = 20;
            break;
        case 16:
            temp = ui_choice("Walk past them with a friendly greeting.", "Walk past them with a solemnly greeting.", "Walk past them without greeting them.", "/");
            if (temp == 0)
            {
                suspicion -= 1;
                current = 17;
            }
            if (temp == 1)
            {
                suspicion += 1;
                current = 18;
            }
            if (temp == 2)
                current = 19;
            break;
        case 17:
            ui_continu_choice(win_men);
            current = 23;
            break;
        case 18:
            ui_continu_choice(win_men);
            current = 23;
            break;
        case 19:
            ui_continu_choice(win_men);
            current = 23;
            break;
        case 20:
            temp = ui_choice("Persevere.", "Search the guard for the key.", "/", "/");
            if (temp == 0)
                current = 49;
            if (temp == 1)
                current = 21;
            break;
        case 21:
            temp = ui_choice("Go in immediately.", "Try to put the key back on the guard so as not to arouse suspicion.", "/", "/");
            if (temp == 0)
            {
                suspicion += 1;
                current = 49;
            }
            if (temp == 1)
                current = 22;
            break;
        case 22:
            ui_continu_choice(win_men);
            current = -1;
            els_is_exit = 666;
            break;
        case 23:
            temp = ui_choice("Go talk to him.", "Continue on your way.", "/", "/");
            if (temp == 0)
                current = 24;
            if (temp == 1)
                current = 36;
            break;
        case 24:
            temp = ui_choice("I have to go watch the kid, where is her cell again?", "What's going on here?", "Do you know where the boss is?", "/");
            if (temp == 0)
                current = 29;
            if (temp == 1)
            {
                suspicion += 1;
                current = 25;
            }
            if (temp == 2)
                current = 27;
            break;
        case 25:
            temp = ui_choice("What I'm asking is why you, you're doing nothing.", "I'm new here.", "/", "/");
            if (temp == 0)
                current = 26;
            if (temp == 1)
                current = 30;
            break;
        case 26:
            temp = ui_choice("I'm from the surveillance team.", "I'm from the team 3.", "/", "/");
            if (temp == 0)
                current = 31;
            if (temp == 1)
                current = 32;
            break;
        case 27:
            temp = ui_choice("Nah, it's just that I would like to see him for a personal thing.", "It's about the kid. Is she still well restrained in the usual place?", "/", "/");
            if (temp == 0)
            {
                suspicion += 1;
                current = 28;
            }
            if (temp == 1)
                current = 33;
            break;
        case 28:
            temp = ui_choice("Usually he's pretty cool isn't he?", "I know but this is special, take care of what concerns you.", "/", "/");
            if (temp == 0)
                current = 34;
            if (temp == 1)
                current = 35;
            break;
        case 29:
            temp = ui_choice("Continue on your way.", "/", "/", "/");
            if (temp == 0)
                current = 36;
            break;
        case 30:
            ui_continu_choice(win_men);
            current = -1;
            els_is_exit = 666;
            break;
        case 31:
            temp = ui_choice("Continue on your way.", "/", "/", "/");
            if (temp == 0)
                current = 36;
            break;
        case 32:
            ui_continu_choice(win_men);
            current = -1;
            els_is_exit = 666;
            break;
        case 33:
            temp = ui_choice("Continue on your way.", "/", "/", "/");
            if (temp == 0)
                current = 36;
            break;
        case 34:
            ui_continu_choice(win_men);
            current = -1;
            els_is_exit = 666;
            break;
        case 35:
            temp = ui_choice("Continue on your way.", "/", "/", "/");
            if (temp == 0)
                current = 36;
            break;
        case 36:
            temp = ui_choice("Go right.", "Go straight.", "Go left.", "/");
            if (temp == 0)
                current = 69;
            if (temp == 1)
                current = 37;
            if (temp == 2)
            {
                suspicion += 2;
                current = 43;
            }
            break;
        case 37:
            temp = ui_choice("Sorry boss, it's just to tell you that the troops are ready soon.", "Sorry boss, I just wanted to tell you some soldiers are wondering if it's worth it to spill more blood.", "/", "/");
            if (temp == 0)
                current = 38;
            if (temp == 1)
            {
                suspicion += 3;
                current = 39;
            }
            break;
        case 38:
            temp = ui_choice("Ok boss.", "Just one more question boss, what do you plan for the child?", "/", "/");
            if (temp == 0)
                current = 41;
            if (temp == 1)
            {
                know_truth = 1;
                suspicion += 2;
                current = 40;
            }
            break;
        case 39:
            temp = ui_choice("Ok boss.", "Just one more question boss, what do you plan for the child?", "/", "/");
            if (temp == 0)
                current = 41;
            if (temp == 1)
            {
                know_truth = 1;
                suspicion += 2;
                current = 40;
            }
            break;
        case 40:
            temp = ui_choice("Return to the junction.", "/", "/", "/");
            if (temp == 0)
                current = 41;
            break;
        case 41:
            temp = ui_choice("Go left.", "Go right.", "/", "/");
            if (temp == 0)
            {
                suspicion += 2;
                current = 42;
            }
            if (temp == 1)
                current = 69;
            break;
        case 42:
            temp = ui_choice("Go straight.", "/", "/", "/");
            if (temp == 0)
                current = 69;
            break;
        case 43:
            temp = ui_choice("Go straight.", "Go left.", "/", "/");
            if (temp == 0)
                current = 69;
            if (temp == 1)
                current = 44;
            break;
        case 44:
            temp = ui_choice("Sorry boss, it's just to tell you that the troops are ready soon.", "Sorry boss, I just wanted to tell you some soldiers are wondering if it's worth it to spill more blood.", "/", "/");
            if (temp == 0)
                current = 45;
            if (temp == 1)
            {
                suspicion += 3;
                current = 46;
            }
            break;
        case 45:
            temp = ui_choice("Ok boss.", "Just one more question boss, what do you plan for the child?", "/", "/");
            if (temp == 0)
                current = 47;
            if (temp == 1)
            {
                suspicion += 2;
                know_truth = 1;
                current = 48;
            }
            break;
        case 46:
            temp = ui_choice("Ok boss.", "Just one more question boss, what do you plan for the child?", "/", "/");
            if (temp == 0)
                current = 47;
            if (temp == 1)
            {
                suspicion += 2;
                know_truth = 1;
                current = 48;
            }
            break;
        case 47:
            temp = ui_choice("Go left.", "/", "/", "/");
            if (temp == 0)
                current = 69;
            break;
        case 48:
            temp = ui_choice("Go left.", "/", "/", "/");
            if (temp == 0)
                current = 69;
            break;
        case 49:
            temp = ui_choice("Go through the ventilation grid.", "Take the corridor.", "/", "/");
            if (temp == 0)
                current = 50;
            if (temp == 1)
                current = 67;
            break;
        case 50:
            temp = ui_choice("Listen to them.", "Keep moving forward.", "/", "/");
            if (temp == 0)
                current = 51;
            if (temp == 1)
                current = 52;
            break;
        case 51:
            temp = ui_choice("Go to right.", "Go to left.", "/", "/");
            if (temp == 0)
                current = 53;
            if (temp == 1)
                current = 58;
            break;
        case 52:
            temp = ui_choice("Go to right.", "Go to left.", "/", "/");
            if (temp == 0)
            {
                know_truth = 1;
                current = 53;
            }
            if (temp == 1)
                current = 58;
            break;
        case 53:
            temp = ui_choice("Wait and see if the guys below leave.", "Turn around anyway and go back to the fork.", "/", "/");
            if (temp == 0)
                current = 54;
            if (temp == 1)
            {
                suspicion += 3;
                current = 57;
            }
            break;
        case 54:
            temp = ui_choice("Wait a little longer.", "Turn around anyway and go back to the fork.", "/", "/");
            if (temp == 0)
                current = 55;
            if (temp == 1)
            {
                suspicion += 3;
                current = 57;
            }
            break;
        case 55:
            temp = ui_choice("Wait a little longer.", "Turn around anyway and go back to the fork.", "/", "/");
            if (temp == 0)
                current = 56;
            if (temp == 1)
            {
                suspicion += 3;
                current = 57;
            }
            break;
        case 56:
            temp = ui_choice("Take cover.", "Run over him.", "/", "/");
            if (temp == 0)
                current = 59;
            if (temp == 1)
                current = 63;
            break;
        case 57:
            temp = ui_choice("Take cover.", "Run over him.", "/", "/");
            if (temp == 0)
                current = 59;
            if (temp == 1)
                current = 63;
            break;
        case 58:
            temp = ui_choice("Take cover.", "Run over him.", "/", "/");
            if (temp == 0)
                current = 59;
            if (temp == 1)
                current = 63;
            break;
        case 59:
            temp = ui_choice("Take cover behind the doorframe.", "Take cover behind the red barrel.", "/", "/");
            if (temp == 0)
            {
                suspicion += 2;
                current = 60;
            }
            if (temp == 1)
                current = 61;
            break;
        case 60:
            temp = ui_choice("Run over him.", "Run away.", "/", "/");
            if (temp == 0)
                current = 62;
            if (temp == 1)
            {
                suspicion += 2;
                current = 69;
            }
            break;
        case 61:
            ui_continu_choice(win_men);
            current = 2;
            break;
        case 62:
            temp = ui_choice("Take his gun before fleeing.", "Run away.", "/", "/");
            if (temp == 0)
            {
                armed = 1;
                current = 69;
            }
            if (temp == 1)
                current = 69;
            break;
        case 63:
            temp = ui_choice("Finish him by a kick in the head.", "Take his gun.", "/", "/");
            if (temp == 0)
                current = 64;
            if (temp == 1)
            {
                armed = 1;
                current = 65;
            }
            break;
        case 64:
            temp = ui_choice("Continue on your way.", "/", "/", "/");
            if (temp == 0)
                current = 69;
            break;
        case 65:
            temp = ui_choice("Tie him up.", "Kill him.", "/", "/");
            if (temp == 0)
                current = 66;
            if (temp == 1)
            {
                suspicion += 3;
                current = 66;
            }
            break;
        case 66:
            temp = ui_choice("Continue on your way.", "/", "/", "/");
            if (temp == 0)
                current = 69;
            break;
        case 67:
            temp = ui_choice("Approach discreetly.", "Go back and go through the ventilation grid.", "/", "/");
            if (temp == 0)
                current = 68;
            if (temp == 1)
                current = 50;
            break;
        case 68:
            ui_continu_choice(win_men);
            current = -1;
            els_is_exit = 666;
            break;
        case 69:
            if (guard_clothes == 1)
                choice2_temp = "Go talk to him.";
            else
                choice2_temp = "/";

            temp = ui_choice("Find a way to get his attention elsewhere.", "Shoot him.", choice2_temp, "/");
            if (temp == 0)
                current = 70;
            if (temp == 1)
            {
                suspicion += 5;
                current = 76;
            }
            if (temp == 2)
                current = 73;
            break;
        case 70:
            temp = ui_choice("Call the guard by trying a random name.", "Drop the crates and simulate a cry for help.", "/", "/");
            if (temp == 0)
                current = 71;
            if (temp == 1)
                current = 72;
            break;
        case 71:
            ui_continu_choice(win_men);
            current = -1;
            els_is_exit = 666;
            break;
        case 72:
            temp = ui_choice("Open the door.", "/", "/", "/");
            if (know_truth == 0)
                current = 77;
            if (know_truth == 1)
                current = 78;
            break;
        case 73:
            temp = ui_choice("Ask him to let you in to see the kid.", "Tell him that you were sent to take over.", "/", "/");
            if (temp == 0)
            {
                suspicion += 1;
                current = 74;
            }
            if (temp == 1)
                current = 75;
            break;
        case 74:
            temp = ui_choice("Tell him that you were sent to take over.", "/", "/", "/");
            if (temp == 0)
            {
                suspicion += 1;
                current = 75;
            }
            break;
        case 75:
            temp = ui_choice("Open the door.", "/", "/", "/");
            if (know_truth == 0)
                current = 77;
            if (know_truth == 1)
                current = 78;
            break;
        case 76:
            temp = ui_choice("Open the door.", "/", "/", "/");
            if (know_truth == 0)
                current = 77;
            if (know_truth == 1)
                current = 78;
            break;
        case 77:
            temp = ui_choice("I'm here to save you, let's go!", "Don't worry sweetie, I'm here to help you. Let's go?", "Come, quickly!", "/");
            if (temp == 0)
                current = 79;
            if (temp == 1)
            {
                child_affection += 5;
                current = 79;
            }
            if (temp == 2)
            {
                child_affection += 5;
                current = 79;
            }
            break;
        case 78:
            temp = ui_choice("I'm here to save you, let's go!", "Don't worry sweety, I'm here to help you. Let's go?", "Come, quickly!", "/");
            if (temp == 0)
                current = 79;
            if (temp == 1)
            {
                child_affection += 5;
                current = 79;
            }
            if (temp == 2)
            {
                child_affection += 5;
                current = 79;
            }
            break;
        case 79:
            temp = ui_choice("Exit the room.", "/", "/", "/");
            if (suspicion > 6)
                current = 80;
            if (suspicion < 7)
                current = 94;
            break;
        case 80:
            temp = ui_choice("Take the kid hostage.", "/", "/", "/");
            if (know_truth == 0 && armed == 1)
            {
                child_affection -= 5;
                current = 81;
            }
            if (know_truth == 1 && armed == 1)
            {
                child_affection -= 5;
                current = 82;
            }
            if (know_truth == 0 && armed == 0)
            {
                child_affection -= 10;
                current = 83;
            }
            if (know_truth == 1 && armed == 0)
            {
                child_affection -= 10;
                current = 84;
            }
            break;
        case 81:
            temp = ui_choice("Why are you so afraid of losing Caitlyn's daughter?", "I appreciate seeing your red face twist in fear.", "/", "/");
            if (temp == 0)
                current = 85;
            if (temp == 1)
                current = 86;
            break;
        case 82:
            temp = ui_choice("So, you are Claire's father? And Caitlyn is her mother?", "So, bye Clifford, I'll go give your daughter to your worst enemy.", "/", "/");
            if (temp == 0)
                current = 87;
            if (temp == 1)
                current = 88;
            break;
        case 83:
            temp = ui_choice("Why are you so afraid of losing Caitlyn's daughter?", "I appreciate seeing your red face twist in fear.", "/", "/");
            if (temp == 0)
                current = 85;
            if (temp == 1)
                current = 86;
            break;
        case 84:
            temp = ui_choice("So, you are Claire's father? And Caitlyn is her mother?", "So, bye Clifford, I'll go give your daughter to your worst enemy.", "/", "/");
            if (temp == 0)
                current = 87;
            if (temp == 1)
                current = 86;
            break;
        case 85:
            temp = ui_choice("Is it true? Why keep her locked up then?", "I don't care about that, I just want what she promised me.", "/", "/");
            if (temp == 0)
                current = 89;
            if (temp == 1)
            {
                repaired_bus = 1;
                current = 90;
            }
            break;
        case 86:
            temp = ui_choice("Ahah! Maybe next time!", "Maybe you don't have to do this. We could find an arrangement.", "/", "/");
            if (temp == 0)
                current = 92;
            if (temp == 1)
            {
                repaired_bus = 1;
                current = 93;
            }
            break;
        case 87:
            temp = ui_choice("So why you keep her in a cell? You're crazy.", "Sorry man, I don't want to get involve into your family problems.", "/", "/");
            if (temp == 0)
                current = 89;
            if (temp == 1)
                current = 88;
            break;
        case 88:
            temp = ui_choice("Sorry, business is business. Bye Clifford.", "Maybe you can do something.", "/", "/");
            if (temp == 0)
                current = 92;
            if (temp == 1)
                current = 93;
            break;
        case 89:
            temp = ui_choice("I'm sorry for you but I have my own problem.", "I don't care about that, I just want what she promised me.", "/", "/");
            if (temp == 0)
            {
                repaired_bus = 1;
                current = 91;
            }
            if (temp == 1)
            {
                repaired_bus = 1;
                current = 90;
            }
            break;
        case 90:
            temp = ui_choice("I promise.", "I can't promise this.", "/", "/");
            if (temp == 0)
            {
                child_affection += 5;
                current = 110;
            }
            if (temp == 1)
                current = 110;
            break;
        case 91:
            temp = ui_choice("I promise.", "I can't promise this.", "/", "/");
            if (temp == 0)
            {
                child_affection += 5;
                current = 110;
            }
            if (temp == 1)
                current = 110;
            break;
        case 92:
            ui_continu_choice(win_men);
            current = 110;
            break;
        case 93:
            temp = ui_choice("I promise.", "I can't promise this.", "/", "/");
            if (temp == 0)
            {
                child_affection += 5;
                current = 110;
            }
            if (temp == 1)
                current = 110;
            break;
        case 94:
            temp = ui_choice("Explore the room.", "Wait a few seconds and go out.", "/", "/");
            if (temp == 0)
                current = 95;
            if (temp == 1)
                current = 96;
            break;
        case 95:
            temp = ui_choice("Come out.", "Leave a note of blackmail hoping to get something from Clifford.", "/", "/");
            if (temp == 0)
                current = 96;
            if (temp == 1)
            {
                repaired_bus = 1;
                current = 97;
            }
            break;
        case 96:
            temp = ui_choice("Try the window.", "Shout at them that you have the kid and that you will hurt her if they come in.", "/", "/");
            if (temp == 0)
                current = 105;
            if (temp == 1)
            {
                child_affection -= 5;
                current = 99;
            }
            break;
        case 97:
            temp = ui_choice("Go out the window.", "Wait without making noise.", "/", "/");
            if (temp == 0)
                current = 100;
            if (temp == 1)
                current = 98;
            break;
        case 98:
            temp = ui_choice("Try the window.", "/", "/", "/");
            if (temp == 0)
                current = 105;
            break;
        case 99:
            temp = ui_choice("Try the window.", "/", "/", "/");
            if (temp == 0)
                current = 105;
            break;
        case 100:
            temp = ui_choice("Fire on the lock to open it.", "Try to break it down.", "/", "/");
            if (temp == 0)
                current = 108;
            if (temp == 1)
                current = 101;
            break;
        case 101:
            temp = ui_choice("Hit the window again.", "Shout at them that you have the kid and that you will hurt her if they come in.", "/", "/");
            if (temp == 0)
                current = 103;
            if (temp == 1)
                current = 102;
            break;
        case 102:
            if (armed == 1)
                choice1_temp = "Fire on the lock to open it.";
            else choice1_temp = "/";

            temp = ui_choice("Hit the window again.", choice1_temp, "/", "/");
            if (temp == 0)
                current = 103;
            if (temp == 1)
                current = 109;
            break;
        case 103:
            if (armed == 1)
                choice1_temp = "Fire on the lock to open it.";
            else choice1_temp = "/";

            temp = ui_choice("Hit the window again.", choice1_temp, "/", "/");
            if (temp == 0)
                current = 104;
            if (temp == 1)
                current = 109;
            break;
        case 104:
            ui_continu_choice(win_men);
            current = 111;
            break;
        case 105:
            if (armed == 1)
                choice1_temp = "Fire on the lock to open it.";
            else choice1_temp = "/";

            temp = ui_choice("Try to break it down.", choice1_temp, "/", "/");
            if (temp == 0)
                current = 106;
            if (temp == 1)
                current = 109;
            break;
        case 106:
            if (armed == 1)
                choice1_temp = "Fire on the lock to open it.";
            else choice1_temp = "/";

            temp = ui_choice("Hit the window again.", choice1_temp, "/", "/");
            if (temp == 0)
                current = 107;
            if (temp == 1)
                current = 109;
            break;
        case 107:
            ui_continu_choice(win_men);
            current = 111;
            break;
        case 108:
            ui_continu_choice(win_men);
            current = 111;
            break;
        case 109:
            ui_continu_choice(win_men);
            current = 111;
            break;
        case 110:
            temp = ui_choice("Let Claire take the mattress.", "Keep the mattress for yourself.", "/", "/");
            if (temp == 0)
            {
                child_affection += 5;
                current = 112;
            }
            if (temp == 1)
            {
                child_affection -= 5;
                current = 112;
            }
            break;
        case 111:
            temp = ui_choice("Let Claire take the mattress.", "Keep the mattress for yourself.", "/", "/");
            if (temp == 0)
            {
                child_affection += 5;
                current = 112;
            }
            if (temp == 1)
            {
                child_affection -= 5;
                current = 112;
            }
            break;
        case 112:
            temp = ui_choice("You speak sometimes, kiddo?", "You don't want to talk a bit sweetie?", "/", "/");
            if (temp == 0)
                current = 113;
            if (temp == 1)
                current = 113;
            break;
        case 113:
            temp = ui_choice("Ok, like you want, I don't care anyway.", "Like you want. But I want to tell you my story.", "/", "/");
            if (temp == 0)
                current = 114;
            if (temp == 1)
            {
                child_affection += 5;
                current = 115;
            }
            break;
        case 114:
            temp = ui_choice("To Caitlyn, like I promise.", "I don't know. If you speak to me, it'll be easier for me to decide.", "/", "/");
            if (temp == 0)
            {
                child_affection -= 5;
                current = 116;
            }
            if (temp == 1)
                current = 117;
            break;
        case 115:
            temp = ui_choice("Yes.", "No.", "/", "/");
            if (temp == 0)
            {
                child_affection += 5;
                current = 118;
            }
            if (temp == 1)
            {
                child_affection -= 5;
                current = 119;
            }
            break;
        case 116:
            temp = ui_choice("Bring her to Caitlyn.", "Bring her back to Clifford.", "Take her with you.", "/");
            if (temp == 0)
                current = 120;
            if (temp == 1)
                current = 121;
            if (temp == 2)
            {
                if (child_affection < 10)
                    current = 122;
                if (child_affection > 9)
                    current = 124;
            }
            break;
        case 117:
            temp = ui_choice("Yes.", "No.", "/", "/");
            if (temp == 0)
            {
                child_affection += 5;
                current = 118;
            }
            if (temp == 1)
                current = 119;
            break;
        case 118:
            temp = ui_choice("Bring her to Caitlyn.", "Bring her back to Clifford.", "Take her with you.", "/");
            if (temp == 0)
                current = 120;
            if (temp == 1)
                current = 121;
            if (temp == 2)
            {
                if (child_affection < 10)
                    current = 122;
                if (child_affection > 9)
                    current = 124;
            }
            break;
        case 119:
            temp = ui_choice("Bring her to Caitlyn.", "Bring her back to Clifford.", "Take her with you.", "/");
            if (temp == 0)
                current = 120;
            if (temp == 1)
                current = 121;
            if (temp == 2)
            {
                if (child_affection < 10)
                    current = 122;
                if (child_affection > 9)
                    current = 123;
            }
            break;
        case 120:
            ui_continu_choice(win_men);
            current = -1;
            en_mod_gas(+4);
            en_mod_food(+5);
            break;
        case 121:
            ui_continu_choice(win_men);
            current = -1;
            en_mod_gas(+4);
            en_mod_food(+5);
            break;
        case 122:
            temp = ui_choice("Bring her to Caitlyn.", "Bring her back to Clifford.", "/", "/");
            if (temp == 0)
                current = 123;
            if (temp == 1)
                current = 121;
            break;
        case 123:
            ui_continu_choice(win_men);
            current = -1;
            en_mod_gas(+3);
            en_mod_food(+5);
            break;
        case 124:
            ui_continu_choice(win_men);
            if (repaired_bus == 0)
                current = 125;
            if (repaired_bus == 1)
                current = 128;
            break;
        case 125:
            temp = ui_choice("Refuse to leave without the child and make a nice tirade full of compassion.", "Leave.", "/", "/");
            if (temp == 0)
                current = 126;
            if (temp == 1)
                current = 127;
            break;
        case 126:
            ui_continu_choice(win_men);
            current = -1;
            els_is_exit = 666;
            break;
        case 127:
            ui_continu_choice(win_men);
            current = -1;
            break;
        case 128:
            ui_continu_choice(win_men);
            en_add_passenger(char3, inventory->pa_count);
            current = -1;
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void pe_event_4()	/* PHEONIX CITY */
{
    int current = 0;
    int temp;
    char* char0 = "David G.Jones";
    char* char1 = "Nina Kramer";
    char* char2 = "Sean Cushing";
    char* char3 = "Someone Singing";
    char* char4 = "/";
    char* char5 = "/";

    int lock_room = 0;
    int lock_morgue1 = 0;
    int lock_morgue2 = 0;
    int lock_morgue3 = 0;

    char* choice0_temp = NULL;
    char* choice1_temp = NULL;
    char* choice2_temp = NULL;

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/4", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            ui_continu_choice(win_men);
            current = 380;
            break;
        case 1:
            if (lock_room == 0)
            {
                choice1_temp = "Search offices for clues.";
                choice2_temp = "Get closer to the painting.";
            }
            else
            {
                choice1_temp = "/";
                choice2_temp = "/";
            }

            temp = ui_choice("Return to the reception.", choice1_temp, choice2_temp, "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
            {
                lock_room = 1;
                current = 3;
            }
            if (temp == 2)
            {
                lock_room = 1;
                current = 4;
            }
            break;
        case 2:
            temp = ui_choice("Heading to the morgue and the quarantine containment area.", "Heading to the Imaging, Physiology and Neurobiology Lab.", "/", "/");
            if (temp == 0)
                current = 11;
            if (temp == 1)
                current = 300;
            break;
        case 3:
            ui_continu_choice(win_men);
            current = 5;
            break;
        case 4:
            temp = ui_choice("Remove the paint from the wall.", "/", "/", "/");
            if (temp == 0)
                current = 8;
            break;
        case 5:
            temp = ui_choice("Return to the reception.", "Get closer to the painting.", "/", "/");
            if (temp == 0)
                current = 2;
            if (temp == 1)
                current = 4;
            break;
        case 8:
            temp = ui_choice("Return to the reception.", "Search offices for clues.", "/", "/");
            if (temp == 0)
                current = 2;
            if (temp == 1)
                current = 3;
            break;
        case 11:
            temp = ui_choice("Pass the decontamination airlock.", "/", "/", "/");
            if (temp == 0)
                current = 12;
            break;
        case 12:
            temp = ui_choice("Head to the morgue.", "Move towards the origin of the sound.", "/", "/");
            if (temp == 0)
                current = 13;
            if (temp == 1)
                current = 100;
            break;
        case 13:
            temp = ui_choice("Look for more information.", "/", "/", "/");
            if (temp == 0)
                current = 19;
            break;
        case 14:
            temp = ui_choice("Access Mr. Jones's computer.", "/", "/", "/");
            if (temp == 0)
                current = 17;
            break;
        case 15:
            ui_continu_choice(win_men);
            current = 18;
            break;
        case 16:
            temp = ui_choice("Look for more information.", "/", "/", "/");
            if (temp == 0)
                current = 19;
            break;
        case 17:
            temp = ui_choice("Find clues in documents.", "/", "/", "/");
            if (temp == 0)
                current = 33;
            break;
        case 18:
            temp = ui_choice("Look for more information.", "/", "/", "/");
            if (temp == 0)
                current = 19;
            break;
        case 19:
            if (lock_morgue1 == 0)
                choice1_temp = "Check the offices.";
            else choice1_temp = "/";
            if (lock_morgue2 == 0)
                choice2_temp = "Check the offices.";
            else choice2_temp = "/";
            if (lock_morgue3 == 0)
                choice3_temp = "Check the offices.";
            else choice3_temp = "/";

            temp = ui_choice("Leave the morgue.", choice1_temp, choice2_temp, choice3_temp);
            if (temp == 0)
                current = 111;
            if (temp == 1)
            {
                current = 14;
                lock_morgue1 = 1;
            }
            if (temp == 2)
            {
                current = 15;
                lock_morgue2 = 1;
            }
            if (temp == 3)
            {
                current = 16;
                lock_morgue3 = 1;
            }
            break;
        case 33:
            temp = ui_choice("Access Mr. Jones's computer.", "/", "/", "/");
            if (temp == 0)
                current = 43;
            break;
        case 43:
            temp = ui_choice("Maryam.", "Thea.", "/", "/");
            if (temp == 0)
                current = 44;
            if (temp == 1)
                current = 49;
            break;
        case 43:
            temp = ui_choice("Open the mailbox.", "/", "/", "/");
            if (temp == 0)
                current = 56;
            break;
        case 44:
            temp = ui_choice("Thea.", "/", "/", "/");
            if (temp == 0)
                current = 49;
            break;
        case 56:
            temp = ui_choice("Look for information.", "/", "/", "/");
            if (temp == 0)
                current = 19;
            break;
        case 100:
            temp = ui_choice("Enter the operating room.", "/", "/", "/");
            if (temp == 0)
                current = 102;
            break;
        case 101:
            temp = ui_choice("Enter the operating room.", "/", "/", "/");
            if (temp == 0)
                current = 102;
            break;
        case 102:
            ui_continu_choice(win_men);
            current = 103;
            break;
        case 103:
            temp = ui_choice("I don't get your bullshit, who are you?", "What exactly are you doing here?!", "Aim it at him with your gun.", "/");
            if (temp == 0)
                current = 104;
            if (temp == 1)
                current = 105;
            if (temp == 2)
                current = 106;
            break;
        case 104:
            ui_continu_choice(win_men);
            current = 107;
            break;
        case 105:
            ui_continu_choice(win_men);
            current = 107;
            break;
        case 106:
            ui_continu_choice(win_men);
            current = 107;
            break;
        case 107:
            temp = ui_choice("Crystal clear.", "So you and your little friends are cannibals?", "What would your daughter Thea think of all this?", "/");
            if (temp == 0)
                current = 108;
            if (temp == 1)
                current = 109;
            if (temp == 2)
                current = 110;
            break;
        case 108:
            ui_continu_choice(win_men);
            current = 115;
            break;
        case 109:
            temp = ui_choice("Why would you need me?", "Are you reconverted to cannibalism?", "/", "/");
            if (temp == 0)
                current = 111;
            if (temp == 1)
                current = 112;
            break;
        case 110:
            temp = ui_choice("What happened to your wife and daughter?", "Are you reconverted to cannibalism?", "Why would you need me?", "/");
            if (temp == 0)
                current = 113;
            if (temp == 1)
                current = 112;
            if (temp == 2)
                current = 111;
            break;
        case 111:
            temp = ui_choice("Are you reconverted to cannibalism?", "What happened to your wife and daughter?", "I don't have any more questions.", "/");
            if (temp == 0)
                current = 112;
            if (temp == 1)
                current = 113;
            if (temp == 2)
                current = 114;
            break;
        case 112:
            temp = ui_choice("What happened to your wife and daughter?", "Why would you need me?", "/", "/");
            if (temp == 0)
                current = 113;
            if (temp == 1)
                current = 111;
            break;
        case 113:
            temp = ui_choice("Are you reconverted to cannibalism?", "Why would you need me?", "/", "/");
            if (temp == 0)
                current = 112;
            if (temp == 1)
                current = 111;
            break;
        case 114:
            ui_continu_choice(win_men);
            current = 115;
            break;
        case 115:
            ui_continu_choice(win_men);
            current = 116;
            break;
        case 116:
            temp = ui_choice("I couldn't understand why am I associated with cannibals?", "I know that both of your colleagues are fed up with the direction of things.", "/", "/");
            if (temp == 0)
                current = 501;
            if (temp == 1)
                current = 502;
            break;
        case 118:
            temp = ui_choice("Let's get it over with.", "/", "/", "/");
            if (temp == 0)
                current = 505;
            break;
        case 300:
            temp = ui_choice("Head towards the source of the light.", "/", "/", "/");
            if (temp == 0)
                current = 301;
            break;
        case 301:
            temp = ui_choice("I don't think so.", "Take a seat.", "/", "/");
            if (temp == 0)
                current = 302;
            if (temp == 1)
                current = 303;
            break;
        case 302:
            temp = ui_choice("It must have been really hard for me to understand how a medical laboratory could be in activity.", "And who am I interested in, tell me?", "I was expecting anything but that.", "/");
            if (temp == 0)
                current = 303;
            if (temp == 1)
                current = 304;
            if (temp == 2)
                current = 305;
            break;
        case 303:
            temp = ui_choice("And who am I interested in, tell me?", "I was expecting anything but that.", "/", "/");
            if (temp == 0)
                current = 304;
            if (temp == 1)
                current = 305;
            break;
        case 304:
            temp = ui_choice("And why?", "Let's cut to the chase.", "/", "/");
            if (temp == 0)
                current = 308;
            if (temp == 1)
                current = 309;
            break;
        case 305:
            temp = ui_choice("Let's cut to the chase.", "Who exactly are you?", "/", "/");
            if (temp == 0)
                current = 309;
            if (temp == 1)
                current = 310;
            break;
        case 306:
            temp = ui_choice("I guess you're not going to let me go, am I right?", "/", "/", "/");
            if (temp == 0)
                current = 312;
            break;
        case 307:
            temp = ui_choice("I am listening.", "I guess you're not going to let me go, am I right?", "/", "/");
            if (temp == 0)
                current = 311;
            if (temp == 1)
                current = 312;
            break;
        case 308:
            temp = ui_choice("I am listening.", "I guess you're not going to let me go, am I right ? ", "/", "/");
            if (temp == 0)
                current = 311;
            if (temp == 1)
                current = 312;
            break;
        case 309:
            temp = ui_choice("I am listening.", "I guess you're not going to let me go, am I right?", "/", "/");
            if (temp == 0)
                current = 311;
            if (temp == 1)
                current = 312;
            break;
        case 310:
            temp = ui_choice("I guess you're not going to let me go, am I right?", "/", "/", "/");
            if (temp == 0)
                current = 312;
            break;
        case 311:
            temp = ui_choice("Someone special?", "What old traditions?", "What is your group?", "/");
            if (temp == 0)
                current = 320;
            if (temp == 1)
                current = 313;
            if (temp == 2)
                current = 314;
            break;
        case 312:
            temp = ui_choice("I am listening.", "", "/", "/");
            if (temp == 0)
                current = 311;
            break;
        case 313:
            temp = ui_choice("I guess I wouldn't know more than that.", "/", "/", "/");
            if (temp == 0)
                current = 316;
            break;
        case 314:
            temp = ui_choice("I have more questions.", "I guess I wouldn't know more than that.", "/", "/");
            if (temp == 0)
                current = 315;
            if (temp == 1)
                current = 316;
            break;
        case 315:
            temp = ui_choice("What is your group?", "What old traditions?", "Someone special?", "/");
            if (temp == 0)
                current = 314;
            if (temp == 1)
                current = 313;
            if (temp == 2)
                current = 320;
            break;
        case 316:
            ui_continu_choice(win_men);
            current = 317;
            break;
        case 317:
            ui_continu_choice(win_men);
            current = 500;
            break;
        case 318:
            temp = ui_choice("And yet, I'm getting out of here.", "That doesn't answer my question, why are you in business.", "/", "/");
            if (temp == 0)
                current = 306;
            if (temp == 1)
                current = 307;
            break;
        case 319:
            temp = ui_choice("I am listening.", "I guess you're not going to let me go, am I right?", "/", "/");
            if (temp == 0)
                current = 311;
            if (temp == 1)
                current = 312;
            break;
        case 320:
            temp = ui_choice("I guess I wouldn't know more than that.", "/", "/", "/");
            if (temp == 0)
                current = 316;
            break;
        case 380:
            temp = ui_choice("Go to the administrative offices.", "Heading to the morgue and the quarantine containment area", "Heading to the Imaging, Physiology and Neurobiology Lab.", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 11;
            if (temp == 2)
                current = 300;
            break;
        case 500:
            temp = ui_choice("I know that both of your colleagues are fed up with the direction of things.", "Can I find out why I am involved in your litigation?", "/", "/");
            if (temp == 0)
                current = 502;
            if (temp == 1)
                current = 503;
            break;
        case 502:
            temp = ui_choice("Let's get it over with.", "/", "/", "/");
            if (temp == 0)
                current = 504;
            break;
        case 503:
            temp = ui_choice("Let's get it over with.", "/", "/", "/");
            if (temp == 0)
                current = 504;
            break;
        case 504:
            temp = ui_choice("Take a seat.", "/", "/", "/");
            if (temp == 0)
                current = 700;
            break;
        case 505:
            temp = ui_choice("Take a seat.", "/", "/", "/");
            if (temp == 0)
                current = 700;
            break;
        case 506:
            temp = ui_choice("Let's get it over with.", "/", "/", "/");
            if (temp == 0)
                current = 505;
            break;
        case 700:
            temp = ui_choice("Nina Kramer.", "Sean Cushing.", "David G. Jones.", "/");
            if (temp == 0)
                current = 701;
            if (temp == 1)
                current = 702;
            if (temp == 2)
                current = 703;
            break;
        case 701:
            ui_continu_choice(win_men);
            current = -1;
            en_mod_gas(+4);
            en_mod_money(+65);
            break;
        case 702:
            ui_continu_choice(win_men);
            current = -1;
            en_mod_gas(+2);
            en_mod_money(+130);
            break;
        case 703:
            ui_continu_choice(win_men);
            current = -1;
            en_mod_gas(+3);
            en_mod_money(+95);
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void pe_event_5() /* FLAGSTAFF */
{
    int current = 0;
    int temp;
    char* char0 = "Suspicious Seller";
    char* char1 = "Old Women";
    char* char2 = "Goofy";
    char* char3 = "Damien";
    char* char4 = "/"; /*Personne du bus*/
    char* char5 = "/";

    char* choice0_temp = NULL;
    char* choice1_temp = NULL;
    char* choice2_temp = NULL;

    int lock_shop = 0;

    /* char4 = a passenger but not Damien */
    if (inventory->pa_count > 0)
    {
        char4 = inventory->passengers[uf_random(inventory->pa_count)];
        while (uf_strcmp(char3, char4))
        {
            char4 = inventory->passengers[uf_random(inventory->pa_count)];
        }
    }

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/5", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            ui_continu_choice(win_men);
            current = 1;
            break;
        case 1:
            if (lock_shop == 0)
            {
                choice0_temp = "Head to the organic supermarket : Group Foods Market";
                choice1_temp = "Head to the fast-food : Mc Goofie's";
                choice2_temp = "Head to the clothing-retail : M&H";
            }
            else
            {
                choice0_temp = "Leave.";
                choice1_temp = "/";
                choice2_temp = "/";
            }
            temp = ui_choice(choice0_temp, choice1_temp, choice2_temp, "/");
            if (temp == 0)
            {
                if (lock_shop == 1)
                    current = 200;
                else
                    current = 4;
            }
            if (temp == 1)
            {
                current = 5;
                lock_shop = 1;
            }
            if (temp == 2)
            {
                current = 2;
                lock_shop = 1;
            }
            if (temp == 3)
            {
                current = 4;
                lock_shop = 1;
            }
            break;
        case 2:
            temp = ui_choice("Hamburger on a bed of French fry oil, between two stale breads.(15$, 1 food)", "Special promotion, 3 barrels of gasoline for the price of 4.(40$, 3 gas)", "Bag of fries cooked and dried. (20$, 2 food)", " / ");
            if (temp == 0)
            {
                current = 20;
                en_mod_money(-25);
                en_mod_food(+1);
            }
            if (temp == 1)
            {
                current = 21;
                en_mod_money(-75);
                en_mod_gas(+1);
            }
            if (temp == 2)
            {
                current = 22;
                en_mod_money(-30);
                en_mod_food(+2);
            }
            break;
        case 3:
            temp = ui_choice("Check out the bus", "/", "/", "/");
            if (temp == 0)
            {
                if (inventory->pa_count > 1)
                    current = 300;
                else
                    current = 301;
            }
            break;
        case 4:
            temp = ui_choice("Sitting down.", "Leave the room.", "/", "/");
            if (temp == 0)
                current = 12;
            if (temp == 1)
                current = 11;
            break;
        case 5:
            temp = ui_choice("You really own this store?", "What did you sell?", "/", "/");
            if (temp == 0)
                current = 6;
            if (temp == 1)
                current = 104;
            break;
        case 6:
            temp = ui_choice("What did you sell?", "/", "/", "/");
            if (temp == 0)
                current = 104;
            break;
        case 7:
            temp = ui_choice("Return to the lobby of the shopping center.", "/", "/", "/");
            if (temp == 0)
                current = 1;
            break;
        case 8:
            temp = ui_choice("Return to the lobby of the shopping center.", "/", "/", "/");
            if (temp == 0)
                current = 1;
            break;
        case 9:
            temp = ui_choice("Return to the lobby of the shopping center.", "/", "/", "/");
            if (temp == 0)
                current = 1;
            break;
        case 10:
            ui_continu_choice(win_men);
            current = 1;
            break;
        case 11:
            temp = ui_choice("Return to the lobby of the shopping center.", "Leave the shopping center.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 200;
            break;
        case 12:
            temp = ui_choice("No, thank you. What do you sell here?", "Why not.", "/", "/");
            if (temp == 0)
                current = 13;
            if (temp == 1)
                current = 14;
            break;
        case 13:
            temp = ui_choice("Leave the room.", "You mean you killed him?", "/", "/");
            if (temp == 0)
                current = 11;
            if (temp == 1)
                current = 128;
            break;
        case 14:
            temp = ui_choice("It's out of the question, Granny.", "/", "/", "/");
            if (temp == 0)
                current = 16;
            break;
        case 15:
            temp = ui_choice("Return to the lobby of the shopping center.", "Leave the shopping centre.", "/", "/");
            if (temp == 0)
                current = 5;
            if (temp == 1)
                current = 200;
            break;
        case 16:
            ui_continu_choice(win_men);
            {
                current = 17;
                en_mod_money(-25);
            }
            break;
        case 17:
            ui_continu_choice(win_men);
            current = 1;
            break;
        case 20:
            temp = ui_choice("Leave the room.", "/", "/", "/");
            if (temp == 0)
                current = 23;
            break;
        case 21:
            temp = ui_choice("Leave the room.", "/", "/", "/");
            if (temp == 0)
                current = 23;
            break;
        case 22:
            temp = ui_choice("Leave the room.", "/", "/", "/");
            if (temp == 0)
                current = 23;
            break;
        case 23:
            ui_continu_choice(win_men);
            current = 1;
            break;
        case 102:
            temp = ui_choice("Goulash. 25$", "Marinated beef sirloin. 35$", "Pork with meatball and sauerkraut. 40$", "/");
            if (temp == 0)
            {
                current = 7;
                en_mod_money(-25);
                en_mod_food(+1);
            }
            if (temp == 1)
            {
                current = 8;
                en_mod_money(-35);
                en_mod_food(+2);
            }
            if (temp == 2)
            {
                current = 9;
                en_mod_money(-40);
                en_mod_food(+4);
            }
            break;
        case 128:
            temp = ui_choice("Thanks, Grandma. But I'm not interested in the frizz. I'll go look elsewhere if I find what I need.", "/", "/", "/");
            if (temp == 0)
                current = 15;
            break;
        case 200:
            ui_continu_choice(win_men);
            if (uf_compare("Damien") != -1)
                current = 3;
            else
                current = -1;
            break;
        }

        after_event_clear(win_env, win_men);
    }
}



void pe_event_7()	/* Dallas */
{
    int current = 0;
    int temp;
    char* char0 = "Rafe";
    char* char1 = "Evelynn";
    char* char2 = "/";
    char* char3 = "Masked Guy";
    char* char4 = "Absjorn";
    char* char5 = "Evelynn";

    int required_passenger = 4;
    int explosives_installed = 0; /* 0 == false      1 == true */

    if (inventory->pa_count > 0)
        char2 = inventory->passengers[uf_random(inventory->pa_count)];

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/7", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Honk.", "Get out of the bus.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 2;
            break;
        case 1:
            temp = ui_choice("Find a way to open the portal.", "/", "/", "/");
            if (temp == 0)
                current = 3;
            break;
        case 2:
            temp = ui_choice("Find a way to open the portal.", "/", "/", "/");
            if (temp == 0)
                current = 3;
            break;
        case 3:
            temp = ui_choice("Push the portal.", "/", "/", "/");
            if (temp == 0)
                current = 4;
            break;
        case 4:
            temp = ui_choice("Push harder the portal.", "/", "/", "/");
            if (temp == 0)
                current = 5;
            break;
        case 5:
            temp = ui_choice("Stay in the bus.", "Get out of the bus.", "/", "/");
            if (temp == 0)
                current = 6;
            if (temp == 1)
            {
                if (who_is_alive == 1) /* Evelynn */
                    current = 10;
                if (who_is_alive == 1) /* Rafe */
                    current = 11;
            }
            break;
        case 6:
            temp = ui_choice("Stay in the bus.", "Get out of the bus.", "/", "/");
            if (temp == 0)
                current = 7;
            if (temp == 1)
            {
                if (who_is_alive == 1) /* Evelynn */
                    current = 10;
                if (who_is_alive == 1) /* Rafe */
                    current = 11;
            }
            break;
        case 7:
            temp = ui_choice("Stay in the bus.", "Get out of the bus.", "/", "/");
            if (who_is_alive == 0) /* Evelynn */
            {
                if (temp == 0)
                    current = 8;
                if (temp == 1)
                    current = 10;
            }
            if (who_is_alive == 1) /* Rafe */
            {
                if (temp == 0)
                    current = 9;
                if (temp == 1)
                    current = 11;
            }
            break;
        case 8:
            ui_continu_choice(win_men);
            current = 20;
            break;
        case 9:
            ui_continu_choice(win_men);
            current = 200;
            break;
        case 10:
            ui_continu_choice(win_men);
            current = 20;
            break;
        case 11:
            ui_continu_choice(win_men);
            current = 200;
            break;
        case 20:
            ui_continu_choice(win_men);
            if (inventory->pa_count == 0)
                current = 21;
            if (inventory->pa_count == 1)
                current = 22;
            if (inventory->pa_count > 0)
                current = 23;
            break;
        case 21:
            temp = ui_choice("What are you doing here?", "How did you survive in the hospital?", "/", "/");
            if (temp == 0)
                current = 24;
            if (temp == 1)
                current = 28;
            break;
        case 22:
            temp = ui_choice("What are you doing here?", "How did you survive in the hospital?", "/", "/");
            if (temp == 0)
                current = 24;
            if (temp == 1)
                current = 28;
            break;
        case 23:
            ui_continu_choice(win_men);
            current = 24;
            break;
        case 24:
            temp = ui_choice("Who do you wanna help?", "Alright, if you wanna help, untie my links!", "/", "/");
            if (temp == 0)
                current = 26;
            if (temp == 1)
                current = 25;
            break;
        case 25:
            ui_continu_choice(win_men);
            current = 26;
            break;
        case 26:
            temp = ui_choice("Please, help me. Untie my links!", "How did you survive in the hospital?", "/", "/");
            if (temp == 0)
                current = 27;
            if (temp == 1)
                current = 28;
            break;
        case 27:
            temp = ui_choice("How did you survive in the hospital?", "/", "/", "/");
            if (temp == 0)
                current = 28;
            break;
        case 28:
            temp = ui_choice("How dare you?!", "Struggle to break the links.", "/", "/");
            if (temp == 0)
                current = 29;
            if (temp == 1)
                current = 30;
            break;
        case 29:
            temp = ui_choice("Spit in her face.", "Struggle to break the links.", "/", "/");
            if (temp == 0)
                current = 31;
            if (temp == 1)
                current = 31;
            break;
        case 30:
            ui_continu_choice(win_men);
            current = 29;
            break;
        case 31:
            ui_continu_choice(win_men);
            if (inventory->pa_count >= required_passenger)
                current = 40;
            if (inventory->pa_count > 1 && inventory->pa_count < required_passenger)
                current = 41;
            if (inventory->pa_count == 1)
                current = 42;
            if (inventory->pa_count == 0)
                current = 43;
            break;
        case 40:
            ui_continu_choice(win_men);
            current = 44;
            break;
        case 41:
            ui_continu_choice(win_men);
            current = 45;
            break;
        case 42:
            ui_continu_choice(win_men);
            current = 46;
            break;
        case 43:
            ui_continu_choice(win_men);
            current = 47;
            break;
        case 44:
            ui_continu_choice(win_men);
            current = 48;
            break;
        case 45:
            ui_continu_choice(win_men);
            current = 49;
            break;
        case 46:
            ui_continu_choice(win_men);
            current = 49;
            break;
        case 47:
            ui_continu_choice(win_men);
            current = 50;
            break;
        case 48:
            ui_continu_choice(win_men);
            current = 400;
            break;
        case 49:
            ui_continu_choice(win_men);
            current = 62;
            break;
        case 50:
            ui_continu_choice(win_men);
            current = 62;
            break;
        case 62:
            temp = ui_choice("Yes.", "No.", "/", "/");
            if (temp == 0)
                current = 63;
            if (temp == 1)
                current = 63;
            break;
        case 63:
            ui_continu_choice(win_men);
            current = 64;
            break;
        case 64:
            temp = ui_choice("Yes.", "No.", "/", "/");
            if (temp == 0)
                current = 65;
            if (temp == 1)
                current = 65;
            break;
        case 65:
            temp = ui_choice("Yell at her.", "Nothing.", "/", "/");
            if (temp == 0)
                current = 66;
            if (temp == 1)
                current = 67;
            break;
        case 66:
            temp = ui_choice("Ye...", "N... No...", "/", "/");
            if (temp == 0)
                current = 68;
            if (temp == 1)
                current = 68;
            break;
        case 67:
            temp = ui_choice("Y...", "...No, no...", "/", "/");
            if (temp == 0)
                current = 69;
            if (temp == 1)
                current = 69;
            break;
        case 68:
            temp = ui_choice("Nothing.", "/", "/", "/");
            if (temp == 0)
                current = 70;
            break;
        case 69:
            temp = ui_choice("Yell at her.", "/", "/", "/");
            if (temp == 0)
                current = 71;
            break;
        case 70:
            temp = ui_choice("Noooo!", "/", "/", "/");
            if (temp == 0)
                current = 72;
            break;
        case 71:
            temp = ui_choice("Ask her what she wants.", "/", "/", "/");
            if (temp == 0)
            {
                if (inventory->pa_count > 0)
                {
                    char2 = "Passengers";
                    current = 72;
                }
                else
                    current = 73;
            }
            break;
        case 72:
            temp = ui_choice("Fuck you! All of you!", "/", "/", "/");
            if (temp == 0)
                current = 74;
            break;
        case 73:
            ui_continu_choice(win_men);
            current = 74;
            break;
        case 74:
            temp = ui_choice("Repeat after her.", "Keep silent.", "/", "/");
            if (temp == 0)
                current = 77;
            if (temp == 1)
                current = 75;
            break;
        case 75:
            temp = ui_choice("It won't...", "/", "/", "/");
            if (temp == 0)
                current = 76;
            break;
        case 76:
            temp = ui_choice("Repeat after her.", "/", "/", "/");
            if (temp == 0)
                current = 77;
            break;
        case 77:
            ui_continu_choice(win_men);
            current = 78;
            break;
        case 78:
            ui_continu_choice(win_men);
            current = 79;
            break;
        case 79:
            temp = ui_choice("Write: Goodbye.", "Write: Freedom.", "Don't write anything.", "/");
            if (temp == 0)
                current = 81;
            if (temp == 1)
                current = 81;
            if (temp == 2)
                current = 80;
            break;
        case 80:
            temp = ui_choice("We must hurry.", "/", "/", "/");
            if (temp == 0)
                current = 82;
            break;
        case 81:
            temp = ui_choice("We must hurry.", "/", "/", "/");
            if (temp == 0)
                current = 82;
            break;
        case 82:
            temp = ui_choice("Help the rebels.", "Help the cult.", "/", "/");
            if (temp == 0)
                current = 83;
            if (temp == 1)
                current = 83;
            break;
        case 83:
            temp = ui_choice("We must hurry.", "/", "/", "/");
            if (temp == 0)
                current = 84;
            break;
        case 84:
            temp = ui_choice("Kill him.", "Applaud.", "/", "/");
            if (temp == 0)
                current = 85;
            if (temp == 1)
                current = 85;
            break;
        case 85:
            temp = ui_choice("Time to arm the changing.", "/", "/", "/");
            if (temp == 0)
                current = 86;
            break;
        case 86:
            temp = ui_choice("Go to Oklahoma City.", "/", "/", "/");
            if (temp == 0)
                current = 87;
            break;
        case 87:
            ui_continu_choice(win_men);
            current = 88;
            break;
        case 88:
            ui_continu_choice(win_men);
            current = 89;
            break;
        case 89:
            temp = ui_choice("Attack from the rear.", "Attack from a roof.", "/", "/");
            if (temp == 0)
                current = 90;
            if (temp == 1)
                current = 92;
            break;
        case 90:
            temp = ui_choice("Knock her down.", "Kill her.", "/", "/");
            if (temp == 0)
                current = 91;
            if (temp == 1)
                current = 91;
            break;
        case 91:
            temp = ui_choice("Every heretics should die.", "/", "/", "/");
            if (temp == 0)
                current = 93;
            break;
        case 92:
            temp = ui_choice("Knock her down.", "Kill her.", "/", "/");
            if (temp == 0)
                current = 91;
            if (temp == 1)
                current = 91;
            break;
        case 93:
            temp = ui_choice("He should die.", "He should be saved.", "/", "/");
            if (temp == 0)
                current = 94;
            if (temp == 1)
                current = 94;
            break;
        case 94:
            temp = ui_choice("Head for the first floor by taking the stairs.", "/", "/", "/");
            if (temp == 0)
                current = 95;
            break;
        case 95:
            temp = ui_choice("Release your faith.", "/", "/", "/");
            if (temp == 0)
                current = 96;
            break;
        case 96:
            temp = ui_choice("Go through the corridor.", "/", "/", "/");
            if (temp == 0)
            {
                char1 = "Evelynn";
                char3 = "Unknown Man";
                current = 97;
            }
            break;
        case 97:
            ui_continu_choice(win_men);
            current = 98;
            break;
        case 98:
            temp = ui_choice("Go to the headquarters of Oklahoma City.", "/", "/", "/");
            if (temp == 0)
                current = 99;
            break;
        case 99:
            temp = ui_choice("Destroy the city.", "/", "/", "/");
            if (temp == 0)
            {
                char4 = "Great Preacher";
                current = 100;
            }
            break;
        case 100:
            temp = ui_choice("May our world stay faithful.", "/", "/", "/");
            if (temp == 0)
            {
                els_is_exit = 666;
                els_is_win = 1;
                current = -1;
            }
            break;
        case 200:
            temp = ui_choice("Then, what are you doing in Dallas?", "/", "/", "/");
            if (temp == 0)
                current = 201;
            break;
        case 201:
            temp = ui_choice("Wow, easy! What do you mean?", "/", "/", "/");
            if (temp == 0)
                current = 202;
            break;
        case 202:
            temp = ui_choice("What do you expect from me?", "/", "/", "/");
            if (temp == 0)
                current = 203;
            break;
        case 203:
            ui_continu_choice(win_men);
            if (inventory->pa_count == 0)
                current = 207;
            if (inventory->pa_count == 1)
                current = 204;
            if (inventory->pa_count > 1)
                current = 205;
            break;
        case 204:
            ui_continu_choice(win_men);
            current = 206;
            break;
        case 205:
            ui_continu_choice(win_men);
            current = 206;
            break;
        case 206:
            ui_continu_choice(win_men);
            current = 208;
            break;
        case 207:
            ui_continu_choice(win_men);
            current = 208;
            break;
        case 208:
            temp = ui_choice("It rocks!", "Not bad.", "/", "/");
            if (temp == 0)
                current = 209;
            if (temp == 1)
                current = 210;
            break;
        case 209:
            ui_continu_choice(win_men);
            current = 211;
            break;
        case 210:
            ui_continu_choice(win_men);
            current = 211;
            break;
        case 211:
            temp = ui_choice("So, what are your plans?", "/", "/", "/");
            if (temp == 0)
                current = 212;
            break;
        case 212:
            temp = ui_choice("Take a break.", "/", "/", "/");
            if (temp == 0)
                current = 213;
            break;
        case 213:
            ui_continu_choice(win_men);
            char1 = "Jay";
            char2 = "Zoe";
            current = 214;
            break;
        case 214:
            ui_continu_choice(win_men);
            char3 = "Masked Controller";
            current = 215;
            break;
        case 215:
            temp = ui_choice("Hello.", "Faithful.", "/", "/");
            if (temp == 0)
                current = 216;
            if (temp == 1)
                current = 217;
            break;
        case 216:
            ui_continu_choice(win_men);
            current = 218;
            break;
        case 217:
            ui_continu_choice(win_men);
            current = 218;
            break;
        case 218:
            temp = ui_choice("Park the bus.", "/", "/", "/");
            if (temp == 0)
                current = 219;
            break;
        case 219:
            ui_continu_choice(win_men);
            char3 = "Not Masked Guy";
            char4 = "Earpiece";
            current = 220;
            break;
        case 220:
            ui_continu_choice(win_men);
            current = 221;
            break;
        case 221:
            temp = ui_choice("Keep following.", "Enter another room.", "/", "/");
            if (temp == 0)
                current = 223;
            if (temp == 1)
                current = 222;
            break;
        case 222:
            ui_continu_choice(win_men);
            current = 223;
            break;
        case 223:
            ui_continu_choice(win_men);
            current = 224;
            break;
        case 224:
            temp = ui_choice("You should set a C-4 to explode the school.", "Please don't touch this. We have to stay focused on the mission.", "/", "/");
            if (temp == 0)
                current = 225;
            if (temp == 1)
                current = 226;
            break;
        case 225:
            ui_continu_choice(win_men);
            explosives_installed = 1;
            current = 227;
            break;
        case 226:
            ui_continu_choice(win_men);
            current = 227;
            break;
        case 227:
            ui_continu_choice(win_men);
            current = 228;
            break;
        case 228:
            ui_continu_choice(win_men);
            current = 229;
            break;
        case 229:
            ui_continu_choice(win_men);
            current = 230;
            break;
        case 230:
            ui_continu_choice(win_men);
            current = 231;
            break;
        case 231:
            temp = ui_choice("Set a bomb on the other installations.", "Leave and take shelter.", "/", "/");
            if (temp == 0)
                current = 232;
            if (temp == 1)
                current = 234;
            break;
        case 232:
            temp = ui_choice("Leave and take shelter.", "/", "/", "/");
            if (temp == 0)
                current = 233;
            break;
        case 233:
            temp = ui_choice("Stand up.", "/", "/", "/");
            if (temp == 0)
                current = 235;
            break;
        case 234:
            ui_continu_choice(win_men);
            current = 237;
            break;
        case 235:
            temp = ui_choice("Stand up.", "/", "/", "/");
            if (temp == 0)
                current = 236;
            break;
        case 236:
            ui_continu_choice(win_men);
            current = 238;
            break;
        case 237:
            ui_continu_choice(win_men);
            current = 238;
            break;
        case 238:
            temp = ui_choice("Who are you?", "How can I trust you if my brother is with you?", "/", "/");
            if (temp == 0)
                current = 239;
            if (temp == 1)
                current = 241;
            break;
        case 239:
            ui_continu_choice(win_men);
            current = 242;
            break;
        case 240:
            ui_continu_choice(win_men);
            current = 242;
            break;
        case 241:
            ui_continu_choice(win_men);
            current = 242;
            break;
        case 242:
            ui_continu_choice(win_men);
            char3 = "Masked Guy";
            if (explosives_installed == 1)
                current = 243;
            else
                current = 244;
            break;
        case 243:
            ui_continu_choice(win_men);
            current = 242;
            break;
        case 244:
            ui_continu_choice(win_men);
            current = 245;
            break;
        case 245:
            ui_continu_choice(win_men);
            if (inventory->pa_count >= required_passenger)
            {
                char3 = "Masked Guy";
                current = 260;
            }
            else
            {
                char1 = "Unknown Woman";
                current = 280;
            }
            break;
        case 260:
            ui_continu_choice(win_men);
            if (uf_compare("Curtis") != -1)
            {
                char2 = "Curtis";
                current = 261;
            }
            else
            {
                if (inventory->pa_count > 0)
                    char4 = inventory->passengers[uf_random(inventory->pa_count)];
                current = 262;
            }
            break;
        case 261:
            ui_continu_choice(win_men);
            current = 263;
            break;
        case 262:
            ui_continu_choice(win_men);
            current = 263;
            break;
        case 263:
            ui_continu_choice(win_men);
            char1 = "Jay";
            char2 = "Zoe";
            char4 = "Drive";
            current = 264;
            break;
        case 264:
            ui_continu_choice(win_men);
            current = 265;
            break;
        case 265:
            temp = ui_choice("For me, the fight is not over.", "/", "/", "/");
            if (temp == 0)
            {
                els_is_exit = 666;
                els_is_win = 1;
                current = -1;
            }
            break;

            /* 400 */

        case 400:
            temp = ui_choice("So there's still hope?", "We're in deep shit!", "We have all the time in the world.", "/");
            if (temp == 0)
                current = 401;
            if (temp == 1)
                current = 402;
            if (temp == 2)
                current = 403;
            break;
        case 401:
            temp = ui_choice("That leaves some of us with a ticket out. I can create a diversion and let some of you take a seat in the truck.", "I doubt we can all escape. We will be noticed very quickly if we all leave at the same time.", "I hope you don't mind the comfort of an ammunition box.", "/");
            if (temp == 0)
                current = 404;
            if (temp == 1)
                current = 405;
            if (temp == 2)
                current = 406;
            break;
        case 402:
            temp = ui_choice("That leaves some of us with a ticket out. I can create a diversion and let some of you take a seat in the truck.", " I doubt we can all escape. We will be noticed very quickly if we all leave at the same time.", "I hope you don't mind the comfort of an ammunition box.", "/");
            if (temp == 0)
                current = 404;
            if (temp == 1)
                current = 405;
            if (temp == 2)
                current = 406;
            break;
        case 403:
            temp = ui_choice("That leaves some of us with a ticket out. I can create a diversion and let some of you take a seat in the truck.", "2 - I doubt we can all escape. We will be noticed very quickly if we all leave at the same time.", "I hope you don't mind the comfort of an ammunition box.", "/");
            if (temp == 0)
                current = 404;
            if (temp == 1)
                current = 405;
            if (temp == 2)
                current = 406;
            break;
        case 404:
            temp = ui_choice("I really can't do that.", "I guess I have no choice...", "/", "/");
            if (temp == 0)
                current = 407;
            if (temp == 1)
                current = 408;
            break;
        case 405:
            temp = ui_choice("I really can't do that.", "I guess I have no choice...", "/", "/");
            if (temp == 0)
                current = 407;
            if (temp == 1)
                current = 408;
            break;
        case 406:
            temp = ui_choice("I really can't do that.", "I guess I have no choice...", "/", "/");
            if (temp == 0)
                current = 407;
            if (temp == 1)
                current = 408;
            break;
        case 407:
            temp = ui_choice("Sorry, I had an absence.", "You seem in a hurry, dear.", "/", "/");
            if (temp == 0)
                current = 409;
            if (temp == 1)
                current = 410;
            break;
        case 408:
            temp = ui_choice("Sorry, I had an absence.", "You seem in a hurry, dear.", "/", "/");
            if (temp == 0)
                current = 409;
            if (temp == 1)
                current = 410;
            break;
        case 409:
            temp = ui_choice("You hide in one of the boxes.", "/", "/", "/");
            if (temp == 0)
                current = 411;
            break;
        case 410:
            temp = ui_choice("You hide in one of the boxes.", "/", "/", "/");
            if (temp == 0)
                current = 411;
            break;
        case 411:
            temp = ui_choice("Wake you up", "/", "/", "/");
            if (temp == 0)
                current = 448;
            break;
        case 412:
            temp = ui_choice("Overturn the ammunition boxes on him.", "Take your momentum and hit him with a dropkick in the face.", "Make him an armlock and disarm him.", "/");
            if (temp == 0)
                current = 414;
            if (temp == 1)
                current = 415;
            if (temp == 2)
                current = 416;
            break;
        case 413:
            temp = ui_choice("Make him an armlock and disarm him.", "Take your momentum and hit him with a dropkick in the face.", "Overturn the ammunition boxes on him.", "/");
            if (temp == 0)
                current = 416;
            if (temp == 1)
                current = 415;
            if (temp == 2)
                current = 414;
            break;
        case 414:
            temp = ui_choice("Take the 81, towards Oklahoma.", "/", "/", "/");
            if (temp == 0)
                current = 417;
            break;
        case 415:
            temp = ui_choice("Take the 81, towards Oklahoma.", "/", "/", "/");
            if (temp == 0)
                current = 417;
            break;
        case 416:
            temp = ui_choice("You won't kill a kid who barely has three hairs. You order him to leave.", "You can't afford to leave him alive. You shoot.", "/", "/");
            if (temp == 0)
                current = 419;
            if (temp == 1)
                current = 418;
            break;
        case 417:
            temp = ui_choice("Do not respond to the radio.", "Answer the radio.", "/", "/");
            if (temp == 0)
                current = 420;
            if (temp == 1)
                current = 421;
            break;
        case 418:
            temp = ui_choice("Take the 81, towards Oklahoma.", "/", "/", "/");
            if (temp == 0)
                current = 417;
            break;
        case 419:
            temp = ui_choice("Take the 80, towards Oklahoma.", "/", "/", "/");
            if (temp == 0)
                current = 517;
            break;

        case 420:
            temp = ui_choice("Continue to Oklahoma without worrying about your pursuers.", "/", "/", "/");
            if (temp == 0)
                current = 427;
            break;
        case 421:
            temp = ui_choice("Well, on the road. Not too far.", "Ask your mother.", "Central Lawton of Delta 7, position in Sector 4.", "/");
            if (temp == 0)
                current = 424;
            if (temp == 1)
                current = 422;
            if (temp == 2)
                current = 423;
        case 422:
            temp = ui_choice("Continue to Oklahoma without worrying about your pursuers.", "/", "/", "/");
            if (temp == 0)
                current = 427;
            break;
        case 423:
            temp = ui_choice("Continue to Oklahoma without worrying about your pursuers.", "/", "/", "/");
            if (temp == 0)
                current = 601;
            break;
        case 424:
            temp = ui_choice("Ask your mother.", "Central Lawton of Delta 7, position in Sector 4.", "/", "/");
            if (temp == 0)
                current = 425;
            if (temp == 1)
                current = 426;
            break;
        case 425:
            temp = ui_choice("Continue to Oklahoma without worrying about your pursuers.", "/", "/", "/");
            if (temp == 0)
                current = 427;
            break;
        case 426:
            temp = ui_choice("Continue to Oklahoma without worrying about your pursuers.", "/", "/", "/");
            if (temp == 0)
                current = 427;
            break;
        case 427:
            temp = ui_choice("Parking and getting out of the truck.", "/", "/", "/");
            if (temp == 0)
                current = 429;

            char3 = "Soldier";
            break;
        case 429:
            temp = ui_choice("That's because I'm not one. I came from one of their Dallas prisons.", "A shipment of ammunition to Lawton that I stole. They won't need it anymore.", "/", "/");
            if (temp == 0)
                current = 432;
            if (temp == 1)
                current = 433;
            break;
        case 432:
            temp = ui_choice("Follow the two soldiers.", "/", "/", "/");
            if (temp == 0)
                current = 445;
            break;
        case 433:
            temp = ui_choice("What's going on here?", "/", "/", "/");
            if (temp == 0)
                current = 434;
            break;
        case 434:
            temp = ui_choice("Follow the two soldiers.", "/", "/", "/");
            if (temp == 0)
                current = 435;
            break;
        case 435:
            temp = ui_choice("I am listening.", "/", "/", "/");
            if (temp == 0)
                current = 436;
            break;
        case 436:
            temp = ui_choice("This truck was my ticket out of Dallas prison.", "I hijacked it on the road.", "/", "/");
            if (temp == 0)
                current = 438;
            if (temp == 1)
                current = 437;
            break;
        case 437:
            temp = ui_choice("The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/");
            if (temp == 0)
                current = 443;
            if (temp == 1)
                current = 444;
            break;
        case 438:
            temp = ui_choice("I don't think it works like that.", "I didn't stay long enough to become a devotee.", "/", "/");
            if (temp == 0)
                current = 440;
            if (temp == 1)
                current = 439;
            break;
        case 439:
            temp = ui_choice("The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/");
            if (temp == 0)
                current = 443;
            if (temp == 1)
                current = 444;
            break;
        case 440:
            temp = ui_choice("So what next? You're keeping me in isolation?", "I can fuck off, if it suits you and reassures you.", "/", "/");
            if (temp == 0)
                current = 441;
            if (temp == 1)
                current = 442;
            break;
        case 441:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "/", "/");
            if (temp == 0)
                current = 444;
            if (temp == 1)
                current = 443;
            break;
        case 442:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "/", "/");
            if (temp == 0)
                current = 444;
            if (temp == 1)
                current = 443;
            break;
        case 443:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/", "/");
            if (temp == 0)
                current = 450;
            break;
        case 444:
            temp = ui_choice("The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "/", "/", "/");
            if (temp == 0)
                current = 449;
            break;
        case 445:
            temp = ui_choice("I slipped into one of their trucks to get out of their prison. It was the only opportunity I had.", "/", "/", "/");
            if (temp == 0)
                current = 446;
            break;
        case 446:
            temp = ui_choice("No... he died in Los Angeles during the putsch. He helped me get through it.", "/", "/", "/");
            if (temp == 0)
                current = 447;
            break;
        case 447:
            temp = ui_choice("The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them", "/", "/");
            if (temp == 0)
                current = 443;
            if (temp == 1)
                current = 444;
            break;
        case 448:
            temp = ui_choice("Hammer the walls to the rhythm of the song 7 Nation Army.", "Imitate the sound of a cat.", "/", "/");
            if (temp == 0)
                current = 412;
            if (temp == 1)
                current = 413;
            break;
        case 449:
            temp = ui_choice("That's all I have, sorry.", "/", "/", "/");
            if (temp == 0)
                current = 451;
            break;
        case 450:
            temp = ui_choice("That's all I have, sorry.", "/", "/", "/");
            if (temp == 0)
                current = 451;
            break;
        case 451:
            temp = ui_choice("What's so special about Oklahoma City?", "How did you meet Rafe?", "No questions, Major.", "What do you know about the cult?");
            if (temp == 0)
                current = 800;
            if (temp == 1)
                current = 801;
            if (temp == 2)
                current = 804;
            if (temp == 3)
                current = 803;
            break;

            /* 500 */

        case 517:
            temp = ui_choice("Do not respond to the radio.", "Answer the radio.", "/", "/");
            if (temp == 0)
                current = 518;
            if (temp == 1)
                current = 519;
            break;

        case 518:
            temp = ui_choice("Continue to Oklahoma without worrying about your pursuers.", "/", "/", "/");
            if (temp == 0)
                current = 427;
            break;
        case 519:
            temp = ui_choice("Ask your mother.", "Central Lawton of Delta 7, position in Sector 4.", "Well, on the road. Not too far.", "/");
            if (temp == 0)
                current = 520;
            if (temp == 1)
                current = 521;
            if (temp == 2)
                current = 522;
            break;
        case 520:
            temp = ui_choice("Continue to Oklahoma without worrying about your pursuers.", "/", "/", "/");
            if (temp == 0)
                current = 427;
            break;
        case 521:
            temp = ui_choice("Who are you?", "What are you looking for?", "/", "/");
            if (temp == 0)
                current = 524;
            if (temp == 1)
                current = 523;
            break;
        case 522:
            temp = ui_choice("Who are you?", "What are you looking for?", "/", "/");
            if (temp == 0)
                current = 524;
            if (temp == 1)
                current = 523;
            break;
        case 523:
            temp = ui_choice("You're right... we're connected... maybe I should…", "/", "/", "/");
            if (temp == 0)
                current = 525;
            break;
        case 524:
            temp = ui_choice("Great things... Rafe's dead now... maybe I should…", "/", "/", "/");
            if (temp == 0)
                current = 526;
            break;
        case 525:
            temp = ui_choice("Continue to Oklahoma without worrying about your pursuers.", "/", "/", "/");
            if (temp == 0)
                current = 700;
            break;
        case 526:
            temp = ui_choice("Continue to Oklahoma without worrying about your pursuers.", "/", "/", "/");
            if (temp == 0)
                current = 700;
            break;

            /* 600 */

        case 601:
            temp = ui_choice("Parking and getting out of the truck.", "/", "/", "/");
            if (temp == 0)
                current = 602;
            break;
        case 602:
            temp = ui_choice("That's because I'm not one. I came from one of their Dallas prisons.", "A shipment of ammunition to Lawton that I stole. They won't need it anymore.", "/", "/");
            if (temp == 0)
                current = 606;
            if (temp == 1)
                current = 605;
            break;
        case 605:
            temp = ui_choice("Choice", "/", "/", "/");
            if (temp == 0)
                current = 607;
            break;
        case 606:
            temp = ui_choice("Follow the two soldiers.", "/", "/", "/");
            if (temp == 0)
                current = 619;
            break;
        case 607:
            temp = ui_choice("Follow the two soldiers.", "/", "/", "/");
            if (temp == 0)
                current = 608;

            char1 = "Henry Cortez";
            break;
        case 608:
            temp = ui_choice("I am listening.", "/", "/", "/");
            if (temp == 0)
                current = 609;
            break;
        case 609:
            temp = ui_choice("This truck was my ticket out of Dallas prison.", "I hijacked it on the road.", "/", "/");
            if (temp == 0)
                current = 610;
            if (temp == 1)
                current = 611;
            break;
        case 610:
            temp = ui_choice(" I don't think it works like that.", "I didn't stay long enough to become a devotee.", "/", "/");
            if (temp == 0)
                current = 613;
            if (temp == 1)
                current = 612;
            break;
        case 611:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them", "The truck I stole was to refuel Lawton to strengthen the city.", "The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "/");
            if (temp == 0)
                current = 618;
            if (temp == 1)
                current = 617;
            if (temp == 2)
                current = 616;
            break;
        case 612:
            temp = ui_choice("The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "The truck I stole was to refuel Lawton to strengthen the city.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/");
            if (temp == 0)
                current = 616;
            if (temp == 1)
                current = 617;
            if (temp == 2)
                current = 618;
            break;
        case 613:
            temp = ui_choice("I can fuck off, if it suits you and reassures you.", "So what next? You're keeping me in isolation?", "/", "/");
            if (temp == 0)
                current = 614;
            if (temp == 1)
                current = 615;
            break;
        case 614:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "The truck I stole was to refuel Lawton to strengthen the city.", "The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "/");
            if (temp == 0)
                current = 618;
            if (temp == 1)
                current = 617;
            if (temp == 2)
                current = 616;
            break;
        case 615:
            temp = ui_choice("The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "The truck I stole was to refuel Lawton to strengthen the city.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/");
            if (temp == 0)
                current = 616;
            if (temp == 1)
                current = 617;
            if (temp == 2)
                current = 618;
            break;
        case 616:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "The truck I stole was to refuel Lawton to strengthen the city.", "/", "/");
            if (temp == 0)
                current = 625;
            if (temp == 1)
                current = 624;
            break;
        case 617:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/", "/");
            if (temp == 0)
                current = 623;
            break;
        case 618:
            temp = ui_choice("The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "The truck I stole was to refuel Lawton to strengthen the city.", "/", "/");
            if (temp == 0)
                current = 629;
            if (temp == 1)
                current = 628;
            break;
        case 619:
            temp = ui_choice("I slipped into one of their trucks to get out of their prison. It was the only opportunity I had.", "/", "/", "/");
            if (temp == 0)
                current = 620;
            break;
        case 620:
            temp = ui_choice("No... he died in Los Angeles during the putsch. He helped me get through it.", "/", "/", "/");
            if (temp == 0)
                current = 621;
            break;
        case 621:
            temp = ui_choice("The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "The truck I stole was to refuel Lawton to strengthen the city.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/");
            if (temp == 0)
                current = 616;
            if (temp == 1)
                current = 617;
            if (temp == 2)
                current = 618;
            break;
        case 622:
            temp = ui_choice("What's so special about Oklahoma City?", "How did you meet Rafe?", "What do you know about the cult?", "No questions, Major.");
            if (temp == 0)
                current = 800;
            if (temp == 1)
                current = 801;
            if (temp == 2)
                current = 803;
            if (temp == 3)
                current = 804;
            break;
        case 623:
            temp = ui_choice("That's all I have.", "/", "/", "/");
            if (temp == 0)
                current = 622;
            break;
        case 624:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/", "/");
            if (temp == 0)
                current = 627;
            break;
        case 625:
            temp = ui_choice("The truck I stole was to refuel Lawton to strengthen the city.", "/", "/", "/");
            if (temp == 0)
                current = 626;
            break;
        case 626:
            temp = ui_choice("That's all I have.", "/", "/", "/");
            if (temp == 0)
                current = 622;
            break;
        case 627:
            temp = ui_choice("That's all I have.", "/", "/", "/");
            if (temp == 0)
                current = 622;
            break;
        case 628:
            temp = ui_choice("That's all I have.", "/", "/", "/");
            if (temp == 0)
                current = 622;
            break;
        case 629:
            temp = ui_choice("The truck I stole was to refuel Lawton to strengthen the city.", "/", "/", "/");
            if (temp == 0)
                current = 630;
            break;
        case 630:
            temp = ui_choice("That's all I have.", "/", "/", "/");
            if (temp == 0)
                current = 622;
            break;

            /* 700 */

        case 700:
            temp = ui_choice("Parking and getting out of the truck.", "/", "/", "/");
            if (temp == 0)
                current = 703;
            break;
        case 703:
            temp = ui_choice("A shipment of ammunition to Lawton that I stole. They won't need it anymore.", "That's because I'm not one. I came from one of their Dallas prisons.", "/", "/");
            if (temp == 0)
                current = 707;
            if (temp == 1)
                current = 706;
            break;
        case 706:
            temp = ui_choice("Follow the two soldiers.", "/", "/", "/");
            if (temp == 0)
                current = 708;
            break;
        case 707:
            temp = ui_choice("What's going on here?", "/", "/", "/");
            if (temp == 0)
                current = 709;
            break;
        case 708:
            temp = ui_choice("I slipped into one of their trucks to get out of their prison. It was the only opportunity I had.", "/", "/", "/");
            if (temp == 0)
                current = 710;
            break;
        case 709:
            temp = ui_choice("Follow the two soldiers.", "/", "/", "/");
            if (temp == 0)
                current = 711;
            break;
        case 710:
            temp = ui_choice("No... he died in Los Angeles during the putsch. He helped me get through it.", "/", "/", "/");
            if (temp == 0)
                current = 712;
            break;
        case 711:
            temp = ui_choice("I am listening.", "/", "/", "/");
            if (temp == 0)
                current = 713;
            break;
        case 712:
            temp = ui_choice("The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "The truck I stole was to refuel Lawton to strengthen the city.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "I was able to exchange with the Great Preacher on the radio.");
            if (temp == 0)
                current = 719;
            if (temp == 1)
                current = 720;
            if (temp == 2)
                current = 721;
            if (temp == 3)
                current = 722;
            break;
        case 713:
            temp = ui_choice("I hijacked it on the road.", "This truck was my ticket out of Dallas prison", "/", "/");
            if (temp == 0)
                current = 714;
            if (temp == 1)
                current = 715;
            break;
        case 714:
            temp = ui_choice("The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "The truck I stole was to refuel Lawton to strengthen the city.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "I was able to exchange with the Great Preacher on the radio.");
            if (temp == 0)
                current = 719;
            if (temp == 1)
                current = 720;
            if (temp == 2)
                current = 721;
            if (temp == 3)
                current = 722;
            break;
        case 715:
            temp = ui_choice("I didn't stay long enough to become a devotee.", "I don't think it works like that.", "/", "/");
            if (temp == 0)
                current = 716;
            if (temp == 1)
                current = 717;
            break;
        case 716:
            temp = ui_choice("I was able to exchange with the Great Preacher on the radio.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "The truck I stole was to refuel Lawton to strengthen the city.", "The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.");
            if (temp == 0)
                current = 722;
            if (temp == 1)
                current = 721;
            if (temp == 2)
                current = 720;
            if (temp == 3)
                current = 719;
        case 717:
            temp = ui_choice("So what next? You're keeping me in isolation?", "I can fuck off, if it suits you and reassures you.", "/", "/");
            if (temp == 0)
                current = 718;
            if (temp == 1)
                current = 751;
            break;
        case 718:
            temp = ui_choice("I was able to exchange with the Great Preacher on the radio.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "The truck I stole was to refuel Lawton to strengthen the city.", "The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival");
            if (temp == 0)
                current = 722;
            if (temp == 1)
                current = 721;
            if (temp == 2)
                current = 720;
            if (temp == 3)
                current = 719;
            break;
        case 719:
            temp = ui_choice("The truck I stole was to refuel Lawton to strengthen the city.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "I was able to exchange with the Great Preacher on the radio.", "/");
            if (temp == 0)
                current = 723;
            if (temp == 1)
                current = 724;
            if (temp == 2)
                current = 725;
            break;
        case 721:
            temp = ui_choice("I was able to exchange with the Great Preacher on the radio.", "The truck I stole was to refuel Lawton to strengthen the city.", "/", "/");
            if (temp == 0)
                current = 742;
            if (temp == 1)
                current = 743;
            break;
        case 722:
            temp = ui_choice("The truck I stole was to refuel Lawton to strengthen the city.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/");
            if (temp == 0)
                current = 747;
            if (temp == 1)
                current = 746;
            break;
        case 720:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "I was able to exchange with the Great Preacher on the radio.", "/", "/");
            if (temp == 0)
                current = 739;
            if (temp == 1)
                current = 738;
            break;
        case 723:
            temp = ui_choice("I was able to exchange with the Great Preacher on the radio.", "Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/");
            if (temp == 0)
                current = 727;
            if (temp == 1)
                current = 726;
            break;
        case 724:
            temp = ui_choice("The truck I stole was to refuel Lawton to strengthen the city.", "I was able to exchange with the Great Preacher on the radio.", "/", "/");
            if (temp == 0)
                current = 731;
            if (temp == 1)
                current = 730;
            break;
        case 725:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "The truck I stole was to refuel Lawton to strengthen the city.", "/", "/");
            if (temp == 0)
                current = 734;
            if (temp == 1)
                current = 735;
            break;
        case 726:
            temp = ui_choice("Iwas able to exchange with the Great Preacher on the radio.", "/", "/", "/");
            if (temp == 0)
                current = 728;
            break;
        case 727:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/", "/");
            if (temp == 0)
                current = 729;
            break;
        case 728:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 729:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 730:
            temp = ui_choice("The truck I stole was to refuel Lawton to strengthen the city.", "/", "/", "/");
            if (temp == 0)
                current = 732;
            break;
        case 731:
            temp = ui_choice("I was able to exchange with the Great Preacher on the radio.", "/", "/", "/");
            if (temp == 0)
                current = 733;
            break;
        case 732:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 733:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 734:
            temp = ui_choice("The truck I stole was to refuel Lawton to strengthen the city.", "/", "/", "/");
            if (temp == 0)
                current = 737;
            break;
        case 735:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/", "/");
            if (temp == 0)
                current = 736;
            break;
        case 736:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 737:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 739:
            temp = ui_choice("I was able to exchange with the Great Preacher on the radio.", "/", "/", "/");
            if (temp == 0)
                current = 741;
            break;
        case 738:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/", "/");
            if (temp == 0)
                current = 740;
            break;
        case 740:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 741:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 743:
            temp = ui_choice("I was able to exchange with the Great Preacher on the radio.", "/", "/", "/");
            if (temp == 0)
                current = 745;
            break;
        case 742:
            temp = ui_choice("The truck I stole was to refuel Lawton to strengthen the city.", "/", "/", "/");
            if (temp == 0)
                current = 744;
            break;
        case 744:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 745:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 746:
            temp = ui_choice("The truck I stole was to refuel Lawton to strengthen the city.", "/", "/", "/");
            if (temp == 0)
                current = 748;
            break;
        case 747:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "/", "/", "/");
            if (temp == 0)
                current = 749;
            break;
        case 748:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 749:
            temp = ui_choice("What next, Major?", "/", "/", "/");
            if (temp == 0)
                current = 750;
            break;
        case 750:
            temp = ui_choice("What do you know about the cult?", "How did you meet Rafe?", "No questions, Major.", "What's so special about Oklahoma City?");
            if (temp == 0)
                current = 803;
            if (temp == 1)
                current = 801;
            if (temp == 2)
                current = 804;
            if (temp == 3)
                current = 800;
            break;
        case 751:
            temp = ui_choice("Dallas's camp is used to produce ammunition. They use the prisoners to manufacture them.", "The truck I stole was to refuel Lawton to strengthen the city.", "The Great Preacher is on his way to Dallas. They are mobilizing their troops for his arrival.", "I was able to exchange with the Great Preacher on the radio.");
            if (temp == 0)
                current = 721;
            if (temp == 1)
                current = 720;
            if (temp == 2)
                current = 719;
            if (temp == 3)
                current = 722;
            break;

            /* 800 */

        case 800:
            temp = ui_choice("How did you meet Rafe?", "What do you know about the cult?", "No questions, Major.", "/");
            if (temp == 0)
                current = 805;
            if (temp == 1)
                current = 807;
            if (temp == 2)
                current = 804;
            break;
        case 801:
            temp = ui_choice("What do you know about the cult?", "What's so special about Oklahoma City?", "No questions, Major.", "/");
            if (temp == 0)
                current = 808;
            if (temp == 1)
                current = 811;
            if (temp == 2)
                current = 804;
            break;
        case 803:
            temp = ui_choice("What's so special about Oklahoma City?", "How did you meet Rafe?", "No questions, Major.", "/");
            if (temp == 0)
                current = 814;
            if (temp == 1)
                current = 806;
            if (temp == 2)
                current = 804;
            break;
        case 804:
            temp = ui_choice("I have people who stayed in the prison and helped me escape. I am indebted to them.", "/", "/", "/");
            if (temp == 0)
                current = 817;
            break;
        case 805:
            temp = ui_choice("What do you know about the cult?", "No questions, Major.", "/", "/");
            if (temp == 0)
                current = 809;
            if (temp == 1)
                current = 804;
            break;
        case 806:
            temp = ui_choice("What's so special about Oklahoma City?", "No questions, Major.", "/", "/");
            if (temp == 0)
                current = 815;
            if (temp == 1)
                current = 804;
            break;
        case 807:
            temp = ui_choice("How did you meet Rafe?", "No questions, Major.", "/", "/");
            if (temp == 0)
                current = 810;
            if (temp == 1)
                current = 804;
            break;
        case 808:
            temp = ui_choice("What's so special about Oklahoma City?", "No questions, Major.", "/", "/");
            if (temp == 0)
                current = 812;
            if (temp == 1)
                current = 804;
            break;
        case 809:
            temp = ui_choice("No questions, Major.", "/", "/", "/");
            if (temp == 0)
                current = 804;
            break;
        case 810:
            temp = ui_choice("No questions, Major.", "/", "/", "/");
            if (temp == 0)
                current = 804;
            break;
        case 811:
            temp = ui_choice(" What do you know about the cult?", "No questions, Major.", "/", "/");
            if (temp == 0)
                current = 813;
            if (temp == 1)
                current = 804;
            break;
        case 812:
            temp = ui_choice("No questions, Major.", "/", "/", "/");
            if (temp == 0)
                current = 804;
            break;
        case 813:
            temp = ui_choice("No questions, Major.", "/", "/", "/");
            if (temp == 0)
                current = 804;
            break;
        case 814:
            temp = ui_choice("How did you meet Rafe? ", "No questions, Major.", "/", "/");
            if (temp == 0)
                current = 816;
            if (temp == 1)
                current = 804;
            break;
        case 815:
            temp = ui_choice("No questions, Major.", "/", "/", "/");
            if (temp == 0)
                current = 804;
            break;
        case 816:
            temp = ui_choice("No questions, Major.", "/", "/", "/");
            if (temp == 0)
                current = 804;
            break;
        case 817:
            ui_continu_choice(win_men);
            current = 818;
            break;
        case 818:
            ui_continu_choice(win_men);
            current = 819;
            break;
        case 819:
            temp = ui_choice("Adjusting the precision bezel", "/", "/", "/");
            if (temp == 0)
                current = 820;
            char4 = "Team Alpha";
            break;
        case 820:
            temp = ui_choice("It's rare to see a Major in the field.", "Marksman 1, reporting.", "/", "/");
            if (temp == 0)
                current = 822;
            if (temp == 1)
                current = 821;
            break;
        case 821:
            temp = ui_choice("Give an account of the forces involved.", "/", "/", "/");
            if (temp == 0)
                current = 823;
            break;
        case 822:
            temp = ui_choice("Give an account of the forces involved.", "/", "/", "/");
            if (temp == 0)
                current = 823;
            break;
        case 823:
            temp = ui_choice("We are clearly in numerical advantage on this operation, why try to be so careful.", "You can quickly neutralize groups, Tango 2 and Alpha. Their formations are tight.", "/", "/");
            if (temp == 0)
                current = 825;
            if (temp == 1)
                current = 824;
            break;
        case 824:
            temp = ui_choice("Observe building windows.", "/", "/", "/");
            if (temp == 0)
                current = 826;
            break;
        case 825:
            temp = ui_choice("Observe building windows.", "/", "/", "/");
            if (temp == 0)
                current = 826;
            break;
        case 826:
            temp = ui_choice("875 meters away.", "/", "/", "/");
            if (temp == 0)
                current = 875;
            break;
        case 827:
            temp = ui_choice("1850 meters away.", "850 meters away.", "/", "/");
            if (temp == 0)
                current = 829;
            if (temp == 1)
                current = 828;

            char4 = "Marksman 2";
            break;
        case 828:
            temp = ui_choice("900 meters away.", "1200 meters away.", "1800 meters away.", "/");
            if (temp == 0)
                current = 830;
            if (temp == 1)
                current = 831;
            if (temp == 2)
                current = 832;
            break;
        case 829:
            temp = ui_choice("900 meters away.", "1200 meters away.", "1800 meters away.", "/");
            if (temp == 0)
                current = 830;
            if (temp == 1)
                current = 831;
            if (temp == 2)
                current = 832;

            char4 = "Team Alpha";
            break;
        case 830:
            temp = ui_choice("Continue.", "/", "/", "/");
            if (temp == 0)
                current = 838;
            break;
        case 831:
            temp = ui_choice("If we succeed, what's next?", "Why not just get the weapons back?", "/", "/");
            if (temp == 0)
                current = 833;
            if (temp == 1)
                current = 834;
            break;
        case 832:
            temp = ui_choice("Continue.", "/", "/", "/");
            if (temp == 0)
                current = 838;
            break;
        case 833:
            temp = ui_choice("Dallas is even better guarded than Lawton, you really do have a plan.", "So you plan to occupy Lawton?", "/", "/");
            if (temp == 0)
                current = 835;
            if (temp == 1)
                current = 836;
            break;
        case 834:
            temp = ui_choice("So you plan to occupy Lawton?", "Dallas is even better guarded than Lawton, you really do have a plan.", "/", "/");
            if (temp == 0)
                current = 836;
            if (temp == 1)
                current = 835;
            break;
        case 835:
            temp = ui_choice("Choice", "/", "/", "/");
            if (temp == 0)
                current = 837;
            break;
        case 836:
            temp = ui_choice("I don't see any reinforcements at the moment, everything is quiet.", "/", "/", "/");
            if (temp == 0)
                current = 837;

            char4 = "Team Alpha";
            break;
        case 837:
            temp = ui_choice("Continue.", "/", "/", "/");
            if (temp == 0)
                current = 838;
            break;
        case 838:
            temp = ui_choice("Enter the room.", "/", "/", "/");
            if (temp == 0)
                current = 839;
            break;
        case 839:
            temp = ui_choice("What's on your mind, Evelynn?", "I heard you were eating again.", "/", "/");
            if (temp == 0)
                current = 841;
            if (temp == 1)
                current = 840;
            break;
        case 840:
            temp = ui_choice("I miss him too.", "So why did you join them?", "/", "/");
            if (temp == 0)
                current = 842;
            if (temp == 1)
                current = 843;
            break;
        case 841:
            temp = ui_choice("What I understood was that it was more dangerous than I could have imagined.", "Yes, but because of him Rafe is dead. No matter the beautiful promises and sighs.", "/", "/");
            if (temp == 0)
                current = 844;
            if (temp == 1)
                current = 845;
            break;
        case 842:
            temp = ui_choice("I would like you to answer some of my questions, Eve.", "/", "/", "/");
            if (temp == 0)
                current = 846;
            break;
        case 843:
            temp = ui_choice("I would like you to answer some of my questions, Eve.", "/", "/", "/");
            if (temp == 0)
                current = 846;
            break;
        case 844:
            temp = ui_choice("I would like you to answer some of my questions, Eve.", "/", "/", "/");
            if (temp == 0)
                current = 846;
            break;
        case 845:
            temp = ui_choice("I would like you to answer some of my questions, Eve.", "/", "/", "/");
            if (temp == 0)
                current = 846;
            break;
        case 846:
            temp = ui_choice("Have you ever met the Great Preacher?", "The Great Preacher has a real name?", "/", "/");
            if (temp == 0)
                current = 847;
            if (temp == 1)
                current = 849;
            break;
        case 847:
            temp = ui_choice("Does he or she have a name other than the one you give him or her?", "/", "/", "/");
            if (temp == 0)
                current = 848;
            break;
        case 848:
            temp = ui_choice("I confess that all of this is completely beyond me.", "/", "/", "/");
            if (temp == 0)
                current = 851;
            break;
        case 849:
            temp = ui_choice("Wait, but what does he or she look like?", "/", "/", "/");
            if (temp == 0)
                current = 900;
            break;
        case 850:
            temp = ui_choice("I confess that all of this is completely beyond me.", "/", "/", "/");
            if (temp == 0)
                current = 851;
            break;
        case 851:
            temp = ui_choice("Leave the place.", "/", "/", "/");
            if (temp == 0)
                current = 852;
            break;
        case 852:
            temp = ui_choice("Start a new day.", "/", "/", "/");
            if (temp == 0)
            {
                els_is_exit = 666;
                els_is_win = 1;
                current = -1;
            }
            break;

        }
        after_event_clear(win_env, win_men);
    }
}

void pe_event_100()	/* Maxence */
{
    int current = 0;
    int temp;
    char* char0 = "Maxence";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/100", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Sorry, I prefer to play Detroit Become Human.", "I don't understand, are you selling me something?", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
                current = 2;
            break;
        case 1:
            ui_continu_choice(win_men);
            current = -1;
            break;
        case 2:
            temp = ui_choice("Sorry, I prefer to play Detroit Become Human.", "Why not. It's on my way.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
            {
                current = 3;
                en_add_passenger(char0, inventory->pa_count);
            }
            break;
        case 3:
            ui_continu_choice(win_men);
            current = -1;
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void pe_event_101()	/* Fake Axel */
{
    int current = 0;
    int temp;
    char* char0 = "Axel";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/101", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("No way, it breaks my balls. Goodbye!", "I'm on my way to the East, buddy. I can take you there.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
            {
                current = 2;
                en_add_passenger(char0, inventory->pa_count);
            }
            break;
        case 1:
            ui_continu_choice(win_men);
            {
                current = -1;
                if (inventory->money > 0)
                    en_mod_money(-25);
            }
            break;
        case 2:
            ui_continu_choice(win_men);
            current = -1;
            break;
        }

        after_event_clear(win_env, win_men);
    }
}

void pe_event_103()	/* Cosmo */
{
    int current = 0;
    int temp;
    char* char0 = "Cosmo";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/103", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("You're not going anywhere with me, pal.", "I wanted to go for a chimichanga in Albuquerque, that's a good thing. Come on in.", "/", "/");
            if (temp == 0)
                current = 1;
            if (temp == 1)
            {
                current = 2;
                en_add_passenger(char0, inventory->pa_count);
            }
            break;
        case 1:
            ui_continu_choice(win_men);
            current = -1;
            break;
        case 2:
            ui_continu_choice(win_men);
            current = -1;
        }

        after_event_clear(win_env, win_men);
    }
}

void pe_event_106()	/* Road Blocked */
{
    int current = 0;
    int temp;
    char* char0 = "/";
    char* char1 = "/";
    char* char2 = "/";
    char* char3 = "/";
    char* char4 = "/";
    char* char5 = "/";

    while (current >= 0)
    {
        ui_print_dial(win_env, current, ev_w, "event/principal/106", char0, char1, char2, char3, char4, char5);

        switch (current)
        {
        case 0:
            temp = ui_choice("Keep driving.", "/", "/", "/");
            if (temp == 0)
                current = -1;
            break;
        }

        after_event_clear(win_env, win_men);
    }
}
