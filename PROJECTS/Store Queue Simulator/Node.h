/*Name: Osaze Ogieriakhi
* Class: CptS122 Spring 2023
* Task: Programming Assignment #5
* Description: This prgram is designed to simulate a queue manager for a
*			customers at a supermarket including tracking their wait and
*			processing times
* Date: 03.06.2023
*/
#include "Data.h"



class Node
{
public:
	Node(Data* newData = nullptr);
	void setNextPtr(Node* pNewNext);
	

	
	//getter
	Node* getNext(void);
	Data* getData(void);

	//setters
	void setData(Data* newData);
	void setNext(Node* nextNode);
private:
	Data* pData;
	Node* pNext;
};