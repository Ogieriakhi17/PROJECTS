#pragma once
/*
Name: Osaze Ogeirakhi
Class: CptS 122 Spring 2023
Task: Programming Assginment #6
Description: This porgramm is designed to decode Morse Code
Date: 03.18.23
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class Node
{
public:
	//constructor
	Node(char newCharacter = '\0', string newMorse = "") : mpLeft(nullptr), mpRight(nullptr)
	{
	
		this->Character = newCharacter;
		this->morseChar = newMorse;
	}

	~Node();

	//setters
	void setCharacter(char newChar);
	void setMorseCode(string newMorse);
	void setLeftPtr(Node* leftPtr);
	void setRightPtr(Node* rightPtr);

	//getter
	char getCharacter();
	string& getMorseChar();
	Node* getLeftPtr();
	Node* getRightPtr();

	//member functions

private: 
	char Character;
	string morseChar;
	Node* mpLeft,
		*mpRight;
};