/*NAME: Osaze Ogieriakhi
 CLASS: CptS 121 Fall 2022
 TASK: Programming Assignment #7
 DESCRIPTION: This programmed to simulate the game of 5-Card Draw Poker.
 DATE: 11.12.2022
 */


#include "poker.h"
int main(void)
{
	int choice = 0;

	do {
		do
		{
			welcome_menu();
			choice = get_input();
		} while (choice < 1 || choice > 3);

		switch (choice)
		{
		case 1: system("cls");
			print_rules();
			system("pause");
			system("cls");
			break;
		case 2:
			system("pause");
			system("cls");
			play_game();
			break;
		case 3: printf("Goodbye");
			break;
		}
	} while (choice != 3);



	return 0;
}