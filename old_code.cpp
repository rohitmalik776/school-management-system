#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;


//A simple function to set a password to the project
void lock(){

    string admin = "admin";
    string password = "Passw0rd";
    
    while(1){
 
        system("cls");

        cout << "Default username is: 'Admin'"<<endl;
        cout << "Default password is: 'Passw0rd'"<<endl;
        cout << "Enter username: ";
        getline(cin, admin);
        cout << "Enter password: ";
        getline(cin, password);
        if (password == "Passw0rd")
            return;
        else cout << "Wrong username/password...\n Please try again";
        system("pause"); 
    }
}

///Creating a student class
class student{

///Using access modifier to make contents below, public
    public:

///Declaring required student properties
    string name, rollno, batch;

///Class constructor
    student(){
    }

};

///declaring students as a global array of objects
vector<student> students;

/// Function to add a student
void addstudent(){

    //Making a temporary student type object
    student temp;

    //Taking input of it's properties
    cout<<"Enter name of the student...\n";
    getline(cin,temp.name);

    cout << "Enter the roll no for " << temp.name << endl;
    getline(cin, temp.rollno);

    cout << "Enter the batch for " << temp.name << endl;
    getline(cin, temp.batch);

    //Finally, adding it to the array
    students.push_back(temp);
    cout << "Student added!\n";

    system ( "pause" );
    system ( "cls" );

}

//This is similar to namesearch function, it just compares the roll numbers.
void rollsearch ( string key ){

    int i = 0;

    while( i < students.size() ){

        if ( students[i].rollno == key ){

            cout << students[i].name << endl << students[i].rollno<<" "<< students[i].batch<<endl;

            system ( "pause" );
            system ( "cls" );
            return;

        }

    i++;

    }

    cout << "No such student found!" << endl ;
    
    system ( "pause" );
    system ( "cls" );

}

///Function to modify students

void studentmodify(){

    int modselector, opselector, modifyagain=0;

    for( int i = 0; i < students.size() ; i++ ){

        cout << i + 1 << ". " << students[i].name << endl ;

    }

    cin >> modselector ;

    labelModifyAgain:
    cout << "Details for " << students[modselector-1].name << " are:\n";
    cout << "1. Name: " << students[modselector-1].name << endl;
    cout << "2. Roll no.: " << students[modselector-1].rollno << endl;
    cout << "3. Batch: " << students[modselector-1].batch << endl;

    cout << "Choose a property to modify\n";
    cin >> opselector;

    switch ( opselector ){

        case 1:

            cout << "Enter new name for student " << students[modselector-1].name << endl;
            cin.ignore();
            getline ( cin, students[modselector-1].name ) ;
            
            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if(modifyagain)
                goto labelModifyAgain;

            break;

        case 2:

            cout << "Enter new Roll no. for student " << students[modselector-1].name << endl;
            cin.ignore();
            getline ( cin, students[modselector-1].rollno ) ;
            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if(modifyagain)
                goto labelModifyAgain;

            break;

        case 3:

            cout << "Enter new batch for student " << students[modselector-1].name << endl;
            cin.ignore();
            getline (cin, students[modselector-1].batch );
            cout << "Would you like to modify something else too?\n";
            cout << "0. No\n1. Yes\n";
            cin >> modifyagain;
            if(modifyagain)
                goto labelModifyAgain;

            break;

        default:

            cout << "No matching option found!\n";

    }

    system ( "pause" );
    system ( "cls" );
}

/// Function to delete students
void studentdelete(){

    int delselector;
    bool del, confirm;

    //Printing the names of all the available students
    for( int i = 0; i < students.size() ; i++ ){

        cout << i + 1 << ". " << students[i].name << "  " << students[i].batch << "  " << students[i].rollno << endl ;

    }

    cin >> delselector ;

    cout << "Details for " << students[delselector-1].name << " are:\n";
    cout << "1. Name: " << students[delselector-1].name << endl;
    cout << "2. Roll no.: " << students[delselector-1].rollno << endl;
    cout << "3. Batch: " << students[delselector-1].rollno << endl;

    cout << "Do you want to delete " << students[delselector-1].name << "?\n";
    cout << "0. No\n1. Yes\n";
    cin >> del;

    if ( del ){

        cout << "Are you sure, you want to delete " << students[delselector-1].name <<"'s data?\n";
        cin >> confirm;
        
        if ( confirm ){

            students.erase(students.begin() + delselector - 1);
            cout << "Student's data deleted successfully!\n" ;

            system ( "pause" );
            system ( "cls" );

        }

    }

}

/// Function to view all students at once
void viewstudents(){

    for ( int i = 0; i < students.size(); i++){

        cout << students[i].name << " " << students[i].rollno << " " << students[i].batch <<endl;

    }

    system ( "pause" );
    system ( "cls" );

}

void ImportStudents(){

    ifstream db;
    db.open("Database.txt");

    student temp;

    while ( !db.eof() ){

        getline(db, temp.name);
        getline(db, temp.rollno);
        getline(db, temp.batch);

        //To make sure, no useless data to be imported
        if(db.eof()){
            break;
        }
        students.push_back(temp);

    }

    db.close();

}

void eksport(){

    ofstream db;
    db.open("Database.txt");

    for (int i = 0; i < students.size(); i++){
        db << students[i].name;
        db << endl;
        db << students[i].rollno;
        db << endl;
        db << students[i].batch;
        db << endl;
    }
    db.close();

    system ("pause");
    system ("cls");
}


int main(){

//    system ( "color 30" );
    system ( "cls" );
    
    //Invoking "lock()" function to ask the user for username and password
    lock();
    
    ImportStudents();

    char selector;
    char search_selector;
    string key;

///Label for returning to menu after performing an operation
    lab:

    cout<<"Select an option...\n";
    cout<<"1. Add a student\n";
    cout<<"2. Search for a student by roll no\n";
    cout<<"3. Modify a student\n";
    cout<<"4. Delete a student\n";
    cout<<"5. View all students\n";
    cout<<"6. Save and Exit\n";

    cin>>selector;
    cin.ignore();

    switch(selector){

        case '1':

            addstudent();
            break;

        case '2':

            cout << "Enter the roll no of the student\n";

            // cin.ignore();
            getline ( cin , key );

            rollsearch(key);
            break;


        case '3':

            cout << "Select a student to modify\n" ;
            studentmodify();
            
            break;

        case '4':
            
            cout << "Select a student to delete\n" ;
            studentdelete();

            break;

        case '5':

            viewstudents();
            break;

        case '6':

            eksport();
            return 0;

        default:
            cout << "No matching option found\n" ;
            cout << "Please retry\n" ;

    }

///Jump to the start of menu
    goto lab;

    return 0;

}