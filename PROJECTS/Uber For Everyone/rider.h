#include <iostream>
#include<string>

using std::cout;
using std::endl;
using std::ifstream;
using std::cin;
using std::fstream;
using std::string;

class Rider
{
    public:
        // constructor
        Rider(string newDisability):User(string newName, string newAge, string newPhone,
            char newGen, string newPassword)
        {
            disability = newDisability;
      }
        string setDisability(string Disability)
        {
            Disability = this->disability;
       }
        string getDisability()
        {
            return this->disability;
        }
private:
	string disability;
};