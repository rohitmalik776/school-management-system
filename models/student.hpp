#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "person.hpp"

using namespace std;

/// Creating a Student class
class StudentClass : public Person
{
private:

public:
    string batch, rollNo;
    StudentClass(string name, string age, string batch, string rollNo)
    {
        this->name = name;
        this->age = age;
        this->batch = batch;
        this->rollNo = rollNo;
    }

    // Print single student
    void view()
    {
        cout << this->name << " " << this->rollNo << " " << this->batch << " " << this->age << endl;
    }

    // static void save()
    // {
    //     fstream db;
    //     db.open("student_data.txt", ios::in);

    //     for (int i = 0; i < students.size(); i++)
    //     {
    //         db << students[i].name;
    //         db << endl;
    //         db << students[i].rollNo;
    //         db << endl;
    //         db << students[i].batch;
    //         db << endl;
    //     }
    //     db.close();

    //     system("pause");
    //     system("cls");
    // }

    StudentClass() {}
};




/*NOTES
base -> person
extend -> Student and teacher
member functions
function overriding
abstract class
virtual and purely virtual functions

abstraction         using abstract classes
encapsulation       getters and setters                                       kind of done
inheritance         base and derived classes                                  done
polymorphism        overloading and virtual functions
dynamic binding     using base class and purely virtual functions
file handling

*/