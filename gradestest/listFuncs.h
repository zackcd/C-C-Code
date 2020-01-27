// Name: Zack Downing
// USC NetID: zdowning
// CSCI 455 PA5
// Spring 2018


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

void initList(ListType &list);

bool append(ListType & list, string newKey, int newValue);

bool prepend(ListType & list, string newKey, int newValue);

int length(ListType list);

void printList(ListType list);

bool deleteNode(ListType & list, string deleteKey);

int * searchValue(ListType list, string target);

bool contains(ListType list, string target);

bool isEmpty(ListType list);


// keep the following line at the end of the file
#endif
