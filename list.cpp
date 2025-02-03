#include "volsort.h"

List::List(){
    Node* first = new Node;
    first->next = nullptr;
    first->number = 0;
    first->string = "";
}

List::~List(){
    Node* temp = head; 
    while(temp != nullptr){
        delete head;
        temp = temp->next;
    }
    delete temp;
}

void List::push_front(const std::string &s) {
    Node* first = new Node;
    first->next = head;
    head = first; 
}
