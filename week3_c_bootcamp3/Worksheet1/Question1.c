#include <stdio.h>

void main(){
    int UserNumber, squared;
    char filename []= "Sqaures.dat";

    FILE *file = fopen(filename,"w");
    printf("Please enter a number between 10 and 20");
    scanf("%d\n", &UserNumber);
    for (int i ; i < UserNumber; i++){
        squared = i * i;
        printf("%d\n", squared);
    }


    fclose(file);
}