#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <fstream>
#include <chrono>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::getline;
using std::ostream;




template <class T>
class Stack
{
public: 
	//Stack(int newSize = 0);
	~Stack();
	Stack()
	{
		maxSize = 100;
		currentSize = 0;
		//pTop = new T[100];
	}
	int getSize();


	bool push(T& newStudent);
	bool pop(T& deletedItem);
	T peek();
	


private:
	T pTop[100];
	int currentSize;
	int maxSize;
};

//template <class T>
//Stack<T>::Stack(int newSize)
//{
//	int maxSize = 100;
//	currentSize = newSize;
//	//pTop = new T[100];
//}

template<class T>
Stack<T>::~Stack()
{
	delete pTop;
}

template<class T>
int Stack<T>::getSize()
{
	return this->currentSize;
}

template<class T>
bool Stack<T>::push(T& newStudent)
{

	if (currentSize <= maxSize)//there is still space on the Stack
	{
		pTop[currentSize] = newStudent;
		++currentSize;
		return true;
	}
	
	else
	{
		cout << "no space on stack" << endl;
		return false;
	}
	
}

template<class T>
bool Stack<T>::pop(T& deletedItem)
{
	if (this->currentSize != 0)
	{
		currentSize--;
		deletedItem = pTop[currentSize];
		//free(deletedItem);
		return true;
	}

	cout << "there is nothing in the stack" << endl;
	return false;
}

template<class T>
T Stack<T>::peek()
{
	if (this->currentSize != 0)
	{
		return pTop[currentSize - 1];
	}

	else
	{
		cout << "stack is empty" << endl;
	}
	
}
