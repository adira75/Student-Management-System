#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>

using namespace std;


struct Student
{
    int rollNo;
    string name;
    int age;
    string branch;
    float marks;
};


void addStudent(Student students[], int &count);

void displayStudents(Student students[], int count);

void searchStudent(Student students[], int count);

void updateStudent(Student students[], int count);

void deleteStudent(Student students[], int &count);


#endif