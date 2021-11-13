#include <iostream>
#include <string>
#include <vector>

#include "student.hpp"

using namespace std;

class Admin
{
public:
    string password;
    vector<StudentClass> studentsArray;
    Admin()
    {
        password = "Password";
        studentsArray = {};
    }


    void addStudent()
    {
        // Making a temporary Student type object
        StudentClass temp;
        // Taking input of it's properties
        cout << "Enter name of the Student...\n";
        getline(cin, temp.name);

        cout << "Enter the age of the Student...\n";
        getline(cin, temp.age);

        cout << "Enter the roll no for " << temp.name << endl;
        getline(cin, temp.rollNo);

        cout << "Enter the batch for " << temp.name << endl;
        getline(cin, temp.batch);

        // Finally, adding it to the array
        studentsArray.push_back(temp);
        cout << "Student added!\n";

        system("pause");
        system("cls");
    }

    void searchStudent()
    {
        string key;
        cout << "Enter roll no. of a student to search: ";
        cin.ignore();
        getline(cin, key);

        int i = 0;
        while (i < studentsArray.size())
        {
            if (studentsArray[i].rollNo == key)
            {
                cout << studentsArray[i].name << endl
                     << studentsArray[i].rollNo << " " << studentsArray[i].batch << endl;
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

    void viewAllStudents()
    {
        for (auto x : studentsArray)
        {
            x.view();
        }
        system("pause");
        system("cls");
    }

    void updateAStudent()
    {
        if (studentsArray.size() == 0)
        {
            cout << "No students exist to modify\n";
            return;
        }
        int modselector, opselector, modifyagain = 0;
        for (int i = 0; i < studentsArray.size(); i++)
        {

            cout << i + 1 << ". " << studentsArray[i].name << endl;
        }

        cin >> modselector;

    labelModifyAgain:
        cout << "Details for " << studentsArray[modselector - 1].name << " are:\n";
        cout << "1. Name: " << studentsArray[modselector - 1].name << endl;
        cout << "2. Roll no.: " << studentsArray[modselector - 1].rollNo << endl;
        cout << "3. Batch: " << studentsArray[modselector - 1].batch << endl;

        cout << "Choose a property to modify\n";
        cin >> opselector;

        switch (opselector)
        {

        case 1:

            cout << "Enter new name for student " << studentsArray[modselector - 1].name << endl;
            cin.ignore();
            getline(cin, studentsArray[modselector - 1].name);

            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if (modifyagain)
                goto labelModifyAgain;

            break;

        case 2:

            cout << "Enter new Roll no. for student " << studentsArray[modselector - 1].name << endl;
            cin.ignore();
            getline(cin, studentsArray[modselector - 1].rollNo);
            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if (modifyagain)
                goto labelModifyAgain;

            break;

        case 3:

            cout << "Enter new batch for student " << studentsArray[modselector - 1].name << endl;
            cin.ignore();
            getline(cin, studentsArray[modselector - 1].batch);
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

    void removeAStudent()
    {

        int delselector;
        bool del, confirm;

        // Printing the names of all the available students
        for (auto x : studentsArray)
        {
            x.view();
        }

        cin >> delselector;

        cout << "Details for " << studentsArray[delselector - 1].name << " are:\n";
        cout << "1. Name: " << studentsArray[delselector - 1].name << endl;
        cout << "2. Roll no.: " << studentsArray[delselector - 1].rollNo << endl;
        cout << "3. Batch: " << studentsArray[delselector - 1].rollNo << endl;

        cout << "Do you want to delete " << studentsArray[delselector - 1].name << "?\n";
        cout << "0. No\n1. Yes\n";
        cin >> del;
        if (del)
            studentsArray.erase(studentsArray.begin() + delselector - 1);
    }
};