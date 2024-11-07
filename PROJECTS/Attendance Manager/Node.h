/*Name: Osaze Ogieriakhi
Class: CptS122 Spring 2023
Task: Progrmming Assignment #7
Description: This program is written to manage attandnace of students
		in a claas, allowing the user to print, read in attendace as well
		as edit.
Date: 02.29.2023
*/
#pragma once
#include "Data.h"


template <class T>
class Node
{
public:
	Node(T newData)
	{
		data = newData;
		pNext = nullptr;

	}
	Node()
	{
		data = nullptr;
		pNext = nullptr;
	}
	~Node() {} ;
	//Node(Node<T>& copy);

	T& getData(void);
	Node<T>* getNext(void);

	void setData(T newData);
	void setNextPtr(Node<T>* newNext);

private:
	T data;
	Node<T>* pNext;

};



//template <class T>
//Node<T>::Node( Node<T>& copy)
//{
//	copy.data = this->getData();
//	copy.pNext = this->getNext();
//}

template <class T>
T& Node<T>::getData()
{
	return this->data;
}

template <class T>
Node<T>* Node<T>::getNext()
{
	return this->pNext;
}

template <class T>
void Node<T>::setData(T newData)
{
	this->data = newData;
}

template <class T>
void Node<T>::setNextPtr(Node<T>* newNext)
{
	this->pNext = newNext;
}

