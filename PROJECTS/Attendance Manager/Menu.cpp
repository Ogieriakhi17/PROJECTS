#include "menu.h"

Menu::~Menu()
{

}

int Menu::displayMenu()
{
	int choice = 0;

	do {
		cout << "Class Attendance Manager 2.0" << endl;
		cout << "1. Load Course List" << endl;
		cout << "2. Load master List" << endl;
		cout << "3. Store Master List" << endl;
		cout << "4. Mark Absences" << endl;
		cout << "5. Edit Absences" << endl;
		cout << "6. Generate Report" << endl;
		cout << "7. Exit" << endl;
	} while (choice < 1 && choice >= 7);
	cin >> choice;
	return choice;
}

bool Menu::importList(ifstream &input)
{
	
	if (input.is_open())
	{
		classList->load(input);
		return true;
	}

	else
	{
		cout << "File opened unsuccessfully" << endl;
		return false;
	}
}



bool Menu::storeList(ofstream &outfile)
{
	if (outfile.is_open())
	{
		classList->store(outfile);
		return true;
	}
}









void Menu::runProgram()
{
	ifstream infile;
	ifstream secfile;
	ofstream outfile;
	
	int  secondChoice = 0;
	string trash = "";
	int choice = 0;
	
	do
	{
		choice = displayMenu();
		Node<Data>* pCur = classList->getNode();
		switch (choice)
		{
		case 1:
			infile.open("ClassList.csv");
			getline(infile, trash);
			this->importList(infile);
			infile.close();
			system("pause");
			system("cls");

			break;

		case 2:
			outfile.open("MassterList.csv");
			this->importList(secfile);
			secfile.close();

			system("pause");
			system("cls");
			break;

		case 3:
			outfile.open("MassterList.csv");
			this->storeList(outfile);
			outfile.close();

			system("pause");
			system("cls");
			break;

		case 4:
			this->classList->markAbsence();
			system("pause");
			system("cls");
		
			break;

		case 5:
			cout << "operation not supported" << endl;
			break;

		case 6:

			system("cls");

			cout << "1. Generate all Student Reports (Most recent Absence)" << endl;
			cout << "2. Reports with absences over a certain amount" << endl;
			cin >> secondChoice;

			switch (secondChoice)
			{
				
			case 1:
				system("cls");

				while (pCur != nullptr)
				{
				cout << pCur->getData();
				pCur = pCur->getNext();
				}

				system("pause");
				system("cls");
				
				break;

			case 2:

				system("cls");
				int threshold;
				cout << "please enter the threshold for absences?" << endl;
				cin >> threshold;
				while (pCur != nullptr)
				{
					if (pCur->getData().getNumAbsences() > threshold)
					{
						cout << pCur->getData();
					}
					pCur = pCur->getNext();
				}

				system("pause");
				system("cls");
				break;

			}
			break;

		case 7:

			break;
		}
	} while (choice != 7);
}
