#include <stdio.h>

void main(){
    int ArryOfInt[6] = {1,2,3,2,1,4} , temp = 0, counter = 0;

    for (int i = 0; i < 6 ; i++)
    {
        counter = 0;
        temp = ArryOfInt[i];

        for (int j = i + 1; j < 6; j++)

        {
            if ((temp == ArryOfInt[j]) && (counter == 0))
            {
                counter = 1;
                printf("A duplicate of %d has been found\n" ,temp);
            }
                
            
        }
    }
}