#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



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

// Complete the main function
int main() {
    //Plan
    // Initializing all variables that are needed.
    // 
    // While loop where FileLine not equal (Null/ EOF) with counter for size of file
    // make an array with type of fitness data (Maybe like 100 in size? or is there is way to find the file length/num of line).
    // While loop where FileLine not equal (Null/ EOF)
    // use tokenizeRecord to split the data. 
    // then print the len of array and the first 3 items. 

    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    char date[11], time[6], steps[4];
    int buffer_size = 1000, i = 0;
    char line [30] = {};
    FITNESS_DATA FitnessData[buffer_size];
    
    if (file == NULL){
        perror("");
        return 1;
    }
    

    while (fgets(line, 24, file) != NULL) {
        for (int i = 0; i < 24; i++)
        {
            if (line[i] == '\r')
            {
                line[i] = '\0';
            }
        }

        tokeniseRecord(line, ",", date, time, steps);
        
 
        strcpy(FitnessData[i].date , date);
        strcpy(FitnessData[i].time , time);
        FitnessData[i].steps = atoi(steps);


        i += 1;
    };

    printf("Number of records in file: %d\n", i);
    for (int j = 0; j <60; j++)
        printf("%s/%s/%d\n", FitnessData[j].date, FitnessData[j].time,FitnessData[j].steps);


    fclose(file);
    return 0;
}


