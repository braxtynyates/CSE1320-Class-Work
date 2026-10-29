//A stack is like a stack of plates you cant remove a middle plate it has to be the top 
//Basically Last In First Out or First In Last Out

//use 2 funconalitys push(); pop(); 
//basically limiting yourself to only adding and taking from the front of the list 

//push is equal to the addToFront(); function 

#include <stdio.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

int push (Node **top){

}

int pop (Node **top){
    if (top == NULL){
        printf("Stack is empty");
        return -1;
    }
    //stack has values 
    Node* temp = *top;
    *top = (*top)->next;
    int topValue = temp->data;
    free(temp);
    return topValue;
}




//Queue first in first out need 2 points 1 to know the first and 1 to know the end 

int isEmpty (Node *front){ // chekcs if the queue is empty 
 return (front == NULL);
}

void enqueue(Node **front, Node **tail, int value){ // will add to the end/tail of the list right before the null
    //Dynamically allocate a newNode
    Node* newNode = (Node *) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    //check if the queue is empty
    if (isEmpty(*front)){
        //add newNode to the front of queue
        *front = newNode;
        *tail = newNode;
        // *front = *tail = newNode;
    }else{
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

int dequeue(Node **front, Node **tail){ // will remove from the first on the list
    Node *temp = *front;
    if(isEmpty(*front)){ // checks list to see if its empty
        printf("the list is empty\n");
        return 0;
    }

    int value = temp->data;
    *front = (*front)->next;

    free(temp);
    return value;
}

//example with an array

void pushArry(int data[6], int *top){
    int value;
    if (top==5){
        return;
    }
    *top++;
    data[*top] = value;
}

void popArry(int data[6], int *top, int *back){

}

int main(){
    Node* front = NULL;
    Node* tail = NULL;

    enqueue (&front, &tail, 10);
    enqueue (&front, &tail, 20);

    return 0;
}