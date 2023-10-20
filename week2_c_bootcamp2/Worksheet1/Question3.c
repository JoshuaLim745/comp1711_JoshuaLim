#include <stdio.h>

int main() {
    // Write C code here
    int mark;
    
    scanf("%d", &mark);
    
    if(mark < 50){
        printf("you have failed");
    }
    else if(mark>= 50 && mark < 70){
        printf("you have passed");
    }
    else if (mark >= 70 && mark <= 100){
        printf("you have obtained a distinction");
    }
    else {
        printf("please enter a number between 0 and 100");
    }
}
