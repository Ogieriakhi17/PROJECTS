/*Name: Osaze Ogieriakhi
Class: CptS 121 Fall 2022
Task: Programming Assignment #4
Date: 10.03.2022
Description: This program is the games of "Craps"
*/

#include "craps.h"


/*
Description: This function is designed to print out the main menu of the game

Precondition: The function has no preconditions

Postcondition:After the function is called, it prints the menu of craps.
*/
void main_menu(void)
{
	printf("WELCOME TO CRAPS!!!\n");
	printf("1. Display the rules\n");
	printf("2. Play the game!\n");
	printf("3. Exit.\n");
}

/*
Description: This function is designed to print out the rules of the game

Precondition:The function has no preconditions

Postcondition: After the function is called, it prints the rules of craps
*/
void print_game_rules(void)
{
	printf("Here are the rules!!\n");
	printf("You get to roll two dice, each having six sides numbered 1-6.");
	printf("After the dice are rolled, the sum of the two are calculated.");
	printf("If the sum of the first roll is 7 or 11, congrats!! you win!\n");
	printf("If the sum is 2,3, or 12... CRAPS!! you lose.\n");
	printf("If the sum is 4,5,6,8,9,10 on the first throw, then that becomes your point.\n");
	printf("To win, you must keep rolling until you make your point.");
	printf("But beware, you lose if you roll a 7 before then.\n");
	printf("HAVE FUN!!!\n\n");
}

/*
Description: This function is designed to get the input from the user

Precondition: No precondtion must be met before the exectution of this function.

Postcondition: After the function is called, it scans in the input and returns it to the calling function 
*/
int get_input(void)
	{
	int choice = 0;
	scanf("%d", &choice);
	return choice;
	}


/*
Description: This function is designed to prompt and accept the bank balance from the user of the game 

Precondition: The user must input a float.

Postcondition: After the input is accepted the function returns the input
*/
double get_bank_balance(void)
{
	double bank_balance = 0.0;

	printf("Please enter your bank balance:");
	scanf("%lf", &bank_balance);
	return bank_balance;
}

/*
Description: This finction is designed to prompt and accept ammount 
			they wish to wager 

Precondition:A float must be inputted by the user.

Postcondition: The function returns the input to the calling function
*/
double get_wager_amount(void)
{
	double wager = 0.0;

	printf("Please enter the amount you wish to wage:");
	scanf("%lf", &wager);
	return wager;
}


/*
Description: This function is designed to check if the amount the user wants
			to wager is below or equal to their bank balance

Precondition: Two doubles must be passed into the function.

Postcondition: After the determination if the wager is valid 0 is returned
			if not, 1 is returned.
*/
double check_wager_amount(double wager, double balance)
{
	if (wager <= balance)
	{
		return 0; //it is valid
	}
	else
	{
		return 1;  // it isnt valid
	}
}

/*
Description:This function is designed to generate a random number between 1-6

Precondition: This function has no preconditions

Postcondition: It reutrns a random number to the calling function 
*/
int roll_die(void)
{
	return (rand() % 6 + 1);
}

/*
Description: This function is designed to calculate the sum of two dice values

Precondition: Two integer values must be passed into the function 

Postcondition: After the calculation the function returns the sum
*/
int calc_dice_sum(int die1, int die2)
{
	int sum_dice = 0;
	sum_dice = die1 + die2;
	return sum_dice;
}

/*
Description: This function is designed to determine whether a players roll is 
			a win, loss, or poin value

Precondition: The sum of the dice roll must be passed into the funtion as arguments

Postcondition: It returns 1 if the player won, 0 if they lost, or -1 if that is the point value
*/
int is_win_loss_or_point(int sum_dice)
{
	if (sum_dice == 7 || sum_dice == 11)
	{
		return 1; //player has won
	}
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		return 0; // player has lost
	}
	else
	{
		return -1; // their point value
	}
}

/*
Description: This function is designed to determine whether a player wins, loses,
			or neither i.e they have not gotten their point value on subsequent rolls

Precondition: The sum of the present roll and the point value must be passed in

Postcondition: The function returns 0 if they lose, or -1 if they havent gotten their 
			point value 
*/
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	if (sum_dice == 7)
	{
		return 0;  //the player has lost
	}
	else
	{
		return -1; // they keep rolling 
	}
}

/*
Description: This function is designed to determine if the user's bank balance is subtracted 
			or added to based on the outcome of the game.

Precondition: The function uses the output from the "is_point_loss_neither" function 

Postcondition: 0 is returned if the wager is meant to be subtracted from the bank balance
			and 1 if they won and their wager is added to their balance.
*/
int add_or_subtract(is_point_loss_or_neither)
{
	if (is_point_loss_or_neither == 0)
	{
		return 0;    //the player lost and would lose money
	}
	else if (is_point_loss_or_neither == -1)
	{
		return 1;  //the player won and would win money 
	}
}


