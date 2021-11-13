#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person{
    public:
    string name, age;
    // virtual void add()=0;
    virtual void view()=0;
    // virtual void search()=0;
    // virtual void update()=0;
    // virtual void remove()=0;
    // virtual void save()=0;
    Person(){}
};