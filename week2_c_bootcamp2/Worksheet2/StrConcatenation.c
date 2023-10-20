#include <stdio.h>
#include <string.h>

char ConcatenatedString[] = "";

char* concatStrings(char string1[], char string2[]){
    
    int counter = 0;

    for (int i = 0; i< strlen(string1); i++){
        ConcatenatedString[i] = string1[i];
        counter += 1;
    }

    for (int i = 0; i< strlen(string2); i++){
        ConcatenatedString[counter] = string2[i];
        counter += 1;
    }

    return (ConcatenatedString);
}

void main(){
    char string1[100000], string2[100000], answer[100000];

    printf("Please enter a string\n");
    scanf("%s", string1);
    printf("Please enter a second string\n");
    scanf("%s", string2);

    printf("%s \n", concatStrings(string1, string2));
}