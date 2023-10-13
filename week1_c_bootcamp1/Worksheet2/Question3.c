#include <stdio.h>

void main(){
    int ArrayOfInt[5] = {13,9,39,42,47}, Highest = 0, i;

    for (i = 0 ; i<4; i++);
    {
        if (Highest < ArrayOfInt[i])
        {
            Highest = ArrayOfInt[i];
        }
    }

    printf("The Highest value is %d\n", Highest);
}