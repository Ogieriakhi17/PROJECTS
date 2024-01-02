/*Name: Osaze Ogieriakhi
Class: Cpts122 Spring 2023
Task: Programming Assginment #2 & #3
Description: This program is designed to create a digital music manager which performs
			a number of operations on songs and records in playlist including editting
			deleting, rating, etc.
Date: 01.29.2023
*/


#include "DigMusicManager.h"


int main_menu(void)
{

	int choice = 0;
	printf("****DIGITAL MUSIC MANAGER****\n");
	printf("1. load\n");
	printf("2. store\n");
	printf("3. display\n");
	printf("4. insert\n");
	printf("5. delete\n");
	printf("6. edit\n");
	printf("7. sort\n");
	printf("8. rate\n");
	printf("9. play\n");
	printf("10. shuffle\n");
	printf("11. exit\n");
	printf("12. Testing\n");
	scanf("%d", &choice);
	printf("%d\n", choice);
	return choice;
}


void initList(Node** pList)
{
	*pList = NULL;
}

Node* makeNode(Record song)
{
	Node* pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL)//then space was allocated succesfully
	{
		strcpy(pMem->data.artist, song.artist);
		strcpy(pMem->data.album, song.album);
		strcpy(pMem->data.title, song.title);
		strcpy(pMem->data.genre, song.genre);
		pMem->data.s_length = song.s_length;
		pMem->data.repeats = song.repeats;
		pMem->data.rating = song.rating;
		pMem->pNext = NULL;
		pMem->pPrev = NULL;

	}

	return pMem;
}


int insertFront(Node** pList, Record song)
{
	Node* pMem = makeNode(song);
	int success = 0;

	if (song.rating < 1 || song.rating > 5)
	{
		printf("Rating does not match format\n");
		return success;
	}

	if (song.repeats < 1)
	{
		printf("No.of times played does not fit format\n");
		return success;
	}

	if (pMem != NULL)
	{

		success = 1;
		if (*pList == NULL)//then the list is empty
		{
			pMem->pPrev = NULL;
			pMem->pNext = NULL;
			*pList = pMem;

		}
		else
		{
			(*pList)->pPrev = pMem;
			pMem->pNext = *pList;
			pMem->pPrev = NULL;
			*pList = pMem;

		}
	}
	return success;
}


int Load(Node** pList, FILE* infile)
{
	char line[100];
	char trash = '\0';
	int success = 0;
	Record generic;

	if (infile != NULL)
	{


		while ((fgets(line, 100, infile)) != NULL)
		{

			if (line[0] == '\"')
			{
				strcpy(generic.artist, strtok(&line[1], "\""));
				strcpy(generic.album, strtok(NULL, ","));
				strcpy(generic.title, strtok(NULL, ","));
				strcpy(generic.genre, strtok(NULL, ","));
				generic.s_length.minutes = atoi(strtok(NULL, ":"));
				generic.s_length.seconds = atoi(strtok(NULL, ","));
				generic.repeats = atoi(strtok(NULL, ","));
				generic.rating = atoi(strtok(NULL, ","));
			}

			else
			{
				strcpy(generic.artist, strtok(line, ","));
				strcpy(generic.album, strtok(NULL, ","));
				strcpy(generic.title, strtok(NULL, ","));
				strcpy(generic.genre, strtok(NULL, ","));
				generic.s_length.minutes = atoi(strtok(NULL, ":"));
				generic.s_length.seconds = atoi(strtok(NULL, ","));
				generic.repeats = atoi(strtok(NULL, ","));
				generic.rating = atoi(strtok(NULL, ","));

			}

			success = insertFront(pList, generic);
			
		}
	}

	return success;

}

int store(Node* pList, FILE* outfile)
{
	Node* pCur = pList;
	int success = 0;
	while (pCur != NULL)
	{
		fprintf(outfile, " \"%s\", %s, %s, %s,", pCur->data.artist, pCur->data.album, pCur->data.title, pCur->data.genre);
		fprintf(outfile, " %d:%d, %d, %d\n", pCur->data.s_length.minutes, pCur->data.s_length.seconds, pCur->data.repeats, pCur->data.rating);
		pCur = pCur->pNext;
	}

	return 0;
}


