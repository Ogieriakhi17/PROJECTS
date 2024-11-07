#include "test.h"


void Test::enqueueTestEmpty(void)
{
	cout << "ENQUEUE WITH EMPTY QUEUE" << endl;
	Queue tester;

	Data* testData = new Data(4, 5, 6);
	tester.enqueue(*testData);

	if (tester.getHead()->getData()->getNumCustomer() == testData->getNumCustomer())
	{
		cout << "Customer has been added to the Queue" << endl;
	}

	else
	{
		cout << "Enqueuing failed" << endl;
	}
}
void Test::enqueueTestNotEmpty(void)
{
	cout << "TESTING ENQUEUE WITH NON-EMPTY QUEUE" << endl;
	Queue tester;

	Data* firstData = new Data(4, 5, 6);
	tester.enqueue(*firstData);

	Data* secondData = new Data(7, 8, 9);
	tester.enqueue(*secondData);

	if (tester.getTail()->getData()->getNumCustomer() == secondData->getNumCustomer())
	{
		cout << " Enqueue of the second Customer was sucessful" << endl;
	}

	else
	{
		cout << "Enqueue failed" << endl;
	}
}


void Test::dequeueTestOneNode(void)
{
	cout << "TESTING FOR DELETING WITH ONE NODES" << endl;
	Queue tester;

	Data* firstData = new Data(4, 5, 6);
	tester.enqueue(*firstData);
	tester.dequeue();
	
	if(tester.getHead() == nullptr)
	{
		cout << "Dequeue successful" << endl;
	}
	else if (tester.getHead()->getData()->getNumCustomer() != firstData->getNumCustomer())
	{
		cout << "Dequeue failed" << endl;
	}

}
void Test::dequeueTestTwoNode(void)
{
	cout << "TESTING FOR DELETING WITH TWO NODES" << endl;
	Queue tester;

	Data* firstData = new Data(4, 5, 6);
	tester.enqueue(*firstData);

	Data* secondData = new Data(7, 8, 9);
	tester.enqueue(*secondData);

	tester.dequeue();

	if (tester.getHead()->getData()->getNumCustomer() != secondData->getNumCustomer())
	{
		cout << "Dequeue failed, Customer 2 not at front of Line" << endl;
	}

	else
	{
		cout << "Dequeue successful" << endl;
	}
}

void Test::Twenty_FourTest(void)
{
	cout << "simulating for a 24hr period" << endl;
	runProgram(1440);
}

void Test::RunTests(void)
{
	enqueueTestEmpty();
	system("pause");
	system("cls");
	enqueueTestNotEmpty();
	system("pause");
	system("cls");
	dequeueTestOneNode();
	system("pause");
	system("cls");
	dequeueTestTwoNode();
	system("pause");
	system("cls");
	Twenty_FourTest();
	system("pause");
	system("cls");

}