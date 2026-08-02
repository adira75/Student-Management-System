#include "FileHandler.h"
#include<iostream>
#include<fstream>

using namespace std;


// Save data into file
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