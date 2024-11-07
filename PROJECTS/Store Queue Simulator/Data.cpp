/*Name: Osaze Ogieriakhi
* Class: CptS122 Spring 2023
* Task: Programming Assignment #5
* Description: This prgram is designed to simulate a queue manager for a
*			customers at a supermarket including tracking their wait and
*			processing times
* Date: 03.06.2023
*/
#include "Data.h"

int Data::getNumCustomer(void)
{
	return this->numCustomer;
}
int Data::getServiceTime(void)
{
	return this->serviceTime;
}
int Data::getTotalTime(void)
{
	return this->totalTime;
}