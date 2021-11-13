#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "person.hpp"

class TeacherClass : public Person
{
private:
public:
    string subject, designation, id;
    TeacherClass(string name, string age, string subject, string designation, string id)
    {
        this->name = name;
        this->age = age;
        this->subject = subject;
        this->designation = designation;
        this->id = id;
    }
    TeacherClass() {}
    void view()
    {
        cout << name << " " << age << " " << subject << " " << designation << " " << id << endl;
    }
};