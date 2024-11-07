#include "excercisePlan.h"

ExcercisePlan::ExcercisePlan()
{
	stepGoal = 0;
	planName = '\0';
	planDate = '\0';

}

void ExcercisePlan::setStepsGoal(double nGoal)
{
	if (nGoal > 0)
	{
		stepGoal = nGoal;
	}
}

void ExcercisePlan::setPlanName(string nName)
{
	planName = nName;
}

void ExcercisePlan::setPlanDate(string nDate)
{
	planDate = nDate;
}

ExcercisePlan::ExcercisePlan(double nGoal, string newplanName, string nplanDate)
{
	setStepsGoal(nGoal);
	setPlanName(newplanName);
	setPlanDate(nplanDate);
}

int ExcercisePlan::getGoal()
{
	return stepGoal;
}

string ExcercisePlan::getPlanName()
{
	return planName;
}
string ExcercisePlan::getDate()
{
	return planDate;
}

void ExcercisePlan::editExcerciseGoal()
{
	double newGoal;
	cout << "what do you want the new goal to be?" << endl;
	cin >> newGoal;

	this->setStepsGoal(newGoal);

}


fstream& operator>> (fstream& lhs, ExcercisePlan& rhs)
{
	string namedata;
	string datedata;
	string trash;
	double calories;

	getline(lhs, namedata);
	rhs.setPlanName(namedata);

	getline(lhs, trash);
	calories = stof(trash);
	rhs.setStepsGoal(calories);

	getline(lhs, datedata);
	rhs.setPlanDate(datedata);

	getline(lhs, trash);
	return lhs;
}

ostream& operator<< (ostream& lhs, ExcercisePlan& rhs)
{
	lhs << "Plan Name: " << rhs.getPlanName() << endl;
	lhs << "Calorie Goal: " << rhs.getGoal() << endl;
	lhs << "Date: " << rhs.getDate() << endl;
	return lhs;
}

fstream& operator<< (fstream& lhs, ExcercisePlan& rhs)
{
	lhs <<  rhs.getPlanName() << endl;
	lhs <<  rhs.getGoal() << endl;
	lhs <<  rhs.getDate() << endl;
	lhs << endl;
	return lhs;
}