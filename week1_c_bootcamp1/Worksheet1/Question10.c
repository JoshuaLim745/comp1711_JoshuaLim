#include <stdio.h>

void main(){
    /*Calculating simple interest rate*/
    int Principal, time = 10;
    float rate = 0.08, Total;
    scanf("Please enter the starting amount %d" ,&Principal);
    Total = ((Principal * time * rate) + Principal);

    printf("The Total value of this account after 10 years is %f", Total);


}