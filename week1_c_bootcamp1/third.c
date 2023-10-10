#include <stdio.h>

int main()
{
    int age ;
    printf("Hello, please enter your age:");
    scanf("%d", &age); 
    /*
    & sign give the address of the memory chunk/variable
    
    */
    printf("Your age is %d\n", age);  
    return 0;
}
