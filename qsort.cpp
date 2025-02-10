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
            if (na->number < nb->number) return -1;
            else if (na->number > nb->number) return 1;
            return 0;
            //   cout<<"na: "<<na->number<<"   nb: "<<nb->number<<endl;
            // return na->number - nb->number;
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
            // cout << current->string << "->";
            current = current->next;
        }
        // cout << current->string << "\n";
        vec[vec.size() - 1]->next = nullptr;
        current = l.head;

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
            // cout << current->string << "->";
            current = current->next;
        }
        // cout << current->string << "\n";
        vec[vec.size() - 1]->next = nullptr;
        current = l.head;
    }
}

// int main(){
//  Node *n1 = new Node;
//     n1->string = "a";
//     n1->number = 1;
//     Node *n2 = new Node;
//     n2->string = "b";
//     n2->number = 2;
//     Node *n3 = new Node;
//     n3->string = "c";
//     n3->number = 3;
//     Node *n4 = new Node;
//     n4->string = "d";
//     n4->number = 4;

//     // Link nodes (4 -> 1 -> 3 -> 2)
//     n4->next = n1;
//     n1->next = n3;
//     n3->next = n2;
//     n2->next = nullptr;

//     List l;
//     l.head = n4;
//     qsort_sort(l,false);
    
//     return 0;
// }   



// this is only for scripts, not for main
// int compare(const void *a, const void *b) {
//     const Node *na = *(const Node **)a;
//     const Node *nb = *(const Node **)b;

//     return na->string.compare(nb->string);  // Adjust this for numeric sorting if needed
// }

// qsort_sort(l, true, l.head, 4, sizeof(Node), [numeric](const void *a, const void *b) -> int
//     //  {
//          Node *na = (Node *)a;
//          Node *nb = (Node *)b;
//          if (numeric) {
//              return na->number - nb->number;
    //     } else {
    //         return na->string.compare(nb->string);
    //     }
    // });

    // Node *current = l.head;
    // while (current != nullptr) {
    //     cout << current->string << "->";
    //     current = current->next;
    // }
    // cout << current->string << "\n";

    // while (l.head != nullptr) {
    //     Node *temp = l.head;
    //     l.head = l.head->next;
    //     delete temp;
    // }
