//
//  DoubleLinkedList.cpp
//  linkedListProblems
//
//  Created by KrishnaChaitanya Amjuri on 10/07/16.
//  Copyright © 2016 Krishna Chaitanya. All rights reserved.
//

#include "DoubleLinkedList.hpp"

#pragma mark - Inserting Nodes

void insertNodeAtFrontOfDLL(DNodePtr &head, int data) {
    
    DNodePtr newNode = new DNode;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if (head != nullptr) {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }else {
        head = newNode;
    }
}

void insertNodeAtEndOfDLL(DNodePtr &head, int data) {
    
    DNodePtr newNode = new DNode;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    DNodePtr temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertNodeAfterGivenInDLL(DNodePtr &given, int data) {
    
    DNodePtr newNode = new DNode;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    DNodePtr next = given->next;
    newNode->next = next;
    given->next = newNode;
    newNode->prev = given;
}

void insertNodeBeforeGivenInDLL(DNodePtr &given, int data) {

    DNodePtr newNode = new DNode;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    DNodePtr prev = given->prev;
    newNode->next = given;
    given->prev = newNode;
    if (prev != nullptr) {
        prev->next = newNode;
    }
}

#pragma mark - Node Deletion

void deleteAnodeAtPositionInDLL(DNodePtr &head, int pos) {
    
    if (head == nullptr) {
        return;
    }
    
    DNodePtr temp1 = head->next;
    
    if (pos == 0) {
        if (temp1 != nullptr) {
            temp1->prev = nullptr;
            head->next = head;
            head = temp1;
            return;
        }
    }
    
    DNodePtr temp = head;
    int count = 0;
    while (temp != nullptr) {
        if (count == pos) {
            DNodePtr prev = temp->prev;
            DNodePtr next = temp->next;
            temp->next = temp;
            temp->prev = nullptr;
            prev->next = next;
            if (next != nullptr) {
                next->prev = prev;
            }
            return;
        }
        temp = temp->next;
        count++;
    }
}

#pragma mark - Reverse double linked list

void reverseDoubleLinkedList(DNodePtr &head) {
    
    if (head == nullptr) {
        return;
    }
    
    if (head->next == nullptr) {
        return;
    }
    
    DNodePtr current = head;
    while (current != nullptr) {
        DNodePtr next = current->next;
        current->next = current->prev;
        current->prev = next;
        if (next == nullptr) {
            head = current;
            return;
        }
        current = next;
    }
    
}

#pragma mark - merge sort

DNodePtr mergeLinkedLists(DNodePtr X, DNodePtr Y) {
    DNodePtr head = nullptr;
    DNodePtr tail = nullptr;
    
    // dealing if one or both of X, Y are empty
    if (X == nullptr) {
        return Y;
    }
    
    if (Y == nullptr) {
        return X;
    }
    
    while (!(X == nullptr && Y == nullptr)) {
        
        DNodePtr dataPtr = nullptr;
        
        if (X != nullptr && Y != nullptr) {
            if (X->data <= Y->data) {
                dataPtr = X;
                X = X->next;
            }else {
                dataPtr = Y;
                Y = Y->next;
            }
        }else {
            if (X != nullptr) {
                dataPtr = X;
                X = X->next;
            }else if (Y != nullptr) {
                dataPtr = Y;
                Y= Y->next;
            }
        }
        
        if (head == nullptr) {
            head = dataPtr;
            tail = head;
        }else {
            DNodePtr temp = tail;
            temp->next = dataPtr;
            tail = dataPtr;
        }
    }
    
    return head;
}

void splitLinkedListInToTwoHalves(DNodePtr head, DNodePtr &a, DNodePtr &b) {
    
    if (head == nullptr) {
        return;
    }
    
    if (head->next == nullptr) {
        a = head;
        return;
    }
    
    DNodePtr slow = head;
    DNodePtr fast = head;
    DNodePtr prev = nullptr;
    
    while (fast != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = (fast->next == nullptr) ? fast->next : fast->next->next;
    }
    prev->next = nullptr;
    
    a = head;
    b = slow;
}

// not completed
DNodePtr linkedListMergeSort(DNodePtr head) {
    
    DNodePtr a = nullptr;
    DNodePtr b = nullptr;
    
    splitLinkedListInToTwoHalves(head, a, b);
    if (a->next != nullptr) {
        linkedListMergeSort(a);
    }
    if (b->next != nullptr) {
        linkedListMergeSort(b);
    }
    head = mergeLinkedLists(a, b);
    return head;
}












