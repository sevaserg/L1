#pragma once
#include "student.h"

class list
{
private:
    int amt;
    student *l;
    student *lb;
public:

    void sort();

    list();

    void del(int k);

    void add();

    void show();
};
