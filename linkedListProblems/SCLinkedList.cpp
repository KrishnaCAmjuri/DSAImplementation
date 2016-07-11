//
//  SCLinkedList.cpp
//  linkedListProblems
//
//  Created by KrishnaChaitanya Amjuri on 10/07/16.
//  Copyright © 2016 Krishna Chaitanya. All rights reserved.
//

#include "SCLinkedList.hpp"

#pragma mark - insert Node problems

void insertNodeAtFront(KNodePtr &head, int data) {
    
    KNodePtr newHead = new KNode;
    newHead->data = data;
    
    if (head != nullptr) {
        KNodePtr temp = head;
        newHead->next = temp;
        head = newHead;
    }else {
        head = newHead;
    }
}

void insertNodeAfter(KNodePtr &given, int data) {
    
    KNodePtr newNode = new KNode;
    newNode->data = data;
    newNode->next = nullptr;
    
    if (given->next != nullptr) {
        KNodePtr temp = given->next;
        given->next = newNode;
        newNode->next = temp;
    }else {
        given->next = newNode;
    }
}

void insertNodeAtEnd(KNodePtr &head, int data) {
    
    KNodePtr newNode = new KNode;
    newNode->data = data;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    if (head->next == nullptr) {
        head->next = newNode;
        return;
    }
    
    KNodePtr temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

#pragma mark - delete node problems
void deleteNodeWithData(KNodePtr &head,int data) {
    
    if (head == nullptr) {
        return;
    }
    
    if (head->next == nullptr) {
        if (head->data == data) {
            head = nullptr;
        }
        return;
    }
    
    KNodePtr temp = head;
    KNodePtr prev = nullptr;
    while (temp != nullptr) {
        if (temp->data == data) {
            if (prev != nullptr) {
                prev->next = temp->next;
                temp->next = temp;
            }else {
                head = temp->next;
                temp->next = temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void deleteNodeAtPosition(KNodePtr &head, int position) {
    
    if (head == nullptr) {
        return;
    }
    
    if (head->next == nullptr) {
        if (position == 0) {
            head = nullptr;
        }
        return;
    }
    
    KNodePtr temp = head;
    KNodePtr prev = nullptr;
    int pos = 0;
    while (temp != nullptr) {
        if (pos == position) {
            if (prev != nullptr) {
                prev->next = temp->next;
                temp->next = temp;
            }else {
                head = temp->next;
                temp = temp->next;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
        pos++;
    }
    
}

#pragma mark - length of node problems
int lengthOfLinkedList(const KNodePtr &head) {
    
    if (head == nullptr) {
        return 0;
    }
    
    KNodePtr temp = head;
    
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

#pragma mark - swap nodes problem
void swapNodesInLinkedList(KNodePtr &head, int x, int y) {
    // Here, we assume that Nodes corresponding to values x and y are present in the linked list
    
    if (x == y) {
        return;
    }
    
    // find x, y;
    
    KNodePtr X = head;
    KNodePtr prev_X = nullptr;
    while (X->next != nullptr) {
        if (X->data == x) {
            break;
        }
        prev_X = X;
        X = X->next;
    }
    
    KNodePtr Y = head;
    KNodePtr prev_Y = nullptr;
    while (Y->next != nullptr) {
        if (Y->data == y) {
            break;
        }
        prev_Y = Y;
        Y = Y->next;
    }
    
    // swap adjacent nodes;
    
    if (X->next == Y) {
        KNodePtr next_Y = Y->next;
        Y->next = X;
        X->next = next_Y;
        if (prev_X != nullptr) {
            prev_X->next = Y;
        }else {
            head = Y;
        }
        return;
    }else if (Y->next == X) {
        KNodePtr next_X = X->next;
        X->next = Y;
        Y->next = next_X;
        if (prev_Y != nullptr) {
            prev_Y->next = X;
        }else {
            head = X;
        }
        return;
    }
    
    // swap non adjacent nodes;
    
    KNodePtr next_Y = Y->next;
    
    Y->next = X->next;
    if (prev_X != nullptr) {
        prev_X->next = Y;
    }else {
        head = Y;
    }
    
    X->next = next_Y;
    if (prev_Y != nullptr) {
        prev_Y->next = X;
    }else {
        head = X;
    }
}

#pragma mark - reversing linkedlist problems
void reverseLinkedList(KNodePtr &head) {
    
    if (head == nullptr) {
        return;
    }
    
    if (head->next == nullptr) {
        return;
    }
    
    KNodePtr prev = nullptr;
    KNodePtr curr = head;
    KNodePtr next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void reverseLinkedListForSize(KNodePtr &head, int size) {
    
    if (head == nullptr) {
        return;
    }
    
    if (head->next == nullptr) {
        return;
    }
    
    int position = 0;
    KNodePtr prev = nullptr;
    KNodePtr next = nullptr;
    KNodePtr current = head;
    KNodePtr currentTail = nullptr;
    KNodePtr previousTail = nullptr;
    
    while (current != nullptr) {
        
        if (position == 0) {
            currentTail = current;
        }
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        position++;
        
        if (position == size || current == nullptr) {
            if (previousTail != nullptr) {
                previousTail->next = prev;
            }else {
                head = prev;
            }
            previousTail = currentTail;
            prev = nullptr;
            position = 0;
        }
    }
}

#pragma mark - linkedlist sorting problems
KNodePtr mergeLinkedLists(KNodePtr X, KNodePtr Y) {
    KNodePtr head = nullptr;
    KNodePtr tail = nullptr;
    
    // dealing if one or both of X, Y are empty
    if (X == nullptr) {
        return Y;
    }
    
    if (Y == nullptr) {
        return X;
    }
    
    while (!(X == nullptr && Y == nullptr)) {
        
        KNodePtr dataPtr = nullptr;
        
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
            KNodePtr temp = tail;
            temp->next = dataPtr;
            
            tail = dataPtr;
        }
    }
    
    return head;
}

void splitLinkedListInToTwoHalves(KNodePtr head, KNodePtr &a, KNodePtr &b) {
    
    if (head == nullptr) {
        return;
    }
    
    if (head->next == nullptr) {
        a = head;
        return;
    }
    
    KNodePtr slow = head;
    KNodePtr fast = head;
    KNodePtr prev = nullptr;
    
    while (fast != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = (fast->next == nullptr) ? fast->next : fast->next->next;
    }
    prev->next = nullptr;
    
    a = head;
    b = slow;
}

KNodePtr linkedListMergeSort(KNodePtr head) {
    
    KNodePtr a = nullptr;
    KNodePtr b = nullptr;
    
    splitLinkedListInToTwoHalves(head, a, b);
    if (a->next != nullptr) {
        a = linkedListMergeSort(a);
    }
    if (b->next != nullptr) {
        b = linkedListMergeSort(b);
    }
    head = mergeLinkedLists(a, b);
    return head;
}

#pragma mark - detecting loop in linked list and removing it

void detectLoopAndRemoveFromLinkedList(KNodePtr &head) {
    
    KNodePtr turtle = head;
    KNodePtr hare = head;
    
    bool loopDetected = false;
    
    while (hare != nullptr) {
        turtle = turtle->next;
        if (hare->next->next != nullptr) {
            hare = hare->next->next;
        }else {
            hare = hare->next;
        }
        if (hare != nullptr) {
            if (hare == turtle) {
                // loop detected
                turtle = head;
                loopDetected = true;
                break;
            }
        }
    }
    
    if (!loopDetected) {
        return;
    }
    
    // now transfer hare to another slow pointer
    KNodePtr slowedHare = hare;
    KNodePtr prev = nullptr;
    
    while (slowedHare != turtle) {
        prev = slowedHare;
        turtle = turtle->next;
        slowedHare = slowedHare->next;
    }
    // if slowedHare == turtle, then that pointer is where the loop starts and setting prev pointer to null ends the loop
    
    prev->next = nullptr;
}

#pragma mark - Adding two numbers represented by Linked List and return sum in form of Linked List
int convertLinkedListToNumber(KNodePtr L) {
    
    int sum = 0;
    int k = 0;
    
    while (L != nullptr) {
        sum += (L->data)*pow(10, k);
        L = L->next;
        k++;
    }
    return sum;
}

KNodePtr convertNumberToLinkedList(int l) {
    
    KNodePtr numLL = nullptr;
    while (l != 0) {
        int rem = l%10;
        l = (int)l/10;
        insertNodeAtEnd(numLL, rem);
    }
    
    return numLL;
}

KNodePtr returnSumLinkedList(KNodePtr L1, KNodePtr L2) {
    
    int a = convertLinkedListToNumber(L1);
    int b = convertLinkedListToNumber(L2);
    int sum = a+b;
    
    return convertNumberToLinkedList(sum);
}

#pragma mark - Rotate a Linked List
void rotateLinkedListCounterClockWise(KNodePtr &head, int k) {
    
    int count = 0;
    KNodePtr current = head;
    KNodePtr prev = nullptr;
    KNodePtr prevHead = head;
    
    while (current != nullptr) {
        if (count == k) {
            if (prev == nullptr) {
                return;
            }
            prev->next = nullptr;
            head = current;
        }
        prev = current;
        current = current->next;
        if (current == nullptr) {
            prev->next = prevHead;
        }
        count++;
    }
}

#pragma mark - Circular Linked List
void makeCircularLinkedList(KNodePtr &head, int A[], int n) {
    
    KNodePtr tail = nullptr;
    for (int i = 0; i < n; i++) {
        insertNodeAtFront(head, A[i]);
        if (i == 0) {
            tail = head;
        }
    }
    tail->next = head;
}

void printElementsInCircularLinkedList(const KNodePtr &head) {
    
    KNodePtr temp = head;
    do {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != head);
}

void splitCircularLinkedListToTwoHalves(KNodePtr head, KNodePtr &half1, KNodePtr &half2) {
    
    KNodePtr temp = head;
    int count = 0;
    do {
        temp = temp->next;
        count++;
    } while (temp != head);
    
    int position = 0;
    temp = head;
    half1 = head;
    KNodePtr next = nullptr;
    do {
        next = temp->next;
        if (position == (count/2 - 1)) {
            temp->next = half1;
        }
        if (position == count/2) {
            half2 = temp;
        }
        if (position == count-1) {
            temp->next = half2;
        }
        temp = next;
        position++;
    } while (temp != head);
}

void sortedInsertForCircularLinkedList(KNodePtr &head, int value) {
    
    KNodePtr newNode = new KNode;
    newNode->data = value;
    
    KNodePtr prev = nullptr;
    KNodePtr hare = head;
    do {
        if (hare->next != head) {
            if (hare->next->next == head) {
                prev = hare->next;
                break;
            }
            hare = hare->next->next;
        }else {
            prev = hare;
            break;
        }
    } while (hare != head);
    
    KNodePtr temp = head;
    do {
        if (temp->data <= value) {
            prev->next = newNode;
            newNode->next = temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
}
