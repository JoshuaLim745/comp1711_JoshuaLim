#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    /* data */
    double x, y;
}point;

void main(){
    int SizeOfArray = 10, i;
    point ArrayOfPointers[SizeOfArray];

    for(i = 0; i < SizeOfArray; i++){
        ArrayOfPointers[i].x = rand();
        ArrayOfPointers[i].y = rand();
    }

    for(i = 0; i < SizeOfArray; i++){
        printf("(%.2f, %.2f) \n", ArrayOfPointers[i].x, ArrayOfPointers[i].y);
    }

}