/*
Description: This function is designed to adjust the bank balance of the user 
			acording to the outcome of the game.

Precondition: The bank balance, wager amount, and the output of the "add_or_subtract"
			must be passed into this function.

Postcondition: After evaluation the function returns the new balance.
*/
double adjust_bank_balance(double bank_balance, double wager_amount,
	int add_or_subtract)
{
	double new_balance = 0.0;

	if (add_or_subtract == 0)
	{
		new_balance = bank_balance - wager_amount;
		return new_balance;
	}
	else if (add_or_subtract == 1)
	{
		new_balance = bank_balance + wager_amount;
	}
	return new_balance;
}

/*
Description: This function is designed to print message to the screen throughout the game

Precondition: This function is dependent on the number of rolls of the user, whether they
			win or lose 

Postcondition: When the a condition is met, an appropriate message is printed to the screen.
*/
void chatter_messages(int number_rolls, int win_loss_neither,
	double initial_bank_balance, double current_bank_balance)
{
	if (number_rolls == 1 && win_loss_neither == 1)
	{
		printf("On the first try, youre a pro!!\n");
	}
	if (number_rolls == 1 && win_loss_neither == 0)
	{
		printf("CRAPS! you lost. better luck next time\n");
	}
	if (number_rolls == 3)
	{
		printf("dont stop now...\n");
	}
	if (number_rolls == 5 && win_loss_neither == -1)
	{
		printf("still?? just keep going you'll win big\n");
	}
	if (current_bank_balance < initial_bank_balance)
	{
		printf("less that you came with, that's tough.\n");
	}
	if (number_rolls == 10)
	{
		printf("if you wager a lot more, you might win\n");
	}
	if (number_rolls > 5 && win_loss_neither == 0)
	{
		printf("after all that you still lost?? you must be really unlucky :(\n");
	}
	if (number_rolls > 5 && win_loss_neither == 1)
	{
		printf("Finally success!!\n");
	}
}

/*
Description: This the main game function.

Precondition: No precondtion is needed for this function

Postcondition: The function has no post condions.
*/
void play_game(void)
{
	
	double initial_bank_balance = 0.0, wager = 0.0, current_bank_balance = 0;

	initial_bank_balance = get_bank_balance();
	current_bank_balance = initial_bank_balance;

		int die1 = roll_die(), die2 = roll_die(), sum = 0, point_value = 0;
		do
		{
			wager = get_wager_amount();
		}
		while (check_wager_amount(wager, current_bank_balance));
		sum = calc_dice_sum(die1, die2);
		printf("Die I rolled %d  Die II rolled %d. Your sum is %d\n", die1, die2, sum);
		int result = is_win_loss_or_point(sum);
		int num_rolls = 1;
		
		if (result == -1)
		{
			point_value = sum;
			do
			{
				do
				{
					wager = get_wager_amount();
				} while (check_wager_amount(wager, current_bank_balance));
				die1 = roll_die();
				die2 = roll_die();
				num_rolls += 1;
				sum = calc_dice_sum(die1, die2);
				printf("Die I rolled %d  Die II rolled %d. Your sum is %d\n", die1, die2, sum);
				chatter_messages(num_rolls, -1, initial_bank_balance, current_bank_balance);
				
			} while (sum != point_value && sum != 7);
		
			if (sum == 7)
			{
				printf("you lost\n");
				current_bank_balance = adjust_bank_balance(current_bank_balance, wager, 0);
				printf("You came out with $%.1lf\n\n", current_bank_balance);
			}
			else
			{
				printf("YOU WON!!\n");
				current_bank_balance = adjust_bank_balance(current_bank_balance, wager, 1);
				printf("You cashed out with $%.1lf\n\n", current_bank_balance);
			}
		} else
		
		{
			if (result == 1)
			{
				printf("YOU WON!!!\n");
				current_bank_balance = adjust_bank_balance(current_bank_balance, wager, 1);
				chatter_messages(num_rolls, 1, initial_bank_balance, current_bank_balance);
				printf("You cashed out with $%.1lf\n\n", current_bank_balance);
			}
			else
			{
				printf("you lost.\n");
				current_bank_balance = adjust_bank_balance(current_bank_balance, wager, 0);
				chatter_messages(num_rolls, 0, initial_bank_balance, current_bank_balance);
				printf("You came out with $%.1lf\n\n", current_bank_balance);
			}
		}
}