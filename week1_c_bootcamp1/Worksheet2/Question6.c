#include <stdio.h>

void main(){


    int ArrayOfSetNumber1[3] ={27,17,31}, ArrayOfSetNumber2[3]={15,68,62}, FinalOfInt[6],Counter = 0;

    for(int i =0; i < 6 ; i++)
    {
        if (i <= 2)
        {
            FinalOfInt[i] = ArrayOfSetNumber1[i];
        }
        else if (i>2)
        {
            FinalOfInt[i] = ArrayOfSetNumber2[Counter];
            Counter += 1;
        }
        
    }

    for(int i =0; i < 6 ; i++)
    {
        printf("The value in the concatenated array is %d\n" , FinalOfInt[i]);
    }
}
