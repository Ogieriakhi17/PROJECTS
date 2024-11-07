#pragma once
/*
Name: Osaze Ogeirakhi
Class: CptS 122 Spring 2023
Task: Programming Assginment #6
Description: This porgrammed is designed to be conversion tool for morse 
			code.
Date: 03.18.23
*/

#include "BSTNode.h"

class BST
{
public: 

	BST(string text = "", string morse = "", Node* mpRoot = nullptr);
	

	void insert(Node* newNode);
	string findTarget(string target);
	void printTree();
	
	void converter();

private: 
	Node* mpRoot;
	string morseCode;
	string Text;

	void insert(Node* newNode, Node* pTree);
	Node* makeNode(char text, string morseCode);
	void initiateBST(fstream& infile);
	string findTarget(Node* pTree, string target);
	void printTree(Node* pTree);
	string convertText(fstream& input);
	string convertTextToMorse(string text);

};