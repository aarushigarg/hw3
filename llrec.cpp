#include "llrec.h"

#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (!head) 
        return;
    
    Node *cur = head;
    head = head->next;

    llpivot(head, smaller, larger, pivot);

    if (cur->val <= pivot) {
        cur->next = smaller;
        smaller = cur;
    }
    else {
        cur->next = larger;
        larger = cur;
    }
}