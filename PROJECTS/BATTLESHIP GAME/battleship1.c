/*Name: Osaze Ogieriakhi
Class: CptS121 Fall 2022
Task: Programming Assignment #6
Description: This program is designed to play the game of "Battleship"
*/

#include "battleship1.h"

void welcome_screen(void)
{
	printf("************WELCOME TO BATTLESHIP!!**************\n\n");
	printf("Rules of the Game\n");
	printf("1. This is a two player game\n");
	printf("2. Player 1 is you and player 2 is the computer\n");
	printf("3. You have 5 ships:\n");
	printf(">>>>>>>>>>the Carrier that spans 5 cells\n");
	printf(">>>>>>>>>>the Battleship that spans 4 cells\n");
	printf(">>>>>>>>>>the Cruiser & Submarine hving 3 cells each\n");
	printf(">>>>>>>>>>then finally the Destroyer of just 2 cells\n\n");
	printf("You can either choose to place your ships manually or randomly.\n");
	printf("Ships can be placed horizontally or vertically, not diagonally\n");
	printf("Whoever sinks all the enemy ships wins\n");
}

char initialize_game_board(char board[ROW_SIZE][COL_SIZE])
{
	int rows = 0, columns = 0;

	for (rows = 0; rows < 10; ++rows)
	{
		for (columns = 0; columns < 10; ++columns)
		{
			board[rows][columns] = '~';
		}
	}

}

int select_who_starts_first(void)
{
	int choice = 0;
	choice = rand() % 2 + 1;
	printf("Player %d starts\n", choice);
	return choice;
}

void place_ship(char board[][COL_SIZE], int x, int y, char ship, char dir)
{
	if (ship == 'c')
	{
		if (dir == 'H')
		{
			for (int index = y; index < y + 5; ++index)
			{
				board[x][index] = 'c';
			}
		}

		else if (dir == 'V')
		{
			for (int index = x; index < x + 5; ++index)
			{
				board[index][y] = 'c';
			}
		}
	}

	if (ship == 'b')
	{
		if (dir == 'H')
		{
			for (int index = y; index < y + 4; ++index)
			{
				board[x][index] = 'b';
			}
		}
		else if (dir == 'V')
		{
			for (int index = x; index < x + 4; ++index)
			{
				board[index][y] = 'b';
			}
		}
	}


	if (ship == 'r')
	{
		if (dir == 'H')
		{
			for (int index = y; index < y + 3; ++index)
			{
				board[x][index] = 'r';
			}
		}
		else if (dir == 'V')
		{
			for (int index = x; index < x + 3; ++index)
			{
				board[index][y] = 'r';
			}
		}
	}


	if (ship == 's')
	{
		if (dir == 'H')
		{
			for (int index = y; index < y + 3; ++index)
			{
				board[x][index] = 's';
			}
		}
		else if (dir == 'V')
		{
			for (int index = x; index < x + 3; ++index)
			{
				board[index][y] = 's';
			}
		}
	}


	if (ship == 'd')
	{

		if (dir == 'H')
		{
			for (int index = y; index < y + 2; ++index)
			{
				board[x][index] = 'd';
			}
		}
		else if (dir == 'V')
		{
			for (int index = x; index < x + 2; ++index)
			{
				board[index][y] = 'd';
			}
		}
	}
}

int boundary_check(int x, int y, int ship_size)
{

	int invalid = 0;

	if (x + ship_size > 10)
	{
		invalid = 1;
	}

	if (y + ship_size > 10)
	{
		invalid = 1;
	}

	return invalid; //if it is 1 it is out of bounds. if its 0 it is inbounds
}

int overlap_check(int x, int y, char board[][10], int ship_size, char direction)
{

	int invalid = 0;

	if (direction == 'H')
	{
		for (int index = y; index < y + ship_size; ++index)
		{
			if (board[x][index] != '~')
			{
				invalid = 1;
			}
		}
	}

	if (direction == 'V')
	{
		for (int index = x; index < x + ship_size; ++index)
		{
			if (board[index][y] != '~')
			{
				invalid = 1;
			}
		}
	}
	return invalid; //if 1 it is overlaps. if 0 it doesnt 
}