int rateSong(Node** pList)
{
	char songSearch[20];
	Node* pCur = *pList;
	int rate = 0, success = 0;

	printf("what song do you want to rate?\n");
	//scanf("%s", songSearch);
	fseek(stdin, 0, SEEK_END);
	gets(songSearch);
	//puts(songSearch);

	while (pCur != NULL)
	{

		if (strcmp(pCur->data.title, songSearch) == 0)
		{
			success = 1;
			do
			{
				printf("what rating do you want to give?\n");
				scanf("%d", &rate);
			} while (rate > 5 || rate < 1);
			pCur->data.rating = rate;
			printf("New song rating for %s is %d\n", songSearch, rate);
			system("pause");
			system("cls");
			

		}
		pCur = pCur->pNext;
	}
	return success;

}

void play(Node* pList)
{
	Node* pCur = pList;
	char songSearch[20];

	printf("What song do you wish to play?\n");
	fseek(stdin, 0, SEEK_END);
	gets(songSearch);

	while (pCur != NULL)
	{
		if (strcmp(pCur->data.title, songSearch) == 0)
		{
			while (pCur != NULL)
			{
				printf("Now playing: ");
				puts(pCur->data.title);
				Sleep(2000);
				system("cls");
				pCur = pCur->pNext;
			}
			break;
		}
		pCur = pCur->pNext;
	}
}


void display(Node* pList)
{
	Node* pCur = pList;

	if (pCur == NULL)
	{
		printf("Playlist is empty\n");
	}

	while (pCur != NULL)
	{
		printf("Artist: %s\n", pCur->data.artist);
		printf("Album: %s\n", pCur->data.album);
		printf("Title: %s\n", pCur->data.title);
		printf("Genre: %s\n", pCur->data.genre);
		printf("Length: %d:%d\n", pCur->data.s_length.minutes, pCur->data.s_length.seconds);
		printf("Replays: %d\n", pCur->data.repeats);
		printf("Rating: %d\n", pCur->data.rating);
		printf("    ******     \n");
		
		pCur = pCur->pNext;
	}

}


void EditFunction(Node** pList)
{
	Node* pCur = *pList;
	char songSearch[20], artistSearch[20], holder[20];
	int artistCount = 0, choice = 0;

	printf("What artist record do you wish to edit?\n");
	fseek(stdin, 0, SEEK_END);
	gets(artistSearch);

	while (pCur != NULL)
	{
		if (strcmp(pCur->data.artist, artistSearch) == 0)
		{
			++artistCount; //this is to check if an artist has multiple songs in the playlist
		}
		pCur = pCur->pNext;
	}

	if (artistCount == 0)
		printf("Artist not found\n");

	else if (artistCount > 1)
	{
		printf("What song of %s do you wish to edit?\n", artistSearch);
		fseek(stdin, 0, SEEK_END);
		gets(songSearch);

		pCur = *pList;
		while (pCur != NULL)
		{
			if (strcmp(pCur->data.title, songSearch) == 0)
			{
				printf("What part of the record do you want to edit?\n");
				printf("1. Artist\n2. Album\n3. Title\n4.Genre\n");
				printf("5. Song Length\n6. Times Played\n7. Rating\n");
				scanf("%d", &choice);
			}
			pCur = pCur->pNext;
		}
	}

	else if (artistCount == 1)
	{
		printf("What part of the record do you want to edit?\n");
		printf("1. Artist\n2. Album\n3. Title\n4.Genre\n");
		printf("5. Song Length\n6. Times Played\n7. Rating\n");
		scanf("%d", &choice);

	}

	pCur = *pList;

	//reset pCur to the artist
	while (pCur != NULL)
	{
		if (strcmp(pCur->data.title, songSearch) == 0)
		{
			break;
		}

		pCur = pCur->pNext;
	}

	switch (choice)
	{
	case 1:
		printf("please enter new artist name.\n");
		fseek(stdin, 0, SEEK_END);
		gets(holder);
		strcpy(pCur->data.artist, holder);
		break;

	case 2:
		printf("please enter new album name.\n");
		fseek(stdin, 0, SEEK_END);
		gets(holder);
		strcpy(pCur->data.album, holder);
		break;

	case 3:
		printf("please enter new song title.\n");
		fseek(stdin, 0, SEEK_END);
		gets(holder);
		strcpy(pCur->data.title, holder);
		break;

	case 4:
		printf("please enter new genre name.\n");
		fseek(stdin, 0, SEEK_END);
		gets(holder);
		strcpy(pCur->data.genre, holder);
		break;

	case 5:
		printf("please enter new duration (minutes).\n");
		fseek(stdin, 0, SEEK_END);
		gets(holder);
		pCur->data.s_length.minutes = atoi(holder);
		printf("please enter new duration (seconds).\n");
		gets(holder);
		pCur->data.s_length.seconds = atoi(holder);
		break;

	case 6:
		printf("please enter new number of times played.\n");
		fseek(stdin, 0, SEEK_END);
		gets(holder);
		pCur->data.repeats = atoi(holder);
		break;

	case 7:
		printf("please enter new rating.\n");
		fseek(stdin, 0, SEEK_END);
		gets(holder);
		pCur->data.rating = atoi(holder);
		break;
	}



}

