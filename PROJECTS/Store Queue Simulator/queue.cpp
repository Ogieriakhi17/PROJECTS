/*Name: Osaze Ogieriakhi
* Class: CptS122 Spring 2023
* Task: Programming Assignment #5
* Description: This prgram is designed to simulate a queue manager for a
*			customers at a supermarket including tracking their wait and
*			processing times
* Date: 03.06.2023
*/


#include "queue.h"


Queue::Queue()
{
	this->pHead = nullptr;
	this->pTail = nullptr;
}


Node* Queue::getHead(void)
{
	return pHead;
}

Node* Queue::getTail(void)
{
	return pTail;
}


int Queue::enqueue(Data newCustomer)
{
	Data* pData = new Data(newCustomer);

	Node* pMem = new Node (pData);
	int success = 0;

	if (pMem != nullptr)
	{
		success = 1;

		if (this->pHead == nullptr)
		{
			//the list is empty
			this->pHead = this->pTail = pMem;

		}
		else
		{
			this->pTail->setNextPtr(pMem);
			this->pTail = pMem;
		}
	}
	return success;
}
int Queue::dequeue(void)
{
	Node* pTemp = nullptr;
	int success = 0;

	if (pHead == pTail)
	{
		//only one Node
		pTemp = pHead;
		pHead = pTail = nullptr;
		delete pTemp;
		success = 1;
	}

	else
	{
		pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
		success = 1;
	}

	return success = 0;
}

void Queue::printQueue(Node* HeadP)
{
	if (HeadP != nullptr)
	{
		cout << "[" << HeadP->getData()->getNumCustomer() << "] <--";
		printQueue(HeadP->getNext());
	}
	else
	{
		cout << endl;
	}
}

unsigned int Queue::calcSumTimes(Node* pNext)
{
	int sum = 0;
	if (pNext != nullptr)
	{
		sum = pNext->getData()->getServiceTime();
		return calcSumTimes(pNext->getNext()) + sum;
	}
	return sum;
}