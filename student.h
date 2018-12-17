#pragma once

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

    int getgradesum();

    void show();

    ~student();

};
