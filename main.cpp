#include<iostream>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    int age;
    string branch;
    float marks;
};


// Function to add student
void addStudent(Student students[], int &count)
{
    cout << "\nEnter Roll No: ";
    cin >> students[count].rollNo;

    cout << "Enter Name: ";
    cin >> students[count].name;

    cout << "Enter Age: ";
    cin >> students[count].age;

    cout << "Enter Branch: ";
    cin >> students[count].branch;

    cout << "Enter Marks: ";
    cin >> students[count].marks;

    count++;

    cout << "\nStudent Added Successfully!\n";
}


int main()
{
    Student students[100];   // store maximum 100 students
    int count = 0;            // number of students
    int choice;


    do
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice)
        {
            case 1:
                addStudent(students, count);
                break;


            case 2:
                cout << "\nThank you for using the system!";
                break;


            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 2);


    return 0;
}