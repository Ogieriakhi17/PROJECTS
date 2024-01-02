/*Name: Osaze Ogieriakhi
Class: CptS 122 Spring 2023
Task: Programming Assignment #4
Description: This program is desgined be a diet and excercise plan manager.
			It reads in users excercise and diet plans and allow the user
			edit certain aspects of their plans.
Date: 02.23.2023
*/
#pragma once

#include "excercisePlan.h"

class FitnessAppWrapper
{
public:

	//constructor 
	FitnessAppWrapper();

	//destructor
	~FitnessAppWrapper();

	//MEMBER FUNCTIONS

	void runApp(void);
	void loadDailyPlan(fstream& infile, DietPlan& plan);
	void loadDailyPlan(fstream& infile, ExcercisePlan& plan);

	void loadWeeklyPlan(fstream& infile, DietPlan plan[]);
	void loadWeeklyPlan(fstream& infile, ExcercisePlan plan[]);


	void displayDailyPlan(DietPlan weeksDietPlan);
	void displayDailyPlan(ExcercisePlan weeksExcercisePlan);

	void displayWeeklyPlan(DietPlan dietArray[]);
	void displayWeeklyPlan(ExcercisePlan excerciseArray[]);

	void storeDailyPlan(fstream& outfile, DietPlan& plan);
	void storeDailyPlan(fstream& outfile, ExcercisePlan& plan);

	void storeWeeklyPlan(fstream& outfile, DietPlan plan[]);
	void storeWeeklyPlan(fstream& outfile, ExcercisePlan plan[]);
	int displayMenu(void);


private:
	
	//there are no private data members

};
