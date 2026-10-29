#include "MusicManager.h"

void insertFront(Node **pList, Node *newNode) {
    newNode->next = *pList;
    newNode->previous = NULL;

    if (*pList != NULL) {
        (*pList)->previous = newNode;
    }

    *pList = newNode;


}

void clear_stdin(void) { // clears input 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void testToSeeIfInt(int *invalidInt){ // tests input to see if its a valid int then asks for a new one if not
    while (1) {
        if (*invalidInt == 1) {
            clear_stdin(); // Clear trailing newline and leftover characters
            break;
        }

        printf("Invalid input. Please enter digits only.\n");
        clear_stdin(); // Clear the bad input from the buffer
        scanf("%d", invalidInt);
    }
}

void loadFromFile(Node **pList){

    
    FILE *file =  fopen("musicPlayList.csv", "r"); // opens file
    if (file == NULL){ //file didnt open
        printf("File Failed to open\n");
    }else { // file opened
        char buffer[256];
        Node *newNode = *pList;

        while (fgets(buffer, sizeof(buffer), file) != NULL) //keeps checking each line till it hits the end of the file 
        {
      
                Node *newNode = malloc(sizeof(Node)); //sets memory aside for newNode 
                newNode->data = malloc(sizeof(Record)); //sets memory aside for data 
                newNode->next = NULL; // sets next to null so no errors

                sscanf(buffer, "%100[^,],%100[^,],%100[^,],%100[^,],%d,%d,%d,%d",
                newNode->data->artist, newNode->data->album,newNode->data->title,
                newNode->data->genre,&newNode->data->duration.mins,
                &newNode->data->duration.secs,&newNode->data->timesPlayed,&newNode->
                data->rating);  //in the fine line goes until it sees a comma stores that value into one of the structs data types 
                
                insertFront(pList, newNode);
       
            }
            printf("Succesfully Loaded\n");
        }
        
        fclose(file);
    }

void store(Node **pList){ // opens the file then checks for all the records for their data stores it line by line in a file called musicPlayList.csv
    
    
    
    if (*pList == NULL){ // if theres no data to store it prints 
        printf("The Playlist is empty theres nothing to store!\n");
    }else { //
        FILE *file =  fopen("musicPlayList.csv", "w"); // opens file
        if (file == NULL){ //file didnt open
        printf("File Failed to open\n");
    }
        Node *current = *pList;
        while (current != NULL) //stores data for each node each line repersentds a new record/node 
        {
            fprintf(file, "%s,", current->data->artist);
            fprintf(file, "%s,", current->data->album);
            fprintf(file, "%s,", current->data->title);
            fprintf(file, "%s,", current->data->genre);
            fprintf(file, "%d,", current->data->duration.mins);
            fprintf(file, "%d,", current->data->duration.secs);
            fprintf(file, "%d,", current->data->timesPlayed);
            fprintf(file, "%d", current->data->rating);   

            fprintf(file, "\n");

            current = current->next;
        }
        fclose(file); // closes file 
    }
    
}

void display(Node *pList){ // pritns out all the nodes/records data line by line 
    if (pList == NULL){
        printf("The Playlist is empty!\n");
    }else {
        Node *current = pList;
         while (current != NULL){
            printf("%s,", current->data->artist);
            printf("%s,", current->data->album);
            printf("%s,", current->data->title);
            printf("%s,", current->data->genre);
            printf("%d,", current->data->duration.mins);
            printf("%d,", current->data->duration.secs);
            printf("%d,", current->data->timesPlayed);
            printf("%d", current->data->rating);   
            printf("\n");

            current = current->next;
         }
    }
}

void displayByArtist(Node *pList){ // takes in the users input for the artists and prints out all the records in the file that match the artists name  
     if (pList == NULL){
        printf("The Playlist is empty!\n");
    }else {
        Node *current = pList;
        char artist[100];
        printf("Enter the artists name: ");
        clear_stdin();
        if (fgets(artist, sizeof(artist), stdin) != NULL) { // sets users input to artist also removes the \n that fgets causes cant use scanf cus of spaces 
            // Remove trailing newline
            artist[strcspn(artist, "\r\n")] = '\0';
        }
            printf("Heres all the songs for that Artist!\n"); 
            bool artistsPrinted = false; // allows the program to check if the artist actually exists in the playlist 
             while (current != NULL){

               if ( strcmp(artist, current->data->artist) == 0){ // compares user input to the current nodes artist then prints if true 
                printf("%s,", current->data->artist);
                printf("%s,", current->data->album);
                printf("%s,", current->data->title);
                printf("%s,", current->data->genre);
                printf("%d,", current->data->duration.mins);
                printf("%d,", current->data->duration.secs);
                printf("%d,", current->data->timesPlayed);
                printf("%d", current->data->rating);   
                printf("\n");
                artistsPrinted = true;
               }
               current = current->next; // goes to next node
            
            } 
            if (artistsPrinted == false){ // no matches
                printf("That artists has no songs in this playlist!\n");
            }
         }
            
    }

