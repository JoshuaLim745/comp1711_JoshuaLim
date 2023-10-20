#include <stdio.h>

int main() {
    // Write C code here
    int number;
    

    while (number != -1){
        printf("please enter a number from 1 to 100 and to terminate enter -1 \n");
        scanf("%d", &number);
        if(number == -1){
            printf("the program will terminate\n");
        }
        
        
        else if (number < 0 || number > 100){
            printf("The number you have entered is invalid as it does not meet the requirements of 0 to 100\n");
        }
    }
    
    
}
