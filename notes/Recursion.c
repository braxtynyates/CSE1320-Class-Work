#include <stdio.h>

//solving a large problem through smaller subproblems of the same structure 
//base case: 
//is the stopping point 
//the simplest instance of the problem w/o making anymore recursive calls 
//recursive case:
//The part of the funciton that calls on itself with a modified argument that moves towards the
//base case

int factorial(int n){
    //base case
    if (n <= 1){
        return 1;
    }
    //recursive case
    return n*factorial(n-1);
}

int main(){
printf("%d",factorial(5));

}