#include<iostream>
#include<vector>

#include"../models/student.hpp"

using namespace std;
/// Function to view all students at once
void viewstudents(vector<student> students)
{

    for (int i = 0; i < students.size(); i++)
    {

        cout << students[i].name << " " << students[i].rollno << " " << students[i].batch << endl;
    }

    system("pause");
    system("cls");
}