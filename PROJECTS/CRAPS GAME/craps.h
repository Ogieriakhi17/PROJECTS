/*Name: Osaze Ogieriakhi
Class: CptS 121 Fall 2022
Task: Programming Assignment #4
Date: 10.03.2022
Description: This program is the games of "Craps"
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>




#define RULES 1
#define PLAY 2
#define EXIT 3

void main_menu(void);

void print_game_rules(void);

int get_input(void);

double get_bank_balance(void);

double get_wager_amount(void);

double check_wager_amount(double wager, double balance);

int roll_die(void);

int calc_dice_sum(int die1, int die2);

int is_win_loss_or_point(int sum_dice);

int is_point_loss_or_neither(int sum_dice, int point_value);

int add_or_subtract(is_point_loss_or_neither);

double adjust_bank_balance(double bank_balance, double wager_amount,
	int add_or_subtract);

void chatter_messages(int number_rolls, int win_loss_neither,
	double initial_bank_balance, double current_bank_balance);

void play_game(void);