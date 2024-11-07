/*Name: Osaze Ogieriakhi
* Class: CptS122 Spring 2023
* Task: Programming Assignment #5
* Description: This prgram is designed to simulate a queue manager for a
*			customers at a supermarket including tracking their wait and
*			processing times
* Date: 03.06.2023
*/

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

using std::cout;
using std::endl;
using std::ifstream;
using std::cin;
using std::fstream;
using std::string;

class Data
{
public:
	Data(int newNumCustomer = 0, int newServiceTime = 0, int newTotalTime = 0) : numCustomer(newNumCustomer),
		serviceTime(newServiceTime), totalTime(newTotalTime) {};
	int getNumCustomer(void);
	int getServiceTime(void);
	int getTotalTime(void);


private:
	int numCustomer;
	int serviceTime;
	int totalTime;
};

