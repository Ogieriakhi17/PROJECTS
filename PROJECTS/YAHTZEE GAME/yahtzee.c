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



void main_menu(void)
{
	printf("WELCOME TO YAHTZEE!!!\n");
	printf("1. Display the rules\n");
	printf("2. Play the game!\n");
	printf("3. Exit.\n");
}
/**********************************************************************/

void print_game_rules(void)
{
	printf("Here are the rules\n");
	printf("You can roll 5 dice a max of 3 times a round for a total of 13 rounds.\n");
	printf("After rolling you then choose the what combination you want to be scored in\n");
	printf("There are 13 scoring combinations which you can choose from each round\n");
	printf("After you select a combination it cant be used again\n");
	printf("Your points are summed up from each round to determine your total\n\n");

}
/************************************************************************/

int get_input(void)
{
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
/***********************************************************************/

int roll_die(void)
{
	return (rand() % 6 + 1);
}
/**********************************************************************/


void print_array(int array[], int size)
{
	int temp_list[6] = { 0 };
	printf("You rolled\n");
	printf(">>[");
	for (int index = 0; index < size; index++)
	{
		printf(" %d,", array[index]);
	}

	printf("]\n");
}
/******************************************************************************/

void round_control(void)
{
	int player1_scr_arr[14]; int player2_scr_arr[14];
	int player1_score = 0, player2_score = 0, player1_round = 0, player2_round = 0;
	int rounds = 14;
	int player1_temp_score = 0, player2_temp_score = 0, bonus1 = 0, bonus2 = 0;


	for (int index = 0; index < rounds; ++index)
	{
		player1_scr_arr[index] = -1;
		player2_scr_arr[index] = -1;
	}

	for (int index = 0; index < rounds; ++index)
	{
		printf("IT'S PLAYER 1'S TURN\n");
		player1_score = play_game(player1_scr_arr);
		printf("player 1 scored %d\n", player1_score);
		player1_temp_score += player1_score;
		printf("Player 1's score is now %d\n", player1_temp_score);
		system("pause");
		system("cls");

		printf("IT'S PLAYER 2'S TURN\n");
		player2_score = play_game(player2_scr_arr);
		printf("player 2 scored %d\n", player2_score);
		player2_temp_score += player2_score;
		printf("Player 2's score is now %d\n", player2_temp_score);
		system("pause");
		system("cls");

		player1_round++;
		player2_round++;

	}

	system("pause");
	system("cls");

	for (int index = 0; index < 7; ++index) 
	{
		int bonus1 =+ player1_scr_arr[index];
	}
	return bonus1;

	if (bonus1 >= 63)//this is for the bonus points of player 1
	{
		player1_temp_score = player1_temp_score + 35;
	}


	for (int index = 0; index < 7; ++index)
	{
		int bonus2 = +player2_scr_arr[index];
	}
	return bonus2;

	if (bonus2 >= 63)//this is for the bonus points of player 2
	{
		player2_temp_score = player2_temp_score + 35;
	}
	
	if (player1_temp_score > player2_temp_score)
	{
		printf("<<<<PLAYER 1 WINS!!!>>>>\n");
	}

	else if (player1_temp_score < player2_temp_score)
	{
		printf("<<<<PLAYER 2 WINS!!!>>>>\n");
	}

	else if (player1_temp_score == player2_temp_score)
	{
		printf("IT WAS TIE!! GGs!");
	}
}
/*****************************************************************************************/

int freq_table(int dice[], int freq_tab[])
{
	
	for (int index = 0; index < 5; ++index)
	{
		
		freq_tab[dice[index]]++;

	}
	
}
/**************************************************************************************/


int score_combination_choice(int array[], int checker_array[])
{
	
	int choice = 0;
	printf("<<<<WHAT COMBINATION DO YOU WISH TO USE?>>>>\n");
	printf("> 1. SUM OF 1'S\n");
	printf("> 2. SUM OF 2'S\n");
	printf("> 3. SUM OF 3'S\n");
	printf("> 4. SUM OF 4'S\n");
	printf("> 5. SUM OF 5'S\n");
	printf("> 6. SUM OF 6'S\n");
	printf("> 7. THREE-OF-A-KIND\n");
	printf("> 8. FOUR-OF-A-KIND\n");
	printf("> 9. FULL HOUSE\n");
	printf("> 10. SMALL STRAIGHT\n");
	printf("> 11. LARGE STRAIGHT\n");
	printf("> 12. ****YAHTZEE*****\n");
	printf("> 13. ------CHANCE------\n");
	printf("\n>>>");

	scanf(" %d", &choice);
	while (choice < 1 || choice > 13 || checker_array[choice] != -1) //this os checking if the player has already used that combination 
	{
		printf("<<<<WHAT COMBINATION DO YOU WISH TO USE?>>>>\n");
		scanf(" %d", &choice);

	}


	return choice;
}

/************************************************************************************************/

int three_of_a_kind(int dice_array[])
{
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);

	for (int index = 0; index < 7; index++)
	{
		if (frequency[index] >= 3)
		{
			return 1;
		}
	}

	return 0;
}
/***********************************************************************************************/

int four_of_a_kind(int dice_array[])
{
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);
	
	for (int index = 0; index < 7; index++)
	{
		if (frequency[index] >= 4)
		{
			return 1;
		}
	}
	
	return 0;
}
/************************************************************************************************/

