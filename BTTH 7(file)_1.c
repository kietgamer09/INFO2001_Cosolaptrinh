#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char studentID[10];
    float score;
} Student;

void addStudent(FILE *file) {
    Student student;
    printf("Nhap ten: ");
    fgets(student.name, sizeof(student.name), stdin);
    printf("Nhap ma sinh vien: ");
    fgets(student.studentID, sizeof(student.studentID), stdin);
    printf("Nhap diem so: ");
    scanf("%f", &student.score);

    strtok(student.name, "\n");
    strtok(student.studentID, "\n");

    fwrite(&student, sizeof(Student), 1, file);
    printf("Da them sinh vien vao tep tin.\n");
}

void removeStudent(FILE *file, const char *studentID) {
    FILE *tempFile = fopen("temp.txt", "wb");
    if (tempFile == NULL) {
        printf("Loi: Khong the mo tep tin tam thoi.\n");
        return;
    }

    Student student;
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (strcmp(student.studentID, studentID) != 0) {
            fwrite(&student, sizeof(Student), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("students.txt");
    rename("temp.txt", "Danh sach sinh vien.txt");

    printf("Da xoa sinh vien co ma so %s.\n", studentID);
}

void updateStudent(FILE *file, const char *studentID) {
    FILE *tempFile = fopen("temp.txt", "wb");
    if (tempFile == NULL) {
        printf("Loi: Khong the mo tep tin tam thoi.\n");
        return;
    }

    Student student;
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (strcmp(student.studentID, studentID) == 0) {
            printf("Nhap thong tin cap nhat cho sinh vien co ma so %s:\n", studentID);
            printf("Nhap ten: ");
            fgets(student.name, sizeof(student.name), stdin);
            printf("Nhap diem so: ");
            scanf("%f", &student.score);
            strtok(student.name, "\n");
            fwrite(&student, sizeof(Student), 1, tempFile);
            printf("Da cap nhat sinh vien co ma so %s.\n", studentID);
        } else {
            fwrite(&student, sizeof(Student), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("students.txt");
    rename("temp.txt", "students.txt");
}

void printStudents(FILE *file) {
    Student student;
    printf("Danh sach sinh vien:\n");
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        printf("Ten: %s\n", student.name);
        printf("Ma sinh vien: %s\n", student.studentID);
        printf("Diem so: %.2f\n", student.score);
        printf("----------------------\n");
    }
}

int main() {
    FILE *file = fopen("students.txt", "ab+");
    if (file == NULL) {
        printf("Loi: Khong the mo tep tin.\n");
        return 1;
    }

    int choice;
    char studentID[10];

    do {
        printf("Menu:\n");
        printf("1. Them sinh vien\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Cap nhat sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addStudent(file);
                break;
            case 2:
                printf("Nhap ma sinh vien can xoa: ");
                fgets(studentID, sizeof(studentID), stdin);
                strtok(studentID, "\n");
                removeStudent(file, studentID);
                break;
            case 3:
                printf("Nhap ma sinh vien can cap nhat: ");
                fgets(studentID, sizeof(studentID), stdin);
                strtok(studentID, "\n");
                updateStudent(file, studentID);
                break;
            case 4:
                printStudents(file);
                break;
            case 0:
                printf("Ket thuc chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 0);

    fclose(file);

    return 0;
}
