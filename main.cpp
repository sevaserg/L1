#include <iostream>
#include <stdlib.h>
#include "list.h"

using namespace std;

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
