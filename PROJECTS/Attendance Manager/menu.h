//#include "Stack.h"
//#include "Data.h"
#pragma once
#include "List.h"

class Menu
{
public:
	Menu() 
	{
		classList = new List<Node<Data>>;
	};

	~Menu();
	bool importList(ifstream &input);
	bool storeList(ofstream &outfile);
	void runProgram();
	//void addAbsence(List<Data>& list);
	
private:
	int displayMenu();
	
	ifstream infille;
	ofstream outfille;
	List<Node<Data>>* classList;
};

