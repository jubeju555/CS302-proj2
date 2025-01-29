// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>

void qsort_sort(List &l, bool numeric) {
    int arr[l.size];
    Node *temp = l.head;
    l.head = qsort(l.head, l.size, numeric);
        

}

