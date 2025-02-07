// merge.cpp

#include "volsort.h"

#include <iostream>
using namespace std;

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
    msort(l.head, numeric);
}

Node* msort(Node* head, bool numeric) {
    //base case
    if(head->next == nullptr){
        return head;
    }
    Node* left;
    Node* right;
    Node* p_head;
    split(head, left, right);
    //merge_sort left call
    left = msort(left, numeric);
    //merge_sort right call
    right = msort(right, numeric);
    //merge call
    head = merge(left, right, numeric);
    p_head = head;
    // cout<<"After: ";
    // while(p_head!= nullptr){
    //     cout<<"["<<p_head->string<<"]";
    //     p_head = p_head->next;
    // }
    // cout<<endl<<"returning head ("<<head->number<<")"<<endl;
    return head;
}

//make two sublists to then pass into msort calls

void split(Node* head, Node* &left, Node* &right) {
    //since the last element is already pointing at nullptr, we dont need to make it
    // cout<<"-split call-"<<endl;
    // Node* p = head;
    // while(p!=nullptr){
    //     cout<<"["<<p->string<<"]";
    //     p = p->next;
    // }
    // cout<<endl;
    Node* slow_trail = head;
    Node* slow = head;
    Node* fast = head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow_trail = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    left = head; //left head
    slow_trail->next = nullptr;
    right = slow; //right head
    // p = left;
    // cout<<"Left:";
    // while(p!=nullptr){
    //     cout<<"["<<p->string<<"]";
    //     p = p->next;
    // }
    // cout<<endl;
    // p = right;
    // cout<<"Right:";
    // while(p!=nullptr){
    //     cout<<"["<<p->string<<"]";
    //     p = p->next;
    // }
    // cout<<endl;
}

Node *merge(Node* left, Node* right, bool numeric) {
    //assuming left and right are the head of left and head of right
    // cout<<"----Merging----"<<endl<<"Left: ";
    // Node* p_left = left;
    // Node* p_right = right;
    // while(p_left!=nullptr){
    //     cout<<"["<<p_left->string<<"]";
    //     p_left = p_left->next;
    // }
    // cout<<endl<<"Right: ";
    // while(p_right!=nullptr){
    //     cout<<"["<<p_right->string<<"]";
    //     p_right = p_right->next;
    // }
    // cout<<endl;
    Node* head;
    Node* prev;
    //set head
    if(!numeric){
        left->string < right->string ? head = left : head = right;
        left->string < right->string ? left = left->next : right = right->next;
        prev = head;
        while(!(left==nullptr && right==nullptr)){
            if(right == nullptr || (left!=nullptr && left->string<right->string)){
                prev->next = left;
                prev = left; 
                left = left->next;
            }
            else{
                prev->next = right;
                prev = right;
                right = right->next;
            }
        }
    }
    else{
        left->number < right->number ? head = left : head = right;
        left->number < right->number ? left = left->next : right = right->next;
        prev = head;
        while(!(left==nullptr && right==nullptr)){
            if(right == nullptr || (left!=nullptr && left->number<right->number)){
                prev->next = left;
                prev = left; 
                left = left->next;
            }
            else{
                prev->next = right;
                prev = right;
                right = right->next;
            }
        }
    }
    return head;
}


