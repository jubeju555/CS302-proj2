// quick.cpp

#include "volsort.h"
#include <iostream>
using namespace std;
// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// c++.com was used to teach me what qsort is 
void quick_sort(List &l, bool numeric) {
    l.head = qsort(l.head, numeric);
    Node *current = l.head;
    if (current != nullptr) {
        while (current->next != nullptr) {
            cout << current->string << "->";
            current = current->next;
        }
        cout << current->string << "\n";
    }
    // cout << head->string << "\n";

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

    Node *postpivotlist = pivot;
    postpivotlist->next = nullptr;
    return concatenate(concatenate(left, postpivotlist), right);
}
// c++.com was used to teach me what partition is
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
int main(){
    
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
    //order :(4, 1, 3, 2)
    n2->next = n1;
    n1->next = n3;
    n3->next = n4;
    n4->next = nullptr;

    List l;
    l.head = n4;
    // quick_sort(l, false);
    // Node* head = l.head;
        // head = l.head;

    quick_sort(l, false);


   
    return 0;
}
