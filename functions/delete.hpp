#include<iostream>
#include<string>
#include<vector>

#include"../models/student.hpp"

using namespace std;

/// Function to delete students
void studentdelete(vector<student> students)
{

    int delselector;
    bool del, confirm;

    // Printing the names of all the available students
    for (int i = 0; i < students.size(); i++)
    {

        cout << i + 1 << ". " << students[i].name << "  " << students[i].batch << "  " << students[i].rollno << endl;
    }

    cin >> delselector;

    cout << "Details for " << students[delselector - 1].name << " are:\n";
    cout << "1. Name: " << students[delselector - 1].name << endl;
    cout << "2. Roll no.: " << students[delselector - 1].rollno << endl;
    cout << "3. Batch: " << students[delselector - 1].rollno << endl;

    cout << "Do you want to delete " << students[delselector - 1].name << "?\n";
    cout << "0. No\n1. Yes\n";
    cin >> del;

    if (del)
    {

        cout << "Are you sure, you want to delete " << students[delselector - 1].name << "'s data?\n";
        cin >> confirm;

        if (confirm)
        {

            students.erase(students.begin() + delselector - 1);
            cout << "Student's data deleted successfully!\n";

            system("pause");
            system("cls");
        }
    }
}