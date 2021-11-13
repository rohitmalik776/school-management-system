#include <iostream>
#include <assert.h>

#include "models/student.hpp"
#include "models/admin.hpp"

#define _padding_ "\t\t"

enum PersonType
{
    Student,
    Teacher,
    SaveAndExit
};
enum MenuOption
{
    Create,
    Search,
    Read,
    Update,
    Delete,
    GoBack
};

using namespace std;

inline void drawHorizontalSeperator()
{
    cout << _padding_;
    for (int i = 0; i < 20; i++)
        cout << '*';
    cout << endl;
}

void drawMainMenu()
{
    string arr[] = {"Select an option",
                    "1.) Student",
                    "2.) Teacher",
                    "3.) Save & Exit"};
    for (auto x : arr)
    {
        cout << _padding_ << x << endl;
    }
}

PersonType selectMainMenuOption()
{
    char temp;
    while (true)
    {
        drawHorizontalSeperator();
        drawMainMenu();
        cout << _padding_;
        cin >> temp;
        switch (temp)
        {
        case '1':
        {
            return PersonType::Student;
        }
        case '2':
        {
            return PersonType::Teacher;
        }
        case '3':
        {
            return PersonType::SaveAndExit;
        }
        default:
        {
            system("cls");
            cout << _padding_ << "Try again" << endl;
            break;
        }
        }
    }
}

void drawSubMenu()
{
    string arr[] = {"Select an option", "1.) Create data for new student",
                    "2.) Search for a student",
                    "3.) Display all students",
                    "4.) Update data for an existing student",
                    "5.) Delete a record",
                    "6.) Go back"};
    for (auto x : arr)
    {
        cout << _padding_ << x << endl;
    }
}

MenuOption selectSubMenuOption()
{
    char temp;
    while (true)
    {
        drawHorizontalSeperator();
        drawSubMenu();
        cout << _padding_;
        cin >> temp;
        switch (temp)
        {
        case '1':
        {
            return MenuOption::Create;
        }
        case '2':
        {
            return MenuOption::Search;
        }
        case '3':
        {
            return MenuOption::Read;
        }
        case '4':
        {
            return MenuOption::Update;
        }
        case '5':
        {
            return MenuOption::Delete;
        }
        default:
        {
            system("cls");
            cout << _padding_ << "Try again" << endl;
            break;
        }
        }
    }
}


int main()
{
    Admin admin;

    PersonType mainMenuOption = selectMainMenuOption();
    if (mainMenuOption == PersonType::Student)
    {
    // Student menu
    STUDENTMENU:
        MenuOption menuOption = selectSubMenuOption();
        switch (menuOption)
        {
        case MenuOption::Create:
        {
            cin.ignore();
            admin.addStudent();
            goto STUDENTMENU;
            break;
        }
        case MenuOption::Search:
        {
            admin.searchStudent();
            goto STUDENTMENU;
            break;
        }
        case MenuOption::Read:
        {
            admin.viewAllStudents();
            goto STUDENTMENU;
            break;
        }
        case MenuOption::Update:
        {
            admin.updateAStudent();
            goto STUDENTMENU;
            break;
        }
        case MenuOption::Delete:
        {
            admin.removeAStudent();
            goto STUDENTMENU;
            break;
        }
        default:
            break;
        }
    }
    else if (mainMenuOption == PersonType::Teacher)
    {
        // Do something
    }
    else if (mainMenuOption == PersonType::SaveAndExit)
    {
        StudentClass::save();
        // TeacherClass::Save();
        return 0;
    }
    else
    {
        assert(0 && "No option matched in while selecting person type");
    }
    drawHorizontalSeperator();
    return 0;
}