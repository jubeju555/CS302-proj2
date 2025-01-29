// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
using namespace std;

void stl_sort(List &l, bool numeric) {
    List lis = l;
    sort(lis.begin(), lis.end());
}