int manually_place_ships(char board[][COL_SIZE])
{
	int x = 0, y = 0, invalid = 0, overlap = 0;
	char direction = '\0';

	do
	{
		printf("Please enter the coordinates for the Carrier:\n");
		scanf("%d%c%d", &x, &direction, &y);
		printf("Which direction do you want it in? Horizontal(H) or Vertial(V)\n");
		scanf(" %c", &direction);


		if (x < 0 || y < 0 || y > 10 || x > 10)
		{
			invalid = 1;
		}

		if (x + 5 > 10) //horizontal check
		{
			invalid = 1;
		}

		if (y + 5 > 10)
		{
			invalid = 1;
		}

		if (!invalid)
		{
			place_ship(board, x, y, 'c', direction);
		}

	} while (invalid);

	print_board(board, 10, 10);

	do
	{
		printf("Please enter the coordinates for the Battleship:\n");
		scanf("%d%c%d", &x, &direction, &y);
		printf("Which direction do you want it in? Horizontal(H) or Vertial(V)\n");
		scanf(" %c", &direction);

		if (x < 0 || y < 0 || y > 10 || x > 10)
		{
			invalid = 1;
		}

		if (x + 4 > 10) //horizontal check
		{
			invalid = 1;
		}

		if (y + 4 > 10) //vertical check
		{
			invalid = 1;
		}

		overlap = overlap_check(x, y, board, 4, direction);

		if (overlap == 1)
		{
			invalid = 1;
		}
		if (!invalid)
		{
			place_ship(board, x, y, 'b', direction);
		}

	} while (invalid);

	print_board(board, 10, 10);

	do
	{
		printf("Please enter the coordinates for the Cruiser:\n");
		scanf("%d%c%d", &x, &direction, &y);
		printf("Which direction do you want it in? Horizontal(H) or Vertial(V)\n");
		scanf(" %c", &direction);

		if (x < 0 || y < 0 || y > 10 || x > 10)
		{
			invalid = 1;
		}

		if (x + 3 > 10) //horizontal check
		{
			invalid = 1;
		}

		if (y + 3 > 10) //vertical check
		{
			invalid = 1;
		}

		overlap = overlap_check(x, y, board, 3, direction);
		if (overlap == 1)
		{
			invalid = 1;
		}

		if (!invalid)
		{
			place_ship(board, x, y, 'r', direction);
		}

	} while (invalid);

	print_board(board, 10, 10);

	do
	{
		printf("Please enter the coordinates for the Submarine:\n");
		scanf("%d%c%d", &x, &direction, &y);
		printf("Which direction do you want it in? Horizontal(H) or Vertial(V)\n");
		scanf(" %c", &direction);

		if (x < 0 || y < 0 || y > 10 || x > 10)
		{
			invalid = 1;
		}

		if (x + 3 > 10) //horizontal check
		{
			invalid = 1;
		}

		if (y + 3 > 10) //vertical check
		{
			invalid = 1;
		}

		overlap = overlap_check(x, y, board, 3, direction);
		if (overlap == 1)
		{
			invalid = 1;
		}

		if (!invalid)
		{
			place_ship(board, x, y, 's', direction);
		}
	} while (invalid);

	print_board(board, 10, 10);
	do
	{
		printf("Please enter the coordinates for the Destroyer:\n");
		scanf("%d%c%d", &x, &direction, &y);
		printf("Which direction do you want it in? Horizontal(H) or Vertial(V)\n");
		scanf(" %c", &direction);

		if (x < 0 || y < 0 || y > 10 || x > 10)
		{
			invalid = 1;
		}

		if (x + 2 > 10) //horizintal check
		{
			invalid = 1;
		}

		if (y + 2 > 10) //vertical check
		{
			invalid = 1;
		}

		overlap = overlap_check(x, y, board, 2, direction);
		if (overlap == 1)
		{
			invalid = 1;
		}
		if (!invalid)
		{
			place_ship(board, x, y, 'd', direction);
		}
	} while (invalid);

	print_board(board, 10, 10);
}

