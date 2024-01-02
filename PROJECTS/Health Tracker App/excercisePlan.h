/*Name: Osaze Ogieriakhi
Class: CptS 122 Spring 2023
Task: Programming Assignment #4
Description: This program is desgined be a diet and excercise plan manager.
			It reads in users excercise and diet plans and allow the user
			edit certain aspects of their plans.
Date: 02.23.2023
*/

#pragma once

#include "dietPlan.h"

class ExcercisePlan
{
public:
	//constructor
	ExcercisePlan();
	ExcercisePlan(double nGoal, string planName, string nplanDate);
	//ExcercisePlan(ExcercisePlan &copy);

	//setters
	void setStepsGoal(double nGoal);
	void setPlanName(string nName);
	void setPlanDate(string nDate);

	//getters
	int getGoal();
	string getPlanName();
	string getDate();


	void editExcerciseGoal();

private:
	int stepGoal;
	string planName;
	string planDate;
};

//This the operator defintion for reading a diet plan from the file
fstream& operator>> (fstream& lhs, ExcercisePlan& rhs);

//This operator is for printing out a plan to the screen
ostream& operator<< (ostream& lhs, ExcercisePlan& rhs);

//This operator is defined for reading a excercise plan from a file
fstream& operator<< (fstream& lhs, ExcercisePlan& rhs);


