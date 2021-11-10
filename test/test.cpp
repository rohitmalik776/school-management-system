#include <iostream>
using namespace std;

class Person{
    public:
    int name, id, group;
    virtual void create()=0;
    virtual void remove(){

    }
};

class Student: public Person{
    public:
    void create (){
        cout << "created student" << endl;
    }
};

class Teacher: public Person{
    public:
    void create (){
        cout << "created teacher" << endl;
    }
};

int main(){
    Student s1;
    cout << sizeof(s1);
    return 0;
}