/*
Task: Programming Assginment #9
Class: CptS122 Spring 2023
Date: 04.18.2023
*/


#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

#include "User.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::cin;
using std::fstream;
using std::string;

class Driver : public User
{
public:
    Driver(string newName, int newAge, string newPhone, char newGen,
        bool newTraining) : User(newName, newAge, newPhone, newGen)
    {
        training = newTraining;
    }

    ~Driver() {};

    bool getTraining()
    {
        return this->training;
    }

    void setTraining()
    {
        this->training = training;
    }

private:
    bool training;
};