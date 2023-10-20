#include <stdio.h>

int main() {
    // Write C code here
    int number;
    
    scanf("%d", &number);
    
    if(number < 0){
        printf("the number entered is negative");
    }
    else if (number == 0){
        printf("the number entered is zero");
    }
    else if (number > 0){
        printf("the number is positive");
    }
}
