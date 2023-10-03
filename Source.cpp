#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;


D_Heap::D_Heap(int _n)
{
    n = _n;
    d = 3;
    currentsize = 0;
    key = new int[n];
    //name = new int[n];
    index = new int[n];
}

D_Heap :: ~D_Heap()
{
    delete[] key;
    //delete[] name;
    delete[] index;
}
int D_Heap::first_child(int i) {
    int k = i * d + 1;
    if (k > (currentsize-1))
        return -1;
    else
        return k;
}

int D_Heap::last_child(int i)
{
    int k = i * d + d;
    if (k > (currentsize-1))
        return -1;
    else return k;
}

int D_Heap::minchild(int i) {
    int first = first_child(i);
    if (first == -1)//? провера на то есть ли потомки
        return i;
    else {
        int last = last_child(i);
        int min_key = key[first];
        int minchild = first;
        for (int j = first + 1; j <= last; j++) {
            if (key[j] < min_key) {
                min_key = key[j];
                minchild = j;
            }
        }
        return minchild;
    }
}

int D_Heap::father(int i) {
    return ((i - 1) / d);
}

void D_Heap::Bubbling(int i)
{
    int p = father(i);
    while (i != 0 && key[i] < key[p])
    {
        swap(key[i], key[p]);
        index[i] = i;
        i = p;
        p = father(i);
    }
}

void D_Heap::Sinking(int i)
{
    int p = minchild(i);
    while (p != i && key[i] > key[p])
    {
        swap(key[i], key[p]);
        index[i] = i;
        i = p;
        p = minchild(i);
    }
}

int D_Heap::maxchild(int i)
{
    int first = first_child(i);
    if (first == -1)//?
        return i;
    else {
        int last = last_child(i);
        int max_key = key[first];
        int maxchild = first;
        for (int j = first + 1; j <= last; j++) {
            if (key[j] > max_key) {
                max_key = key[j];
                maxchild = j;
            }
        }
        return maxchild;
    }

}

void D_Heap::Insert(int tmp)
{
    if (currentsize < n)
    {
        key[currentsize] = tmp;
        Bubbling(currentsize);
        currentsize++;
    }
}

void D_Heap::Form_Qeue() 
{
    for (int i = n; i >= 0; i--)
        Sinking(i);
}

int D_Heap::Get_Minimum( /*int& name1*/) {
    //name1 = name[0];
    int key1 = key[0];
    //name[0] = name[n];
    key[0] = key[n - 1];
    //name[n] = name1;
    key[n - 1] = key1;
    n = n - 1;
    if (n > 0)
        Sinking(0);
    return key1;
}

void D_Heap::Input_D_Heap()
{
    for (int i = currentsize; i < n; i++)
    {
        cin >> key[i];
        currentsize++;
    }
}

void D_Heap::Remove(int i)
{
    if (currentsize != 0)
    {
        key[i] = key[currentsize - 1];
        currentsize--;
        if (i != 0 && key[i] > key[father(i)])
            Bubbling(i);
        else
            Sinking(i);
    }
}

void D_Heap::Output_D_Heap()
{
    for (int i = 0; i < currentsize; i++)
    {
        cout << key[i] << " ";
    }
}

Graph_G::Graph_G(int _n, int _m)
{
    n = _n;
    m = _m;
    array = new int* [n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[m];
    }
}
Graph_G:: ~Graph_G()
{
    for (int i = 0; i < n; i++)
        delete[] array[i];
    delete[] array;
}
int Graph_G::InputFile()
{
    int elemstr;
    ifstream inputFile("file1.txt"); // Открываем файл для чтения
    if (!inputFile) {
        cout << "Произошла ошибка при открытии файла!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            inputFile >> array[i][j];
        }
    }
    inputFile.close(); // Закрываем файл
    return 0;
}

Graph_G::Graph_G(ADJtype* ADJ)
{
    for (int i = 0; i < n; i++)
    {
        ADJ[i] = nullptr;
        for (int j = 0; j < m; j++)
        {
            vtype* p = new vtype;
            p->name = j;
            p->w = array[i][j];
            p->next = ADJ[i];
            ADJ[i] = p;
        }
    }
}

//void Graph_G::LDG_DIJKSTRA_D_HEAP(int s)
//{
//    for (int i = 0; i < n; i++)
//    {
//        up[i] = 0;
//        dist[i] = 10000;
//        key[i] = 10000;
//    }
//    key[s] = 0;
//    int nq = n;
//    Form_Qeue();
//    while (nq > 0)
//    {
//        Get_Minimum();
//        int name0, key0;
//
//        int i = name0;
//        dist[i] = key0;
//        vtype* p = ADJ[i].next;
//
//        while (p != nullptr)
//        {
//            int j = p->name;
//            
//        }
//    }
//}

void Graph_G::LDG_DIJKSTRA_D_HEAP(int s)
{
   
}
