#include <stdio.h>

void main(){
    int i, Userinput, result = 1;

    scanf("%d\n", &Userinput);
    for (i = 1 ; i <= Userinput; i++){
        result = result * i;
    };

    printf("The factorial of the number entered is %d\n", result);

}