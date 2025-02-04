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
int main(){
    //initializing
    Node* n1 = new Node;
    n1->string = "a";
    n1->number = 1;
    Node* n2 = new Node;
    n2->string = "b";
    n2->number = 2;
    Node* n3 = new Node;
    n3->string = "c";
    n3->number = 3;
    Node* n4 = new Node;
    n4->string = "d";
    n4->number = 4;
    //ordering (4, 1, 3, 2)
    n2->next = n1;
    n1->next = n3;
    n3->next = n4;
    n4->next = nullptr;

    List l;
    l.head = n4;
    l.qsort_sort(l, false, l.head, 4, sizeof(Node), [](const void *a, const void *b) -> int {
        Node *na = (Node *)a;
        Node *nb = (Node *)b;
        return na->string.compare(nb->string);
    });
    Node* head = l.head;
    while(head->next != nullptr){
        std::cout<<head->string<<"->";
        head = head->next;
    }
    std::cout<<head->string<<"\n";
    return 0;
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
