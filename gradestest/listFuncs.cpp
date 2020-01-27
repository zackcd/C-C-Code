// Name: Zack Downing
// USC NetID: zdowning
// CSCI 455 PA5
// Spring 2018


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}


//*************************************************************************
// put the function definitions for your list functions below

//Initializes the pointed to the head of a list to null
void initList(ListType &list) {
    list = NULL;
}

//Appends an element to the end of a list. If the list is empty, creates a list with the
//new element as the head
bool append(ListType & list, string newKey, int newValue) {
    Node *newNode = new Node(newKey, newValue);
    Node *p = list;
    
    if(p == NULL) {
        p = newNode;
        return true;
    }
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
    return true;
}

//Prepends an element to the front of a list. If the list is empty, creates a list with the
//new element as the head
bool prepend(ListType & list, string newKey, int newValue) {
    if(contains(list, newKey))
        return false;
    else {
        Node *newNode = new Node(newKey, newValue, list);

        list = newNode;
        return true;
    }
}

//Returns the length of a list by iterating over the pointers to the next item in the list
int length(ListType list) {
    int count = 0;
    Node *p = list;
    
    while(p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

//Prints the list
void printList(ListType list) {
    if(list == NULL)
        cout << "empty " << endl;
    
    Node *p = list;
    while(p != NULL) {
        cout << p->key << " " << p->value << endl;
        p = p->next;
    }
}

//Deletes a node from the list, given a target key to search for then delete
//Iterates over the list then deletes the node with that key and points the
//previous node to the next node to reform the list
bool deleteNode(ListType & list, string deleteKey) {

    Node *p = list;
    Node *temp = list;
    
    // If head node itself holds the key to be deleted
    if (p != NULL && p->key == deleteKey)
    {
        list = p->next;
        free(p);
        return true;
    }
    
    // Search for the key to be deleted
    while (p != NULL && p->key != deleteKey)
    {
        temp = p;
        p = p->next;
    }
    
    // If key was not present in linked list
    if (p == NULL)
        return false;
    
    // Unlink the node from linked list
    temp->next = p->next;
    
    free(p);  // Free memory
    
    return true;
}

//Searches the list for a given target key and returns a pointer to the
//value of the node associated with that key
int * searchValue(ListType list, string target) {
    Node * p = list;
    int * val = NULL;
    
    while(p != NULL) {
        if(p->key == target) {
            val = &p->value;
            return val;
        }
        p = p->next;
    }
    return val;
}

//Returns true if a list contains a node with the given target key and
//returns false otherwise.
bool contains(ListType list, string target) {
    Node *p = list;
    
    while(p != NULL) {
        if(p->key == target) {
            return true;
        }
        p = p->next;
    }
    return false;
}

//Returns true if a list is empty and false otherwise
bool isEmpty(ListType list) {
    Node *p = list;
    
    if(p == NULL) {
        return true;
    }
    return false;
}


