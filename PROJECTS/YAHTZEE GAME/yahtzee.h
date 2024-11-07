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


#ifndef YAHTZEE_H
#define YAHTZEE_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>




#define RULES 1
#define PLAY 2
#define EXIT 3

/*******************************************************************************************
Name: void main_menu

Description: This function is designed to print out the main menu of the game

Precondition: The function has no preconditions

Postcondition:After the function is called, it prints the menu of yahtzee.
********************************************************************************************/
void main_menu(void);

/*******************************************************************************************
Name: print_game_rules

Description: This function is designed to print out the rules of the game

Precondition:The function has no preconditions

Postcondition: After the function is called, it prints the rules of yahtzee
********************************************************************************************/
void print_game_rules(void);

/*******************************************************************************************
Name: get_input

Description: This function is designed to get the input from the user

Precondition: No precondtion must be met before the exectution of this function.

Postcondition: After the function is called, it scans in the input and returns it to the calling function
********************************************************************************************/
int get_input(void);

/*******************************************************************************************
Name: roll_die

Description:This function is designed to generate a random number between 1-6

Precondition: This function has no preconditions

Postcondition: It returns a random number to the calling function
*******************************************************************************************/
int roll_die(void);

/******************************************************************************************
Name: print_array

Description: This funtion is designed to print an array of integers 

Precondition: An array and its size must be provided.

Postcondition:None
******************************************************************************************/
void print_array(int array[], int size);

/******************************************************************************************
Name: round_control

Description: This function is designed to control the rounds in the yahtzee game 

Precondition: None

Postcondition: None
******************************************************************************************/
void round_control(void);

/******************************************************************************************
Name: freq_table

Description: This function finds the number of times a number occurs in a set of rolls

Precondition:It needs to be provided with two arrays

Postcondition:It returns the the frequency evaluated.
*****************************************************************************************/
int freq_table(int array[], int freq_tab[]);

/***************************************************************************************
Name: score_combination_choice 

Description: This is a function designed to prompt the user and determine the scoring 
type a user wishes to use 

Precondition: None

Postcondition: None
***************************************************************************************/
int score_combination_choice(int dice_array[], int checker_array[]);

/***************************************************************************************
Name: four_of_kind

Description: This is a function desingned to judge if a dice roll has a three of a kind

Precondition: An array must be passed into the function

Postcondition: It returns a 1 or 0.
***************************************************************************************/
int four_of_a_kind(int dice_array[]);

/**************************************************************************************
Name: sum_ones

Description:This function evaluates the sum of 1 in a dice roll

Precondition: None 

Postcondition:None
**************************************************************************************/
int sum_ones(int dice_array[]);


/**************************************************************************************
Name: sum_twos

Description:This function evaluates the sum of 2 in a dice roll

Precondition:  None 

Postcondition:None
**************************************************************************************/
int sum_twos(int dice_array[]);


/**************************************************************************************
Name: sum_threes

Description: This function evaluates the sum of 3 in a dice roll

Precondition: None

Postcondition: None
**************************************************************************************/
int sum_threes(int dice_array[]);

/**************************************************************************************
Name:sum_fours

Description:This function is designed to sum find of fours in a array of
		dice rolls.

Precondition:An array must be passed into the function for evaluation 

Postcondition:It returns the sum as an integer 
**************************************************************************************/
int sum_fours(int dice_array[]);

/**************************************************************************************
Name:sum_fives

Description:This function is designed to sum find of fives in a array of
		dice rolls.

Precondition:An array must be passed into the function for evaluation

Postcondition:It returns the sum as an integer
**************************************************************************************/
int sum_fives(int dice_array[]);

/**************************************************************************************
Name:sum_sixes

Description:This function is designed to sum find of sixes in a array of
		dice rolls.

Precondition:An array must be passed into the function for evaluation

Postcondition:It returns the sum as an integer
***************************************************************************************/
int sum_sixes(int dice_array[]);

/**************************************************************************************
Name: three_of_a_kind

Description: This is a function desingned to judge if a dice roll has a three of a kind

Precondition: An array must be passed into the function 

Postcondition: It returns a 1 or 0.
**************************************************************************************/
int three_of_a_kind(int dice_array[]);

/**************************************************************************************
Name: full_house

Description: This function is designed to evaluate whether or not a dice array 
		has a full house

Precondition:A dice array must be passed into the function

Postcondition:It returns a 1 for true or 0 for false.
**************************************************************************************/
int full_house(int dice_array[]);

/**************************************************************************************
Name: small_straight

Description: This function is designed to evaluate whether or not a dice array
		has a small_straight

Precondition:A dice array must be passed into the function

Postcondition:It returns a 1 for true or 0 for false.
**************************************************************************************/
int small_straight(int dice_array[]);

/**************************************************************************************
Name: play_game

Description: This the main game function It designed to play one round of 
		the game yahtzee.

Precondition: No precondtion is needed for this function

Postcondition: The function after running on round returns the score from that round
**************************************************************************************/
int play_game(int checker_array[]);

#endif 