void newRecord(Node **pList){ //asks teh user for values to put into a new record then adds it to the end of the list 
        if (*pList == NULL){
        printf("The Playlist is empty!\n");
    }else {
       

        Node *newNode = malloc(sizeof(Node)); //sets memory aside for newNode 
        newNode->data = malloc(sizeof(Record)); //sets memory aside for data 
        newNode->next = NULL; // sets next to null so no errors

       
        
        Node *current = *pList;

         while (current->next != NULL){
            current = current->next;
         }
         if (current->next == NULL){
            printf("Enter the Data for the New Record\n");
            clear_stdin();
            printf("Artist: ");
             if (fgets(newNode->data->artist, sizeof(newNode->data->artist), stdin) != NULL) { // sets users input to artist also removes the \n that fgets causes cant use scanf cus of spaces 
            // Remove trailing newline
            newNode->data->artist[strcspn(newNode->data->artist, "\r\n")] = '\0';
            }
            printf("Album: ");
             if (fgets(newNode->data->album, sizeof(newNode->data->album), stdin) != NULL) { // sets users input to album also removes the \n that fgets causes cant use scanf cus of spaces 
            // Remove trailing newline
            newNode->data->album[strcspn(newNode->data->album, "\r\n")] = '\0';
            }
            printf("Title: ");
             if (fgets(newNode->data->title, sizeof(newNode->data->title), stdin) != NULL) { // sets users input to title also removes the \n that fgets causes cant use scanf cus of spaces 
            // Remove trailing newline
            newNode->data->title[strcspn(newNode->data->title, "\r\n")] = '\0';
            }
            printf("Genre: ");
             if (fgets(newNode->data->genre, sizeof(newNode->data->genre), stdin) != NULL) { // sets users input to genre also removes the \n that fgets causes cant use scanf cus of spaces 
            // Remove trailing newline
            newNode->data->genre[strcspn(newNode->data->genre, "\r\n")] = '\0';
            }
            
            printf("Duration in Minutes: ");
            scanf("%d", &newNode->data->duration.mins);
            testToSeeIfInt(&newNode->data->duration.mins);
            

             printf("Duration in Seconds: ");
            scanf("%d", &newNode->data->duration.secs);
            testToSeeIfInt(&newNode->data->duration.secs);

            printf("Timesplayeds: ");
            scanf("%d", &newNode->data->timesPlayed);
            testToSeeIfInt(&newNode->data->timesPlayed);
           

            printf("Rating: ");
            scanf("%d", &newNode->data->rating);
            testToSeeIfInt(&newNode->data->rating);
         }
         current->next = newNode;
         newNode->previous = current;
         printf("Warning this has not been saved to the playlist file make sure to run the store command to save!\n");

    }
}

void deleteRecord(Node **pList) { //asks the user for a artists name then checks the list for all records with that artists then deletes it from the list
    if (pList == NULL || *pList == NULL) {
        printf("The Playlist is empty!\n");
        return;
    }

    char artist[100];
    printf("Enter the artists name: ");
    clear_stdin();
    if (fgets(artist, sizeof(artist), stdin) != NULL) {
        artist[strcspn(artist, "\r\n")] = '\0';
    }

    bool succesfullyDeleted = false;
    Node *current = *pList;

    while (current != NULL) {
        if (strcmp(artist, current->data->artist) == 0) {
            Node *temp = current;

            // 1. Update the previous neighbor (or the head pointer)
            if (current->previous == NULL) {
                // Deleting the head node
                *pList = current->next;
                if (*pList != NULL) {
                    (*pList)->previous = NULL;
                }
            } else {
                // Deleting a middle or tail node
                current->previous->next = current->next;
            }

            // 2. Update the next neighbor (if one exists)
            if (current->next != NULL) {
                current->next->previous = current->previous;
            }

            // 3. Move current forward BEFORE freeing temp
            current = current->next;

            // 4. Free the deleted node's memory
            free(temp->data);
            free(temp);

            succesfullyDeleted = true;
        } else {
            // Only advance if no deletion occurred
            current = current->next;
        }
    }

    if (!succesfullyDeleted) {
        printf("That artists has no songs in this playlist!\n");
    }
}

