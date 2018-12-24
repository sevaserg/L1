#include "list.h"
#include <iostream>
#include <stdlib.h>
#define ERR_001 1
#define ERR_002 2
#include "student.h"

using namespace std;

void list::sort()
{
        if (amt > 1)
            for (int i = 0; i < amt; i++)
                for (int j = 0; j < amt - 1; j++)
                    if (l[j].getgradesum() < l[j + 1].getgradesum())
                        swap(l[j],l[j + 1]);

};

list::list()
{
    amt = 8;
        l = new student[amt];
        for (int i = 0; i < amt; i++)
        {
            cout << "Student #"<<i+1<<":"<<endl;
            cin >> l[i];
        }
        sort();
};

void list::del(int k)
{
    try
    {
        if (k<0)throw ERR_001;
        if (k>=amt) throw ERR_002;
        for (int i = k; i < amt - 1; i++)
            l[i] = l[i + 1];
        lb = new student[amt--];
        for (int i = 0; i < amt; i++)
            lb[i] = l[i];
        delete[]l;
        l = new student[amt];
        for (int i = 0; i < amt; i++)
            l[i] = lb[i];
        delete[]lb;
    }
    catch(int k)
    {
        cout<<"Error #"<<k<<" has occured: ";
        if (k == ERR_001) cout<<"there are no elements with negative number!"<<endl;
        if (k == ERR_002) cout<<"such element doesn't exist!"<<endl;
    }
};

void list::add()
{
        lb = new student[amt];
        for (int i = 0; i < amt-1; i++)
            lb[i] = l[i];
        delete[]l;
        amt++;
        l = new student[amt];
        for (int i = 0; i < amt-1; i++)
            l[i] = lb[i];
        delete[]lb;
        cin >> l[amt-1];
};

void list::show()
{
    int botamt = 0;
    for (int i = 0; i < amt; i++)
    {
        if (l[i].getgrade(0)>3&&l[i].getgrade(1)>3&&l[i].getgrade(2)>3&&l[i].getgrade(3)>3&&l[i].getgrade(4)>3)
            {
                cout << "Student #" << i + 1 << ":" << endl;
                cout << l[i];
                botamt++;
            }
    }
    if (botamt == 0)
        cout<<"No students with grades 4 and 5 only!"<<endl;
};
