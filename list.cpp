#include "volsort.h"

List::List(){
    size = 0;
    head = nullptr;
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
    first->string = s;
    first->number = stoi(s);
    first->next = head;
    head = first;
    size ++;
}
