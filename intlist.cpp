// intlist.cpp
// Implements class IntList
// TOBIAS WATTERS: April 6, 2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = tail = nullptr; // base case: if source is empty, return head = tail = nullptr

    Node* curr = source.head; // curr reused to traverse source list
    while (curr != nullptr) {
        push_back(curr->info);  // use push_back function
        curr = curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }

    head = nullptr;
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    Node* curr = head;
    int sum(0);
    while (curr!=NULL) {
        sum += curr->info;
        curr = curr->next;
    }
    return sum; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->info == value)
            return true;
        curr = curr->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const 
{
    Node* curr = head;
    if (curr == NULL)
        return 0;
    int max = curr->info;
    while (curr!=NULL) 
    {
        if (curr->info > max)
            max = curr->info;
        curr = curr->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int n = count();
    if (n == 0)
        return 0.0;

    return static_cast<double>(sum()) / n;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* top = new Node;
    top->next = head;
    top->info = value;
    head = top;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* end = new Node;
    end->info = value;
    end->next = NULL;
    if (tail != NULL) 
        tail->next = end;
    else 
        head = end;
    tail = end;
}

// return count of values
int IntList::count() const {
    Node* curr = head;
    int count(0);
    while (curr!=NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) // check for self assignment
        return *this;  
    Node* curr = head; // curr used to traverse this list
    while (curr != nullptr) { // delete all nodes in this
        Node* next = curr->next;
        delete curr;
        curr = next;
    }

    head = tail = nullptr; // base case: if source is empty, return head = tail = nullptr

    curr = source.head; // curr reused to traverse source list
    while (curr != nullptr) {
        push_back(curr->info);  // use push_back function
        curr = curr->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = NULL; // empty list has no nodes so head and tail is NULL
    tail = NULL;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}