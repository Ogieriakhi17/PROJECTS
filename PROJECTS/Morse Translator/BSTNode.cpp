#include "BSTNode.h"


void Node::setCharacter(char newChar)
{
	this->Character = newChar;
}
void Node::setMorseCode(string newMorse)
{
	this->morseChar = newMorse;
}
void Node::setLeftPtr(Node* leftPtr)
{
	this->mpLeft = leftPtr;
}
void Node::setRightPtr(Node* rightPtr)
{
	this->mpRight = rightPtr;
}



char Node::getCharacter()
{
	return this->Character;
}
string& Node::getMorseChar()
{
	return this->morseChar;
}
Node* Node::getLeftPtr()
{
	return this->mpLeft;
}
Node* Node::getRightPtr()
{
	return this->mpRight;
}



Node::~Node()
{
	//delete (Character);
}