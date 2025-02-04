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
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    Node *left = nullptr;
    Node *right = nullptr;
    Node *pivot = head;
    // c++.com (what to put inside the partition) front, pivot, left, right, and amount of elements
    partition(head, pivot, left, right, numeric);
    left = qsort(left, numeric);
    right = qsort(right, numeric);
    return concatenate(left, concatenate(pivot, right));
}
// c++.com was used to teach me what partition is and concatenating

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    if(head == nullptr){
        left = nullptr;
        right = nullptr;
        return;
    }
    Node *lefttail = nullptr;
    Node *righttail = nullptr;
    Node *temp = head;
    pivot = head;
    temp = temp->next;
    while(temp != nullptr){
        if((numeric && temp->number < pivot->number) || (!numeric && temp->string < pivot->string)){
            if(left == nullptr){
                left = temp;
                lefttail = left;
            } else {
                lefttail->next = temp;
                lefttail = lefttail->next;
            }
        } else {
            if(right == nullptr){
                right = temp;
                righttail = right;
            } else {
                righttail->next = temp;
                righttail = righttail->next;
            }
        }
        temp = temp->next;
    }
    if(lefttail != nullptr){
        lefttail->next = nullptr;
    }
    if(righttail != nullptr){
        righttail->next = nullptr;
    }
    pivot->next = nullptr;
    
    
}

Node *concatenate(Node *left, Node *right) {
    if(left == nullptr){
        return right;
    }
    if(right == nullptr){
        return left;
    }
    Node *temp = left;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = right;
    return left;

}

