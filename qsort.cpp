// qsort.cpp
#include "volsort.h"
#include <cstdlib>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void qsort_sort(List &l, bool numeric)
{
    vector<Node *> vec;
    Node *current = l.head;
    while (current != nullptr)
    {
        vec.push_back(current);
        current = current->next;
    }  
    if (l.head == nullptr)
    {
        return;
    }    
    if(numeric){
    // quick google search for methods that get first pointer, size i already knew
        qsort(vec.data(), vec.size(), sizeof(Node *), [](const void *a, const void *b) -> int
        {
            Node *na = *(Node **)a;
            Node *nb = *(Node **)b;
            return na->number - nb->number;
        });
        } else {
        qsort(vec.data(), vec.size(), sizeof(Node *), [](const void *a, const void *b) -> int
        {
            Node *na = *(Node **)a;
            Node *nb = *(Node **)b;
            return na->string.compare(nb->string);
        });

        l.head = vec[0];
        for (size_t i = 0; i < vec.size() - 1; i++)
        {
            vec[i]->next = vec[i + 1];
        }
        vec[vec.size() - 1]->next = nullptr;

        current = l.head;
        while (current->next != nullptr)
        {
            cout << current->string << "->";
            current = current->next;
        }
        cout << current->string << "\n";
        vec[vec.size() - 1]->next = nullptr;
        current = l.head;
    }
}
