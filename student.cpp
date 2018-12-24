#include "student.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

student::student()
{
    cout<<"New student added!"<<endl;
};

student::student(student &s)
{
        cout<<"Student copy added!"<<endl;
        for(int i = 0; i < 20; i++)
        {
            fname[i] = s.fname[i];
            lname[i] = s.lname[i];
            if (i<5)grade[i] = s.grade[i];
        }
        group = s.group;
};

int student::getgrade(int i)
{
    return grade[i];
};

int student::getgradesum()
{
        int sum = 0;
        for (int j = 0; j < 5; j++)
            sum += grade[j];
        return sum;
};

student::~student()
{
        cout <<"Student deleted!"<<endl;
};

ostream& operator <<(ostream& output, student& pointer)
{
        cout <<pointer.fname<<' '<<pointer.lname<< endl << pointer.group << endl << "Grades: "<<endl;
        for (int i = 0; i < 5; i++)
            cout << pointer.grade[i] << endl;
        return output;
};

void operator >>(istream& input, student& pointer)
{


        cout << "first name: ";
        cin >> pointer.fname;
        cout << "last name: ";
        cin >> pointer.lname;
        cout << "group: ";
        cin >> pointer.group;
        for (int i = 1; i <= 5; i++)
        {
            cout << "subject #" << i << " grade: ";
            cin >> pointer.grade[i - 1];
        }
};
