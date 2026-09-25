#include <stdio.h>
#include <string.h>

struct Player{
    char name[50];
    int score;
    float health;
};

int main(int argc, char const *argv[])
{
    

    struct Player p1 = {"Alice", 100, 95.5};

    struct Player p2 = {.score = 250, .health = 80.8, .name = "Bill"};

    struct Player p3 = {0};

    struct Player p4; // garb value 

    strcpy(p4.name, "Wilson");
    p4.health = 65.5;
    p4.score = 500;

    scanf("%f", &p3.health);

    printf("Player 1 score is %d\n",p1.score);

    if (p1.score > p2.score){
        printf("Player 1 wins\n");
    } else {
        printf("Player 2 wins\n");
    }
    return 0;
}
