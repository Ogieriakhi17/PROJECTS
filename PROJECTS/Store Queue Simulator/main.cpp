/*Name: Osaze Ogieriakhi
* Class: CptS122 Spring 2023
* Task: Programming Assignment #5
* Description: This prgram is designed to simulate a queue manager for a
*			customers at a supermarket including tracking their wait and
*			processing times
* Date: 03.06.2023
*/


//#include "main.h"
#include "test.h"

int main(void)
{
	Test testFuntions;

	testFuntions.RunTests();

	srand(time(NULL));
	int runTime = 0;
	cout << "how many times do you wish to run the program?" << endl;

	cin >> runTime;
	runProgram(runTime);

}

void runProgram(int runtime)
{
	Queue expressLane, normalLane;
	int normalArrivalTime = rand() % 6 + 3,
		normalServiceTime = rand() % 6 + 3;
	int totalTime = 0;
	int normalCustomerNum = 1;
	int originalNorServiceTime = normalServiceTime;

	int expressArrivalTime = rand() % 5 + 1,
		expressServiceTime = rand() % 5 + 1,
		expressCustomerNum = 1,
		originalExServiceTime = expressServiceTime; //this is to track the time spent ni the line
												    //because the service time being decrmented results in negative service time


	for (; totalTime < runtime; ++totalTime) //looping every minute 
	{

		if (totalTime == normalArrivalTime)
		{

			int sumTime = normalLane.calcSumTimes(normalLane.getTail());
			unsigned int cusTime = originalNorServiceTime + sumTime;
			Data* customer = new Data(normalCustomerNum, normalServiceTime, cusTime);
			int success = normalLane.enqueue(*customer);

			normalArrivalTime = rand() % 6 + 3 + totalTime;//arrival time for the next customer
			normalServiceTime = rand() % 5 + 1;
			originalNorServiceTime = normalServiceTime;

			if (success == 1)
			{
				cout << "customer #" << customer->getNumCustomer() << " joined the Normal Lane" << endl;
			}

			normalCustomerNum++;
		}

		if (normalServiceTime == 0 && normalLane.getHead() != nullptr)
		{

			cout << "customer #" << normalLane.getHead()->getData()->getNumCustomer() << " has checked out from the Normal Lane" << endl;
			cout << "they were in line for " << normalLane.getHead()->getData()->getTotalTime() << "mins" << endl;
			int success = normalLane.dequeue();
		}

		else
		{//as the time loops, this is to decrementing the time for processing each customer 
			normalServiceTime--;
		}

		if (totalTime % 10 == 0)
		{
			cout << "NORMAL LANE at " << totalTime << " minutes" << endl;
			normalLane.printQueue(normalLane.getHead());
		}

		//FOR THE EXPRESS LANE 
		if (totalTime == expressArrivalTime)
		{

			int exSumTime = expressLane.calcSumTimes(expressLane.getTail());
			unsigned int exCusTime = originalExServiceTime + exSumTime;
			Data* exCustomer = new Data(expressCustomerNum, expressServiceTime, exCusTime);
			int success = expressLane.enqueue(*exCustomer);

			expressArrivalTime = rand() % 6 + 3 + totalTime;//arrival time for the next customer
			expressServiceTime = rand() % 5 + 1;
			originalExServiceTime = expressServiceTime;

			if (success == 1)
			{
				cout << "customer #" << exCustomer->getNumCustomer() << " joined the Express Lane" << endl;
			}

			expressCustomerNum++;
		}

		if (expressServiceTime == 0 && expressLane.getHead() != nullptr)
		{

			cout << "customer #" << expressLane.getHead()->getData()->getNumCustomer() << " has checked out from the Express Lane" << endl;
			cout << "they were in line for " << expressLane.getHead()->getData()->getTotalTime() << "mins" << endl;
			int success = expressLane.dequeue();
		}

		else
		{
			expressServiceTime--;
		}

		if (totalTime % 10 == 0)
		{
			cout << "EXPRESS LANE at " << totalTime << " minutes" << endl;
			expressLane.printQueue(expressLane.getHead());
		}
	}


}