/*Name: Osaze Ogieriakhi
Class: CptS121 Fall 2022
Task: Programming Assignment #6
Description: This program is designed to play the game of "Battleship"
*/


#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ROW_SIZE 10
#define COL_SIZE 10

typedef struct stats
{
	int num_hits;
	int num_misses;
	int num_shots;
	int hit_to_miss;
}Stats;

/*---------------------------------------------------------------------------------*
Name: WELCOME_SCREEN

Description:This function is designed to display the welcome page of the game.

Precondtions: None

Postconditions:It displays the menu function
*---------------------------------------------------------------------------------*/
void welcome_screen(void);

/*---------------------------------------------------------------------------------*
Name:INITIALIZE_GAME_BOARD

Description:This function is designed to initialize the gameboard and fill it
		with the character "-"

Precondtions: A 2D array must be passed into the function.

Postconditions: It populates an array with -
*---------------------------------------------------------------------------------*/
char initialize_game_board(char board[ROW_SIZE][COL_SIZE]);
/*---------------------------------------------------------------------------------*
Name: SELECT_WHO_STARTS_FIRST

Description: This function is designed to randomly select who goes first in the game

Precondtions: None

Postconditions:It returns a 1 or 2 representing Player 1 or 2.
*---------------------------------------------------------------------------------*/
int select_who_starts_first(void);

/*---------------------------------------------------------------------------------*
Name:MANUALLY_PLACE_SHIP

Description:this function is designed to prompt the user to input the coordinates
			they wish to place their ships

Precondtions:NONE

Postconditions:It accepts and checks the coordinates then makes a copy and returns.
*---------------------------------------------------------------------------------*/
int manually_place_ships(char board[][COL_SIZE]);

/*---------------------------------------------------------------------------------*
Name:RANDOMLY_PLACE_SHIP

Description:This function is designed to randomly generate coordinates and place
		the ships on the board.

Precondtions:NONE

Postconditions:It places the ships on the board
*---------------------------------------------------------------------------------*/
int randomly_place_ship(char board[][COL_SIZE]);

/*---------------------------------------------------------------------------------*
Name:PRINT_BOARD

Description:This function is designed to display the board of the game

Precondtions:A 2D array along with its row and column size is needed as parameters

Postconditions:It displays the boards to the user
*---------------------------------------------------------------------------------*/
void print_board(char board[][COL_SIZE], int num_rows, int num_cols);

/*---------------------------------------------------------------------------------*
Name:PRINT2_BOARD

Description:This function is designed to print out the board of the CPU and hides 
			the locations of the ships

Precondtions:The 2D array and the number of its rows and columns

Postconditions:The board is displayed to the screen.
*----------------------------------------------------------------------------------*/
void print2_board(char board[][COL_SIZE], int num_rows, int num_cols);

/*---------------------------------------------------------------------------------*
Name:PLACE_SHIP

Description:This  function is designed to replace places on the board with the
			markers for the different ships

Precondtions:A 2D array, the x and y coordinates along with the desired direction
			are needed to be passed into the function

Postconditions:It places the ships on the board.
*---------------------------------------------------------------------------------*/
void place_ship(char board[][COL_SIZE], int x, int y, char ship, char dir);

/*---------------------------------------------------------------------------------*
Name:BOUNDARY_CHECK

Description:This function is to check whether the coordinated entered for a ship
			inbounds of the board

Precondtions:The intended coordinates and the ship size are needed.

Postconditions:It returns a 1 or 0.
*---------------------------------------------------------------------------------*/
int boundary_check(int x, int y, int ship_size);

/*---------------------------------------------------------------------------------*
Name:OVERLAP_CHECK

Description:This function is designed to check whether a ship's placement overlaps
			with a ship that has already been placed.

Precondtions: The x,y coordinates, the board, the ship size and direction are
			parameters

Postconditions:IT returns a 1 or 0.
*---------------------------------------------------------------------------------*/
int overlap_check(int x, int y, char board[][10], int ship_size, char direction);

/*---------------------------------------------------------------------------------*
Name:CHECK_SHOT

Description:This function is designed to check whether a shot was a hit or miss

Precondtions:The coordinates of the shot and the board are needed.

Postconditions:It returns a 1, 0, or -1 after execution.
*---------------------------------------------------------------------------------*/
int check_shot(char board[][COL_SIZE], int x, int y);

/*---------------------------------------------------------------------------------*
Name:UPDATE_BOARD

Description:This function is designed to update the board after a shot has  been
			taken.

Precondtions:The coordinates of the shot and the board are needed.

Postconditions:It replaces the character on the boarding corresponding to the shot
			taken.
*---------------------------------------------------------------------------------*/
char update_board(char board[][COL_SIZE], int x, int y);

/*---------------------------------------------------------------------------------*
Name:CHECK_IF_SHIP_SUNK

Description:This function is designed to see whether a ship has been sunk

Precondtions:The board and the ship it is checking for are needed as parameters

Postconditions:It returns a 1 or 0.
*---------------------------------------------------------------------------------*/
int check_if_sunk_ship(char board[][COL_SIZE], char ship);

/*---------------------------------------------------------------------------------*
Name:COMP_TAKE_SHOT

Description:This function is programmed to randomly let the computer take shot at
			the other players ships

Precondtions:Only the board is need as a parameter

Postconditions:NONE
*---------------------------------------------------------------------------------*/
void comp_take_shot(char board[][COL_SIZE], FILE* outfile);

/*---------------------------------------------------------------------------------*
Name:USER_TAKE_SHOT

Description:This functon is designed to take prompt and accept coordinates for where
			the user wishes to fire

Precondtions: The board is the only parameter.

Postconditions: NONE
*---------------------------------------------------------------------------------*/
void user_take_shot(char board[][COL_SIZE], FILE *outfile);

/*---------------------------------------------------------------------------------*
Name:OUTPUT_CURRENT_MOVE

Description:This function is designed to output the moves of each player to the
			screen and logfile

Preconditions:An output file that has already been opened is needed for the function

Postconditions:NONE
*---------------------------------------------------------------------------------*/
void output_current_move(int x, int y, int try, FILE* outfile, int player);

/*---------------------------------------------------------------------------------*
Name:OUTPUT_STATS

Description:This function is designed to return the statistics of a player after
			the game of battleship

Precondtions:An output file and a struct must be passed as arguments

Postconditions:The function returns a struct Stats
*----------------------------------------------------------------------------------*/
Stats output_stats(FILE* outfile, Stats player);
/*---------------------------------------------------------------------------------*
Name:IS_WINNER

Description:This functon is written to determine the if a player has won by checking
			if all the ship have been sunk or not

Precondtions:A board must be passed in for as an argument

Postconditions:It returns a 1 or 0.
*----------------------------------------------------------------------------------*/
int is_winner(char board[][COL_SIZE]);

/*---------------------------------------------------------------------------------*
Name:STATS_CHECKER

Description:This function is designed to check and evaluate the statistics of a 
			player after a game

Precondtions: A board must be passed in for examination.

Postconditions: It returns a struct.
*----------------------------------------------------------------------------------*/
Stats stats_checker(char board[][COL_SIZE]);
#endif 


