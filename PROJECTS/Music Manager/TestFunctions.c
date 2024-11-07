#include "TestFunctions.h"



void InsertTest(void)
{
	Record testSong;

	Node* testHead = NULL;
	initList(&testHead);
	
	strcpy(testSong.album, "Witness");
	strcpy(testSong.artist, "Katy Perry");
	strcpy(testSong.title, "Chained to the Rhythm");
	strcpy(testSong.genre, "Pop");
	testSong.s_length.minutes = 4;
	testSong.s_length.seconds = 36;
	testSong.repeats = -1;
	testSong.rating = 6;

	int result = insertFront(testHead, testSong);

	if (result == 0)
	{
		printf("Test failed\n");
	}

	if (result == 1)
	{
		printf("Insertion was successful\n");
	}
}

void DeleteTest(void)
{
	Record testSong;
	int success = 0;
	strcpy(testSong.album, "Witness");
	strcpy(testSong.artist, "Katy Perry");
	strcpy(testSong.title, "Chained to the Rhythm");
	strcpy(testSong.genre, "Pop");
	testSong.s_length.minutes = 4;
	testSong.s_length.seconds = 36;
	testSong.repeats = 3;
	testSong.rating = 5;

	Node* testHead = NULL;
	initList(&testHead);
	success = insertFront(&testHead, testSong);
	Node* pCur = testHead;
	char* deleteItem = "Chained to the Rhythm";
	
	while (pCur != NULL)
	{
		Node* pPrev = pCur->pPrev;
		Node* pNext = pCur->pNext;
		if (strcmp(deleteItem, pCur->data.title) == 0)
		{
			success = 1;
			if (pCur->pPrev == NULL) //it is the first in the list
			{
				testHead = pCur->pNext;
				free(pCur);
			}

			else if (pCur->pNext != NULL)
			{
				
				pPrev->pNext = pCur->pNext;
				pNext->pPrev = pPrev;

				free(pCur);
			}

			else if (pCur->pNext == NULL)//at the end
			{
				pPrev->pNext = NULL;
				free(pCur);
			}

		}

		if (pNext == NULL)
		{
			break;
		}

		pPrev = pCur;
		pCur = pNext;
		pNext = pNext->pNext;

	}


	if (success== 1)
	{
		printf("Deletion was successful\n");
	}



}

void ShuffleTest(void)
{

	Node* testHead = NULL;
	initList(&testHead);
	int shuffleOrder[3] = { 3, 1, 2 };
	Record songList[3];
	int result = 0, present = 0;

	strcpy(songList[0].album, "Sonder Son");
	strcpy(songList[0].artist, "Brent Faiyaz");
	strcpy(songList[0].title, "Talk 2 U");
	strcpy(songList[0].genre, "R&B");
	songList[0].s_length.minutes = 2;
	songList[0].s_length.seconds = 36;
	songList[0].repeats = 3;
	songList[0].rating = 4;

	strcpy(songList[1].album, "Rave & Roses");
	strcpy(songList[1].artist, "Rema");
	strcpy(songList[1].title, "Addicted");
	strcpy(songList[1].genre, "Afrobeats");
	songList[1].s_length.minutes = 2;
	songList[1].s_length.seconds = 36;
	songList[1].repeats = 3;
	songList[1].rating = 5;

	strcpy(songList[2].album, "MLLE");
	strcpy(songList[2].artist, "Wizkid");
	strcpy(songList[2].title, "Pressure");
	strcpy(songList[2].genre, "Afrobeats");
	songList[2].s_length.minutes = 3;
	songList[2].s_length.seconds = 23;
	songList[2].repeats = 3;
	songList[2].rating = 5;

	for (int input = 0; input < 3; ++input)
	{
		result = insertFront(&testHead, songList[input]);
	}

	

	for (int index = 0; index < 3; ++index)
	{
		Node* pCur = testHead;

		for (int gg = 0; gg < shuffleOrder[present] - 1; ++gg)
		{
			pCur = pCur->pNext;
		}

		system("cls");
		printf("Now Playing: ");
		puts(pCur->data.title);
		Sleep(2000);
		system("cls");

		present++;
	}

}