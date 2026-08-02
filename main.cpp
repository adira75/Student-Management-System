#include<iostream>
#include<string>
#include<fstream>

using namespace std;


struct Student
{
    int rollNo;
    string name;
    int age;
    string branch;
    float marks;
};



// Save data to file
void saveToFile(Student students[], int count)
{
    ofstream file("students.txt");


    for(int i = 0; i < count; i++)
    {
        file << students[i].rollNo << endl;
        file << students[i].name << endl;
        file << students[i].age << endl;
        file << students[i].branch << endl;
        file << students[i].marks << endl;
    }


    file.close();
}



// Load data from file
void loadFromFile(Student students[], int &count)
{
    ifstream file("students.txt");


    if(!file)
    {
        return;
    }


    while(file >> students[count].rollNo)
    {
        file.ignore();


        getline(file, students[count].name);


        file >> students[count].age;


        file.ignore();


        getline(file, students[count].branch);


        file >> students[count].marks;


        count++;
    }


    file.close();
}



// Add Student
void addStudent(Student students[], int &count)
{
    if(count >= 100)
    {
        cout << "\nStudent limit reached!\n";
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


    for(int i = 0; i < count; i++)
    {
        cout << "\nStudent " << i+1 << endl;

        cout << "Roll No : " << students[i].rollNo << endl;
        cout << "Name    : " << students[i].name << endl;
        cout << "Age     : " << students[i].age << endl;
        cout << "Branch  : " << students[i].branch << endl;
        cout << "Marks   : " << students[i].marks << endl;

        cout << "-----------------------------\n";
    }
}



// Search Student
void searchStudent(Student students[], int count)
{
    int roll;
    bool found = false;


    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;


    for(int i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            cout << "\nStudent Found!\n";


            cout << "Roll No : " << students[i].rollNo << endl;
            cout << "Name    : " << students[i].name << endl;
            cout << "Age     : " << students[i].age << endl;
            cout << "Branch  : " << students[i].branch << endl;
            cout << "Marks   : " << students[i].marks << endl;


            found = true;
            break;
        }
    }


    if(!found)
    {
        cout << "\nStudent Not Found!\n";
    }
}



// Update Student
void updateStudent(Student students[], int count)
{
    int roll;
    bool found = false;


    cout << "\nEnter Roll Number to Update: ";
    cin >> roll;


    for(int i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            cin.ignore();


            cout << "Enter New Name: ";
            getline(cin, students[i].name);


            cout << "Enter New Age: ";
            cin >> students[i].age;


            cin.ignore();


            cout << "Enter New Branch: ";
            getline(cin, students[i].branch);


            cout << "Enter New Marks: ";
            cin >> students[i].marks;


            saveToFile(students,count);


            cout << "\nStudent Updated Successfully!\n";


            found = true;
            break;
        }
    }


    if(!found)
    {
        cout << "\nStudent Not Found!\n";
    }
}



// Delete Student
void deleteStudent(Student students[], int &count)
{
    int roll;
    bool found = false;


    cout << "\nEnter Roll Number to Delete: ";
    cin >> roll;


    for(int i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {

            for(int j = i; j < count-1; j++)
            {
                students[j] = students[j+1];
            }


            count--;


            saveToFile(students,count);


            cout << "\nStudent Deleted Successfully!\n";


            found = true;
            break;
        }
    }


    if(!found)
    {
        cout << "\nStudent Not Found!\n";
    }
}




int main()
{
    Student students[100];

    int count = 0;

    int choice;


    // Load previous data
    loadFromFile(students,count);



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
                addStudent(students,count);
                break;


            case 2:
                displayStudents(students,count);
                break;


            case 3:
                searchStudent(students,count);
                break;


            case 4:
                updateStudent(students,count);
                break;


            case 5:
                deleteStudent(students,count);
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