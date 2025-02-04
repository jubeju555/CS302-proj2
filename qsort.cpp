// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>
/*

*/
void List::qsort_sort(List &l, bool numeric, void* base, size_t num, size_t width, int (*compare)(const void*, const void*))
{
    qsort(base, num, width, compare);
}
{

    Node *temp = l.head;
    Node *head = l.head;
    Node *tail = l.head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node *pivot = head;
    Node *prev = head;
    Node *curr = head->next;

        if (head == nullptr || head == tail)
    {
        return;
    }
    Node *pivot = partition(head, tail, numeric);
    qsort_sort(l, head, pivot, numeric);
    qsort_sort(l, pivot->next, tail, numeric);
        delete temp;

}

    // Node *temp = l.head;
    // l.head = qsort(l.head, l.size, numeric);
    // delete temp;

