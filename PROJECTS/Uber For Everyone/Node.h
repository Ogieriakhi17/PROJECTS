#include "baseDriver.h"
#include "User.h"

class Node
{
public:
	Node(User* newData = nullptr);
	void setNextPtr(Node* pNewNext);


	Node* getNext(void);
	User* getData(void);

	//setters
	void setData(User* newData);
	Driver setNext(Node* nextNode);

private:
	User* pData;
	Node* pNext;
};
