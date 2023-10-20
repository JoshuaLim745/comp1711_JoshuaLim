#include <stdio.h> 

float VolumeOfSphere(float radius){
    float volume;

    volume = 4/3 * 3.14 * radius * radius * radius;

    return (volume);
}

void main(){
    float radius, answer;

    printf("Please enter the radius of the sphere.\n");

    scanf("%f", &radius);


    answer = VolumeOfSphere(radius);

    printf("%f", answer);

}