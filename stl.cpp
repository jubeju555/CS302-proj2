// stl.cpp

#include "volsort.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//true if first is greater
bool node_string_compare(const Node* a, const Node* b){
    return a->string < b->string;
}
     
//true if first is greater
bool node_number_compare(const Node* a, const Node* b){
    return a->number < b->number;
}
     
void stl_sort(List &l, bool numeric) {
    Node* head = l.head;
    vector<Node*> vec;
    while(head!=nullptr){
        vec.push_back(head);
        head = head->next;
    }
    //if numeric, sort by int. if not sort by string
    if(numeric) sort(vec.begin(), vec.end(), node_number_compare);
    else sort(vec.begin(), vec.end(), node_string_compare);
   
    //make the list the same order as the vec
    l.head = vec[0];
    for(size_t i=0; i<vec.size()-1; i++){
        vec[i]->next = vec[i+1];
    }
    vec[vec.size()-1]->next = nullptr;
}
// int main(){
//     //initializing
//     Node* n1 = new Node;
//     n1->string = "a";
//     n1->number = 1;
//     Node* n2 = new Node;
//     n2->string = "b";
//     n2->number = 2;
//     Node* n3 = new Node;
//     n3->string = "c";
//     n3->number = 3;
//     Node* n4 = new Node;
//     n4->string = "d";
//     n4->number = 4;
//     //ordering (4, 1, 3, 2)
//
//     n4->next = n3;
//     n3->next = n2;
//     n2->next = n1;
//     n1->next = nullptr;
//
//     List l;
//     l.head = n4;
//     Node* head = l.head;
//
//     while(head->next != nullptr){
//         cout<<head->number<<"->";
//         head = head->next;
//     }
//     cout<<head->number<<"\n";
//
//     stl_sort(l, false);
//
//     while(head->next != nullptr){
//         cout<<head->number<<"->";
//         head = head->next;
//     }
//     cout<<head->number<<"\n";
// }
