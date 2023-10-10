#include <stdio.h>

int main()
{
    char name[15]; /*Name has char data type that holds 15 chars*/
    printf("Hello, please enter your name:");
    scanf("%s", name); 
    /*
    & sign give the address of the memory chunk/variable
    */
    printf("Your name is %s\n", name);  
    return 0;
}