void editRecord(Node **pList){
    if (*pList == NULL){
        printf("The Playlist is empty!\n");
    }else {
        Node *current = *pList;
        char artist[100];
        printf("Enter the artists name: ");
        clear_stdin();
        if (fgets(artist, sizeof(artist), stdin) != NULL) { // sets users input to artist also removes the \n that fgets causes cant use scanf cus of spaces 
            // Remove trailing newline
            artist[strcspn(artist, "\r\n")] = '\0';
            }
            bool artistsPrinted = false; // allows the program to check if the artist actually exists in the playlist 
             while (current != NULL){

               if ( strcmp(artist, current->data->artist) == 0){ // compares user input to the current nodes artist then prints if true 
                printf("%s,", current->data->artist);
                printf("%s,", current->data->album);
                printf("%s,", current->data->title);
                printf("%s,", current->data->genre);
                printf("%d,", current->data->duration.mins);
                printf("%d,", current->data->duration.secs);
                printf("%d,", current->data->timesPlayed);
                printf("%d", current->data->rating);   
                printf("\n");

                printf("Do you want to edit this record? Y for Yes, Any other input for no\n");
                char yesOrNo;
                int userInt;

                scanf(" %c", &yesOrNo);
                clear_stdin();
                    char newChar[100];
                    int newInt;
                    while (yesOrNo == 'Y' || yesOrNo == 'y' ){
                        printf("Which one do you want to change?\n");
                        
                        printf("1). Artist\n2). Album Title\n3). Song Title\n4). Genre\n5). Duration(mins)\n6). Duration(secs)\n7). Number of times played\n8). Rating\n0). None/Exit\n");

                        scanf("%d", &userInt);

                        if(userInt == 1){
                            clear_stdin();
                            printf("What do you want to change the artists name to?\n");
                            if (fgets(newChar, sizeof(newChar), stdin) != NULL) {
                            newChar[strcspn(newChar, "\r\n")] = '\0'; // Remove trailing newline
                            strcpy(current->data->artist, newChar);
                            }
                        }

                         if(userInt == 2){
                            clear_stdin();
                            printf("What do you want to change the Album name to?\n");
                            if (fgets(newChar, sizeof(newChar), stdin) != NULL) {
                            newChar[strcspn(newChar, "\r\n")] = '\0'; // Remove trailing newline
                            strcpy(current->data->album, newChar);
                            }
                        }

                             if(userInt == 3){
                            clear_stdin();
                            printf("What do you want to change the Title to?\n");
                            if (fgets(newChar, sizeof(newChar), stdin) != NULL) {
                            newChar[strcspn(newChar, "\r\n")] = '\0'; // Remove trailing newline
                            strcpy(current->data->title, newChar);
                            }
                        }
                             if(userInt == 4){
                            clear_stdin();
                            printf("What do you want to change the Genre to?\n");
                            if (fgets(newChar, sizeof(newChar), stdin) != NULL) {
                            newChar[strcspn(newChar, "\r\n")] = '\0'; // Remove trailing newline
                            strcpy(current->data->genre, newChar);
                            }
                        }
                            
                            if (userInt == 5){
                                printf("What do you want to change the sogns Durations in minutes to?\n");
                                scanf("%d", &newInt);
                                current->data->duration.mins = newInt;
                            }

                            if (userInt == 6){
                                printf("What do you want to change the sogns remaining seconds to?\n");
                                scanf("%d", &newInt);
                                current->data->duration.secs = newInt;
                            }

                            if (userInt == 7){
                                printf("What do you want to change the number of times played to?\n");
                                scanf("%d", &newInt);
                                current->data->timesPlayed = newInt;
                            }

                            if (userInt == 8){
                                printf("What do you want to change the sogns rating to?\n");
                                scanf("%d", &newInt);
                                current->data->rating = newInt;
                            }

                            if (userInt == 0){
                                exit;
                            }
                            

                            printf("Do you want to continue editing this record? Y for Yes, N for No\n");
                            scanf(" %c", &yesOrNo);
                        }
                    
                artistsPrinted = true;
               }
               current = current->next; // goes to next node
            
             } 
            if (artistsPrinted == false){ // no matches
                printf("That artists has no songs in this playlist!\n");
            }
         }
    }

void sortRecord(){
    printf("this feature is not implemented yet sorry!\n");
}

