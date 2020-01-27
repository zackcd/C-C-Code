/*  Name: Zack Downing
 *  USC NetID: zdowning
 *  CS 455 Spring 2018, Extra Credit assignment
 *
 *  See ecListFuncs.h for specification of each function.
 */

#include <iostream>

#include <cassert>

#include "ecListFuncs.h"

using namespace std;


bool isInOrder(ListType list) {
    bool inOrder = true;
    
    if(list == NULL || list->next == NULL) {
        return true;
    }
    
    while(list->next != NULL) {
        if(list->next->data < list->data)
            return false;
        else
            list = list->next;
    }
    return inOrder;
}



void insertInOrder(ListType & list, Node *itemP) {
    assert(isInOrder(list));     // checks the preconditions
    assert(itemP->next == NULL);
    // add the rest of the code after this line
    
    if(list == NULL) {
        list = itemP;
    }
    else if(list->data > itemP->data) {
        itemP->next = list;
        list = itemP;
    }
    else {
        ListType p = list;
        while(p->next != NULL && (p->next->data < itemP->data)) {
            p = p->next;
        }
        itemP->next = p->next;
        p->next = itemP;
    }
    
}



void insertionSort(ListType &list) {
    ListType sort = NULL;
    ListType curr = list;
    
    while(curr != NULL) {
        ListType next = curr->next;
        curr->next = NULL;
        insertInOrder(sort, curr);
        
        curr = next;
    }
    
    list = sort;
}




void splitEvenOdd(ListType &list, ListType &a, ListType &b) {
    if(list == NULL) {
        return;
    }
    else if(list->next == NULL) {
        a = list;
        list = NULL;
    }
    else {
        ListType tempA = list;
        ListType tempB = list->next;
        
        while(list != NULL && list->next != NULL) {
            ListType temp = list->next;
            list->next = temp->next;
            if(list->next != NULL && list->next->next != NULL) {
                temp->next = list->next->next;
            }
            else {
                temp->next = NULL;
                list = NULL;
                break;
            }
            list = list->next;
        }
        a = tempA;
        b = tempB;
    }

}





