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


// Function to display all students
void displayStudents(Student students[], int count)
{
    if(count == 0)
    {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    cout << "\n========== Student Records ==========\n";

    for(int i = 0; i < count; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Roll No : " << students[i].rollNo << endl;
        cout << "Name    : " << students[i].name << endl;
        cout << "Age     : " << students[i].age << endl;
        cout << "Branch  : " << students[i].branch << endl;
        cout << "Marks   : " << students[i].marks << endl;

        cout << "-----------------------------\n";
    }
}


// Function to search student
void searchStudent(Student students[], int count)
{
    if(count == 0)
    {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    for(int i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            cout << "\n===== Student Found =====\n";

            cout << "Roll No : " << students[i].rollNo << endl;
            cout << "Name    : " << students[i].name << endl;
            cout << "Age     : " << students[i].age << endl;
            cout << "Branch  : " << students[i].branch << endl;
            cout << "Marks   : " << students[i].marks << endl;

            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "\nStudent Not Found!\n";
    }
}


// Function to update student
void updateStudent(Student students[], int count)
{
    if(count == 0)
    {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;


    for(int i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            cout << "\nStudent Found!\n";

            cout << "Enter New Name: ";
            cin >> students[i].name;

            cout << "Enter New Age: ";
            cin >> students[i].age;

            cout << "Enter New Branch: ";
            cin >> students[i].branch;

            cout << "Enter New Marks: ";
            cin >> students[i].marks;


            cout << "\nStudent Updated Successfully!\n";

            found = true;
            break;
        }
    }


    if(found == false)
    {
        cout << "\nStudent Not Found!\n";
    }
}


// Function to delete student
void deleteStudent(Student students[], int &count)
{
    if(count == 0)
    {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    int roll;
    bool found = false;

    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;


    for(int i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            for(int j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            count--;

            cout << "\nStudent Deleted Successfully!\n";

            found = true;
            break;
        }
    }


    if(found == false)
    {
        cout << "\nStudent Not Found!\n";
    }
}



int main()
{
    Student students[100];

    int count = 0;
    int choice;


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
                cout << "\nThank You for Using Student Management System!\n";
                break;


            default:
                cout << "\nInvalid Choice!\n";
        }


    }while(choice != 6);


    return 0;
}