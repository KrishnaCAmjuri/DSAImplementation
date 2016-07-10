//
//  main.cpp
//  linkedListProblems
//
//  Created by KrishnaChaitanya Amjuri on 07/07/16.
//  Copyright © 2016 Krishna Chaitanya. All rights reserved.
//

#include <iostream>
#include "SCLinkedList.hpp"
#include "DoubleLinkedList.hpp"
using namespace std;

#pragma mark - main function
int main(int argc, const char * argv[]) {
    // insert code here...
    
//    int A[6] = {1,2,3,4,5,6};
//    
//    KNodePtr head = nullptr;
//    
//    for (int i = 0; i < 6; i++) {
//        insertNodeAtEnd(head, A[i]);
//    }
//    
//    cout << "length of linked list: " << lengthOfLinkedList(head) << endl;
//    
////    deleteNodeAtPosition(head, 1);
////    swapNodesInLinkedList(head, 4, 6);
//    reverseLinkedList(head);
//    
//    while (head != nullptr) {
//        cout << head->data << endl;
//        head = head->next;
//    }
    
    /* merging two sorted linked list in sorted way
    int B[1] = {6};
    int C[5] = {1, 2, 3, 4, 5};
    
    KNodePtr B_L = nullptr;
    KNodePtr C_L = nullptr;
    for (int i = 0; i < 1; i++) {
        insertNodeAtEnd(B_L, B[i]);
    }
    for (int i = 0; i < 5; i++) {
        insertNodeAtEnd(C_L, C[i]);
    }
    
    KNodePtr merged = mergeLinkedLists(B_L, C_L);
    
    while (merged != nullptr) {
        cout << merged->data << endl;
        merged = merged->next;
    }*/
    
    /* merge sort implementation testing for linked list
    int D[8] = {2, 8, 22, 5, 3, 10, 1, 7};
    KNodePtr D_L = nullptr;
    for (int i = 0; i < 8; i++) {
        insertNodeAtEnd(D_L, D[i]);
    }
    
    D_L = linkedListMergeSort(D_L);
    
    while (D_L != nullptr) {
        cout << D_L->data << endl;
        D_L = D_L->next;
    }*/
    
    /* reverse linkedlist for groups of size k
    int E[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    KNodePtr E_L = nullptr;
    for (int i = 0; i < 8; i++) {
        insertNodeAtFront(E_L, E[i]);
    }
    
    reverseLinkedListForSize(E_L, 5);
    
    while (E_L != nullptr) {
        cout << E_L->data << endl;
        E_L = E_L->next;
    }*/
    
    /* detect and remove loop from linked list
    int L[7] = {7, 6, 5, 4, 3, 2, 1};
    KNodePtr L_L = nullptr;
    KNodePtr Loop_start = nullptr;
    KNodePtr Loop_End = nullptr;
    for (int i = 0; i < 7; i++) {
        insertNodeAtFront(L_L, L[i]);
        if (i == 3) {
            Loop_start = L_L;
        }
        if (i == 0) {
            Loop_End =  L_L;
        }
    }
    Loop_End->next = Loop_start;
    
    detectLoopAndRemoveFromLinkedList(L_L);
    
    while (L_L != nullptr) {
        cout << L_L->data << endl;
        L_L = L_L->next;
    }*/
    
    /* Add two numbers represented by linked lists and return sum in form of linked list
    int a = 75960;
    int b = 48;
    
    KNodePtr sum_L = returnSumLinkedList(convertNumberToLinkedList(a), convertNumberToLinkedList(b));
    while (sum_L != nullptr) {
        cout << sum_L->data << endl;
        sum_L = sum_L->next;
    }*/
    
    /* Rotate Linked List by k counter clockwise
    int R[6] = {6, 5, 4, 3, 2, 1};
    KNodePtr R_L = nullptr;
    for (int i = 0; i < 6; i++) {
        insertNodeAtFront(R_L, R[i]);
    }
    
    rotateLinkedListCounterClockWise(R_L, 0);
    while (R_L != nullptr) {
        cout << R_L->data << endl;
        R_L = R_L->next;
    }*/
    
    /* Circular Linked List make and traversal
    int A[5] = {1,2,3,4,5};
    KNodePtr head = nullptr;
    makeCircularLinkedList(head, A, 5);
    printElementsInCircularLinkedList(head);
    */
    
    /* split circular linked list into two
    int A[6] = {6, 5, 4, 3, 2, 1};
    KNodePtr head = nullptr;
    makeCircularLinkedList(head, A, 6);
    KNodePtr split1 = nullptr, split2 = nullptr;
    splitCircularLinkedListToTwoHalves(head, split1, split2);
    printElementsInCircularLinkedList(split1);
    cout << endl;
    printElementsInCircularLinkedList(split2);
    */
    
    /* sorted insert for circular linkedlist
    int A[6] = {1, 2, 3, 5, 6, 7};
    KNodePtr head = nullptr;
    makeCircularLinkedList(head, A, 6);
    sortedInsertForCircularLinkedList(head, 4);
    printElementsInCircularLinkedList(head);
    */
    
    /* double linked list
    int A[6] = {1, 2, 3, 4, 5, 6};
    DNodePtr head = nullptr;
    for (int i = 0; i < 6; i++) {
        insertNodeAtFrontOfDLL(head, A[i]);
    }

    deleteAnodeAtPositionInDLL(head, 4);
    
    while (head != nullptr) {
        cout << head->data << endl;
        head = head->next;
    }*/
    
    /* reverse double linked list
    int A[6] = {1, 2, 3, 4, 5, 6};
    DNodePtr head = nullptr;
    for (int i = 0; i < 6; i++) {
        insertNodeAtFrontOfDLL(head, A[i]);
    }
    reverseDoubleLinkedList(head);
    while (head != nullptr) {
        cout << head->data << endl;
        head = head->next;
    }*/
    
    return 0;
}
