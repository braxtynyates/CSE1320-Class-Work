#include "linked_list.h"

Node *makeNode(Data newItem){
    //dynamically allocate node 
    Node *pMem = NULL;
    pMem = (Node*) malloc(sizeof(Node));

    if (pMem != NULL){
        pMem->item = newItem;
        pMem->next = NULL;
    }
    return pMem;
};

void appendList (Node **pList, Data newItem){
    Node *pMem = NULL;
    pMem = makeNode(newItem); // created a new node and it is in the funciton appendList 

    if (pMem != NULL){
        //case 1 the list is empty 
        if(*pList == NULL){
            *pList = pMem;
        }else { //list is not empty 
                //assign a temp pointer (tranvers pointer ) to head 
            Node *current = *pList;
            while (current->next != NULL){//traverse to the end of the list 
                current = current->next;
            } 
              current->next = pMem;
        }
      
    }
};



void displayList(Node **pList){
    //case empty list 
    if(*pList == NULL){
        printf("The List is Empty\n");
    }else{  //case nonempty list
        Node *current = *pList;
            while (current != NULL){//traverse to the end of the list 
                printf("The value in the node is: %lf", *pList->item.value);
                current = current->next;
            } 
    }

   