int InsertRecord(Node** pList)
{
	int success = 0;
	Record newSong;
	char ArtistReader[20], AlbumReader[20], TitleReader[20], GenreReader[20];

	printf("Please enter a new artist name.\n");
	fseek(stdin, 0, SEEK_END);
	gets(ArtistReader);
	strcpy(newSong.artist, ArtistReader);

	printf("Please enter a new album name.\n");
	fseek(stdin, 0, SEEK_END);
	gets(AlbumReader);
	strcpy(newSong.album, AlbumReader);

	printf("Please enter a new song title.\n");
	fseek(stdin, 0, SEEK_END);
	gets(TitleReader);
	strcpy(newSong.title, TitleReader);

	printf("Please enter the genre of the song.\n");
	fseek(stdin, 0, SEEK_END);
	gets(GenreReader);
	strcpy(newSong.genre, GenreReader);

	printf("please enter the song length minutes\n");
	scanf("%d", &newSong.s_length.minutes);

	printf("please enter the song length seconds\n");
	scanf("%d", &newSong.s_length.seconds);

	do {
		printf("Please enter the no. of replays\n");
		scanf("%d", &newSong.repeats);
	} while (!(newSong.repeats > 0));

	do {
		printf("Enter the rating for the record\n");
		scanf("%d", &newSong.rating);
	} while (newSong.rating < 1 || newSong.rating > 5);

	success = insertFront(pList, newSong);

	return success;
}


