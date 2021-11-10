#pragma once

#include<string>
using namespace std;
/// Creating a student class
class student
{
    /// Using access modifier to make contents below, public
public:
    /// Declaring required student properties
    string name, rollno, batch;

    /// Class constructor
    student()
    {
    }
};

/*NOTES
base -> person
extend -> student and teacher
member functions
function overriding
abstract class
virtual and purely virtual functions

abstraction         using abstract classes
encapsulation       getters and setters
inheritance         base and derived classes
polymorphism        overloading and virtual functions
dynamic binding     using base class and purely virtual functions
file handling

*/