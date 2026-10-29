#include <stdio.h>
#include <stdlib.h>


// malloc calloc realloc free

typedef struct student{
    int id;
    char *name;
    float gpa;
}Student;

typedef struct node {
    Student s;
    struct node *next; // can declare itself and points to the next memory location for the struct student 
}Node;

int main(){
    int *ptr = malloc (sizeof(int)); // holds 1 int values 4 bits
    ptr = malloc (5 * sizeof(int)); // holds 5 int values 20 bits 

    *(ptr+1) = 25; // puts 25 in the memory location of malloc slot 2 

    int *ptr_new = realloc (ptr, 10 * sizeof(int)); // adds 10 int values and 40 bits to *ptr 
    free(ptr);//removes its memory location and makes the varible free no memory being used for that value 
    free(ptr_new);

    Node *S1 = NULL; //always assign the first varbiel to null 

    S1 = (Node *) malloc(sizeof(Node)); 

    if (S1 != NULL){
        S1->s.id = 124;
        S1->s.name = "Lucas";
        S1 -> s.gpa = 3.5;
        S1 -> next = NULL;
    }


    Node * head = NULL; // assigns head as an empty list and is the start of the list cannont move 

    if (head == NULL){
        head = S1; // head now points to node S1
    }else{
         Node *tmp = head;
        while (tmp->next != NULL){ // needs to be tmp -> next because to amke a new node you need the last one not NULL
            tmp = tmp->next; //points to the next area of the list 
        }
        //tmp->next = S2;
    }

}
