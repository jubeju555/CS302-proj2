// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//true if first is greater
bool node_string_compare(const Node* a, const Node* b){
    return a->string > b->string;
}

//true if first is greater
bool node_number_compare(const Node* a, const Node* b){
    return a->number > b->number;
}

void stl_sort(List &l, bool numeric) {
    Node* head = l.head;
    vector<Node*> vec;
    if(numeric){
        while(head!=nullptr){
            vec.push_back(head);
            head = head->next;
        }
    }
    else{
        while(head!=nullptr){
            vec.push_back(head);
            head = head->next;
        }
    }
    //if numeric, sort by int. if not sort by string
    if(numeric) sort(vec.begin(), vec.end(), node_string_compare);
    else sort(vec.begin(), vec.end(), node_string_compare);

    //make the list the same order as the vec
    l.head = vec[0];
    for(size_t i=0; i<vec.size(); i++){
        vec[i]->next = vec[i+1];
        cout<<vec[i]->string;
    }
    vec[vec.size()-1]->next = nullptr;
    head = l.head;
}


