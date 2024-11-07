#pragma once
#include "Stack.h"


class Data
{
public: 
	Data() {};
	Data(string info);
	Data(Data* newCopy)
	{
		this->recordNumber = newCopy->getRecordNumber();
		this->idNumber = newCopy->getIDnumber();
		this->name = newCopy->getName();
		this->email = newCopy->getEmail();
		this->creditOrAU = newCopy->getCredits();
		this->major = newCopy->getMajor();
		this->level = newCopy->getLevel();
		this->numAbsences = newCopy->getNumAbsences();
		this->absences = newCopy->getAbsentDates();

	}

	~Data() {};

	//getters
	int getRecordNumber();
	int getIDnumber();
	string getName();
	string getEmail();
	string getCredits();
	string getMajor();
	string getLevel();
	int getNumAbsences();
	string getRecentAbs();
	void addAbsence();
	Stack <string>* getAbsentDates();

private:
	int recordNumber;
	int idNumber;
	string name;
	string email;
	string creditOrAU;
	string major;
	string level;
	int numAbsences;
	Stack <string>* absences;

};

ofstream& operator<< (ofstream& lhs, Data& rhs);

ostream& operator<< (ostream& lhs, Data& rhs);



