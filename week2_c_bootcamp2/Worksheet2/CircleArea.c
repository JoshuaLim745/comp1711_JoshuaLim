#include <stdio.h>

float circleArea (float radius){
    float area;

    area = 3.14 * radius * radius;

    return area;
}

void main(){

    float UserInputtedValue, answer;

    printf("Please enter the radius of the circle \n");
    scanf("%f", &UserInputtedValue);

    answer = circleArea(UserInputtedValue);

    printf("%f",answer);
}