//
//  DoubleLinkedList.hpp
//  linkedListProblems
//
//  Created by KrishnaChaitanya Amjuri on 10/07/16.
//  Copyright © 2016 Krishna Chaitanya. All rights reserved.
//

#ifndef DoubleLinkedList_hpp
#define DoubleLinkedList_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode *next;
    DNode *prev;
};

typedef DNode* DNodePtr;

//insert
void insertNodeAtFrontOfDLL(DNodePtr &head, int data);

void insertNodeAtEndOfDLL(DNodePtr &head, int data);

void insertNodeAfterGivenInDLL(DNodePtr &given, int data);

void insertNodeBeforeGivenInDLL(DNodePtr &given, int data);

//delete
void deleteAnodeAtPositionInDLL(DNodePtr &head, int pos);

//reverse
void reverseDoubleLinkedList(DNodePtr &head);

#endif /* DoubleLinkedList_hpp */
