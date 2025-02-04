#include "volsort.h"

List::List(){
    Node* first = new Node;
    first->next = nullptr;
    first->number = 0;
    first->string = "";
}

List::~List(){
    Node* prev = head; 
    Node* curr = head->next; 
    while(curr != nullptr){

        delete prev;
        prev = curr;
        curr = curr->next;
    }
    delete prev;
    delete curr;
}

void List::push_front(const std::string &s) {
    Node* first = new Node;
    first->next = head;
    head = first; 
}
