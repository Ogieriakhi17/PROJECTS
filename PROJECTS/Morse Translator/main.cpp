/*
Name: Osaze Ogeirakhi 
Class: CptS 122 Spring 2023
Task: Programming Assginment #6
Description: This porgrammed is designed to be conversion tool for morse 
			code.
Date: 03.18.23
*/

#include "BST.h"

int main(void)
{
	BST main;

	int choice = 0;
	do
	{
		cout << "***MORSE TRANSLATOR***" << endl;
		cout << "1. Print Tree" << endl;
		cout << "2. Translator" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: main.printTree();
			system("pause");
			system("cls");
			break;

		case 2: main.converter();
			system("pause");
			system("cls");
			break;

		}



	} while (choice > 0 && choice != 3);
	
}

