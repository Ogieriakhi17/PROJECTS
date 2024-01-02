/*NAME: Osaze Ogieriakhi
 CLASS: CptS 121 Fall 2022
 TASK: Programming Assignment #7
 DESCRIPTION: This programmed to simulate the game of 5-Card Draw Poker.
 DATE: 11.12.2022
 */

#include "poker.h"


void welcome_menu(void)
{
	printf("\n********5-CARD-DRAW POKER**********\n");
	printf("1. Display the rules\n");
	printf("2. Play the game!\n");
	printf("3. Exit.\n");
}


int get_input(void)
{
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void print_rules(void)
{
	printf("These are the rules for 5-Card-Draw Poker\n");
	printf("Each player is dealt 5 cards from the deck\n");
	printf("After cards have been dealt ");
	printf("each player has the choice to discard up to three of their cards; after");
	printf("which they would be replaced.\n");
	printf("The player with a better hands wins the game\n");
}


/* shuffle cards in deck */
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
Hand deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int num_cards, int start_pt)
{

	Hand temp_hand;
	int row = 0;    /* row number */
	int column = 0; /*column number */
	//int num_cards = 0;   /* card counter */
	int start = 0, hand_index = 0;
	/* deal the ammount of cards passed */
	for (start = start_pt; start < start_pt + num_cards; start++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == start)
				{

					//printf("here.");
					temp_hand.card_array[hand_index].face_value = column;
					temp_hand.card_array[hand_index].suit = row;
					//printf("%d\n\n\n", column);

				}
			}
		}
		hand_index += 1;
	}
	//printf("%d\n\n\n", temp_hand.card_array[1].face_value);
	return temp_hand;
}

int replace_card(int array[])
{
	int replacement = 0, index = 0, choice = 0, amount = 0, cards[5] = {0};
		
	for (index = 0; index < 5; ++index)
	{
		printf("do you want to replace card %d?\n", index);
		printf("enter 1. yes or 2. no\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			array[index] = 1;
			++amount;
		}
		if (amount == 3)
		{
			break;
		}
	}
}

int pair_check(Hand variable)
{
	int frequency[13] = {0}, counter = 0;

	//this is to check throught the players hand and find occurrences of cards
	for (int index = 0; index < 5; ++index)
	{
		++frequency[variable.card_array[index].face_value];
	}

	for (int index = 0; index < 13; ++index)
	{
		if (frequency[index] == 2)
		{
			counter++;
		}
	}

	if (counter == 1)
	{
		return 1; // the players hand had ONE pair
	}

	if (counter == 2)
	{
		return 2; //the player had TWO pairs
	}

	return 0;
}

int check_flush(Hand variable)
{
	int frequency[4] = {0};

	for (int index = 0; index < 5; ++index)
	{
		++frequency[variable.card_array[index].suit];
	}

	for (int index = 0; index < 5; ++index)
	{
		if (frequency[index] == 5)
		{
			return 1; //there is a flush
		}
	}
	return 0; //there wasnt a flush
}

int four_of_a_kind(Hand variable)
{
	int frequency[13] = {0};

	for (int index = 0; index < 5; ++index)
	{

		++frequency[variable.card_array[index].face_value];
	}

	for (int index = 0; index < 13; ++index)
	{
		if (frequency[index] == 4)
		{
			return 1;  //the players hand contains a four of a kind
		}
	}

	return 0;
}

int three_of_a_kind(Hand variable)
{
	int frequency[13] = {0};

	for (int index = 0; index < 5; ++index)
	{
		++frequency[variable.card_array[index].face_value];
	}

	for (int index = 0; index < 13; ++index)
	{
		if (frequency[index] == 3)
		{
			return 1;  //the players hand contains a three of a kind
		}
	}

	return 0;
}

int full_house(Hand variable)
{
	int frequency[13] = {0}, threes = 0, pair = 0;

	for (int index = 0; index < 5; ++index)
	{
		++frequency[variable.card_array[index].face_value];
	}

	for (int index = 0; index < 14; ++index)
	{
		if (frequency[index] == 3)
		{
			threes++;
		}
		if (frequency[index] == 2)
		{
			pair++;
		}
	}

	if (threes >= 1 && pair >= 1)
	{
		return 1; //this means there is a full house
	}

	else return 0;
}

