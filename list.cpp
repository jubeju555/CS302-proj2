#include "volsort.h"

List::List(){
    size = 0;
    head = nullptr;
}

List::~List(){
    Node* curr; 
    while(head != nullptr){
        curr = head->next;
        delete head;
        head = curr;
    }
}

void List::push_front(const std::string &s) {
    Node* first = new Node;
    first->string = s;
    first->number = stoi(s);
    first->next = head;
    head = first;
    size ++;
}
