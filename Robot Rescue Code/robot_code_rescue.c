#include <stdio.h>

void printEnergy(int *energy){
    printf("Current energy is %d\n", *energy);
    printf("Energy memory location is %d\n",energy);
    
}

void chargeEnergyFull(int *energy){
    printf("Current energy is %d\n", *energy);
   *energy += 20;
    printf("Current energy is %d\n", *energy);
}

void upgradeByTen(int *upgrade){
    *upgrade += 10;
    printf("Upgrade Sucesful!\n");
}

void upgradeBy15(int *upgrade){
    *upgrade += 15;
    printf("Repair Sucesful!\n Current value is %d\n", *upgrade);
}

void swapCords(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;

    printf("Swapping cords! %d,%d\n", *x,*y);
}



void printSensors(int *sensors){
    for (int i = 0; i < 5; i++){
        printf("%d\n", *sensors);
        sensors++;
    }

}

/*
this function is broken because it passes energy as a copy in the paramater not as a memory location of the value and does 
affect the orignial value
*/
void recharge(int energy)
{
    energy = 100;
}



int main(){

    // sets the original value of the robots energy
    int energy = 75;
    // gets the pointer for the value energy 
    int *energyP= &energy;
    //sets the original value of the robots armor
    int armor = 30;
    int *armorP = &armor;

    int speed = 20;
    int *speedP = &speed;

    int cordY = 10;
    int cordX = 25;

    int *cordYP = &cordY;
    int *crodXP = &cordX;

    int sensors[5]= {12, 24, 36, 48, 60};
    int *sensorsP = &sensors[0]; 



    printEnergy(energyP);
    chargeEnergyFull(energyP);

    upgradeByTen(speedP);

    swapCords(crodXP,cordYP);

    printSensors(sensorsP);



    //Final part 
    energy = 40;
    armor = 20;
    cordX = 10;
    cordY = 50;

    chargeEnergyFull(energyP);
    upgradeBy15(armorP);
    swapCords (crodXP, cordYP);

    




} 



/*
Exit Ticket:

In your own words, why would a function use a pointer parameter instead of a normal integer parameter?:
    normal integers only pass copys of the value not the real value by passing a pointer you can edit the value directly
    
 . What is the difference between: p and *p:
 p is the pointer as an memory address while * derefrences is it to get you the value at that memory location.

 What does this do? swap(&x, &y);
 passes the memory location of x and y to the function swap

 What does this represent when p points to an array? p + 1

 this indicates what ever memory slot p is currently at to move over 1 to the right

 Which part of today's lab was most difficult, and why? 

 tbh i didnt stuggle with much if anything the only thing that stumped me for a second was that i forgot to set y equal to my
 temp value instead of *x i was confused for like 10 seconds then i realized i didnt use the temp i made LOL

*/