#include<iostream>
#include<vector>

#include"../models/student.hpp"

/// Function to add a student
void addstudent(vector<student> students)
{

    // Making a temporary student type object
    student temp;

    // Taking input of it's properties
    cout << "Enter name of the student...\n";
    getline(cin, temp.name);

    cout << "Enter the roll no for " << temp.name << endl;
    getline(cin, temp.rollno);

    cout << "Enter the batch for " << temp.name << endl;
    getline(cin, temp.batch);

    // Finally, adding it to the array
    students.push_back(temp);
    cout << "Student added!\n";

    system("pause");
    system("cls");
}