#include <stdio.h>

void occupySpace(int *space)
{
    // TODO
    *space = 1;
}

int countOccupied(int *spaces, int size)
{
    // TODO
    int count = 0;
    for (int i = 0; i < size; i++){
        if (*spaces){
            
            count++;
        }
        spaces++;
    }
    return count;

}

int main(void)
{
    int spaces[5] = {0, 1, 0, 0, 1};

    printf("Parking Lot:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Space %d: %s\n",
               i + 1,
               spaces[i] ? "Occupied" : "Available");
    }

    // Space 3 becomes occupied
    occupySpace(&spaces[2]);

    int occupied = countOccupied(spaces, 5);

    printf("\nTotal occupied: %d\n", occupied);

    return 0;
}