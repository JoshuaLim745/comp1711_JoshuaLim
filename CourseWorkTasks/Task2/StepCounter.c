#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"


// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char UserEnteredFileName[20];
FITNESS_DATA FitnessData[60];


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

int FileReading(char UserEnteredFileName[20]){

    FILE *file = fopen(UserEnteredFileName, "r");
    char date[11], time[6], steps[10];
    int buffer_size = 1000, counter = 0;
    char Linereader[30] = {};
    int Loaded = 0;
            
    if (file == NULL){
        perror("Error: Could not find or open the file.");
        exit(1);

    }
    else {
        printf("File successfully loaded.\n");
        Loaded = 1;
    }

    if (Loaded == 1){
        //Inspired from my CourseWork 1 "StepsTask1.c"
        while (fgets(Linereader, 24, file) != NULL){

        tokeniseRecord(Linereader, ",", date, time, steps);
        
 
        strcpy(FitnessData[counter].date , date);
        strcpy(FitnessData[counter].time , time);
        FitnessData[counter].steps = atoi(steps);

        counter++;

        }
    }

    else{
        return 1;
    }
}

void DisplayTotalRecords(){

    FILE *file = fopen(UserEnteredFileName, "r");
    char Linereader[30] = {};
    int counter = 0;

    while (fgets(Linereader, 24, file) != NULL) {

        counter += 1;
    };

    printf("Total Records: %d \n", counter);
} 

void FewestSteps(){
    int LowestSteps = FitnessData[0].steps, counter = 1, Recordedcounter = 0;

    while (counter < 59){

        if (FitnessData[counter].steps < LowestSteps){
            LowestSteps = FitnessData[counter].steps;
            Recordedcounter = counter;
        }

        counter += 1;
    }

    printf("Fewest Steps: %s %s\n", FitnessData[Recordedcounter].date, FitnessData[Recordedcounter].time);
}

void LargestSteps(){
    int LargestSteps = FitnessData[0].steps, counter = 1, Recordedcounter = 0;

    while (counter < 59){
        
        if (FitnessData[counter].steps > LargestSteps){
            LargestSteps = FitnessData[counter].steps;
            Recordedcounter = counter;
        }

        counter ++;
    }

    printf("Largest Steps: %s %s\n", FitnessData[Recordedcounter].date, FitnessData[Recordedcounter].time);
}


int Meanvalue(){
    float Total = 0 , mean = 0, SizeOfArray = 59;
    int FinalValue = 0;
    
    for (int i = 0; i < 59; i++){

        Total = Total + FitnessData[i].steps;
    }

    mean = Total / SizeOfArray;

    return mean;

    
}

void LongestContinousPeriod(){
    int StartCounter = 0, EndCounter = 0, CurrentCounter = 0, i=0, LongestperiodCounter =0, FinalStart =0, FinalEnd = 0;
    char Larger ='T';

    for(CurrentCounter =0; CurrentCounter < 59 ; CurrentCounter++) {
        

        if (FitnessData[CurrentCounter].steps >= 500){
            StartCounter = CurrentCounter;
            i = CurrentCounter;
            Larger = 'T';

            while (Larger == 'T'){
                i++;
                if (FitnessData[i].steps >= 500){
                    EndCounter = i;
                }
                else{
                    Larger = 'F';
                }
            }
            
        }


        if (LongestperiodCounter < (EndCounter - StartCounter)){
            FinalStart = StartCounter;
            FinalEnd = EndCounter;
            LongestperiodCounter = (EndCounter - StartCounter);
        }



        if (CurrentCounter < EndCounter){
            CurrentCounter = EndCounter;
        }

    
    }
    printf("Longest period start: %s %s \n", FitnessData[FinalStart].date, FitnessData[FinalStart].time);
    printf("Longest period end: %s %s \n", FitnessData[FinalEnd].date, FitnessData[FinalEnd].time);
}


// Complete the main function
int main() {
   char UserValue = 'F' , *PreferredValue = "ABCDEFQabcdefq"; 
   char DoesFileexist;
   int meanvalue = 0;

    while (strchr(PreferredValue, UserValue) != NULL){
        printf("Menu Options:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");

        printf("Enter choice: ");

        scanf(" %c", &UserValue);


        switch (UserValue)
        {
        case 'A':
        case 'a':

            printf("Input Filename: ");
            scanf("%s", UserEnteredFileName);

            FileReading(UserEnteredFileName);

            break;

        case 'B':
        case 'b':
            DisplayTotalRecords();

            break;

        case 'C':
        case 'c':
            
            FewestSteps();

            break;

        case 'D':
        case 'd':
            
            LargestSteps();

            break;

        case 'E':
        case 'e':
            
            meanvalue = Meanvalue();
            printf("Mean step count: %d", meanvalue);

            break;

        case 'F':
        case 'f':
            LongestContinousPeriod();

            break;

        case 'Q':
        case 'q':

            return 0;
            break;
        
        default:
            printf("\n");
            printf("Invalid choice. Try again.\n");
        
            break;
        }
   
    }
   
    return 1;

}

