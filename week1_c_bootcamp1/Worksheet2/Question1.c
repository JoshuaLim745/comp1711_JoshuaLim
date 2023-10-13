#include <stdio.h>

int main(){
    int ArrayOfInt[5] ,Total = 0, i;

    ArrayOfInt[1] = 1 , ArrayOfInt[2] = 2, ArrayOfInt[3] = 3, ArrayOfInt[4] = 4, ArrayOfInt[5] = 5;

    for (i = 1; i < 5 ; i++)
    {
        Total +=  ArrayOfInt[i];
    }

    printf("The Total of the array is %d\n", Total);
    return(0);
}