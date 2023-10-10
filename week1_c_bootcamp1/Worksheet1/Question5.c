#include <stdio.h>

void main(){
    int Num1 = 5, Num2 = 10, Temp;

    printf("Num1 has a value of %d and Num2 has a value of %d \n", Num1, Num2);

    Temp = Num1;
    Num1 = Num2;
    Num2 = Temp;


    printf("Num1 has a value of %d and Num2 has a value of %d \n", Num1, Num2);
}