#include "Data.h"


Data::Data(string info)
{
	string data = "",
		name = "", fullname = "";

		this->numAbsences = 0;

	stringstream newLine(info);
	//int index = 0;

	getline(newLine, data, ',');


	this->recordNumber = stoi(data);
	//++index
	getline(newLine, data, ',');
	this->idNumber = stoi(data);

	getline(newLine, data, ',');
	getline(newLine, name, ',');
	fullname = data + " " + name;
	this->name = fullname;

	getline(newLine, data, ',');
	this->email = data;

	getline(newLine, data, ',');
	this->creditOrAU = data;

	getline(newLine, data, ',');
	this->major = data;

	getline(newLine, this->level, '\n');


	//string clocktime;

	
	this->absences = new Stack<string>();
	
}



int Data::getRecordNumber()
{
	return this->recordNumber;
}

int Data::getIDnumber()
{
	return this->idNumber;
}

string Data::getName()
{
	return this->name;
}

string Data::getEmail()
{
	return this->email;
}

string Data::getCredits()
{
	return this->creditOrAU;
}

string Data::getMajor()
{
	return this->major;
}
string Data::getLevel()
{
	return this->level;
}

int Data::getNumAbsences()
{
	return this->numAbsences;
}

string Data::getRecentAbs()
{
	string result = "no absences";

	if (this->absences->getSize() == 0)
	{
		return result;
	}
	else
	{
		return this->absences->peek();//this returns the most recent absence

	}
	
}

void Data::addAbsence()
{
	stringstream stream;
	string date;
	string test = "04.01.2023";

	//***CODE FROM ANDY***
	const std::chrono::time_point<std::chrono::system_clock> now =
		std::chrono::system_clock::now();

	const std::time_t t_c = std::chrono::system_clock::to_time_t(now);

	(std::localtime(&t_c));
	
	//stringstream stream;
	
	stream << t_c;
	date = stream.str();
	//this->absences->push(date); //this is the code that takes the date from the comp
	this->absences->push(test); //but this is takes a random date to show the function works
	++this->numAbsences;
}

Stack<string>* Data::getAbsentDates()
{
	Stack<string>* temp = new Stack<string>;
	string holder = "", result = "";
	stringstream stream;

	return this->absences;
}

//this is to print out the records to the csv file
ofstream& operator<< (ofstream& lhs, Data& rhs)
{
	lhs << rhs.getRecordNumber() << ",";
	lhs << rhs.getIDnumber() << ",";
	lhs << rhs.getName() << ",";
	lhs << rhs.getEmail() << ",";
	lhs << rhs.getCredits() << ",";
	lhs << rhs.getMajor() << ",";
	lhs << rhs.getLevel() << ",";
	lhs << rhs.getNumAbsences() << ",";
	lhs << rhs.getRecentAbs() << endl;
	return lhs;
}

//this is to print out the students to the screen
ostream& operator<< (ostream& lhs, Data& rhs)
{
	lhs << "Record Num: " << rhs.getRecordNumber() << endl;
	lhs << "ID number: " << rhs.getIDnumber() << endl;
	lhs << "Name: " << rhs.getName() << endl;
	lhs << "Email: " << rhs.getEmail() << endl;
	lhs << "Credits:" << rhs.getCredits() << endl;
	lhs << "Major:" << rhs.getMajor() << endl;
	lhs << "Year: " << rhs.getLevel() << endl;
	lhs << "Absences:" << rhs.getNumAbsences() << endl;
	lhs << "Most Recent Absence: " << rhs.getRecentAbs() << endl;
	lhs << endl;
	return lhs;
}