void rate(Node **pList){
    if (*pList == NULL){
        printf("The Playlist is empty!\n");
    }else {
        Node *current = *pList;
        char artist[100];
        printf("Enter the artists name: ");
        clear_stdin();
        if (fgets(artist, sizeof(artist), stdin) != NULL) { // sets users input to artist also removes the \n that fgets causes cant use scanf cus of spaces 
            // Remove trailing newline
            artist[strcspn(artist, "\r\n")] = '\0';
            }
            bool artistsPrinted = false; // allows the program to check if the artist actually exists in the playlist 
             while (current != NULL){


               if ( strcmp(artist, current->data->artist) == 0){ // compares user input to the current nodes artist then prints if true 
                printf("%s,", current->data->artist);
                printf("%s,", current->data->album);
                printf("%s,", current->data->title);
                printf("%s,", current->data->genre);
                printf("%d,", current->data->duration.mins);
                printf("%d,", current->data->duration.secs);
                printf("%d,", current->data->timesPlayed);
                printf("%d", current->data->rating);   
                printf("\n");

                printf("Do you want to rate this record? Y for Yes, N for No ");
                char yesOrNo;
                int userInt;

                scanf(" %c", &yesOrNo);
                    int newInt;
                    if (yesOrNo == 'Y' || yesOrNo == 'y' ){
                        printf("What do you want to rate the song? Make sure its a rating 1-5!\n");
                       while (scanf("%d", &newInt) != 1 || newInt < 1 || newInt > 5) {
                            // Clear the bad input (letters, symbols, newlines) out of the buffer
                            clear_stdin();

                            printf("Invalid input! I said to enter a valid number from 1 to 5, try again -_- \n");
                        }
                        current->data->rating = newInt;
                        printf("Its been set! Make sure to run store if you want to save that!\n");
                        }
                        artistsPrinted = true;
                }
                    
                
                current = current->next; // goes to next node
               }
               
            
              
            if (artistsPrinted == false){ // no matches
                printf("That artists has no songs in this playlist!\n");
            }
         }
}

void playSongs(Node **pList){
    if (*pList == NULL){
        printf("The Playlist is empty!\n");
    }else {
        Node *current = *pList;
        char song[100];
        char yesOrNo;
        printf("Enter the songs name: ");
        clear_stdin();
        if (fgets(song, sizeof(song), stdin) != NULL) { // sets users input to artist also removes the \n that fgets causes cant use scanf cus of spaces 
            // Remove trailing newline
            song[strcspn(song, "\r\n")] = '\0';
        }
            printf("Heres all the songs for that Artist!\n"); 
            bool artistsPrinted = false; // allows the program to check if the artist actually exists in the playlist 
             while (current != NULL){
           
               if ( strcmp(song, current->data->title) == 0){ // compares user input to the current nodes artist then prints if true 
                printf("%s,", current->data->artist);
                printf("%s,", current->data->album);
                printf("%s,", current->data->title);
                printf("%s,", current->data->genre);
                printf("%d,", current->data->duration.mins);
                printf("%d,", current->data->duration.secs);
                printf("%d,", current->data->timesPlayed);
                printf("%d", current->data->rating);   
                printf("\n");
                artistsPrinted = true;

                printf("Do you want to play this song? Y for Yes, N for No ");
                int userInt;

                scanf(" %c", &yesOrNo);
                    int newInt;
                    if (yesOrNo == 'Y' || yesOrNo == 'y' ){
                        break;
                    }
               }
               current = current->next; // goes to next node
            
            } 
            
            if (artistsPrinted == false){ // no matches
                printf("There is no songs named that in this playlist!");
            }
            if (yesOrNo == 'Y' || yesOrNo == 'y'){
                while (current != NULL){ 
                  system("cls"); // Clears the Windows terminal screen
                    // 1. Display the song information
                    printf("Now Playing:\n");
                    printf("Artist: %s\n", current->data->artist);
                    printf("Title:  %s\n", current->data->title);
                    printf("Album:  %s\n", current->data->album);
                    printf("Genre:  %s\n", current->data->genre);
                    printf("Length: %d:%02d\n", current->data->duration.mins, current->data->duration.secs);

                    // 2. Increment play count
                    current->data->timesPlayed++;

                    // 3. Pause for 3 seconds
                    Sleep(3000);

                    // 4. Move to next song
                    current = current->next;
                }
                system("cls");
                printf("You have reached the end of the playlist!\n");
            }
         }

}

void shuffle(){
     printf("this feature is not implemented yet sorry!\n");
}

void exitProgram(Node **pList){
    if (pList == NULL) {
            return;
        }

        printf("Saving\n");
        store(pList);

        Node *current = *pList;
        while (current != NULL) {
            Node *temp = current->next; // Save the next node before freeing

            if (current->data != NULL) {
                free(current->data);    // Free the Record struct
            }
            free(current);              // Free the Node struct

            current = temp;             // Advance to the saved next node
        }

        *pList = NULL; // Reset head pointer to avoid dangling references
}