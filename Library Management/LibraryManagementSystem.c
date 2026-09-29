#include <stdio.h>
#include <string.h>
#include "LMS_pFun.h"

struct Book
{
    char title[100];
    char author[100];
    int isbn;
    int year;
    int available;
};

// void printBook (struct Book book){
//     printf("Title: %s\n", book.title);
//     printf("Author: %s\n", book.author);
//     printf("ISBN: %d\n", book.isbn);
//     printf("Year: %d\n", book.year);
//     if (book.available){
//         printf("Avalible: True\n");
//     }else {
//          printf("Avalible: Flase\n");
//     }
//     printf("\n\n");
// }

struct Book createBook(){
    struct Book book;
    printf("\nEnter Title \n");
    fgets(book.title, sizeof(book.title), stdin);
    printf("\nEnter Author \n");
    fgets(book.author, sizeof(book.author), stdin);
    printf("\nEnter ISBN \n");
    scanf("%d", &book.isbn);
    printf("\nEnter Year \n");
    scanf("%d", &book.year);
    printf("\nIs the book avalible?\n 1 for yes \n 0 for no \n");
    scanf("%d", &book.available);
    return book;
}

void checkoutBook (struct Book *book){
    if(book->available){
        book->available = 0;
        printf("%s is available\n", book->title);
    }else{
        printf(" %s is already checked out\n", book->title);
    }
}

void findeBookViaISBN (struct Book library[], int size, int userIsbn){
    for (int i = 0; i < size; i++){
        if (library[i].isbn == userIsbn){
            printf("Book Found\n");
            printBook(library[i]);
            return;
        }
          
    }
     printf("Book Not Found\n");
}

int main()
{
    struct Book b1 = {.title = "The Hobbit", .author = "J.R.R Tolken", .isbn = 12345, .year = 1937, .available = 1};
    //struct Book b2 = {.title = "1984", .author = "George Orwell", .isbn = 54321, .year = 1949, .available = 1};
    struct Book b3 = {.title = "Dune", .author = "Frank Herbert", .isbn = 67890, .year = 1965, .available = 1};

    printBook(b1);
    //struct Book b2 = createBook();
    //printBook(b2);
    printBook(b3);

    checkoutBook(&b1);

    struct Book library[3] = {
            {"Frankenstein", "Mary Shelby", 789654, 1823, 1},
            {"1984","George Orwell",54321,1949,1},
            {"To Kill A Mockingbird", "Harper Lee", 542154, 1}
    };

    int i =0;
    for (; i < 3; i++){
        printBook(library[i]);
    }

    printf("Enter the ISBN for the book you are looking for: \n");

    int userIsbn;
    scanf("%d",&userIsbn);
    findeBookViaISBN(library, 3, userIsbn); 

    return 0;
}
