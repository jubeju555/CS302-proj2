#include "volsort.h"


List::List(){
    

}

List::~List(){
    Node* temp = head; 
    while(temp != nullptr){
        temp = head;
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
