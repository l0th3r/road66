/* LIBS */
#include "../../includes.h"

void empty() {}

void pe_event_1();
void pe_event_2();

int who_is_alive = 0;

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
				temp = ui_choice("Ask information to the organizer.", "Leave.","/", "/");                  
                if(temp == 0)
                    current = 410;
                if(temp == 1)
                    current = 403;
			break;
			case 403:
				temp = ui_choice("Yes.", "No, I have ever been to Las Vegas.", "/", "/");                  
                if(temp == 0)
                    current = 404;
                if(temp == 1)
                    current = 407;
			break;
			case 404:
				temp = ui_choice("I don't know.", "Play in a casino.", "Maybe have a date with you.", "Something like tropical holidays, a house or whatever.");                  
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
                if(temp == 0)
                    current = 412;
                if(temp == 1)
                    current = 414;
				if(temp == 2)
                    current = 423;
			break;
            case 412:
				temp = ui_choice("Let's fight.", "Negotiate.", "It sounds shit. Thank you, still.", "/");
                if(temp == 0)
                    current = 600;
                if(temp == 1)
                    current = 602;
				if(temp == 2)
                    current = 413;
			break;
            case 413:
                if(inventory->money > 0)
                    choice3_temp = "Bet.";
                else
                    choice3_temp = "/";
                temp = ui_choice("Leave the room.", "Stay.", "Let's fight.", choice3_temp);
                if(temp == 0)
                    current = 900;
                if(temp == 1)
                    current = 611;
				if(temp == 2)
                    current = 600;
                if(temp == 3)
                    current = 414;
			break;
            case 414:
				temp = ui_choice("Angel.", "Tyler.", "/", "/");
                if(temp == 0) 
                {
                    fighter_bet = "Angel";
                    current = 415;
                }
                if(temp == 1)
                {
                    fighter_bet = "Tyler";
                    current = 416;
                }
			break;
            case 415:   /* identique au 416 */
                current = 417;
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
                    if (inventory->money == 0)
                        current = 418;
                    if (inventory->money < 50)
                        money_bet = inventory->money;
                    else if (inventory->money >= 50)
                        money_bet = 50;

                if (temp == 1)
                    money_bet = 100;
                if (temp == 2)
                    current = 418;
 
                en_mod_money(-money_bet);
			break;
           case 416:    /* identique au 415 */
                current = 417;
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
                    if (inventory->money == 0)
                        current = 418;
                    if (inventory->money < 50)
                        money_bet = inventory->money;
                    else if(inventory->money >= 50)
                        money_bet = 50;

                if (temp == 1)
                    money_bet = 100;
                if (temp == 2)
                    current = 418;
 
                inventory->money -= money_bet;
			break;
            case 417:
				ui_continu_choice(win_men);
                current = 500;
			break;
            case 418:
				temp = ui_choice("Yes explain me please.", "No, I don't want to fight.", "/", "/");
                if(temp == 0)
                    current = 414;
                if(temp == 1)
                    current = 413;
			break;
            case 419:
				temp = ui_choice("Let's fight.", "Negociate.", "It sounds shit. Thank you, still.", "/");
                if(temp == 0)
                    current = 600;
                if(temp == 1)
                    current = 602;
                if(temp == 2)
                    current = 413;
			break;
            case 420:
				temp = ui_choice("Leave the room.", "Stay.", "Let's fight.", "/");
                if(temp == 0)
                    current = 900;
                if(temp == 1)
                    current = 611;
                if(temp == 2)
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
                    current = 501;
                if (temp == 3)
                    current = 502;
			break;
            case 502:
				temp = ui_choice("Stay in touch!", "Take him away!", "Raise your guard!", "You can do it!");
                if (temp == 0 || temp == 1 || temp == 3)
                    current = 505;
                if (temp == 1)
                    current = 506;
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
                en_mod_money(+(money_bet * 2));
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
				temp = ui_choice("What?", "Gimme this shit.", "No thanks.", "/");
                if (temp == 0)
                    current = 603;
                if (temp == 2)
                    current = 604;
                if (temp == 3)
                    current = 605;
			break;
            case 602:
				temp = ui_choice("Let's fight for two hundred bucks.", "Four hundred bucks.", "/", "/");
                if (temp == 0)
                    current = 606;
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
                    current = 606;
                if (temp == 1)
                    current = 609;
			break;
            case 609:
				temp = ui_choice("I take the risk.", "Two hundred bucks is a good price finally.", "No, I said that I don't fight.", "/");
                if (temp == 0)
                    current = 608;
                if (temp == 1)
                    current = 606;
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
				temp = ui_choice("You try a short sequence of low-kick and high.", "Arch your leg behind his and use your shoulder to strike his chest.", "You step back, gain momentum and try to double dropkick.", "/");
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
                current = 617;
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
				temp = ui_choice("Arch your leg behind his and use your shoulder to strike his chest.", "You step back, gain momentum and try to double dropkick.", "Clinch Foreman and stamp his thoracic cavity.", "/");
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
                /* NEED GAME OVER */
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
                en_mod_money(+(money_bet * 2));
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
				ui_continu_choice(win_men);
                current = 801;
			break;
            case 801:
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    if (last_lost_machine_dial == 0)
                    {
                        current = 802;
                        en_mod_money(-10);
                    }
                    else
                        current = last_lost_machine_dial;
                }
                if (temp == 1)
                    current = 850;
			break;
            case 802:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 803;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;

                en_mod_money(+10);
			break;
            case 803:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 804;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
			break;
            case 804:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 805;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
			break;
            case 805:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 806;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
			break;
            case 806:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 807;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;

                en_mod_money(+10);
			break;
            case 807:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 808;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;

                en_mod_money(+50);
			break;
            case 808:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 809;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
			break;
            case 809:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 810;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
			break;
            case 810:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 811;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;

                en_mod_money(+10);
			break;
            case 811:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 812;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
			break;
            case 812:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 813;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
			break;
            case 813:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 814;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
			break;
            case 814:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 815;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;

                en_mod_money(+400);
			break;
            case 815:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 816;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
			break;
            case 816:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 817;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
			break;
            case 817:
				last_lost_machine_dial = (current + 1);
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 818;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;

                en_mod_money(+10);
			break;
            case 818:
                last_lost_machine_dial = 815;
				temp = ui_choice("Insert 10$.", "Leave.", "/", "/");
                if (temp == 0)
                {
                    current = 815;
                    en_mod_money(-10);
                }
                if (temp == 1)
                    current = 850;
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
                if (unlock_hostel == 1)
                    choice1_temp = "I want to sleep one night. Cost: 20$.";
                else if (unlock_exit_door == 1)
                    choice1_temp = "Leave the casino.";
                else choice1_temp = "/";

				temp = ui_choice("Enter the main room.", choice1_temp, "/", "/");
                if (temp == 0) 
                {
                    unlock_hostel = 1;
                    current = 900;
                }
                if (temp == 1)
                {
                    if (unlock_hostel == 1)
                    {
                        unlock_exit_door = 1;
                        current = 998;
                    }
                    else if (unlock_exit_door == 1)
                        current = 999;
                }
			break;
            case 998:
				ui_continu_choice(win_men);
                en_mod_money(-20);
                current = 902;
			break;
            case 999:
				ui_continu_choice(win_men);
                current = -1;
			break;
			}
        after_event_clear(win_env, win_men);
    }

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
    char* char5 = "Maxence";

    if(inventory->pa_count > 0)
        char4 = inventory->passengers[uf_random(inventory->pa_count)];

    while(current >= 0)
    {
        /* 2 = id d'event  */
        ui_print_dial(win_env, current, ev_w, "event/principal/2", char0, char1, char2, char3, char4, char5);

        switch(current)
		{
			case 0:
				if(uf_compare("Maxence") != -1)
                {
                    temp = ui_choice("Drop Maxence in Henderson City.", "/", "/", "/");
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
                /* NEED : remove Maxence from the bus */    
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
