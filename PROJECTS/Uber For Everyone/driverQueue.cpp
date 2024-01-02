/*Name: Osaze Ogieriakhi
* Class: CptS122 Spring 2023
* Task: Programming Assignment #5
* Description: This prgram is designed to simulate a queue manager for a
*			customers at a supermarket including tracking their wait and
*			processing times
* Date: 03.06.2023
*/

#include "driverQueue.h"


Node* Queue::getHead(void)
{
	return pHead;
}

Node* Queue::getTail(void)
{
	return pTail;
}


void Queue::enqueue(User* newCustomer)
{
	Node* pData = new Node(newCustomer);

	if (pData != nullptr)
	{

		if (this->pHead == nullptr)
		{
			//the list is empty
			this->pHead = this->pTail = pData;
		}
		else
		{
			this->pTail->setNext(pData);
			this->pTail = pData;
		}
	}
}

void Queue::dequeue(void)
{
	Node* pTemp = nullptr;

	if (pHead == pTail)
	{
		//only one Node
		pTemp = pHead;
		pHead = pTail = nullptr;
		delete pTemp;
	}
	else
	{
		pTemp = pHead;
		pHead = pHead->getNext();
		delete pTemp;
	}
}

bool Queue::isEmpty()
{
	if (this->pHead == nullptr)
	{
		return true;
	}
	else return false;
}

int Queue::getLength()
{
	int count = 0;

	Node* node = pHead;

	while (node != nullptr)
	{
		node = node->getNext();
		++count;
	}

	return count;
}


//void Queue::printQueue(Node* HeadP)
//{
//	if (HeadP != nullptr)
//	{
//		cout << "[" << HeadP->getData()->getNumCustomer() << "] <--";
//		printQueue(HeadP->getNext());
//	}
//	else
//	{
//		cout << endl;
//	}
//}

//unsigned int Queue::calcSumTimes(Node* pNext)
//{
//	int sum = 0;
//	if (pNext != nullptr)
//	{
//		sum = pNext->getData()->getServiceTime();
//		return calcSumTimes(pNext->getNext()) + sum;
//	}
//	return sum;
//}