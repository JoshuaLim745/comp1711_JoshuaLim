#include <stdio.h>

void main(){
    int ArrayOfInt[5] ={81,100,18,89,47}, ShiftedArrayOfInt[5], LastNumber = 0, i, temp = 0;
    LastNumber = ArrayOfInt[4];
   ;
    for (i = 0 ; i <5 ; i++)
    {
        ShiftedArrayOfInt[i + 1] = ArrayOfInt[i];
    }

    ShiftedArrayOfInt[0] = LastNumber;

    for(i = 0; i< 5; i++)
    {
        printf("The Values in the array is %d\n", ShiftedArrayOfInt[i]);
    }
}