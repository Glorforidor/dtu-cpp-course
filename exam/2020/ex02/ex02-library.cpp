#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list)
{
    if (list == nullptr)
    {
        return 0;
    }

    return list->times + length(list->next);
}

// Task 2(b).  Implement this function
Elem *append(Elem *list, int v)
{
    if (list == nullptr)
    {
        return new Elem{v, 1, nullptr};
    }

    // The first element which needs to be returned.
    Elem *first = list;

    // Loop to the end of list.
    while (list->next != nullptr)
    {
        list = list->next;
    }

    // At the tail of list.
    // Check if value needs to be updated otherwise create new elem.
    if (list->value == v)
    {
        list->times += 1;
    }
    else
    {
        list->next = new Elem{v, 1, nullptr};
    }

    return first;
}

// Task 2(c).  Implement this function
Elem *buildRLEList(int *data, unsigned int n)
{
    Elem *first = nullptr;
    for (unsigned int i = 0; i < n; i++)
    {
        first = append(first, data[i]);
    }

    return first;
}

// Do not modify
void displayRLEList(Elem *list)
{
    if (list == nullptr)
    {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
