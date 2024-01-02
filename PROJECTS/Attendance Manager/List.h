/*Name: Osaze Ogieriakhi
Class: CptS122 Spring 2023
Task: Progrmming Assignment #7
Description: This program is written to manage attandnace of students
		in a claas, allowing the user to print, read in attendace as well
		as edit.
Date: 02.29.2023
*/

//#include "Data.h"
#pragma once
#include "Node.h"


template <class T>
class List
{
public:
	List()
	{
		mpHead = nullptr;
	}  

	List(const List& copy);
	~List() {} ;
	bool insertFront(T newData);
	bool store(ofstream &outfile);
	bool markAbsence();
	bool load(ifstream &infile);
	Node<Data>* getNode();
	Node<Data>* mpHead;


private:
};





template <class T>
List<T>::List(const List& copy)
{
	copy.mpHead = this->mpHead;
}

template <class T>
bool List<T>::insertFront(T newData)
{
	bool status = false;
	Node<Data>* pTemp = new Node<Data>(newData);


	if (this->mpHead == nullptr)
	{
		this->mpHead = pTemp;
	}

	else if (pTemp != nullptr)
	{

		pTemp->setNextPtr(mpHead);
		mpHead = pTemp;
		status = true;
	}

	return status;
}


template <class T>
bool List<T>::load(ifstream &infile)
{
	bool success = false;
	string line;

	while (!infile.eof())
	{

		getline(infile, line);
		Data pNew = new Data(line);
		insertFront(pNew);
		success = true;

	}
	return success;
}

template <class T>
bool List<T>::store(ofstream &outfile)
{
	Node<Data>* pCur = this->mpHead;

	while (pCur != nullptr)
	{
		outfile << pCur->getData();
		pCur = pCur->getNext();
	}
	cout << "Records stored" << endl;
	return true;
}


template <class T>
bool List<T>::markAbsence()
{
	int attendance = 0;
	Node<Data>* pCur = this->mpHead;

	while (pCur != nullptr)
	{
		cout << "Student: " << pCur->getData().getName() << endl;
		cout << "Were they present today? (1) YES (2) NO" << endl;
		cin >> attendance;

		switch (attendance)
		{
		case 1:
			pCur = pCur->getNext();
			break;

		case 2:
			//call the add absecne 
			pCur->getData().addAbsence();
			pCur = pCur->getNext();
			break;
		}
	}
	return true;
}

template <class T>
Node<Data>* List<T>::getNode()
{
	return this->mpHead;
}

