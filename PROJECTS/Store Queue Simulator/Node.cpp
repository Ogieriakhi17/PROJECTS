/*Name: Osaze Ogieriakhi
* Class: CptS122 Spring 2023
* Task: Programming Assignment #5
* Description: This prgram is designed to simulate a queue manager for a
*			customers at a supermarket including tracking their wait and
*			processing times
* Date: 03.06.2023
*/
#include "Node.h"

Node::Node(Data* newData)
{
	this->setData(newData);
	this->setNext(nullptr);
}

void Node::setNextPtr(Node* pNewNext)
{
	this->pNext = pNewNext;
}
Node* Node::getNext(void)
{
	return this->pNext;
}

Data* Node::getData(void)
{
	return this->pData;
}

void Node::setData(Data* newData)
{
	this->pData = newData;
}
void Node::setNext(Node* nextNode)
{
	this->pNext = nextNode;
}