int randomly_place_ship(char board[][COL_SIZE])
{
	int x = 0, y = 0, inbounds = 0, invalid = 0, direction = 0, overlap = 0;

	do //CARRIER PLACEMENT 
	{
		invalid = 0;
		x = rand() % 10;
		y = rand() % 10;
		direction = rand() % 2;

		if (direction == 0)
		{
			direction = 'H';
		}

		if (direction == 1)
		{
			direction = 'V';
		}

		inbounds = boundary_check(x, y, 5);

		if (inbounds == 1)
		{
			invalid = 1;
		}
		if (invalid == 0)
		{
			place_ship(board, x, y, 'c', direction);
		}


	} while (invalid == 1);

	do //BATTLESHIP PLACEMENT
	{
		invalid = 0;
		x = rand() % 10;
		y = rand() % 10;
		direction = rand() % 2;

		if (direction == 0)
		{
			direction = 'H';
		}

		if (direction == 1)
		{
			direction = 'V';
		}

		inbounds = boundary_check(x, y, 4);
		overlap = overlap_check(x, y, board, 4, direction);

		if (inbounds == 1 || overlap == 1)
		{
			invalid = 1;
		}
		if (invalid == 0)
		{
			place_ship(board, x, y, 'b', direction);
		}


	} while (invalid == 1);

	do //CRUISER PLACEMENT
	{
		invalid = 0;

		x = rand() % 10;
		y = rand() % 10;
		direction = rand() % 2;

		if (direction == 0)
		{
			direction = 'H';
		}

		if (direction == 1)
		{
			direction = 'V';
		}

		inbounds = boundary_check(x, y, 3);
		overlap = overlap_check(x, y, board, 3, direction);


		if (inbounds == 1 || overlap == 1)
		{
			invalid = 1;
		}
		if (invalid == 0)
		{
			place_ship(board, x, y, 'r', direction);
		}


	} while (invalid == 1);
	do //SUBMARINE PLACEMENT
	{
		invalid = 0;

		x = rand() % 10;
		y = rand() % 10;
		direction = rand() % 2;

		if (direction == 0)
		{
			direction = 'H';
		}

		if (direction == 1)
		{
			direction = 'V';
		}

		inbounds = boundary_check(x, y, 3);
		overlap = overlap_check(x, y, board, 3, direction);


		if (inbounds == 1 || overlap == 1)
		{
			invalid = 1;
		}
		if (invalid == 0)
		{
			place_ship(board, x, y, 's', direction);
		}


	} while (invalid == 1);
	do //DESTROYER 
	{
		invalid = 0;

		x = rand() % 10;
		y = rand() % 10;
		direction = rand() % 2;

		if (direction == 0)
		{
			direction = 'H';
		}

		if (direction == 1)
		{
			direction = 'V';
		}

		inbounds = boundary_check(x, y, 2);
		overlap = overlap_check(x, y, board, 2, direction);
		

		if (inbounds == 1 || overlap == 1)
		{
			invalid = 1;
		}
		if (invalid == 0)
		{
			place_ship(board, x, y, 'd', direction);
		}


	} while (invalid == 1);


}

void print_board(char board[][COL_SIZE], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

	for (; row_index < num_rows; ++row_index)
	{
		printf("%d", row_index);
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("%2c", board[row_index][col_index]);
		}
		putchar('\n');
	}

}

int check_shot(char board[][COL_SIZE], int x, int y)
{
	int check = 0;
	if (board[x][y] == '*' && board[x][y] == 'm')
	{
		printf("It has aleady been hit\n");
		check = -1;
	 //already hit
	}

	if (board[x][y] == '~')
	{
		printf("That was a miss.\n");
		check = 0;
	}

	if (board[x][y] != '~' && board[x][y] != '*' && board[x][y] != 'm')
	{
		printf("That was a hit!\n");
		check = 1;
	}

	return check;
}