int straight_check(Hand variable)
{
	int frequency[13] = {0}, count = 0;

	for (int index = 0; index < 5; ++index)
	{
		++frequency[variable.card_array[index].face_value];
	}

	for (int index = 0; index < 14; ++index)
	{
		if (frequency[index] == 1)
		{
			count++; //this is to check if a face value exist in the hand
		}
		else count = 0; //if the next face value doesnt appear, the counter resets to 0
	}

	if (count == 5)
	{
		return 1; // they player has a straight
	}
	return 0;
}

void print_hand(Hand variable)
{

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	for (int index = 0; index < 5; ++index)
	{
		printf("%d. %s of %s\n", index, face[variable.card_array[index].face_value], suit[variable.card_array[index].suit]);
		
	}
}

int precedence_check(Hand variable)
{
	int rank = 0;

	if (pair_check(variable) == 1)
	{
		rank = 1;
	}

	if (pair_check(variable) == 2)
	{
		rank = 2;
	}

	if (three_of_a_kind(variable) == 1)
	{
		rank = 3;
	}


	if (check_flush(variable) == 1)
	{
		rank = 4;
	}

	if (full_house(variable) == 1)
	{
		rank = 5;
	}

	if (four_of_a_kind(variable) == 1)
	{
		rank = 6;
	}

	if (straight_check(variable) == 1)
	{
		rank = 7;
	}

	return rank;
}

int comp_intel(Hand variable)
{
	int replacement = 0;
	int cpu_card_rank = precedence_check(variable);

	if (cpu_card_rank < 3)
	{
		replacement = 3;
	}
	if (cpu_card_rank < 6 && cpu_card_rank > 3)
	{
		replacement = 2;
	}

	if (cpu_card_rank > 7)
	{
		replacement = 0;
	}

	return replacement;
}


void play_game(void)
{
	printf("You are now playing the game\n");
	int decision = 0;

	do //this loop is so the user can play as much they want 
	{
		Hand user_hand, comp_hand, temp_hand;
	int cards_dealt = 0, replacement = 0, choice = 0, player_card_rank = 0, cpu_card_rank = 0,
		replaced[5] = { 0 };

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	shuffle(deck);
	printf("you were dealt:\n");
	user_hand = deal(deck, face, suit, 5, 1);
	print_hand(user_hand);

	comp_hand = deal(deck, face, suit, 5, 6);
	cards_dealt = 10; //this is to keep track of how many cards have been dealt
	printf("would you like to relpace any cards? yes(1) or no(2)\n");
	scanf("%d", &choice);

	if (choice == 1)
	{
		replace_card(replaced);

		for (int j = 0; j < 5; ++j)
		{
			if (replaced[j] == 1)
			{
				replacement++;
			}
		}

		temp_hand = deal(deck, face, suit, 5, cards_dealt);
		cards_dealt = 15 + 1;
		//temp_hand = deal(deck, face, suit, replacement, cards_dealt);

		for (int index = 0; index < 5; ++index)
		{
			if (replaced[index] == 1)
			{
				user_hand.card_array[index] = temp_hand.card_array[index];
				cards_dealt += 1;
			}
		}
		print_hand(user_hand);
	}
	
	cpu_card_rank = precedence_check(comp_hand);
	
		replacement = comp_intel(comp_hand);
		if (replacement != 0)
		{
			temp_hand = deal(deck, face, suit, replacement, cards_dealt);
			printf("The dealer swapped %d card(s)\n", replacement);
			for (int index = 0; index < replacement; ++index)
			{
				comp_hand.card_array[index] = temp_hand.card_array[index];
				cards_dealt += 1;
			}
		}


	player_card_rank = precedence_check(user_hand);
	
	cpu_card_rank = precedence_check(comp_hand);
	

	if (player_card_rank > cpu_card_rank)
	{
		printf("Player 1 won!!\n");
	}

	if (cpu_card_rank > player_card_rank)
	{
		printf("The Dealer won.\n");
	}

	if (cpu_card_rank == player_card_rank)
	{
		printf("It was a tie, GGs\n");
	}

	printf("do you want to play again? 1.yes or  2.no\n");
	scanf("%d", &decision);
	system("cls");
	} while (decision != 2);
}


