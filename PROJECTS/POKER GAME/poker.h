/*
 NAME: Osaze Ogieriakhi
 CLASS: CptS 121 Fall 2022
 TASK: Programming Assignment #7
 DESCRIPTION: This programmed to simulate the game of 5-Card Draw Poker.
 DATE: 11.12.2022
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct card
{
	int face_value;
	int suit;
}Card;

typedef struct hand
{
	Card card_array[5];

}Hand;

/*------------------------------------------------------------------------------------*
NAME:WELCOME_MENU

DESCRIPTION: This function is designed to simulate the main menu for the program

PARAMETERS: NONE

POSTCONDITIONS:NONE
*-------------------------------------------------------------------------------------*/
void welcome_menu(void);

/*------------------------------------------------------------------------------------*
NAME:GET_INPUT

DESCRIPTION: This function is designed to get the input form the user from the menu

PARAMETERS:NONE

POSTCONDITIONS:It reutrns the choice of the user as an integer
*-------------------------------------------------------------------------------------*/
int get_input(void);

/*------------------------------------------------------------------------------------*
NAME:PRINT_RULES

DESCRIPTION: This function is designed to print the rules of the game to the screen

PARAMETERS:NONE

POSTCONDITIONS:NONE
*-------------------------------------------------------------------------------------*/
void print_rules(void);

/*------------------------------------------------------------------------------------*
NAME: SHUFFLE

DESCRIPTION:This function is prgrammed to shuffle a the 52 cards of the deck

PARAMETERS:NONE

POSTCONDITIONS:After execution the function randomly fills an 2D array representing
			the cards
*------------------------------------------------------------------------------------*/
void shuffle(int wDeck[][13]);

/*------------------------------------------------------------------------------------*
NAME:DEAL

DESCRIPTION:This function is desgined to deal the amount of cards designed to a hand

PARAMETERS:A part from the card arrays, the number of cards needed to be dealt is needed

POSTCONDITIONS:NONE
*------------------------------------------------------------------------------------*/
Hand deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int num_cards, int start_pt);

/*------------------------------------------------------------------------------------*
NAME:REPLACE_CARD

DESCRIPTION:This function is desgined to prompt and check the amount of cards a player 
			wants to replace 

PARAMETERS:NONE

POSTCONDITIONS:NONE
*------------------------------------------------------------------------------------*/
int replace_card(int array[]);

/*------------------------------------------------------------------------------------*
NAME:PAIR_CHECK

DESCRIPTION:This function is desgined to check if a player's hand contains a pair or 
			two pairs

PARAMETERS:A Hand struct is needed to be passed as an argument

POSTCONDITIONS:It returns a 1 if true or 0 if false 
*------------------------------------------------------------------------------------*/
int pair_check(Hand variable);

/*------------------------------------------------------------------------------------*
NAME:CHECK_FLUSH

DESCRIPTION:This function is desgined to check if a player's hand contains a flush

PARAMETERS:A Hand struct is needed to be passed as an argument

POSTCONDITIONS:It returns a 1 if true or 0 if false 
*------------------------------------------------------------------------------------*/
int check_flush(Hand variable);

/*------------------------------------------------------------------------------------*
NAME:FOUR_OF_A_KIND

DESCRIPTION:This function is desgined to check if a player's hand contains a four of a
			kind.

PARAMETERS:A Hand struct is needed to be passed as an argument

POSTCONDITIONS:It returns a 1 if true or 0 if false 
*------------------------------------------------------------------------------------*/
int four_of_a_kind(Hand variable);

/*------------------------------------------------------------------------------------*
NAME:THREE_OF_A_KIND

DESCRIPTION:This function is desgined to check if a player's hand contains three of a
			kind

PARAMETERS:A Hand struct is needed to be passed as an argument

POSTCONDITIONS:It returns a 1 if true or 0 if false 
*------------------------------------------------------------------------------------*/
int three_of_a_kind(Hand variable);

/*------------------------------------------------------------------------------------*
NAME:STRAIGHT_CHECK

DESCRIPTION:This function is desgined to check if a player's hand contains a straight

PARAMETERS:A Hand struct is needed to be passed as an argument

POSTCONDITIONS:It returns a 1 if true or 0 if false 
*------------------------------------------------------------------------------------*/
int straight_check(Hand variable);

/*------------------------------------------------------------------------------------*
NAME:FULL_HOUSE

DESCRIPTION:This function is desgined to check if a player's hand contains a full house

PARAMETERS:A Hand struct is needed to be passed as an argument

POSTCONDITIONS:It returns a 1 if true or 0 if false 
*------------------------------------------------------------------------------------*/
int full_house(Hand variable);

/*------------------------------------------------------------------------------------*
NAME:PRINT_HAND

DESCRIPTION: This function is desgined to print out the hand a player

PARAMETERS:A Hand struct must be passed into the function 

POSTCONDITIONS:NONE
*------------------------------------------------------------------------------------*/
void print_hand(Hand variable);

/*------------------------------------------------------------------------------------*
NAME:PRECEDENCE_CHECK

DESCRIPTION:This function is desgned to find out whihc players hand has a higher	
			presidence

PARAMETERS:A Hand struct must be passed a parameter

POSTCONDITIONS:It returns an integer
*------------------------------------------------------------------------------------*/
int precedence_check(Hand variable);

/*------------------------------------------------------------------------------------*
NAME:COMP_INTEL

DESCRIPTION:This is a function designed to make the computer more intelligent in 
			swapping cards to get a better combination

PARAMETERS:It needs the computer's hand to evaluate. 

POSTCONDITIONS: It reutrns an integer
*------------------------------------------------------------------------------------*/
int comp_intel(Hand variable);

/*------------------------------------------------------------------------------------*
NAME:PLAY_GAME

DESCRIPTION:This function is designed to simulate the game of 5-Card-Draw Poker

PARAMETERS:NONE

POSTCONDITIONS:NONE
*-------------------------------------------------------------------------------------*/
void play_game(void);


/*------------------------------------------------------------------------------------*
NAME:

DESCRIPTION:

PARAMETERS:

POSTCONDITIONS:
*------------------------------------------------------------------------------------*/