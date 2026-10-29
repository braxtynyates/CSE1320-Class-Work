#include "MusicManager.h"

void printMenu(void)
{
    int choice = 0;

    printf("========== DIGITAL MUSIC MANAGER ==========\n\n");
    printf("0.  See Menu\n");
    printf("1.  Load\n");
    printf("2.  Store\n");
    printf("3.  Display\n");
    printf("4.  Insert\n");
    printf("5.  Delete\n");
    printf("6.  Edit\n");
    printf("7.  Sort\n");
    printf("8.  Rate\n");
    printf("9.  Play\n");
    printf("10. Shuffle\n");
    printf("11. Exit\n\n");

    
}

int main(void)
{

    Node *head = NULL;
    int userInput;

    printMenu();

    do
    {
        printf("Enter your choice (enter 0 to see the menu again): ");

        if (scanf("%d", &userInput) != 1 || userInput < 0 || userInput > 11)
        {
            clear_stdin();
            printf("Invalid input! Please try again!\n");
            continue;
        }
        
        
        if (userInput == 0)
        {
            printMenu();
        }
        
        if (userInput == 1)
        {
            loadFromFile(&head);
        }


        if (userInput == 2)
        {
           store(&head);
        }


        if (userInput == 3)
        {
           printf("1. Display\n2. Display by artist you choose\n");
           int displayChoice;
           while (scanf("%d", &displayChoice) != 1 || (displayChoice != 1 && displayChoice != 2)) {
            clear_stdin(); // Discard bad characters/newlines
            printf("Invalid choice! Please enter 1 or 2: ");
    }
           if (displayChoice == 1){
                display(head);
           }
           if(displayChoice == 2){
                displayByArtist(head);
           }
        }


        if (userInput == 4)
        {
            newRecord(&head);
        }


        if (userInput == 5)
        {
            deleteRecord(&head);
        }


        if (userInput == 6)
        {
            editRecord(&head);
        }


        if (userInput == 7)
        {
            sortRecord();
        }


        if (userInput == 8)
        {
            rate(&head);
        }


        if (userInput == 9)
        {
            playSongs(&head);
        }


        if (userInput == 10)
        {
            shuffle();
        }


        if (userInput == 11)
        {
           exitProgram(&head);
        }
    } while(userInput != 11);
}