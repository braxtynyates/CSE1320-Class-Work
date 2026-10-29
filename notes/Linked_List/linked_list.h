#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data{
    double value;
}Data;

typedef struct node
{
    Data item;
    struct node* next;
}Node;

//allocate space in the heap 
Node *makeNode(Data newItem);

int insertAtFront(Node **pList, Data newItem);

int appendList(Node **pList, Data newItem);

//display list
void displayList(Node **pList);

#endif
