#include <stdio.h>
char* Sign;
float Calc(float Num1, float Num2){
    float answer = 0;
    if(Sign[0] == '+'){
        answer = Num1 + Num2;
    } else if(Sign[0]  == '-'){
       answer = Num1 - Num2;
    } else if(Sign[0]  == '*'){
       answer = Num1 * Num2;
    } else if(Sign[0]  == '/'){
       answer = Num1 / Num2;
    };

    return(answer);

}

void main(){
    float answer;
    Sign[0] = '+';
    answer = Calc(10,5);

    printf("%f", answer);
}