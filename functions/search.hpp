#include<iostream>
#include<vector>

#include"../models/student.hpp"

// Function to search students by roll no
void rollsearch(string key, vector<student> students)
{
    int i = 0;
    while (i < students.size())
    {
        if (students[i].rollno == key)
        {
            cout << students[i].name << endl
                 << students[i].rollno << " " << students[i].batch << endl;
            system("pause");
            system("cls");
            return;
        }
        i++;
    }
    cout << "No such student found!" << endl;
    system("pause");
    system("cls");
}