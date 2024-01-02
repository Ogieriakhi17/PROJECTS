/*Name: Osaze Ogieriakhi
Class: CptS121 Fall 2022
Task: Programming Assignment #6
Description: This program is designed to play the game of "Battleship"
*/

#include "battleship1.h"

int main(void)
{
	srand((unsigned int)time(NULL));
	int choice = 0, win1 = 0, win2 = 0, starter = 0,
		hits1 = 0, miss1 = 0, shots1 = 0,
		hits2 = 0, miss2 = 0, shots2 = 0;
	char P1board[ROW_SIZE][COL_SIZE], P2board[ROW_SIZE][COL_SIZE];
	Stats p1stats = {0}; Stats p2stats = {0};
	FILE* outfile = fopen("battleship1.log", "w");


	initialize_game_board(P1board);
	initialize_game_board(P2board);

	welcome_screen();
	system("pause");
	system("cls");

	starter = select_who_starts_first();
	do {
		printf("Do you want to randomly or manually place the ships on the board?\n");
		printf("Randomly(1) or Manually(2)\n");
		scanf("%d", &choice);
	} while (choice != 1 && choice != 2);

	if (choice == 2)
	{
		manually_place_ships(P1board);
		printf("Player 1's board.\n");
		print_board(P1board, 10, 10);
	}
	if (choice == 1)
	{
		randomly_place_ship(P1board);
		printf("Player 1's board.\n");
		print_board(P1board, 10, 10);
	}
	

	system("pause");
	system("cls");


	if (starter == 1)
	{		
		randomly_place_ship(P2board);

		while (win1 == 0 && win2 == 0)
		{
		
			user_take_shot(P2board, outfile);
			printf("Player 2's board\n");
			print2_board(P2board, 10, 10);
			

			comp_take_shot(P1board, outfile);
			printf("Player 1's board\n");
			print_board(P1board, 10, 10);
			system("pause");
			system("cls");
			win1 = is_winner(P1board);
			win2 = is_winner(P2board);

			if (win1 == 1)
			{
				printf("Player 2 won.\n");
			}
			if (win2 == 1)
			{
				printf("Player 1 won\n");
			}
		}
	}

	else 
	{	
		randomly_place_ship(P2board);

		while (win1 == 0 && win2 == 0)
		{

			comp_take_shot(P1board, outfile);
			printf("Player 1's board\n");
			print_board(P1board, 10, 10);

			user_take_shot(P2board, outfile);
			printf("Player 2's board\n");
			print2_board(P2board, 10, 10);
			
			
			system("pause");
			system("cls");



			win1 = is_winner(P1board);
			win2 = is_winner(P2board);

			if (win1 == 1)
			{
				printf("Player 2 won.\n");
			}
			if (win2 == 1)
			{
				printf("Player 1 won\n");
			}
		}

	}

	p1stats = stats_checker(P2board);
	p2stats = stats_checker(P1board);

	output_stats(outfile, p1stats);
	output_stats(outfile, p2stats);

	fclose(outfile);
	return 0;
}