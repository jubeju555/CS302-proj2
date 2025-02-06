// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric) {
}
//
// Node *msort(Node *head, bool numeric) {
// }
//
// void split(Node *head, Node *&left, Node *&right) {
// }
//
// Node *merge(Node *left, Node *right, bool numeric) {
// }


// NOTE:
// Basic Idea: You have an array [1][4][5][3][2][6]
// Split it up: [1][4][5]    [3][2][6]
