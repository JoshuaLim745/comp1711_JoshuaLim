#include <stdio.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    struct student new_student = {"Joshua Lim", "28932123", 35};
    struct student New_student2 ={"Joshua Lim", "11111111", 100};
    printf("Student name: %s\n", New_student2.name);
    printf("Student ID:   %s\n", New_student2.student_id);
    printf("Final mark:   %u\n", New_student2.mark);
    
    return 0;
}