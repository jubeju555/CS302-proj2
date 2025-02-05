#include "volsort.h"
#include <cstdlib>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
    string string;
    int number;
    Node *next;
};
struct List
{
    Node *head;
};
void qsort_sort(List &l, bool numeric, void *base, size_t num, size_t width, int compare)
{
    if (l.head == nullptr)
    {
        return;
    }    
    if (num <= 1)
    {
        return;
    }
    vector<Node *> vec;
    Node *current = l.head;
    while (current != nullptr)
    {
        vec.push_back(current);
        current = current->next;
    }
}


int main(){
 Node *n1 = new Node;
    n1->string = "a";
    n1->number = 1;
    Node *n2 = new Node;
    n2->string = "b";
    n2->number = 2;
    Node *n3 = new Node;
    n3->string = "c";
    n3->number = 3;
    Node *n4 = new Node;
    n4->string = "d";
    n4->number = 4;

    // Link nodes (4 -> 1 -> 3 -> 2)
    n4->next = n1;
    n1->next = n3;
    n3->next = n2;
    n2->next = nullptr;

    List l;
    l.head = n4;
    return 0;
}    
// qsort_sort(l, true, l.head, 4, sizeof(Node), [numeric](const void *a, const void *b) -> int
    //  {
    //     Node *na = (Node *)a;
    //     Node *nb = (Node *)b;
    //     if (numeric) {
    //         return na->number - nb->number;
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
