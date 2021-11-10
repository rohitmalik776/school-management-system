#include<iostream>
#include<vector>
#include<fstream>

#include"../models/student.hpp"

void ImportStudents(vector<student> students)
{

    ifstream db;
    db.open("Database.txt");

    student temp;

    while (!db.eof())
    {

        getline(db, temp.name);
        getline(db, temp.rollno);
        getline(db, temp.batch);

        // To make sure, no useless data to be imported
        if (db.eof())
        {
            break;
        }
        students.push_back(temp);
    }

    db.close();
}

void eksport(vector<student> students)
{

    ofstream db;
    db.open("Database.txt");

    for (int i = 0; i < students.size(); i++)
    {
        db << students[i].name;
        db << endl;
        db << students[i].rollno;
        db << endl;
        db << students[i].batch;
        db << endl;
    }
    db.close();

    system("pause");
    system("cls");
}
