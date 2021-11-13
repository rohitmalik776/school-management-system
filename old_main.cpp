#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// #include"models/student.hpp"
// #include"functions/add_student.hpp"
// #include"functions/search.hpp"
// #include"functions/modify.hpp"
#include"functions/lock.hpp"
// #include"functions/delete.hpp"
// #include"functions/view.hpp"
// #include"functions/fetch_store.hpp"

using namespace std;

/// declaring students as a global array of objects
// vector<student> students;
int main()
{
    system("cls");

    // Invoking "lock()" function to ask the user for username and password
    lock();

    ImportStudents(students);

    char selector;
    char search_selector;
    string key;

    /// Label for returning to menu after performing an operation
lab:

    cout << "Select an option...\n";
    cout << "1. Add a student\n";
    cout << "2. Search for a student by roll no\n";
    cout << "3. Modify a student\n";
    cout << "4. Delete a student\n";
    cout << "5. View all students\n";
    cout << "6. Save and Exit\n";

    cin >> selector;
    cin.ignore();

    switch (selector)
    {

    case '1':

        addstudent(students);
        break;

    case '2':

        cout << "Enter the roll no of the student\n";

        // cin.ignore();
        getline(cin, key);

        rollsearch(key, students);
        break;

    case '3':

        cout << "Select a student to modify\n";
        studentmodify(students);

        break;

    case '4':

        cout << "Select a student to delete\n";
        studentdelete(students);

        break;

    case '5':

        viewstudents(students);
        break;

    case '6':

        eksport(students);
        return 0;

    default:
        cout << "No matching option found\n";
        cout << "Please retry\n";
    }

    /// Jump to the start of menu
    goto lab;

    return 0;
}