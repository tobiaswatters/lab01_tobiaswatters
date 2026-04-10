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
        Node* next = curr->next; // save next node
        delete curr; // delete current node
        curr = next; // traverse
    }

    head = tail = nullptr; // empty list, head = tail =nullptr
}


// return sum of values in list
int IntList::sum() const {
    Node* curr = head; // pointer to traverse list
    int sum(0); // initialize sum at 0
    while (curr!=NULL) { 
        sum += curr->info; // increment sum
        curr = curr->next; // traverse
    }
    return sum; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head; // pointer to traverse list, start at head
    while (curr != NULL) {
        if (curr->info == value) // check for val
            return true;
        curr = curr->next; // traverse
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const 
{
    Node* curr = head; // pointer to traverse list, start at head
    if (curr == NULL)
        return 0;
    int max = curr->info; // initialize to first node info
    while (curr != NULL) 
    {
        if (curr->info > max)
            max = curr->info; // reassign max val if curr node info is larger than prev max
        curr = curr->next; // travers
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int n = count(); // use count() function
    if (n == 0)
        return 0.0;
    return static_cast<double>(sum()) / n; // use sum() function
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* top = new Node; // use new to create new memory in heap
    top->next = head; // new node point to what head was pointing to
    top->info = value;
    head = top; // head should point to new node
    if (tail == nullptr) // edge case: empty list
        tail = top;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* end = new Node; // new to create new memory in heap
    end->info = value; 
    end->next = NULL; 
    if (tail != NULL) // check if list is not empty
        tail->next = end;
    else 
        head = end; // edge case: empty list
    tail = end;
}

// return count of values
int IntList::count() const {
    Node* curr = head; // pointer to traverse list
    int count(0); // initialize count at 0
    while (curr!=NULL) {
        count++; 
        curr = curr->next; // traverse
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
IntList::IntList(){ // *** how does one differentiate between a constructor and non-constructor, is it just the repeated class name?
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