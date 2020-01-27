// Name: Zack Downing
// USC NetID: zdowning
// CSCI 455 PA5
// Spring 2018

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
    data = new ListType[HASH_SIZE]();
    size = HASH_SIZE;
    
    hashSize = size;
    
    for(int i = 0; i < size; i++) {
        ListType list = NULL;
        data[i] = list;
        
    }
}


Table::Table(unsigned int hSize) {
    data = new ListType[hSize]();
    size = hSize;
    
    hashSize = size;
    
    for(int i = 0; i < size; i++) {
        ListType list = NULL;
        data[i] = list;
    }
}

//Looks up a name given a target key and returns a pointer to the value
//associated with that name if present and a NULL pointer otherwise
int * Table::lookup(const string &key) {
    string word = key;
    ListType list = data[hashCode(word)];
    Node * p = list;
    int * val = searchValue(p, key);
    return val;
}

//Returns true and removes the node if a node with the given target key is found
//and returns false and does nothing if no such node can be found.
bool Table::remove(const string &key) {
    return deleteNode(data[hashCode(key)], key);
}

//Given a key and value, creates a new node and appends it to the given list
bool Table::insert(const string &key, int value) {
    int hashVal = hashCode(key);
    
    ListType list = data[hashVal];
    
    if(list == NULL) {
        ListType n = new Node(key, value);
        data[hashVal] = n;
        return true;
    }
    else {
        bool added = append(list, key, value);
        return added;
    }
}

//Returns the number of entries in the table by iterating over all buckets and counting
//the length of each
int Table::numEntries() const {
    int entries = 0;
    for(int i = 0; i < size; i++) {
        entries += length(data[i]);
    }
    return entries;
}

//Prints all entries, bucket by bucket
void Table::printAll() const {
    for(int i = 0; i < size; i++) {
        if(!isEmpty(data[i]))
            printList(data[i]);
    }

}

//Provides useful stats about the hashtable: the number of buckets, the number of entries,
//the number of non-empty buckets, and the longest chain, that is the longest linkedlist
//stored in a bucket.
void Table::hashStats(ostream &out) const {
    cout << "number of buckets: " << size << endl;
    cout << "number of entries: " << Table::numEntries() << endl;
    cout << "number of non-empty buckets: " << Table::nonEmpty() << endl;
    cout << "longest chain: " << Table::longestChain() << endl;
}

// add definitions for your private methods here

//Helper function for hashStats() to see if a given bucket is empty
//Resturns true if it is not empty, and false otherwise
int Table::nonEmpty() const{
    int notEmpty = 0;
    for(int i = 0; i < size; i++) {
        if(!isEmpty(data[i])) {
            notEmpty++;
        }
    }
    return notEmpty;
}

//Helper function for hashStats() to find the longest chain in a table
//Iterates over all buckets and returns the length of the longest found chain
//using the listFuncs method length().
int Table::longestChain() const {
    int longest = 0;
    for(int i = 0; i < size; i++) {
        int tempLength = length(data[i]);
        if(tempLength > longest) {
            longest = tempLength;
        }
    }
    return longest;
}












