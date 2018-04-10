//Erick Cabanban 4/9/18

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

#define CORRECTCODE 1775

case 21:
{

	while(choice != 99)
	{
		int equipment = 0;
		int combatEvent = 0;
		int randomNumber = 0;
		int dead = 0;

		int HP = 10;
		int enemyHP = 10;
		int totalHP = 10;
		int totalEnemyHP = 10;

		//rifle, shotgun, grenade, 45 DMG
		int weaponDMG[4] = { 4, 6, 8, 5 };
		int attackDMG = 0;
		int weaponChoice = 0;

		//bite, claw, tail swipe DMG
		int enemyWeaponDMG[3] = { 6, 5, 6 };
		int enemyAttackDMG = 0;
		int randomEnemyChoice = 0;

		int inputedCode = 0;

		srand(time(NULL));

		puts("You see yellow footprints leading into Room #21 and you choose to open it");

		puts("As you close the door, red lights are blinking, and you hear \"ALL UNITS GET TO YOUR DESIGNATED EXITS, TAKE YOUR RIFLES OFF SAFETY, and LOCK n' LOAD!!\" ");
	       	puts("You have been transported to the Stallion 475-AXB Shock Transport above Planet Necrotix in Galaxy Traxor");
		puts("You are part of a Special Recon Unit with the specific mission to  destroy the Necrotin Queen Hive");
		
		
		puts("Choose your fate:");
		puts("Enter 1 for Shock Troop equipment");
		puts("Enter 2 for Stealth equipment");

		scanf("%d", &equipment);

		if(equipment == 1)
		{
			puts("You have a Rifle, Shotgun, 2 Hand Grenades, and a .45");

		}
		else if(equipment == 2)
		{
			puts("You have a silenced SMG, a silenced 9mm, 1 Smoke Grenade, 1 Flash Grenade, and a Knife");
		}
	
		switch(equipment)
		{

			case 1: // Shock troop
				
				puts("Get ready, your landing is emminent...");
				sleep(3);		
				puts("As the Space Craft lands, you are the first to put boots on ground and rush to the closest Necrotin");
				puts("You engage in combat with the Necrotin");

				puts("Choose a number between 1 - 3 which will decide whether you attack first, the Necrotin attacks first, or some random combat related incident happens");

				scanf("%d", &combatEvent);

					//int correctCode = 1775;
					//int inputedCode = 0;

				switch(combatEvent)
				{
				
					case 1:
					// random incident
						puts("The new guy shoots at the alien, unfortunately your head was in his line of sight...");
						dead = 1;
						break;

					case 2:
					
						// You attack first
						puts("Choose your weapon: 1) Rifle 2) Shotgun");
						scanf("%d", &weaponChoice);
							
						switch(weaponChoice)
						{
							case 1:
								// rifle
								while(1)
								{
									//printf("weaponDMG[0] = %d\n", weaponDMG[0]);
									enemyHP = (rand() % weaponDMG[0]) + 1;
									//printf("enemyHP: %d\n", enemyHP);
									totalEnemyHP = totalEnemyHP - enemyHP;
									printf("You injured the Necrotin for %d HP\n", enemyHP);
									printf("The Necrotin has %d HP left!\n", totalEnemyHP);
									if(totalEnemyHP < 0)
									{
										puts("You slayed the beast, now keep pushing to the Hive!");
										break;
									}
									
									randomEnemyChoice = ( rand() % 2 );
									HP = (rand() % enemyWeaponDMG[randomEnemyChoice]) + 1;
									totalHP = totalHP - HP;
									printf("The Necrotin injured you for %d HP\n", HP);
									printf("You have %d HP left!\n", totalHP);
									
									if(totalHP < 0)
									{
										puts("GG your alien food...");
										dead = 1;
										break;
									}	

							
								}
								break;
						
							case 2:
						
								// shotgun
								while(1)
								{
									enemyHP = (rand() % weaponDMG[1]) + 1;
									totalEnemyHP = totalEnemyHP - enemyHP;
									printf("You injured the Necrotin for %d HP\n", enemyHP);
									printf("The Necrotin has %d HP left!\n", totalEnemyHP);
									if(totalEnemyHP < 0 )
									{
										puts("You slayed the beast, now keep pushing to the Hive!");
										break;
									}
									randomEnemyChoice = ( rand() % 2 );
									HP = (rand() % enemyWeaponDMG[randomEnemyChoice]) + 1;
									totalHP = totalHP - HP;
									printf("The Necrotin injured you for %d HP\n", HP);
									printf("You have %d HP left!\n", totalHP);

									if(totalHP < 0)
									{
										puts("GG your alien food...");
										dead = 1;
										break;
									}

								}
								break;
						}
						break;

					case 3:
			
						// Necrotin attacks first
						while(1)
						{
							randomEnemyChoice = ( rand() % 2 );
							HP = (rand() % enemyWeaponDMG[randomEnemyChoice]) + 1;
							totalHP = totalHP - HP;
							printf("The Necrotin injured you for %d HP\n", HP);
							printf("You have %d HP left!\n", totalHP);
							if(totalHP < 0)
							{
								puts("GG your alien food...");
								dead = 1;
								break;
							}

							enemyHP = (rand() % weaponDMG[0]) + 1i; // surprise attack! use rifle
						        totalEnemyHP = totalEnemyHP - enemyHP;
							printf("You injured the Necrotin for %d HP\n", enemyHP);
							printf("The Necrotin has %d HP left!\n", totalEnemyHP);
							if(totalEnemyHP < 0)
							{
								puts("You slayed the beast, now keep pushing towards the Hive!");
								break;
							}	
						}
						break;
				}
				break;

			case 2: // sneaky sneaky mission

				puts("Get ready, your landing is emminent...");
				sleep(3);

				puts("With your badass Predator like cloaking suit you are able to rush past hordes of Necrotin and plant C5 explosive charges inside one of there underground tunnels");
				puts("As you start to enter the detonation code, some atmospheric distubance disrupts your cloacking shield and your stealth suit goes offline...");
				puts("You are surrounded on all sides and have no chance of escape");
				puts("However, you still have time to find out what year the Marine Corps was founded and input those 4 last digits to initiate the C5's...");

				scanf("%d", &inputedCode);
				if(inputedCode == CORRECTCODE)
				{
					puts("You blew up a major enemy reinforcement tunnel, sacrificed yourself and prevented many friendly casualties... You're a hero.");
				}
				else
				{
					puts("You failed, and many friendlies died. But I don't blame you... I blame your senior drill instructor.");
				}
				dead = 1;

				break;

		} // end of switch	
		

		// GAME CONTINUES  AFTER INITIAL ACTION EVENT
		if(dead == 1)
		{
			puts("GAME OVER");
		}
		else
		{
			puts("As you continue to rush towards the hive, you get completely surrounded and you and your team shoot it out till the very..");
		}
		break;
		
	} // end of while

	
} // end of case
