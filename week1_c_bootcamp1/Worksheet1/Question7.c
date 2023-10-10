#include <stdio.h>

void main(){

    float Farenheit, Celcius;

    scanf("Please enter a temp %f \n", &Farenheit);

    Celcius = (Farenheit -32) * (5/9);

    printf("The temp converted to celcius is %f\n", Celcius);
}