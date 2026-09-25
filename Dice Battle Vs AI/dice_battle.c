/*
Name: Braxtyn Yates
Course: CSE 1320
Assignment: Dice Battle
Description: The Player and the computer both roll dice to decide who wins a round, the amount of rounds is decided by the
player at the start of the program. This feature was added as my bonus feature that was needed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Uses pointers to update the scores based on the Boolean return value from rollDice().
int updateScore(int *playerScore, int *computerScore, bool results)
{
    if (results)
    {
        *playerScore += 1;
    }
    else
    {
        *computerScore += 1;
    }

    printf("Current score\n Player: %d \n Computer: %d\n", *playerScore, *computerScore);
}

// uses a random number generation to roll 1-6 for both the player and computer.
// Then returns 1 if its a tie or player win, 0 if computer wins.
int rollDice(int player, int computer)
{
    srand(time(NULL));

    player = rand() % 6 + 1;
    computer = rand() % 6 + 1;

    printf("Player rolled a %d\n", player);
    printf("Computer rolled a %d\n", computer);

    if (player > computer)
    {
        printf("You win this time player....\n");
        return 1;
    }
    else if (player == computer)
    {
        printf("Its a tie so thats a point for you....a pity win really\n");
        return 1;
    }
    else
    {
        printf("wait really? I WON HAHAHAHHAH THATS RIGHT THIS ROUND IS MINE\n");
        return 0;
    }
}

int main()
{

    int playerInput;
    int playerScore = 0;
    int *pointerPlayer = &playerScore;
    int computerScore = 0;
    int *pointerComputer = &computerScore;

    int playerDice;
    int computerDice;

    bool results;
    int gameOver = 0;
    int rounds;

    // intro to the game has title and a welcoming
    printf("            DICE GAME       \nWelcome to my dice game player, you're in for a rough time MUWHAHAHAH\n");

    // asks player for amout of rounds doesnt accepts evens
    printf("Before we start best of how many rounds do you want to play?\n");
    scanf("%d", &rounds);
    while (rounds % 2 == 0)
    {
        if (scanf("%d", &playerInput) != 1)
        {

            while (getchar() != '\n')
                ;

            printf("\nPlease choose a numerical value >:(\n\n");
            continue;
        }
        printf("please choose and odd number player\n");
        scanf("%d", &rounds);
    }

    // prints the input menu for the user
    printf("input menu:\n"
           "0: instructions\n"
           "1: roll dice \n"
           "2: be a coward\n");

    // based on user input decides what to do next keeps going until player gives up, or gameover exeeds rounds.
    while (gameOver != rounds)
    {

        if (scanf("%d", &playerInput) != 1)
        {

            while (getchar() != '\n')
                ;

            printf("\nincorrect input try again >:(\n\n");
            continue;
        }
        else if (playerInput == 0)
        {
            printf("Ok we are both going to roll a d6 (6 sided dice for non dnd nerds) the rules are as follows\n"
                   "1) Best of %d wins\n"
                   "2) A tie results in a point for you since im so genirous\n ",
                   rounds);
        }
        else if (playerInput == 1)
        {
            if (rollDice(playerDice, computerDice))
            {
                results = true;
            }
            else
            {
                results = false;
            }
            updateScore(pointerPlayer, pointerComputer, results);
            gameOver++;
        }
        else if (playerInput == 2)
        {
            printf("really? wow i thought more of you...guess i win by default.");
            break;
        }
        else
        {
            printf("\nincorrect input try again >:(\n\n");
        }
    }

    // the game has ended and the results get printed. Of course the computer always has something to say afterwards :)
    printf("Current score\n Player: %d \n Computer: %d\n", playerScore, computerScore);
    if (playerScore > computerScore)
    {
        printf("no...no...no it cant be....I lost? I...I need some time to think about this...goodbye player.");
    }
    else
    {
        printf("See player wasnt this fun...I truly am a winner. Wow it feels good. Thank you player. Goodbye.");
    }

    printf("\nenter any input to close the game");
    if (scanf("%d",&playerInput)){
        exit;
    }
    

    return 0;
}


// My Bonus Feature is the ability to input the amount of rounds and only accept odd rounds

/*
1. Why does your program need a pointer to modify the score inside your function?
Because if you just send in the varible instead it makes a copy and doesnt actually edit the score

2. What does rand() % 6 + 1 accomplish?
generates a random number between 0-5 then adds 1 to it so it really becomes a random number between 1-6

3. Describe one programming problem you encountered while developing your game and how you solved it.
    one issue i had was figuring out how to do a print in multiple lines of code (im use to other langugues
    where you could just press enter) so it looked better for the eyes.
    I solved this by trial and error and searching it up on google AKA googles ai overview
*/