int DeleteRecord(Node** pList)
{
	int success = 0;
	char deleteItem[20];
	Node* pCur = *pList, * pPrev = NULL, * pNext = pCur->pNext;

	printf("What Record do you wish to delete?\n");
	fseek(stdin, 0, SEEK_END);
	gets(deleteItem);

	while (pCur != NULL)
	{

		if (strcmp(deleteItem, pCur->data.title) == 0)
		{
			success = 1;
			if (pCur->pPrev == NULL) //it is the first in the list
			{
				*pList = pCur->pNext;
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



	return success;

}

void SortFunction(Node** pList)
{
	int choice = 0, swap = 1;
	Node* pCur = *pList, * CurPrev = pCur->pPrev, * CurNext = pCur->pNext;
	printf("What order do you want to sort the Playlist\n");
	printf("1. Artist name A-Z\n");
	printf("2. Based on Song Title\n");
	printf("3. Based on the rating\n");
	printf("4. Based on the time played (largest to smallest)\n");

	scanf("%d", &choice);

	switch (choice)
	{
	case 1:

		while (swap == 1)
		{
			swap = 0;
			while (pCur != NULL && CurNext != NULL)
			{
				if (strcmp(pCur->data.artist, CurNext->data.artist) > 0)
				{
					swap = 1;
						//swap

						if (CurPrev != NULL)
						{
							CurPrev->pNext = pCur->pNext;
						}
						else
							*pList = CurNext;
						pCur->pPrev = CurNext;
					pCur->pNext = CurNext->pNext;
					CurNext->pNext = pCur;
					CurNext->pPrev = CurPrev;
					if (pCur->pNext != NULL)
						pCur->pNext->pPrev = pCur;
				}

				CurPrev = pCur;
				pCur = CurNext;
				CurNext = CurNext->pNext;
			}
			pCur = *pList, CurPrev = pCur->pPrev, CurNext = pCur->pNext;
		}

	case 2:
		while (swap == 1)
		{
			swap = 0;
			while (pCur != NULL && CurNext != NULL)
			{
				if (strcmp(pCur->data.title, CurNext->data.title) > 0)
				{
					swap = 1;
					//swap

					if (CurPrev != NULL)
					{
						CurPrev->pNext = pCur->pNext;
					}
					else
						*pList = CurNext;
					pCur->pPrev = CurNext;
					pCur->pNext = CurNext->pNext;
					CurNext->pNext = pCur;
					CurNext->pPrev = CurPrev;
					if (pCur->pNext != NULL)
						pCur->pNext->pPrev = pCur;
				}

				CurPrev = pCur;
				pCur = CurNext;
				CurNext = CurNext->pNext;
			}
			pCur = *pList, CurPrev = pCur->pPrev, CurNext = pCur->pNext;
		}

	case 3:

		while(swap == 1)
		{
			swap = 0;
			while (pCur != NULL && CurNext != NULL)
			{
				if (pCur->data.rating > CurNext->data.rating)
				{
					swap = 1;
					//swap

					if (CurPrev != NULL)
					{
						CurPrev->pNext = pCur->pNext;
					}
					else
						*pList = CurNext;
					pCur->pPrev = CurNext;
					pCur->pNext = CurNext->pNext;
					CurNext->pNext = pCur;
					CurNext->pPrev = CurPrev;
					if(pCur->pNext != NULL)
						pCur->pNext->pPrev = pCur;
				}

				CurPrev = pCur;
				pCur = CurNext;
				CurNext = CurNext->pNext;
			}
			pCur = *pList,  CurPrev = pCur->pPrev, CurNext = pCur->pNext;
		}
	case 4: 
		while (swap == 1)
		{
			swap = 0;
			while (pCur != NULL && CurNext != NULL)
			{
				if (pCur->data.repeats < CurNext->data.repeats)
				{
					swap = 1;
					//swap

					if (CurPrev != NULL)
					{
						CurPrev->pNext = pCur->pNext;
					}
					else
						*pList = CurNext;
					pCur->pPrev = CurNext;
					pCur->pNext = CurNext->pNext;
					CurNext->pNext = pCur;
					CurNext->pPrev = CurPrev;
					if (pCur->pNext != NULL)
						pCur->pNext->pPrev = pCur;
				}

				CurPrev = pCur;
				pCur = CurNext;
				CurNext = CurNext->pNext;
			}
			pCur = *pList, CurPrev = pCur->pPrev, CurNext = pCur->pNext;
		}

	}

}



void ShuffleFunction(Node* pList)
{
	int playSize = 0, repeat = 0, jj = 0, present = 0;
	Node* pCur = pList;
	time_t T;
	srand((unsigned)time(&T));

	while (pCur != NULL)//this is to find the ammount of songs in the playlist 
	{
		pCur = pCur->pNext;
		++playSize;
	}

	
	int RandomNumber[100] = { -1 };


	for (int index = 0; index < playSize; ++index)
	{
		do //this is to create a random oder for the songs to play in while checking that no songs are replayed
		{
			repeat = 0;
			jj = rand() % playSize + 1;
			for (int i = 0; i < 100; ++i)
			{
				if (RandomNumber[i] == jj)
				{
					repeat = 1;
					break;
				}
			}
		} while (repeat == 1);
	

		pCur = pList;

		for (int gg = 0; gg < jj - 1; ++gg) 
		{
			pCur = pCur->pNext;
		}
		
		
		printf("Now Playing: ");
		puts(pCur->data.title);
		Sleep(2000);
		system("cls");
		RandomNumber[present] = jj;
		present++;
	}
}









int ExitFunction(Node* pList, FILE* outfile)
{
	Node* pCur = pList;
	int success = 0;
	while (pCur != NULL)
	{
		fprintf(outfile, " \"%s\", %s, %s, %s", pCur->data.artist, pCur->data.album, pCur->data.title, pCur->data.genre);
		fprintf(outfile, " %d:%d, %d, %d\n", pCur->data.s_length.minutes, pCur->data.s_length.seconds, pCur->data.repeats, pCur->data.rating);
		pCur = pCur->pNext;
	}

	return 0;
}
