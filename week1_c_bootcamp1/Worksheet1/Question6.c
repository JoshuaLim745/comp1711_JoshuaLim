#include <stdio.h>

void main(){
    int UserInput = 0;

    scanf("%d \n", &UserInput);

    if (UserInput % 2 == 0)
    {
        printf("The number entered is even\n");
    }
    else
    {
        printf("The number entered is odd\n");
    }
}