char update_board(char board[][COL_SIZE], int x, int y)
{
	int checked_shot = check_shot(board, x, y);

	if (checked_shot == 1)
	{
		board[x][y] = '*';
	}

	if (checked_shot == 0)
	{
		board[x][y] = 'm';
	}
}

void comp_take_shot(char board[][COL_SIZE], FILE* outfile)
{
	int outputt = 4;
	int x = 0, y = 0;
	x = rand() % 10;
	y = rand() % 10;
	printf("The enemy fired at %d,%d\n", x, y);
	update_board(board, x, y);
	outputt = check_shot(board, x, y);
	output_current_move(x, y, outputt, outfile, 2);

}

void user_take_shot(char board[][COL_SIZE], FILE* outfile)
{
	int outputt = 4;
	int x = 0, y = 0;
	char spacer = '\0';
	printf("Where do you wanna fire commander??\n");
	scanf("%d%c%d", &x, &spacer, &y);
	update_board(board, x, y);
	outputt = check_shot(board, x, y);
	output_current_move(x, y, outputt, outfile, 1);
}

int check_if_sunk_ship(char board[][COL_SIZE], char ship)
{
	int status = 1;

	for (int i = 0; i < ROW_SIZE; ++i)
	{
		for (int j = 0; j < COL_SIZE; ++j)
		{
			if (board[i][j] == ship)
			{
				status = 0;
				return status;
			}
		}
	}

	return status;
	//if status is 0, the ship has sunk
	//if status is 1, the ship still exist
}

void output_current_move(int x, int y, int try, FILE* outfile, int player)
{

	fprintf(outfile, "Player %d fired on %d,%d\n", player, x, y);

	if (try == 1)
	{
		fprintf(outfile, "It was a hit\n");
	}
	if (try == 0)
	{
		fprintf(outfile, "It was a miss\n");
	}
	if (try == -1)
	{
		fprintf(outfile, "It had already been fired on\n");
	}
}

int is_winner(char board[][COL_SIZE])//, int player)
{
	int carrier = 0, battleship = 0, cruiser = 0, submarine = 0, destroyer = 0;
	carrier = check_if_sunk_ship(board, 'c');
	battleship = check_if_sunk_ship(board, 'b');
	cruiser = check_if_sunk_ship(board, 'r');
	submarine = check_if_sunk_ship(board, 's');
	destroyer = check_if_sunk_ship(board, 'd');

	if (carrier == 1 && battleship == 1 && cruiser == 1 && submarine == 1 && destroyer == 1)
	{
		return 1; //they lost
	}
	else return 0;
}

void print2_board(char board[][COL_SIZE], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

	for (; row_index < num_rows; ++row_index)
	{
		printf("%d", row_index);
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			if (board[row_index][col_index] != '~' && board[row_index][col_index] != 'm'
				&& board[row_index][col_index] != '*')
			{
				printf(" ~", board[row_index][col_index]);
			}

			else printf("%2c", board[row_index][col_index]);

		}
		putchar('\n');
	}

}

Stats stats_checker(char board[][COL_SIZE])
{
	Stats temp;

	int hit = 0, miss = 0, shots = 0, hit_to_miss = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (board[i][j] == '*')
			{
				++hit;
			}
			if (board[i][j] == 'm')
			{
				++miss;
			}
		}
	}
	shots = hit + miss;
	hit_to_miss = ((double)hit / (double)miss) * 100;

	temp.num_hits = hit;
	temp.num_misses = miss;
	temp.num_shots = shots;
	temp.hit_to_miss = hit_to_miss;
	return temp;
}

Stats output_stats(FILE* outfile, Stats player)
{

	
	fprintf(outfile, "Total hits: %d", player.num_hits);
	fprintf(outfile, "Total misss: %d", player.num_misses);
	fprintf(outfile, "Total shots taken: %d", player.num_shots);
	fprintf(outfile, "Hit to Miss ratio: %d", player.hit_to_miss);
}
