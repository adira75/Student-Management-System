#include "Student.h"
#include "FileHandler.h"


// Add Student
void addStudent(Student students[], int &count)
{
    if(count >= 100)
    {
        cout << "Student limit reached!\n";
        return;
    }


    cout << "\nEnter Roll No: ";
    cin >> students[count].rollNo;

    cin.ignore();


    cout << "Enter Name: ";
    getline(cin, students[count].name);


    cout << "Enter Age: ";
    cin >> students[count].age;

    cin.ignore();


    cout << "Enter Branch: ";
    getline(cin, students[count].branch);


    cout << "Enter Marks: ";
    cin >> students[count].marks;


    count++;

    saveToFile(students,count);


    cout << "\nStudent Added Successfully!\n";
}



// Display Students
void displayStudents(Student students[], int count)
{
    if(count == 0)
    {
        cout << "\nNo Student Records Found!\n";
        return;
    }


    cout << "\n========== Student Records ==========\n";


    for(int i=0; i<count; i++)
    {
        cout << "\nStudent " << i+1 << endl;

        cout << "Roll No : " << students[i].rollNo << endl;
        cout << "Name    : " << students[i].name << endl;
        cout << "Age     : " << students[i].age << endl;
        cout << "Branch  : " << students[i].branch << endl;
        cout << "Marks   : " << students[i].marks << endl;

        cout << "----------------------\n";
    }
}



// Search Student
void searchStudent(Student students[], int count)
{
    int roll;
    bool found=false;


    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;


    for(int i=0;i<count;i++)
    {
        if(students[i].rollNo == roll)
        {
            cout << "\nStudent Found\n";

            cout<<"Name : "<<students[i].name<<endl;
            cout<<"Age : "<<students[i].age<<endl;
            cout<<"Branch : "<<students[i].branch<<endl;
            cout<<"Marks : "<<students[i].marks<<endl;

            found=true;
            break;
        }
    }


    if(!found)
    {
        cout<<"\nStudent Not Found!\n";
    }
}



// Update Student
void updateStudent(Student students[], int count)
{
    int roll;
    bool found=false;


    cout<<"\nEnter Roll Number to Update: ";
    cin>>roll;


    for(int i=0;i<count;i++)
    {
        if(students[i].rollNo==roll)
        {
            cin.ignore();


            cout<<"Enter New Name: ";
            getline(cin,students[i].name);


            cout<<"Enter New Age: ";
            cin>>students[i].age;


            cin.ignore();


            cout<<"Enter New Branch: ";
            getline(cin,students[i].branch);


            cout<<"Enter New Marks: ";
            cin>>students[i].marks;


            saveToFile(students,count);


            cout<<"\nStudent Updated Successfully!\n";


            found=true;
            break;
        }
    }


    if(!found)
    {
        cout<<"\nStudent Not Found!\n";
    }
}



// Delete Student
void deleteStudent(Student students[], int &count)
{
    int roll;
    bool found=false;


    cout<<"\nEnter Roll Number to Delete: ";
    cin>>roll;


    for(int i=0;i<count;i++)
    {
        if(students[i].rollNo==roll)
        {

            for(int j=i;j<count-1;j++)
            {
                students[j]=students[j+1];
            }


            count--;


            saveToFile(students,count);


            cout<<"\nStudent Deleted Successfully!\n";


            found=true;
            break;
        }
    }


    if(!found)
    {
        cout<<"\nStudent Not Found!\n";
    }
}