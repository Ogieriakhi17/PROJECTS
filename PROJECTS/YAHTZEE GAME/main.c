/*Name: Osaze Ogieriakhi
Class: CptS 121 Fall 2022
Task: Programming Assignment #5
Date: 10.17.2022
Description: This program is the games of "Yahtzee". It is programmed with a concept that 
			there is one function "play_game()" which is designed to play one round of 
			the popular game using a number of other functions created in this project. This 
			main game function is then called repeatedly in by another function "round_control()"
			which controls the playing of rounds of the game.
*/

#include "yahtzee.h"


int main(void)
{
	srand((unsigned int)time(NULL));
	int choice = 0;
	do {
		do
		{
			main_menu();
			choice = get_input();
		} while (choice < RULES || choice > EXIT);

		switch (choice)
		{
		case 1: system("cls");
			print_game_rules();
			system("pause");
			system("cls");
			break;
		case 2: system("cls");
			printf("YOU'RE NOW PLAYING YAHTZEE\n\n");
			round_control();
			system("cls");
			break;
		case 3: printf("See ya next time!!");
			break;
		}
	} while (choice != EXIT);

	return 0;
}