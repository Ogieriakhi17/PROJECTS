#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::cin;
using std::fstream;
using std::string;

class User
{
public:
// constructor
    User(string newName, int newAge, string newPhone,
        char newGen, string newPassword)
    {
        name = newName;
        age = newAge;
        phone = newPhone;
        gender = newGen;
        password = newPassword;
    }
// destructor
   ~User() {};

    // getters
    string getName();
    int getAge();
    string getPhone();
    char getGender();
   // string getTraining();
    string getPassword();

 

    //setters
    string setName(string Name);
    int setAge(int Age);
    string setPhone(string Phone);
    char setGender(char Gender);
   // string setTraining();
    string setPassword(string newPassword);


private:
    string name;
    int age;
    string phone;
    char gender;
    string password;
    //string Training;
};