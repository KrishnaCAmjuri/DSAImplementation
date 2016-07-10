//
//  SCLinkedList.hpp
//  linkedListProblems
//
//  Created by KrishnaChaitanya Amjuri on 10/07/16.
//  Copyright © 2016 Krishna Chaitanya. All rights reserved.
//

#ifndef SCLinkedList_hpp
#define SCLinkedList_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

struct KNode {
    int data;
    KNode *next;
};

typedef KNode* KNodePtr;

//insertion
void insertNodeAtFront(KNodePtr &head, int data);

void insertNodeAfter(KNodePtr &given, int data);

void insertNodeAtEnd(KNodePtr &head, int data);

//deletion
void deleteNodeWithData(KNodePtr &head,int data);

void deleteNodeAtPosition(KNodePtr &head, int position);

//length
int lengthOfLinkedList(const KNodePtr &head);

//swap
void swapNodesInLinkedList(KNodePtr &head, int x, int y);

//reverse
void reverseLinkedList(KNodePtr &head);

void reverseLinkedListForSize(KNodePtr &head, int size);

//merge
KNodePtr mergeLinkedLists(KNodePtr X, KNodePtr Y);

void splitLinkedListInToTwoHalves(KNodePtr head, KNodePtr &a, KNodePtr &b);

KNodePtr linkedListMergeSort(KNodePtr head);

//detect and remove loop
void detectLoopAndRemoveFromLinkedList(KNodePtr &head);

//adding two numbers by linked list
int convertLinkedListToNumber(KNodePtr L);

KNodePtr convertNumberToLinkedList(int l);

KNodePtr returnSumLinkedList(KNodePtr L1, KNodePtr L2);

//rotate linked list
void rotateLinkedListCounterClockWise(KNodePtr &head, int k);

//circular linked list
void makeCircularLinkedList(KNodePtr &head, int A[], int n);

void printElementsInCircularLinkedList(const KNodePtr &head);

void splitCircularLinkedListToTwoHalves(KNodePtr head, KNodePtr &half1, KNodePtr &half2);

void sortedInsertForCircularLinkedList(KNodePtr &head, int value);

#endif /* SCLinkedList_hpp */
