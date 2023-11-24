#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

FITNESS_DATA FitnessData[1000];
char UserEnteredFileName[20];

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

    FILE *file;
    int buffer_size = 1000, counter = 0;
    char Linereader[30] = {};
    int DoesntExist = 1;
            
    if ((file = fopen(UserEnteredFileName, "r")) == NULL){
        printf("Error: Could not find or open the file.\n");
        
    }
    else {
        printf("File successfully loaded.\n");
        DoesntExist = 0;
    }


    return DoesntExist;
}

int DisplayTotalRecords(){

    FILE *file = fopen(UserEnteredFileName, "r");
    char Linereader[30] = {}, date[11], time[6], steps[10];
    int counter = 0;

    while (fgets(Linereader, 24, file) != NULL) {
        tokeniseRecord(Linereader, ",", date, time, steps);
        
 
        strcpy(FitnessData[counter].date , date);
        strcpy(FitnessData[counter].time , time);
        FitnessData[counter].steps = atoi(steps);

        counter++;
    };


    return counter; 
} 

int FewestSteps(int NumberOfRecords){
    int Feweststeps = FitnessData[0].steps, counter = 1, Recordedcounter = 0;

    for (counter; counter < NumberOfRecords; counter++ ){
        
        if (FitnessData[counter].steps < Feweststeps){
            Feweststeps = FitnessData[counter].steps;
            Recordedcounter = counter;
        }

    }

    return Recordedcounter;
    
}


int LargestSteps(int NumberOfRecords){
    int LargestSteps = FitnessData[0].steps, counter = 1, Recordedcounter = 0;

    for (counter; counter < NumberOfRecords; counter++ ){
        
        if (FitnessData[counter].steps > LargestSteps){
            LargestSteps = FitnessData[counter].steps;
            Recordedcounter = counter;
        }

    }

    return Recordedcounter;
}


int Meanvalue(int NumberOfRecords){
    double Total = 0 , mean = 0;
    int FinalValue = 0;
    
    for (int i = 0; i < NumberOfRecords; i++){

        Total = Total + FitnessData[i].steps;
    }

    mean = Total / NumberOfRecords;

    FinalValue = (int)mean;

    if ((mean - FinalValue) >= 0.5){
        FinalValue++;
    }

    return FinalValue;

    
}

void LongestContinousPeriod(int NumberOfRecords){
    int StartCounter = 0, EndCounter = 0, CurrentCounter = 0, i=0, LongestperiodCounter =0, FinalStart =0, FinalEnd = 0;
    char Larger ='T';

    for(CurrentCounter = 0; CurrentCounter < NumberOfRecords ; CurrentCounter++) {
        

        if (FitnessData[CurrentCounter].steps >= 500){
            StartCounter = CurrentCounter;
            i = CurrentCounter;
            Larger = 'T';

            while (Larger == 'T'){
                i++;
                if (FitnessData[i].steps > 500){
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
   int meanvalue = 0, returnvalue = 0;
   int NumberOfRecords = 0;  
   
   FILE ReadFile; 
     

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

            returnvalue = FileReading(UserEnteredFileName);

            if (returnvalue == 1){
                return 1;
            }
            break;

        case 'B':
        case 'b':
            NumberOfRecords = DisplayTotalRecords();
            printf("Total records: %d\n", NumberOfRecords);

            break;

        case 'C':
        case 'c':
            
            returnvalue = FewestSteps(NumberOfRecords);
            printf("Fewest steps: %s %s\n", FitnessData[returnvalue].date, FitnessData[returnvalue].time);
            

            break;

        case 'D':
        case 'd':
            
             returnvalue = LargestSteps(NumberOfRecords);
             printf("Largest steps: %s %s\n", FitnessData[returnvalue].date, FitnessData[returnvalue].time);

            break;

        case 'E':
        case 'e':

            meanvalue = Meanvalue(NumberOfRecords);
            printf("Mean step count: %d\n",meanvalue);


            break;

        case 'F':
        case 'f':

            LongestContinousPeriod(NumberOfRecords);

            break;

        case 'Q':
        case 'q':

            return 0;
            break;
        
        default:

            printf("Invalid choice. Try again.\n");
        
            break;
        }
   
    }
   
    return 0;

}