int full_house(int dice_array[])
{
	int frequency[7] = { 0 }; int counter_three = 0, counter_two = 0;
	freq_table(dice_array, frequency);

	for (int index = 0; index < 7; index++)
	{
		if (frequency[index] == 3 )
		{
			counter_three++;
		}
		if (frequency[index] == 2)
		{
			counter_two++;
		}
	}

	if (counter_two == 1 && counter_three == 1)
	{
		return 1;
	}

	return 0;
}
/******************************************************************************************/


int small_straight(int dice_array[])
{
	int counter = 0;
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);

	for (int index = 0; index < 7; ++index)
	{
		if (frequency[index] >= 1)
		{
			counter++;
			if (counter >= 4)
			{
				return 1;
			}
		}
		else counter = 0;
	}
	return 0;

}
/*****************************************************************************************/

int large_straight(int dice_array[])
{
	int counter = 0;
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);

	for (int index = 0; index < 7; ++index)
	{
		if (frequency[index] >= 1)
		{
			counter++;
			if (counter >= 5)
			{
				return 1;
			}
		}
		else counter = 0;
	}
	return 0;

}
/**********************************************************************************************/

int yahtzee(int dice_array[])
{
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);

	for (int index = 0; index < 7; index++)
	{
		if (frequency[index] >= 5)
		{
			return 1;
		}
	}

	return 0;
}
/**********************************************************************************************/

int sum_twos(int dice_array[])
{
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);
	int sum = frequency[2] * 2;
	return sum;
}
/***********************************************************************************************/

int sum_ones(int dice_array[])
{
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);
	int sum = frequency[1] * 1;
	return sum;
}
/***********************************************************************************************/

int sum_threes(int dice_array[])
{
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);
	int sum = frequency[3] * 3;
	return sum;
}
/***********************************************************************************************/

int sum_fours(int dice_array[])
{
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);
	int sum = frequency[4] * 4;
	return sum;
}
/***********************************************************************************************/

int sum_fives(int dice_array[])
{
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);
	int sum = frequency[5] * 5;
	return sum;
}
/***********************************************************************************************/

int sum_sixes(int dice_array[])
{
	int frequency[7] = { 0 };
	freq_table(dice_array, frequency);
	int sum = frequency[6] * 6;
	return sum;
}
/***********************************************************************************************/

int chance_score(int dice_array[])
{
	int sum = 0;
	for (int index = 0; index < 5; ++index)
	{
		sum += dice_array[index];
	}
	return sum;
}
/***********************************************************************************************/

int play_game(int checker_array[])
{

	system("pause");



	int dice[5] = {0}, choice = 0, roll_choice = 0, count = 0, index = 0, num_rolls = 0;
	int comb = 0, score = 0;

	for (int index = 0; index < 5; ++index)
	{
		dice[index] = roll_die();
	}
	print_array(dice, 5);
	++num_rolls;
	printf("Do you want to roll again. Yes(1) or No(2)?");
	scanf("%d", &choice);

	if (choice == 1)
	{
		
		while (num_rolls < 3 && choice == 1)
		{
			printf("Which dice would you like to re-roll?");
			scanf("%d", &choice);
			dice[choice - 1] = roll_die();
			print_array(dice, choice);
			++num_rolls;
			if (num_rolls == 3)
			{
				break;
			}
			printf("Do you want to re-roll Yes(1) or No(2)\n");
			scanf("%d", &choice);
			
		}

	}

		comb = score_combination_choice(dice, checker_array);


		switch (comb)
		{
		case 1: score = sum_ones(dice);
			checker_array[1] = score;
			return score;
			break;
		case 2: score = sum_twos(dice);
			checker_array[2] = score;
			return score;
			break;
		case 3: score = sum_threes(dice);
			checker_array[3] = score;
			return score;
			break;
		case 4:score = sum_fours(dice);
			checker_array[4] = score;
			return score;
			break;
		case 5:score =  sum_fives(dice);
			checker_array[5] = score;
			return score;
			break;
		case 6:score = sum_sixes(dice);
			checker_array[6] = score;
			return score;
			break;
		case 7:if (three_of_a_kind(dice) == 1)
		{
			int score = 0;
			for (int index = 0; index < 6; ++index)
			{
				score += dice[index];
			}
			checker_array[7] = score;
			return score;
		}
			  else printf("you didnt have a three-of-a-kind\n");
			checker_array[7] = score;
			return 0;
			break;
		case 8: if (four_of_a_kind(dice) == 1)
		{
			int score = 0;
			for (int index = 0; index < 6; ++index)
			{
				score += dice[index];
			}
			checker_array[8] = score;
			return score;
		}
			  else  printf("you didnt have a four-of-a-kind\n");
			checker_array[8] = score;
			return 0;
			break;

		case 9: if (full_house(dice) == 1)
		{
			checker_array[9] = score;
			return 25;
		}
			  else  printf("you didnt have a full house\n");
			checker_array[9] = score;
			return 0;
			break;

		case 10: if (small_straight(dice) == 1)
		{
			checker_array[10] = score;
			return 30;
		}
			   else  printf("you didnt have a small straight\n"); 
			checker_array[10] = score;
			return 0;
			break;

		case 11: if (large_straight(dice) == 1)
		{
			checker_array[11] = score;
			return 40;
		}
			   else printf("you didnt have a large straight\n");
			checker_array[11] = score;
			return 0;
			break;

		case 12: if (yahtzee(dice) == 1)
		{
			checker_array[12] = score;
			return 50;
		}
			   else printf("you didn't have yahtzee :(\n");
			checker_array[12] = score;
			return 0;
			break;

		case 13: score = chance_score(dice);
			checker_array[13] = score;
			return score;
			break;
		}
}