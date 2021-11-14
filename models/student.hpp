#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include "person.hpp"

using namespace std;

/// Creating a Student class
class StudentClass : private Person
{
private:
    friend class Admin;
    string batch, rollNo;

public:
    StudentClass(string name, string age, string batch, string rollNo)
    {
        this->name = name;
        this->age = age;
        this->batch = batch;
        this->rollNo = rollNo;
    }
    
    StudentClass(string rawData){
        char str[100];
        strcpy(str, rawData.c_str());
        
        char* tok = strtok(str, ";");
        this->name = string(tok);

        tok = strtok(NULL, ";");
        this->rollNo = string(tok);
        
        tok = strtok(NULL, ";");
        this->batch = string(tok);
        
        tok = strtok(NULL, ";");
        this->age = string(tok);
    }
  
    StudentClass() {}

    private:
    // Print single student
    void view()
    {
        cout << this->name << " " << this->rollNo << " " << this->batch << " " << this->age << endl;
    }
};




/*NOTES
base -> person                                                                yes
extend -> Student and teacher                                                 yes
member functions                                                              yes
function overriding                                                           yes
abstract class                                                                yes
virtual and purely virtual functions                                          yes

abstraction         using abstract classes                                    done
encapsulation       getters and setters                                       done
inheritance         base and derived classes                                  done
polymorphism        overloading and virtual functions                         done
dynamic binding     using base class and purely virtual functions             done
file handling                                                                 done
*/