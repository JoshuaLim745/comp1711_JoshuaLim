#include <stdio.h>

int str_len(char String[1000000] ){
    int counter = 0;

    while (String[counter] != 0) {
        counter += 1;
    }   

    return (counter);
}

void main (){
    char userString[1000000];
    int answer;
    printf("Please enter a stirng.\n");
    scanf("%s", userString);

    answer = str_len(userString);

    printf("%d \n", answer);

}