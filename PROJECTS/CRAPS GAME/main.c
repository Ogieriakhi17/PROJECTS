/*Name: Osaze Ogieriakhi
Class: CptS 121 Fall 2022
Task: Programming Assignment #4
Date: 10.03.2022
Description: This program is the games of "Craps"
*/

#include "craps.h"


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
	case 1: print_game_rules();
		break;
	case 2: printf("You are now playing the game\n");
		play_game();
		break;
	case 3: printf("Goodbye");
		break;
	}
} while (choice != EXIT);

return 0;
}