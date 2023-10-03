#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

int main()
{
    int a;
    D_Heap A(4);
    A.Insert(15);
    A.Insert(10);
    A.Insert(30);
    A.Insert(5);
    //A.Input_D_Heap();
    A.Output_D_Heap();
    A.Remove(3);
    cout << endl;
    A.Output_D_Heap();

    //A.Input_D_Heap();

    /*cout << A.father(0) << endl;
    cout << A.first_child(1) << endl;
    cout << A.last_child(1) << endl;
    cout << A.minchild(0) << endl;
    cout << A.maxchild(0) << endl;
    A.Sinking(0);
    A.Output_D_Heap();

    */
    //A.Bubbling(4);
    //A.Form_Qeue();
    //cout <<endl << A.Get_Minimum()<<endl;
    return 0;
}

