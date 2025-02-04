// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations
// c++.com was used to teach me what qsort is 
void quick_sort(List &l, bool numeric) {
    l.head = qsort(l.head, numeric);

}

Node *qsort(Node *head, bool numeric) {

}


void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    if(head == nullptr){
        left = nullptr;
        right = nullptr;
        return;
    }
    
}

Node *concatenate(Node *left, Node *right) {
}

