#include <stdio.h>

void main(){
    int UserNumber, squared;
    char filename []= "Squares.dat";

    FILE *file = fopen(filename,"w");
    printf("Please enter a number between 10 and 20\n");
    scanf("%d", &UserNumber);
    for (int i = 0 ; i <= UserNumber; i++){
        squared = i * i;
        fprintf(file, "%d\n", squared);
    }


    fclose(file);
}