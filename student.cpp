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

void student::setstudent()
{
        cout << "first name: ";
        cin >> fname;
        cout << "last name: ";
        cin >> lname;
        cout << "group: ";
        cin >> group;
        for (int i = 1; i <= 5; i++)
        {
            cout << "subject #" << i << " grade: ";
            cin >> grade[i - 1];
        }
};

int student::getgradesum()
{
        int sum = 0;
        for (int j = 0; j < 5; j++)
            sum += grade[j];
        return sum;
};

void student::show()
{
        cout <<fname<<' '<<lname<< endl << group << endl << "Grades: "<<endl;
        for (int i = 0; i < 5; i++)
            cout << grade[i] << endl;
};

student::~student()
{
        cout <<"Student deleted!"<<endl;
};
