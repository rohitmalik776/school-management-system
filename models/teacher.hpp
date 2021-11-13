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

    TeacherClass(string rawData)
    {
        cout << "Inside teacher constructor" << endl;
        char str[100];
        strcpy(str, rawData.c_str());

        char *tok = strtok(str, ";");
        this->name = string(tok);
        tok = strtok(NULL, ";");
        this->age = string(tok);
        tok = strtok(NULL, ";");
        this->subject = string(tok);
        tok = strtok(NULL, ";");
        this->designation = string(tok);
        tok = strtok(NULL, ";");
        this->id = string(tok);
    }

    void view()
    {
        cout << name << " " << age << " " << subject << " " << designation << " " << id << endl;
    }
};