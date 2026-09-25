#include <stdio.h>
#include <string.h>

struct Book
{
    char title[100];
    char author[100];
    int isbn;
    int year;
    int available;
};

void printBook (struct Book book){
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

struct Book createBook(){
    struct Book book;
    printf("\nEnter Title \n");
    fgets(book.title, sizeof(book.title), stdin);
    printf("\nEnter Author \n");
    fgets(book.author, sizeof(book.author), stdin);
    scanf("%s[^\n]", &book.author);
    printf("\nEnter ISBN \n");
    scanf("%d", &book.isbn);
    printf("\nEnter Year \n");
    scanf("%d", &book.year);
    printf("\nIs the book avalible?\n 1 for yes \n 2 for no \n");
    scanf("%d", book.available);
    return book;
}

void checkoutBook (struct Book *book){
    if(book->available){
        book->available = 0;
        printf("%s checkedout", book->title);
    }else{
        printf(" %s is already checkedout", book->title);
    }
}

int main()
{
    struct Book b1 = {.title = "The Hobbit", .author = "J.R.R Tolken", .isbn = 12345, .year = 1937, .available = 1};
    //struct Book b2 = {.title = "1984", .author = "George Orwell", .isbn = 54321, .year = 1949, .available = 1};
    struct Book b3 = {.title = "Dune", .author = "Frank Herbert", .isbn = 67890, .year = 1965, .available = 1};

    printBook(b1);
    struct Book b2 = createBook();
    printBook(b2);
    printBook(b3);

    checkoutBook(&b1);

    return 0;
}
