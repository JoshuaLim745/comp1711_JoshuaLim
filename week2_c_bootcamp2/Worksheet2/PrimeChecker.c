#include <stdio.h>

int isPrime (int Number){
    int Answer = 1, counter = 1;

    while(counter <= Number){
        if (Number % counter == 0 && Number != counter && counter != 1){
            Answer = 0;
            counter = Number + 1;
        } 
        else{
            counter += 1;
        }
    }

    return(Answer);
}


void main (){
    int UserInputtedValue, answer;

    printf("Please enter a number\n");

    scanf("%d", &UserInputtedValue);

    answer = isPrime(UserInputtedValue);

    if (answer == 1){
        printf("The number entered is prime \n");

    }
    else{
        printf("The number entered is not prime \n");
    }
}