#include <stdio.h>
#define N_STUDENTS 4
#define N_MODULES 3

typedef struct {
    char StudentName[50];
    int StudentID;
    float GPA;
    int ProceduralMark;
    int IntroToProgramming; 
    int OperatingSyetems; 
    
} Student;

void extractAndStore(Student students[], int extractedData[][N_MODULES]) {
    for (int i = 0; i < N_STUDENTS; ++i) {
        extractedData[i][0] = students[i].ProceduralMark;
        extractedData[i][1] = students[i].IntroToProgramming;
        extractedData[i][2] = students[i].OperatingSyetems;
    }
}

int main(){
    Student StudentArray[N_STUDENTS]= {
        {"Alex Turner", 2306456, 3.5, 78, 82, 89},
        {"Bob Williams", 2385679, 3.9,100,85,92},
        {"Sophia Mendes", 2374068, 3.7, 93, 90, 87},
        {"Laura Cerroni", 2398452, 3.2, 65, 70, 80}
    };

    for (int i = 0; i<N_STUDENTS; i++){
        printf("Student %d: %d, %d, %d \n", i + 1 , StudentArray[i].ProceduralMark, StudentArray[i].IntroToProgramming, StudentArray[i].OperatingSyetems);
    }





    return 0; 
}