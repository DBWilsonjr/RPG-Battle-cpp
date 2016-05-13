// RPGBattler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <time.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	system("color F1");

	//Variables
	string names[10] = {"", "", "Human", "Catfolk", "Simian", "Werewolf", "Warrior", "Archer", "Mage", "Priest"};
	string title = "a                      versus                   b";
	double stats[4][7] = {{300, 500, 8, 0, 0, 0, 0},
					  {200, 450, 11, 0, 0, 0, 0},
					  {250, 450, 10, 0, 0, 0, 0},
					  {350, 550, 7, 0, 0, 0, 0}};
	double rcHPSav = 0.0;
	double enemy[7] = {};
	string monCom[4] = {"The creature takes a swing!", "Your foe attacks from a distance.", "The beast unleashes mystical power!", "The monster's attack is filled with dark energy."};
	int plAtk[50] = {}, monAtk[50] = {};
	double plDam[50] = {}, monDam[50] = {};
	int race = 0, chCla = 0, monst = 0;
	int rndCnt = 0;
	bool fOver = false;
	char yesNo = 'y';

		//Program start
		srand (time(NULL));
		cout << "\t\t****************************************\n";
		cout << "\t\t**                Shitty              **\n";
		cout << "\t\t**              D&D Battler           **\n";
		cout << "\t\t**            (Don't sue me)          **\n";
		cout << "\t\t****************************************\n\n";
		//Make a Character
		cout << "Please give your character a name: ";
		getline(cin,names[0]);
		cout << "\n";
		do
		{
			cout << "\tPlease choose a race (1 - 5).\n\n\t1) Human\n\t2) Catfolk\n\t3) Monkey\n\t4) Werewolf\n\t5) Random Race" << endl;
			cin >> race;
			if (isdigit(race) != false)
			{
				cout << "You have made an invalid choice, please try again.\n";
				cin.clear(race);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				if (race > 4)
					race = rand() % 4 + 1;
			}
		}
		while (race < 1 || race > 4);
		cout << "You have chosen to be a " << names[race+1] << "." << endl;
		system("pause");
		do
		{
			cout << "Please choose a class (1 - 5).\n\n\t1) Warrior\n\t2) Archer\n\t3) Mage\n\t4) Priest\n\t5) Random Class" << endl;
			cin >> chCla;
			if (isdigit(chCla) != false)
			{
				cout << "You have made an invalid choice, please try again.\n";
				cin.clear(race);
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
			{
				if (chCla > 4)
					chCla = rand() % 4 + 1;
			}
		}
		while (chCla < 1 || chCla > 4);
		cout << "You have chosen to be a " << names[chCla+5] << "." << endl;
		system("pause");
		if (chCla == 1)
		{
			stats[race-1][0] = stats[race-1][0] + 250;
			stats[race-1][2] = stats[race-1][2] + 1;
			stats[race-1][3] = 1.35;
			stats[race-1][4] = 1.15;
			stats[race-1][5] = 0.7;
			stats[race-1][6] = 0.8;
		}
		else
			if (chCla == 2)
			{
				stats[race-1][0] = stats[race-1][0] + 150;
				stats[race-1][2] = stats[race-1][2] + 4;
				stats[race-1][3] = 0.9;
				stats[race-1][4] = 1.45;
				stats[race-1][5] = 0.75;
				stats[race-1][6] = 0.9;
			}
			else
				if (chCla == 3)
				{
					stats[race-1][0] = stats[race-1][0] + 50;
					stats[race-1][2] = stats[race-1][2] + 3;
					stats[race-1][3] = 0.7;
					stats[race-1][4] = 1;
					stats[race-1][5] = 1.45;
					stats[race-1][6] = 0.85;
				}
				else
				{
					stats[race-1][0] = stats[race-1][0] + 175;
					stats[race-1][2] = stats[race-1][2] + 2;
					stats[race-1][3] = 0.9;
					stats[race-1][4] = 0.9;
					stats[race-1][5] = 0.75;
					stats[race-1][6] = 1.45;
				}
		rcHPSav = stats[race-1][0];
		system("CLS");
		cout << "\tYou are " << names[0] << ", the " << names[race+1] << " " << names[chCla+5] << ". You live in a small village and serve as nightwatch. It's a mostly thankless job, but someone has to do it. This particular night has been especially quiet and you can't help but feel yourself starting to nod off.\n\tAn unusual noise behind you snaps you back to reality. You barely have time to turn and reach for your weapon before one of the forest creatures is upon you.\n\n" << endl;
		cout << "\tPrepare for battle!" << endl;
		system("pause");


	do
	{
		if (fOver == true)
		{
			rndCnt = 0;
			stats[race-1][0] = rcHPSav;
			fOver = false;
		}
		//Thank fuck that's over. Now we make a monster.
		monst = rand() % 5 + 1;
		if (monst == 1)
		{
			names[1] = "Minotaur";
			enemy[0] = 750;
			enemy[1] = 600;
			enemy[2] = 7;
			enemy[3] = 1.55;
			enemy[4] = 1.0;
			enemy[5] = 0.7;
			enemy[6] = 0.8;
		}
		else
			if (monst == 2)
			{
				names[1] = "Orc Pyromancer";
				enemy[0] = 450;
				enemy[1] = 600;
				enemy[2] = 10;
				enemy[3] = 1.85;
				enemy[4] = 0.85;
				enemy[5] = 1.45;
				enemy[6] = 0.9;
			}
			else
				if (monst == 3)
				{
					names[1] = "Lizard Necromancer";
					enemy[0] = 450;
					enemy[1] = 600;
					enemy[2] = 10;
					enemy[3] = 1.35;
					enemy[4] = 1.15;
					enemy[5] = 0.7;
					enemy[6] = 0.8;
				}
				else
					if (monst == 4)
					{
						names[1] = "Dark Knight";
						enemy[0] = 500;
						enemy[1] = 450;
						enemy[2] = 14;
						enemy[3] = 1.35;
						enemy[4] = 1.0;
						enemy[5] = 0.75;
						enemy[6] = 0.9;
					}
					else
						if (monst == 5)
						{
							names[1] = "Frisky Ooze";
							enemy[0] = 200;
							enemy[1] = 500;
							enemy[2] = 18;
							enemy[3] = 1.15;
							enemy[4] = 1.15;
							enemy[5] = 0.95;
							enemy[6] = 0.95;
						}
		

		//Now that we have a monster, let's start the fighting.
		title.replace(0,names[0].length(),names[0]);
		title.erase(48);
		title.replace(48,names[1].length(),names[1]);
		do
		{
			system("CLS");
			rndCnt++;
			cout << "\t\t****************************************\n";
			cout << "\t\t**                                    **\n";
			cout << "\t\t**             Round " << rndCnt << "                **\n";
			cout << "\t\t**                                    **\n";
			cout << "\t\t****************************************\n\n";
			cout << "\t" << title << endl;
			cout << "\tHP: " << stats[race-1][0]<< "\t\t\t\t\t\tHP: " << enemy[0]<< "\n\n";
			cout << "\tDefeat the " << names[1] << " or die trying!\n" << endl;
			if (chCla == 1)
			{
				cout << "\tChoose an attack!\n\t1) Smash it with a hammer!\n\t2) Throw an axe!\n\t3) Conjure a flame!\n\t4) Channel divine might!\n";
				cin >> plAtk[rndCnt];
			}
			if (chCla == 2)
			{
				cout << "\tChoose an attack!\n\t1) Slash it with a sword!\n\t2) Shoot it with an arrow!\n\t3) Call down lightning from the sky!\n\t4) Call for aid from the forest creatures!\n";
				cin >> plAtk[rndCnt];
			}
			if (chCla == 3)
			{
				cout << "\tChoose an attack!\n\t1) Punch it with your bare hands!\n\t2) Fire a bolt from your staff!\n\t3) Blast it with eldritch might!\n\t4) Request aid from the gods!\n";
				cin >> plAtk[rndCnt];
			}
			if (chCla == 4)
			{
				cout << "\tChoose an attack!\n\t1) Whack it with your scepter!\n\t2) Throw a vial of holy water!\n\t3) Let loose a darker power!\n\t4) Release a ball of heavenly power!\n";
				cin >> plAtk[rndCnt];
			}
			if (rand() % 20 + 1 > (enemy[2]))
			{
				plDam[rndCnt] = floor(((stats[race-1][1] * stats[race-1][plAtk[rndCnt]+3]) / 10) / enemy[plAtk[rndCnt]+3]);
				enemy[0] = enemy[0] - plDam[rndCnt];
				cout << "You hit " << names[1] << " for " << plDam[rndCnt] << " damage!\n" << endl;
			}
			else
				cout << "You missed the " << names[1] << "!\n" << endl;
			monAtk[rndCnt] = rand() % 4 + 1;
			cout << monCom[monAtk[rndCnt]] << endl;
			if (rand() % 20 + 1 > (stats[race-1][2]))
			{
				monDam[rndCnt] = floor(((enemy[1] * enemy[monAtk[rndCnt]+3]) / 10) / stats[race-1][plAtk[rndCnt]+3]);
				stats[race-1][0] = stats[race-1][0] - monDam[rndCnt];
				cout << "The " << names[1] << " hit you for " << monDam[rndCnt] << " damage!\n" << endl;
			}
			else
				cout << "The " << names[1] << " missed you with its attack!\n" << endl;
			system("pause");
			if (enemy[0] < 0 || stats[race-1][0] < 0)
				fOver = true;
		}
		while (fOver == false);


		//End of this mess. Let's hope they don't want to play again since we still don't know how to fix the issue with naming yourself on the second run. Disregard that; I got around it by just running with the same character.
		if (fOver == true && stats[race-1][0] > 0)
			cout << "\nCongratulations! You were victorious!\n" << endl;
		else
			cout << "\nSorry, you lost this battle. Better luck next time.\n" << endl;
		cout << "Would you like to play again (y or n)?";
		cin >> yesNo;
	}
	while (yesNo == 'y' || yesNo == 'Y');


	//Exit program
	cout << "\n\tThanks for playing.\n";
	system("pause");
	return 0;
}