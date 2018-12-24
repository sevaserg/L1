#pragma once
#include <iostream>
using namespace std;
class student
{
private:
    char fname[20], lname[20];
    int group;
    int grade[5];
public:

    student();

    student(student &s);

    void setstudent();

    int getgrade(int i);

    int getgradesum();

    void show();

    ~student();

    friend ostream& operator <<(ostream& output, student& pointer);

	friend void operator >>(istream& input, student& pointer);

};
