#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {
    /* plan

    structure FITNESSDATA

    array of Fitnessdata with large size initially (maybe 1000)

    Userinput file name

    Open File for reading 
    Check if file exist/is a proper csv file

    Read line
    (How to check for correct formatting?) --> maybe consider the type then the length of char eg date has a length of 10 char and time has length of 5 

    if correct format then, use tokenize records and split on comma
    Place it into array
    Then Sort array using insertion sort

    Then write it to a file create by concatinating the user entered name and .tsv
    
    */

   char Filename[100];
   FILE *file;

   FitnessData FitnessArray[1000];
   char date[11], time[6], Linereader[100];

   int steps = 0, counter = 0;
   int *pointer = &steps;

   
    scanf("Enter Filename: %s\n", Filename);
    
    if((file = fopen(Filename,"r")) == NULL){
        printf("Error: invalid file");
        return 1;

    }

    while(fgets(Linereader,24,file) != NULL)

        tokeniseRecord(Linereader, ',',date, time, pointer);

        if ((date == "")||(time == "")||(*pointer == "")){
            printf("Error: invalid file");
            return 1;
        }

        strcpy(FitnessArray[counter].date , date);
        strcpy(FitnessArray[counter].time , time);
        FitnessArray[counter].steps = *pointer;

        counter++;

    
    for(int i = 0; i < counter; i++){
        printf("%s %s %d \n",FitnessArray[i].date, FitnessArray[i].time, FitnessArray[i].steps);
    }

    




    fclose(file);
    return 0;
}