/* Paste your complete solution code here. */
#include <stdio.h>
// Pointer Notes

void change(int *z);

int main()
{
    int health, armor, energy;
    int *stats[3] = {&health, &armor, &energy};

    *stats[0] = 90;
    *stats[1] = 75;

    //array of strings 
    char names [3][5]= {"Ed ",
                        "Alex",
                        "Chris"};
        
    char *names[]={"Ed", "Alex" , "Christopher"};    //Still static; Dynamic in the fact you can give more bytes at initilization
    *names[2] = "Chris";
    

    //void pointer:
    int x = 70;
    void *p = &x;
        //does not know x is an int
    
    printf("%d", *(int*)p);
                //cast^
                //void pointers give lee way to use it for multiple data types 
                //casting is telling a varible it is a certain type for that certain momment 


    //double pointer: a pointer of a pointer also called double indirection 
    int **p; //pointer to a pointer 

    x = 25;
    int *p =&x;
    int **q = &p; //when passing a memory location to a function it is a copy so to change it you need another pointer

    change(p); //see function below

    printf("%p",p); //will not print an updated version of p

    changeFixed(p); //see function below 
    
    printf("%p",p); // will print the updated version of p
    
}   

void change(int *z){
    z++; //changes the copy not the real value so p wont actually change 
}

void changeFixed(int **z){
    *z++; // uses double pointers so it does change the actual value of p AKA a memory location 
}


 
 
 
 
 
