#include "FitnessAppWrapper.h"


void FitnessAppWrapper::loadDailyPlan(fstream& infile, DietPlan& plan)
{
	infile >> plan;
}


void FitnessAppWrapper::loadDailyPlan(fstream& infile, ExcercisePlan& plan)
{
	infile >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& infile, DietPlan plan[])
{
	

	for (int index = 0; index < 7; ++index)
	{
		loadDailyPlan(infile, plan[index]);
		
		//cout << endl;
	}
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& infile, ExcercisePlan plan[])
{
	for (int index = 0; index < 7; ++index)
	{
		loadDailyPlan(infile, plan[index]);
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan weeksDietPlan)
{
	
	cout << weeksDietPlan << endl;
}

void FitnessAppWrapper::displayDailyPlan(ExcercisePlan weeksExcercisePlan)
{
	cout << weeksExcercisePlan << endl;
}


void FitnessAppWrapper::displayWeeklyPlan(DietPlan dietArray[])
{
	for (int index = 0; index < 7; ++index)
	{
		displayDailyPlan(dietArray[index]);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(ExcercisePlan excerciseArray[])
{
	for (int index = 0; index < 7; ++index)
	{
		displayDailyPlan(excerciseArray[index]);
	}
}

void FitnessAppWrapper::storeDailyPlan(fstream& outfile, DietPlan& plan)
{
	outfile << plan;
	
}


void FitnessAppWrapper::storeDailyPlan(fstream& outfile, ExcercisePlan& plan)
{
	outfile << plan;
	
}
 
void FitnessAppWrapper::storeWeeklyPlan(fstream& outfile, DietPlan plan[])
{
	for (int index = 0; index < 7; ++index)
	{
		storeDailyPlan(outfile, plan[index]);
		
	}
}


void FitnessAppWrapper::storeWeeklyPlan(fstream& outfile, ExcercisePlan plan[])
{
	for (int index = 0; index < 7; ++index)
	{
		storeDailyPlan(outfile, plan[index]);
	}
}



int FitnessAppWrapper::displayMenu(void)
{
	int choice = 0;

	cout << "1. Load Weekly Diet plan from file" << endl;
	cout << "2. Load weekly excercise from the file" << endl;
	cout << "3. Store weekly diet to file" << endl;
	cout << "4. Store weekly excercise to file" << endl;
	cout << "5. Display weekly diet plan to screen" << endl;
	cout << "6. Display weekly excercise plan to screen" << endl;
	cout << "7. Edit daily diet plan" << endl;
	cout << "8. Edit daily excercise plan" << endl;
	cout << "9. Exit" << endl;

	cin >> choice;
	return choice;

}



FitnessAppWrapper::FitnessAppWrapper()
{


}

void FitnessAppWrapper::runApp(void)
{
	int choice = 0, cap = 0;
	DietPlan weeksDietPlan[7];
	ExcercisePlan weeksExcercisePlan[7];
	fstream dietFile;
	fstream excerciseFile;

	do
	{
	
		

		choice = displayMenu();
		string dat;

		switch (choice)
		{
		case 1:
			dietFile.open("checker.txt", std::ios::in);
	
			if (dietFile.is_open())
			{

				loadWeeklyPlan(dietFile, weeksDietPlan);
				dietFile.close();
				system("cls");
				cout << "Plan loaded successfully" << endl;

			}
			else
			{
				cout << "Error opening file" << endl;
			}
			break;

		case 2:
			excerciseFile.open("sapa.txt", std::ios::in);
			
			if (excerciseFile.is_open())
			{
				loadWeeklyPlan(excerciseFile, weeksExcercisePlan);
				excerciseFile.close();
				system("cls");
				cout << "Plan loaded successfully" << endl;
			}
			else
			{
				cout << "Error opening file" << endl;
			}
			break;
		case 3:
			
			dietFile.open("checker.txt", std::ios::out);
			if (dietFile.is_open())
			{
				storeWeeklyPlan(dietFile, weeksDietPlan);
				dietFile.close();
				system("cls");
				cout << "Plans stored successfully" << endl;
			}
			
			else {
				cout << "Error opening file" << endl;
			}
			break;

		case 4:
			excerciseFile.open("sapa.txt", std::ios::out);
			if (excerciseFile.is_open())
			{
				storeWeeklyPlan(excerciseFile, weeksExcercisePlan);
				excerciseFile.close();
				system("cls");
				cout << "Plans stored successfully" << endl;
			}

			else
			{
				cout << "Error opening file" << endl;
			}
			break;

		case 5:
			system("cls");
			displayWeeklyPlan(weeksDietPlan);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			displayWeeklyPlan(weeksExcercisePlan);
			system("pause");
			system("cls");
			break;

		case 7:
			cout << "which day you want to edit" << endl;
			cin >> cap;
			weeksDietPlan[cap].editDietGoal();
			displayDailyPlan(weeksDietPlan[cap]);
			system("pause");
			system("cls");
			break;

		case 8:
			cout << "which day you want to edit" << endl;
			cin >> cap;
			weeksExcercisePlan[cap].editExcerciseGoal();
			system("pause");
			system("cls");
			break;

		case 9:
			dietFile.open("checker.txt");
			storeWeeklyPlan(dietFile, weeksDietPlan);
			dietFile.close();

			excerciseFile.open("sapa.txt");
			storeWeeklyPlan(excerciseFile, weeksExcercisePlan);
			excerciseFile.close();
			break;

		}
	} while (choice != 9);
}






FitnessAppWrapper::~FitnessAppWrapper()
{
	

}






