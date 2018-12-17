#include <iostream>
#include <stdlib.h>
#define ERR_001 1
#define ERR_002 2

using namespace std;

class student
{
private:
    char fname[20], lname[20];
    int group;
    int grade[5];
public:
    student()
    {
        cout<<"New student added!"<<endl;
    }

    student(student &s)
    {
        cout<<"Student copy added!"<<endl;
        for(int i = 0; i < 20; i++)
        {
            fname[i] = s.fname[i];
            lname[i] = s.lname[i];
            if (i<5)grade[i] = s.grade[i];
        }
        group = s.group;
    }
    void setstudent()
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
    }
    int getgradesum()
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
            sum += grade[j];
        return sum;
    }
    void show()
    {
        cout <<fname<<' '<<lname<< endl << group << endl << "Grades: "<<endl;
        for (int i = 0; i < 5; i++)
            cout << grade[i] << endl;
    }
    ~student()
    {
        cout <<"Student deleted!"<<endl;
    }
};

class list
{
private:
    int amt = 3;
    student *l;
    student *lb;
public:
    void sort()
    {
        if (amt > 1)
            for (int i = 0; i < amt; i++)
                for (int j = 0; j < amt - 1; j++)
                    if (l[j].getgradesum() < l[j + 1].getgradesum())
                        swap(l[j],l[j + 1]);
    }
    list()
    {
        l = new student[amt];
        for (int i = 0; i < amt; i++)
        {
            cout << "Student #"<<i+1<<":"<<endl;
            l[i].setstudent();
        }
        sort();
    }
    void del(int k)
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
            cout<<"Error #"<<k<<"has occured: ";
            if (k == ERR_001) cout<<"there are no elements with negative number!"<<endl;
            if (k == ERR_002) cout<<"such element doesn't exist!"<<endl;
        }
    }
    void add()
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
            l[amt-1].setstudent();
    }
    void show()
    {
        for (int i = 0; i < amt; i++)
        {
            cout << "Student #" << i + 1 << ":" << endl;
            l[i].show();
        }
    }
};

int main()
{

    list lst;
    int choice=1, elnum;
    while (choice != 0)
    {

        cout << "1. View students list;" << endl << "2. Add new;" << endl << "3. delete element;"<<endl<<"0. Quit."<<endl<<">>";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                lst.show();
            }break;
            case 2:
            {
                lst.add();
            }break;
            case 3:
            {
                cout << "Type in the number of element you want to delete: ";
                cin >> elnum;
                lst.del(elnum-1);
            }break;
        }
    }
    return 0;
}
