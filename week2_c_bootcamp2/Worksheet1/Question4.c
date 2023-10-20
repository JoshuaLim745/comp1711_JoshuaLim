#include <stdio.h>

int main() {
    // Write C code here
    int temp;
    
    scanf("%d", &temp);
    
    if(temp >= -10 && temp <= 40){
        printf("The temperature you have entered is valid");
    }
    else{
        printf("The temperature you have entered is invalid");
    }
    
}
