#include <stdio.h>
#include <stdlib.h>

void main(){
    char filename []= "Squares.dat";
    FILE *file = fopen(filename, "r");

    int bufferSize = 100;
    char ReadValue[bufferSize];
    float average, counter = 0, sum = 0; 
    ;

    while(fgets(ReadValue, bufferSize, file) != NULL){
        sum += atoi(ReadValue);
        counter += 1;

    }

    average = sum / counter;

    printf("%f\n", average);
}