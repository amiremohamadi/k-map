#include <iostream>
#include "list.h"
using std::cout;

list::list(){}
list::~list(){}

void list::append(Pair p)
{
    arr[pointer] = p;
    pointer++;
}

void list::clear(){ pointer = 0; }

Pair list::get(int i) { return arr[i]; }

// Super list

superList::superList(){}

void superList::append(list p)
{
    arr[pointer] = p;
    pointer++;
}

void superList::clear(){ pointer = 0; }

list superList::get(int i) { return arr[i]; }

void list::print()
{
    for (int i = 0; i < pointer; ++i)
    {
        int greyI = arr[i].i ^ (arr[i].i >> 1);
        int greyJ = arr[i].j ^ (arr[i].j >> 1);
        cout << greyI * 4 + greyJ << " ";
    }
}

void superList::print()
{
    for (int i = 0; i < pointer; ++i)
    {
        arr[i].print();
        cout << "\n";
    }
}