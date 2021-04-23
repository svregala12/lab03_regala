// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE
// Steve Regala 4/21/21

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {

    //IMPLEMENT THIS

    // account for null case
    if (source.first == nullptr) {
        first = nullptr;
    }

    Node *temp = source.first;       // this allows us to create a temp pointer that points to the first node of source
    Node *curr = nullptr;            // create a variable that points to a null
    first = new Node;                // we allocate a new node in memory

    first -> info = temp -> info;    // copy the temp value in to the new head node
    first -> next = nullptr;         // the first's next value will be set to nullptr

    curr = first;                    // point curr to first, curr is supplemental to first
                                     // curr helps us add onto first

    temp = temp -> next;             // making first node equal to temp, we then move to temp's next

    while (temp) {

        curr -> next = new Node;        // allocate memory for a new node
        curr = curr -> next;            // point to new node
        curr -> info = temp -> info;    // copy data over
        curr -> next = nullptr;         // set next to null

        temp = temp -> next;            // iterate through linkedlist
    } 

}



// destructor deletes all nodes
IntList::~IntList() {

    while (first) {
        Node* next = first -> next;
        delete first;
        first = next;
    }

}



// return sum of values in list
int IntList::sum() const {

    int result = 0;
    Node *n = first;

    while (n) {
        result = result + n -> info;
        n = n -> next;
    }

    return result;
}


// returns true if value is in the list; false if not
bool IntList::contains(int value) const {

    Node *n = first;
    while(n) {
        if (value == n -> info) {
            return true;
        }

        n = n -> next;
    }

    return false;
}


// returns maximum value in list, or 0 if empty list
int IntList::max() const {

    Node *n = first;
    
    if (!n) {
        return 0;
    }

    int max = n -> info;
    while (n) {
        if (max <= n -> info) {
            max = n -> info;
        }

        n = n -> next;
    }

    return max;
}


// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {

    Node *n = first;
    if (!n) {
        return 0;
    }

    double addedSum(0.0);
    int counted(0);

    addedSum = sum();
    counted = count();

    return addedSum / counted;
}


// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {

    Node *n = first;

    Node *temp = new Node;
    temp->info = value;
    temp->next = nullptr;

    if (first == nullptr) {
        first = temp;
    }

    else {
        temp -> next = n;
        first = temp;
    }

}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT


    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
