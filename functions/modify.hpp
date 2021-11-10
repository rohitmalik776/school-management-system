#include<iostream>
#include<vector>

#include"../models/student.hpp"

using namespace std;

/// Function to modify students
void studentmodify(vector<student> students)
{

    int modselector, opselector, modifyagain = 0;

    for (int i = 0; i < students.size(); i++)
    {

        cout << i + 1 << ". " << students[i].name << endl;
    }

    cin >> modselector;

labelModifyAgain:
    cout << "Details for " << students[modselector - 1].name << " are:\n";
    cout << "1. Name: " << students[modselector - 1].name << endl;
    cout << "2. Roll no.: " << students[modselector - 1].rollno << endl;
    cout << "3. Batch: " << students[modselector - 1].batch << endl;

    cout << "Choose a property to modify\n";
    cin >> opselector;

    switch (opselector)
    {

    case 1:

        cout << "Enter new name for student " << students[modselector - 1].name << endl;
        cin.ignore();
        getline(cin, students[modselector - 1].name);

        cout << "Would you like to modify something else too?\n";
        cout << "0. No\n1. Yes\n";
        cin >> modifyagain;
        if (modifyagain)
            goto labelModifyAgain;

        break;

    case 2:

        cout << "Enter new Roll no. for student " << students[modselector - 1].name << endl;
        cin.ignore();
        getline(cin, students[modselector - 1].rollno);
        cout << "Would you like to modify something else too?\n";
        cout << "0. No\n1. Yes\n";
        cin >> modifyagain;
        if (modifyagain)
            goto labelModifyAgain;

        break;

    case 3:

        cout << "Enter new batch for student " << students[modselector - 1].name << endl;
        cin.ignore();
        getline(cin, students[modselector - 1].batch);
        cout << "Would you like to modify something else too?\n";
        cout << "0. No\n1. Yes\n";
        cin >> modifyagain;
        if (modifyagain)
            goto labelModifyAgain;

        break;

    default:

        cout << "No matching option found!\n";
    }

    system("pause");
    system("cls");
}