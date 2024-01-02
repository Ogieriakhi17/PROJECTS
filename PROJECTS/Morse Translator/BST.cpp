#pragma once

#include "BST.h"


BST::BST(string text, string morse, Node* mpRoot)
{
	this->morseCode = morse;
	this->Text = text;
	this->mpRoot = mpRoot;
	fstream table("MorseTable.txt");

	if (table.is_open())
	{
		initiateBST(table);
		table.close();

	}
	else cout << "File opened unsuccessfully" << endl;
}


void BST::insert(Node* newNode)
{
	insert(newNode, this->mpRoot);
}

void BST::insert(Node* newNode, Node* pTree)
{
	if (this->mpRoot == nullptr) // base case
	{
		// we know the tree is empty
		this->mpRoot = newNode;
	}
	else if (newNode->getCharacter() > pTree->getCharacter())
	{
		if (pTree->getRightPtr() == nullptr)
		{
			pTree->setRightPtr(newNode);
		}
		else // the right subtree is not empty
		{
			insert(newNode, pTree->getRightPtr());
		}
	}
	else if (newNode->getCharacter() < pTree->getCharacter())
	{
		if (pTree->getLeftPtr() == nullptr)
		{
			pTree->setLeftPtr(newNode);
		}
		else // the left subtree is not empty
		{
			insert(newNode, pTree->getLeftPtr());
		}
	}
}

Node* BST::makeNode(char text, string morseCode)
{
	Node *newNode = new Node;
	newNode->setCharacter(text);
	newNode->setMorseCode(morseCode);
	return newNode;
}

void BST::initiateBST(fstream& infile)
{
	char text = '\0';
	string	morse = "";

	while (!infile.eof())
	{
		infile >> text;
		infile >> morse;
		
		if (morse != "" && text != '\0')
		{
			Node* newEntry = makeNode(text, morse);
			if (newEntry != nullptr)
			{
				insert(newEntry);
			}
		}
	}

}


string BST::findTarget(string target)
{
	string upperCase = target;
	upperCase = toupper(upperCase[0]);
	return findTarget(this->mpRoot, upperCase);
}

string BST::findTarget(Node* pTree, string target)
{
	string result = "";
	
	//this uses the same idea of the insert function
	if (pTree != nullptr)
	{
		if (target[0] == pTree->getCharacter())
		{
			string goat = pTree->getMorseChar();
			return pTree->getMorseChar();
		}

		else if (target[0] < pTree->getCharacter())
		{
			return findTarget(pTree->getLeftPtr(), target);
		}

		else if (target[0] > pTree->getCharacter())
		{
			return findTarget(pTree->getRightPtr(), target);
		}
	}
}

void BST::printTree()
{
	printTree(this->mpRoot);
}

void BST::printTree(Node* pTree)
{
	if (pTree != nullptr)
	{
		printTree(pTree->getLeftPtr());
		cout << pTree->getCharacter() << " " << pTree->getMorseChar() << endl;
		printTree(pTree->getRightPtr());
	}
}

string BST::convertText(fstream& input) 
{
	string text = "", line = "";

	while (!input.eof())
	{
		getline(input, line);//this is to read a single line from the file to convert to morse
		if (line == "")
		{
			line.back();
		}
		else
		{
			text = text + line;
		}
	}
	return text;
}

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
string BST::convertTextToMorse(string text)
{
	int length = text.length();
	char* morse = (char*)malloc(text.length());
	for (int i = 0; i < text.length(); i++) morse[i] = 0;

	for (int index = 0; index < length; ++index)
	{
		
		string cur(1, text[index]); //this is to parse the string into single characters
		
		if (text[index] == '*')
		{
			strcat(morse, "\n");
			

		}
		else if (text[index] == ' ')
		{
			strcat(morse, " ");
			
		}

		else {
			
			strcat(morse, this->findTarget(cur).c_str());
			
		}
	}
	
	return morse; 
}

void BST::converter()
{
	string morse = "";
	
	fstream infile("test.txt");

	if (infile.is_open())
	{
		string text = convertText(infile);
		morse = convertTextToMorse(text);
		cout << "inputted text: " << text << endl;
		cout << "morse: " << morse << endl;
	}

	infile.close();
}