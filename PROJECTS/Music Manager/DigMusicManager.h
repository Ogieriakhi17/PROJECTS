/*Name: Osaze Ogieriakhi
Class: Cpts122 Spring 2023
Task: Programming Assginment #2 & #3
Description:This program is designed to create a digital music manager which performs
			a number of operations on songs and records in playlist including editting
			deleting, rating, etc.
Date: 01.29.2023
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


typedef struct duration
{
	int minutes;
	int seconds;
}Duration;

typedef struct record
{
	char artist[20];
	char album[30];
	char title[30];
	char genre[20];
	struct duration s_length;
	int repeats;
	int rating;
}Record;

typedef struct node
{
	struct record data;
	struct node* pNext;
	struct node* pPrev;
}Node;

/***********************************************************************
NAME: INIT_LIST

DESCRIPTION: This function is desgined to intiate a double linked list

PRECONDTIONS: A pointer to a Node msut be passed in as a parameter

POSTCONDITIONS: NONE
************************************************************************/
void initList(Node** pList);

/***********************************************************************
NAME:MAKENODE

DESCRIPTION: This function is designed to allocate space for a node on
			a heap.

PRECONDTIONS: A record must be passed in to initialize the function

POSTCONDITIONS: It returns a pointer to the node allocated
************************************************************************/
Node* makeNode(Record song);

/***********************************************************************
NAME:INSERTFRONT

DESCRIPTION: This function inserts a node into the front of the playlist

PRECONDTIONS: A list and Record struct must be passed into the function

POSTCONDITIONS: It returns an integer representing wether it was inserted
			or not
************************************************************************/
int insertFront(Node** pList, Record song);

/***********************************************************************
NAME:LOAD

DESCRIPTION: This function loads a record from a csv file and fills
			the node

PRECONDTIONS: A pointer to the beginnig of the list and a csv file

POSTCONDITIONS: It returns an integer.
************************************************************************/
int Load(Node** pList, FILE* infile);

/***********************************************************************
NAME:STORE

DESCRIPTION: This function is designed to store the present playlist file
			into the provided csv file

PRECONDTIONS: the playlist and file are needed as parameters

POSTCONDITIONS: It returns a 1 if success or 0 for failure
************************************************************************/
int store(Node* pList, FILE* outfile);

/***********************************************************************
NAME:RATE_SONG

DESCRIPTION: This function is designed to allow the user change the
			rating of a particular song

PRECONDITIONS: An address to the pointer to the playlist is needed

POSTCONDITIONS:It returns a 1 if success or 0 for failure
************************************************************************/
int rateSong(Node** pList);

/***********************************************************************
NAME:PLAY

DESCRIPTION:This function allows the user to "play" a song from any
			point in the playlist until the end.

PRECONDITIONS:An address to the pointer to the playlist is needed

POSTCONDITIONS:NONE
************************************************************************/
void play(Node* pList);

/***********************************************************************
NAME:DISPLAY

DESCRIPTION: This function is to print the present list to the screen

PRECONDITIONS:A pointer the list is needed.

POSTCONDITIONS:NONE
************************************************************************/
void display(Node* pList);

/***********************************************************************
NAME:EDIT_FUNCTION

DESCRIPTION:This function is designed to edit a single record in the
			playlist

PRECONDITIONS:An address to the pointer to the playlist is needed

POSTCONDITIONS:NONE
************************************************************************/
void EditFunction(Node** pList);

/***********************************************************************
NAME:INSERT_RECORD

DESCRIPTION:This function is to allow the user to insert a new record
			into the playlist.

PRECONDITIONS:An address to the pointer to the playlist is needed

POSTCONDITIONS:It returns a 1 if success or 0 for failure
************************************************************************/
int InsertRecord(Node** pList);

/***********************************************************************
NAME:DELETE_RECORD

DESCRIPTION:This function is designed to delete a record to the list

PRECONDITIONS:An address to the pointer to the playlist is needed

POSTCONDITIONS:It returns a 1 if success or 0 for failure
************************************************************************/
int DeleteRecord(Node** pList);

/***********************************************************************
NAME:SORT_FUNCTION

DESCRIPTION:This function is designed to re organized the playlist based
			on different filters

PRECONDITIONS:An address to the pointer to the playlist is needed

POSTCONDITIONS:NONE
************************************************************************/
void SortFunction(Node** pList);

/***********************************************************************
NAME:SHUFFLE_FUNCTION

DESCRIPTION:This function is meant to shuffle the song in a playlist 
			into a randonly generated order

PRECONDITIONS:It needs a pointer to the address of a playlist

POSTCONDITIONS:NONE
************************************************************************/
void ShuffleFunction(Node* pList);

/***********************************************************************
NAME: EXIT_FUNCTION

DESCRIPTION:This function is designed to print out the present list and
			exit the music manager.

PRECONDITIONS:A pointer the list, and an output file are needed

POSTCONDITIONS:It returns a 1 if success or 0 for failure
************************************************************************/
int ExitFunction(Node* pList, FILE* outfile);

/***********************************************************************
NAME: MAIN_MENU

DESCRIPTION: This function is designed to print out the main menu to the
			user and recieve their chice as input.

PRECONDTIONS: NONE

POSTCONDITIONS: It returns their choice as an integer
************************************************************************/
int main_menu(void);

