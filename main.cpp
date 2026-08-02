#include<iostream>

#include "Student.h"
#include "FileHandler.h"

using namespace std;


int main()
{
    Student students[100];

    int count = 0;

    int choice;


    // Load old data when program starts
    loadFromFile(students, count);



    do
    {
        cout << "\n========== Student Management System ==========\n";

        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";


        cout << "\nEnter your choice: ";
        cin >> choice;



        switch(choice)
        {
            case 1:
                addStudent(students, count);
                break;


            case 2:
                displayStudents(students, count);
                break;


            case 3:
                searchStudent(students, count);
                break;


            case 4:
                updateStudent(students, count);
                break;


            case 5:
                deleteStudent(students, count);
                break;


            case 6:
                cout << "\nThank You For Using Student Management System!\n";
                break;


            default:
                cout << "\nInvalid Choice!\n";
        }


    }while(choice != 6);



    return 0;
}