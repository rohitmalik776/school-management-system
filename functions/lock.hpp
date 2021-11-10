#include<iostream>
#include<string>

using namespace std;

// A simple function to set a password to the project
void lock()
{

    string admin = "admin";
    string password = "Passw0rd";

    while (1)
    {

        system("cls");

        cout << "Default username is: 'Admin'" << endl;
        cout << "Default password is: 'Passw0rd'" << endl;
        cout << "Enter username: ";
        getline(cin, admin);
        cout << "Enter password: ";
        getline(cin, password);
        if (password == "Passw0rd")
            return;
        else
            cout << "Wrong username/password...\n Please try again";
        system("pause");
    }
}