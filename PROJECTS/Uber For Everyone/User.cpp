#include "User.h"

string User::getName()
{
    return this->name;
}

int User::getAge()
{
    return this->age;
}

string User::getPhone()
{
    return this->phone;
}

char User::getGender()
{
    return this->gender;
}
   // string getTraining();
string User::getPassword()
{
    return this->password;
}

 //setters
string  User::setName(string Name)
{
        Name = name;
}
int User::setAge(int Age)
 {
        Age = age;
 }
string User::setPhone(string Phone)
{
        Phone = phone;
}
char User::setGender(char Gender)
{
        Gender = gender;
}
    //string setTraining();
   string User::setPassword(string newPassword)
    {
       this->password = newPassword;
    }