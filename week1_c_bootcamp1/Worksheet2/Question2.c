#include <stdio.h>

void main(){
    int ArrayOfInt[] = {1,2,3,4,5}, i, counter = 0 , FinalArray[5];

    for (i = 4; i >= 0 ; i--)
    {
        FinalArray[counter] = ArrayOfInt[i] ;
        counter += 1;
    }


    for (i = 0; i < 5 ; i++) 
        {
        printf("Final Array %d\n",FinalArray[i]);
        printf("Array of int %d\n",ArrayOfInt[i]);
        }
}