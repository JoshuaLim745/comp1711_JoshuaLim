#include <stdio.h>

int main() {
    // Write C code here
    int number;
    
    scanf("%d", &number);
    
    if(number % 4 == 0 && number % 5 == 0){
        printf("the number entered is divisible by 4 and 5");
    }
    else{
        printf("the number is not divisible by 4 or 5");
    }
}
