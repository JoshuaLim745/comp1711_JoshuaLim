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
    (How to check for correct formatting?) --> just check if it is null/ empty

    if correct format then, use tokenize records and split on comma
    Place it into array
    Then Sort array using insertion sort

    Then write it to a file create by concatinating the user entered name and .tsv
    
    */

    char Filename[100];
    FILE *file;

    FitnessData FitnessArray[1000];
    char date[11], time[6], Linereader[30] = {}, TempTime[6], TempDate [11];

    int steps = 0, counter = 0, TempIndex = 0, j = 0, TempSteps = 0;
    int *pointer = &steps;


    printf("Enter Filename: ");
    scanf("%s", Filename);

    
    if((file = fopen(Filename,"r")) == NULL){
        printf("Error: invalid file");
        return 1;

    }

    while(fgets(Linereader,24,file) != NULL){

        if (strlen(Linereader)!= 24){
            printf("Error: invalid file\n ");
            return 1;
        }

        tokeniseRecord(Linereader, ',',date, time, pointer);


        strcpy(FitnessArray[counter].date , date);
        strcpy(FitnessArray[counter].time , time);
        FitnessArray[counter].steps = *pointer;

        counter++;
        }


    for(int i = 0; i < counter ; i++){
        TempSteps = FitnessArray[i].steps;
        strcpy(TempDate, FitnessArray[i].date);
        strcpy(TempTime, FitnessArray[i].time);
        j = i - 1;
        while( (j >= 0) && (FitnessArray[j].steps < TempSteps)){
            FitnessArray[j + 1].steps = FitnessArray[j].steps;
            strcpy(FitnessArray[j + 1].date, FitnessArray[j].date);
            strcpy(FitnessArray[j + 1].time, FitnessArray[j].time);

            j--;

        }

        FitnessArray[j + 1].steps = TempSteps;
        strcpy(FitnessArray[j + 1].date, TempDate);
        strcpy(FitnessArray[j + 1].time, TempTime);
    }


    for(int i = 0 ; i< counter; i++){
        printf("%s\t%s\t%d\n", FitnessArray[i].date, FitnessArray[i].time, FitnessArray[i].steps);
    }



    




    fclose(file);
    return 0;
}