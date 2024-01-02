#include "Node.h"

Node::Node(User* newData)
{
	this->pData = newData;
	this->pNext = nullptr;
}

Node* Node::getNext(void)
{
	return this->pNext;
}

User* Node::getData(void)
{
	return this->pData;
}

void Node::setData(User* newData)
{
	this->pData = newData;
}
void Node::setNext(Node* nextNode)
{
	this->pNext = nextNode;
}