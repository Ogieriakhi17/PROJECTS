#include "dietPlan.h"

DietPlan::DietPlan()
{
	calories = 0;
	name = '\0';
	date = '\0';

}

DietPlan::DietPlan(double nCalories, string name, string date)
{
	setCalories(nCalories);
	setDate(date);
	setName(name);
}

double DietPlan::getCalories()
{
	return calories;

}
string DietPlan::getName()
{
	return name;
}
string DietPlan::getDate()
{
	return date;
}


void DietPlan::setCalories(double newCalories)
{
	if (newCalories > -1)
	{
		calories = newCalories;
	}
}

void DietPlan::setName(string newName)
{

	name = newName;
}

void DietPlan::setDate(string newDate)
{

	date = newDate;
}


void DietPlan::editDietGoal()
{
	double newGoal;
	cout << "what do you want the new goal to be?" << endl;
	cin >> newGoal;

	this->setCalories(newGoal);

}

fstream& operator>> (fstream& lhs, DietPlan& rhs)
{

	string namedata;
	string datedata;
	double calories;
	string trash;

	getline(lhs, namedata);
	rhs.setName(namedata);

	
	getline(lhs, trash);
	calories = stof(trash);
	rhs.setCalories(calories);

	
	getline(lhs, datedata);
	rhs.setDate(datedata);

	getline(lhs, trash);
	return lhs;
}

ostream& operator<< (ostream& lhs, DietPlan& rhs)
{
	lhs << "Plan Name: " << rhs.getName() << endl;
	lhs << "Calorie Goal: " << rhs.getCalories() << endl;
	lhs << "Date: " << rhs.getDate() << endl; 

		return lhs;
}

fstream& operator<< (fstream& lhs, DietPlan& rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl;
	lhs << endl;
	return lhs;
}
