#include <stdio.h>

void main(){
    int NumOfDays, SpeedOfLight = 299792458; /*In m/s*/
    float DistanceTravelled;

    scanf("Please enter the number of days %d, \n", &NumOfDays);

    DistanceTravelled = ((NumOfDays * 86400) * SpeedOfLight)/ 1000;

    printf("The light will travel %f\n" , DistanceTravelled);


}