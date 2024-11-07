#include "Node.h"

class Queue
{
public:
	//Constructor
	Queue()
	{
		pHead = pTail = nullptr;
	};

	~Queue() {};

	void enqueue(User* newData);
	void dequeue(void);

	Node* getHead(void);
	Node* getTail(void);

	bool isEmpty();

	int getLength();

private:
	Node* pHead;
	Node* pTail;
};