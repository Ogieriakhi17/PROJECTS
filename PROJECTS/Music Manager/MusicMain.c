/*Name: Osaze Ogieriakhi
Class: Cpts122 Spring 2023
Task: Programming Assginment #2 & #3
Description:This program is designed to create a digital music manager which performs
			a number of operations on songs and records in playlist including editting
			deleting, rating, etc.
Date: 01.29.2023
*/


#include "TestFunctions.h"

int main(void)
{
	int choice = 0, check = 0, testChoice;
	FILE* infile = NULL;
	FILE* outfile = NULL;
	infile = fopen("musicPlayList.csv", "r");
	//outfile = fopen("testttt.csv", "w");
	Node* pHead = NULL;
	srand(time(NULL));

	initList(&pHead);


	if (infile == NULL)
	{
		printf("file not opened successfully\n");
	}


	do
	{
		choice = main_menu();
		system("cls");

		switch (choice)
		{
		case 1:
			check = Load(&pHead, infile);
			if (check == 1)
				printf("Songs loaded successfully\n");
			else { printf("Loading failed\n"); }
			fclose(infile);
			break;

		case 2:
			outfile = fopen("musicPlayList.csv", "w");
			check = store(pHead, outfile);
			fclose(outfile);
			break;

		case 3:
			display(pHead);
			break;

		case 4:
			check = InsertRecord(&pHead);
			break;

		case 5:
			check = DeleteRecord(&pHead);
			if (check == 0)
				printf("song not found\n");
			break;

		case 6:
			EditFunction(&pHead);
			break;

		case 7:
			SortFunction(&pHead);
			break;

		case 8:
			check = rateSong(&pHead);
			if (check == 0)
				printf("Song not found in playlist\n");
			break;

		case 9:
			play(pHead);
			break;

		case 10:
			ShuffleFunction(pHead);
			break;
		case 11:
			outfile = fopen("musicPlayList.csv", "w");
			ExitFunction(pHead, outfile);
			fclose(outfile);
			break;

		case 12:

			printf("What function do wish to test\n");
			printf("1. Insert Test\n");
			printf("2: Test Deletion\n");
			printf("3. Test Shuffle\n");
			scanf("%d", &testChoice);

			switch (testChoice)
			{
			case 1:
				InsertTest();
				break;

			case 2:
				DeleteTest();
				break;

			case 3:
				ShuffleTest();
				break;
			}

			break;

		}



	} while (choice != 11 || choice < 1 || choice > 12);



	fclose(infile);
	
}