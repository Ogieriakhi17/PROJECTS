/*Name: Osaze Ogieriakhi
* Class: CptS122 Spring 2023
* Task: Programming Assignment #5
* Description: This prgram is designed to simulate a queue manager for a 
*			customers at a supermarket including tracking their wait and 
*			processing times 
* Date: 03.06.2023
*/


#include "Node.h"

class Queue
{
public:
	Queue();
	int enqueue(Data newCustomer);
	int dequeue(void);
	void printQueue(Node* HeadP);
	unsigned int calcSumTimes(Node* pNext);

	Node* getHead(void);
	Node* getTail(void);

private: 
	Node* pHead;
	Node* pTail;
};