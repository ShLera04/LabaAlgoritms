#pragma once
class D_Heap
{
public:
    int d, n, currentsize;
    int* key;
    //int* name;
    int* index;

public:
    D_Heap() {
        
    }
    D_Heap(int n);
    ~D_Heap();
    int first_child(int i);
    int last_child(int i);
    int minchild(int i);
    int maxchild(int i);
    int father(int i);
    void Sinking(int i);
    void Bubbling(int i);
    void Form_Qeue();
    int Get_Minimum();
    void Insert(int tmp);
    void Remove(int index);
    void Input_D_Heap();
    void Output_D_Heap();
};

struct vtype {
    int name;
    int w;
    vtype* next;
};
using ADJtype = vtype*;
class Graph_G
{
    int n, m;
    int** array;
    int* dist;
    int* up;
public:
    Graph_G(int n, int m);
    Graph_G(ADJtype* ADJ);
    ~Graph_G();
    int InputFile();
    void Form_Graph(ADJtype* ADJ);
    void LDG_DIJKSTRA_D_HEAP(int s);

};
