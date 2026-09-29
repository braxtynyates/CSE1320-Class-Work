#include <stdio.h>
#include "LMS_pFun.h"


//function definitions 
void printBook(struct Book book){
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("ISBN: %d\n", book.isbn);
    printf("Year: %d\n", book.year);
    if (book.available){
        printf("Avalible: True\n");
    }else {
         printf("Avalible: Flase\n");
    }
    printf("\n\n");
}