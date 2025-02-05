// qsort.cpp
#include "volsort.h"
#include <cstdlib>
#include <array>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void List::qsort_sort(List &l, bool numeric, void *base, size_t num, size_t width, int (*compare)(const void *, const void *))
{
    // qsort(base, num, width, compare);
    Node *head = (Node *)base;
    Node *tail = (Node *)base;
    if (l.head == nullptr)
    {
        return;
    }    
    qsort_sort(l, numeric, base, num, width, compare);

}
int main()
{
    // Create test nodes
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

    l.qsort_sort(l, true, l.head, 4, sizeof(Node), [](const void *a, const void *b) -> int {
        Node *na = (Node *)a;
        Node *nb = (Node *)b;
        return na->string.compare(nb->string);
    });

    // Print results
    Node *current = l.head;
    while (current->next != nullptr) {
        cout << current->string << "->";
        current = current->next;
    }
    cout << current->string << "\n";

    // Clean up memory
    while (l.head != nullptr) {
        Node *temp = l.head;
        l.head = l.head->next;
        delete temp;
    }

    return 0;
}
