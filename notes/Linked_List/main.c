#include "linked_list.h"

int main(int argc, char *argv[]){
    Data d1 = {111}, d2 = {222}, d3 = {333};

    Node *head = NULL;

    int success = appendList(&head, d1);
  /*  if (success == 1)(
        printf("Node was successfully appened to the list");
    )
    */
    appendList(&head, d2);
    appendList(&head, d3);


    return 0;
}