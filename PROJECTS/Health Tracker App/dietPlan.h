#pragma once
/*Name: Osaze Ogieriakhi
Class: CptS 122 Spring 2023
Task: Programming Assignment #4
Description: This program is desgined be a diet and excercise plan manager.
			It reads in users excercise and diet plans and allow the user 
			edit certain aspects of their plans. 
Date: 02.23.2023
*/

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::ostream;
using std::getline;


class DietPlan
{
public:
	//constructor
	DietPlan();
	DietPlan(double nCalories, string name, string date);

	//getter
	double getCalories();
	string getName();
	string getDate();


	//setters
	void setCalories(double newCalories);
	void setName(string newName);
	void setDate(string newDate);

	void editDietGoal();

private:
	double calories;
	string name;
	string date;

};

fstream& operator>> (fstream& lhs, DietPlan& rhs);
fstream& operator<< (fstream& lhs, DietPlan& rhs);
ostream& operator<< (ostream& lhs, DietPlan& rhs);

