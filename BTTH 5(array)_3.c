#include <stdio.h>

#define MAX_STUDENTS 50

float calculateAverage(int marks[], int numStudents) {
    int sum = 0;
    int i;
    for (i = 0; i < numStudents; i++) {
        sum += marks[i];
    }
    return (float) sum / numStudents;
}

int main() {
    int numStudents;
    int marks[MAX_STUDENTS];


    printf("Nhap so luong sinh vien trong lop: ");
    scanf("%d", &numStudents);

    printf("Nhap diem cua tung sinh vien:\n");
    int i;
    for (i = 0; i < numStudents; i++) {
        printf("Diem cua sinh vien %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    float average = calculateAverage(marks, numStudents);

    printf("Diem trung binh cua lop la: %.2f\n", average);

    return 0;
}
