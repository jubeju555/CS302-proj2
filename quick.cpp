// quick.cpp

#include "volsort.h"
#include <iostream>
using namespace std;

Node *qsort(Node *head, bool numeric);
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// c++.com was used to teach me what qsort is
void quick_sort(List &l, bool numeric)
{
    l.head = qsort(l.head, numeric);
    cout << "New head after sorting: " << l.head->string << "\n";
    Node *current = l.head;
    if (current != nullptr)
    {
        while (current->next != nullptr)
        {
            cout << current->string << "->";
            current = current->next;
        }
        cout << current->string << "\n";
    }
}

Node *qsort(Node *head, bool numeric)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *left = nullptr;
    Node *right = nullptr;
    Node *pivot = head;
    // c++.com (what to put inside the partition) front, pivot, left, right, and amount of elements
    partition(head, pivot, left, right, numeric);

    left = qsort(left, numeric);
    right = qsort(right, numeric);

    pivot->next = right;
    return concatenate(left, pivot);
}
// c++.com was used to teach me what partition is
void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric)
{

    left = nullptr;
    right = nullptr;
    Node *lefttail = nullptr;
    Node *righttail = nullptr;
    Node *current = head->next;

    pivot->next = nullptr;

    // paul wrote out that the pivot has to be put back, as well as the left and right tails should be put there the same lef tand right pointer are
    while (current != nullptr)
    {
        Node *next = current->next;
        current->next = nullptr;
        if ((numeric && current->number < pivot->number) || (!numeric && current->string < pivot->string))
        {
            if (left == nullptr)
            {
                left = current;
                lefttail = current;
            }
            else
            {
                lefttail->next = current;
                lefttail = current;
            }
        }
        else
        {
            if (right == nullptr)
            {
                right = current;
                righttail = current;
            }
            else
            {
                righttail->next = current;
                righttail = current;
            }
        }

        current = next;
    }

    if (lefttail != nullptr)
        lefttail->next = nullptr;
    if (righttail != nullptr)
        righttail->next = nullptr;
}

Node *concatenate(Node *left, Node *right)
{
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;

    Node *temp = left;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = right;
    return left;
}


// int main()
// {
//     Node *n1 = new Node{"a", 1, nullptr};
//     Node *n2 = new Node{"b", 2, nullptr};
//     Node *n3 = new Node{"c", 3, nullptr};
//     Node *n4 = new Node{"d", 4, nullptr};

//     // Properly linking the nodes in the initial list
//     n4->next = n1;
//     n1->next = n3;
//     n3->next = n2;

//     List l;
//     l.head = n4;

//     quick_sort(l, false);

