// qsort.cpp
#include "volsort.h"
#include <cstdlib>
#include <array>
#include <iostream>
/*

*/
void List::qsort_sort(List &l, bool numeric, void *base, size_t num, size_t width,
                      int (*compare)(const void *, const void *))
{
    qsort(base, num, width, compare);
    if (l.head == nullptr)
    {
        return;
    }
}

//     Node *temp = l.head;
//     Node *head = l.head;
//     Node *tail = l.head;
//     while (tail->next != nullptr)
//     {
//         tail = tail->next;
//     }

//     Node *pivot = head;
//     Node *prev = head;
//     Node *curr = head->next;
//     while (curr != nullptr)
//     {
//         if (numeric)
//         {
//             if (compare(&curr->number, &pivot->number) < 0)
//             {
//                 prev->next = curr->next;
//                 curr->next = head;
//                 head = curr;
//                 curr = prev->next;
//             }
//             else
//             {
//                 prev = curr;
//                 curr = curr->next;
//             }
//         }
//         else
//         {
//             if (compare(&curr->string, &pivot->string) < 0)
//             {
//                 prev->next = curr->next;
//                 curr->next = head;
//                 head = curr;
//                 curr = prev->next;
//             }
//             else
//             {
//                 prev = curr;
//                 curr = curr->next;
//             }
//         }
//     }
//     Node *left = nullptr;
//     Node *right = nullptr;
//     Node *lefttail = nullptr;
//     Node *righttail = nullptr;
//     Node *temp = head;
//     pivot = head;
//     temp = temp->next;
//     while (temp != nullptr)
//     {
//         if ((numeric && temp->number < pivot->number) || (!numeric && temp->string < pivot->string))
//         {
//             if (left == nullptr)
//             {
//                 left = temp;
//                 lefttail = left;
//             }
//             else
//             {
//                 lefttail->next = temp;
//                 lefttail = lefttail->next;
//             }
//         }
//         else
//         {
//             if (right == nullptr)
//             {
//                 right = temp;
//                 righttail = right;
//             }
//             else
//             {
//                 righttail->next = temp;
//                 righttail = righttail->next;
//             }
//         }
//         temp = temp->next;
//     }

//     if (lefttail != nullptr)
//     {
//         lefttail->next = nullptr;
//     }
//     if (righttail != nullptr)
//     {
//         righttail->next = nullptr;
//     }
//     pivot->next = nullptr;
//     if (left == nullptr)
//     {
//         left = pivot;
//     }
//     else
//     {
//         lefttail->next = pivot;
//     }
//     if (right == nullptr)
//     {
//         right = pivot;
//     }
//     else
//     {
//         pivot->next = right;
//     }
//         if (head == nullptr || head == tail)
//         {
//             return;
//         }
//          Node *pivot = partition(head, tail, numeric);
//          qsort_sort(l, head, pivot, numeric);
//          qsort_sort(l, pivot->next, tail, numeric);
//         delete temp;
//     }

//  Node *temp = l.head;
//  l.head = qsort(l.head, l.size, numeric);
//  delete temp;
