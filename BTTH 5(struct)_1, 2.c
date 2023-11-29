#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    int ID;
    char name[30];
    struct Date dateOfBirth;
    int age;
    float gpa;
};

void initStudents(struct Student students[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("Nhap thong tin sinh vien thu %d\n", i + 1);
        printf("Ma sinh vien: ");
        scanf("%d", &students[i].ID);
        printf("Ho va ten: ");
        getchar();
        fgets(students[i].name, 30, stdin);
        printf("Ngay sinh (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &students[i].dateOfBirth.day, &students[i].dateOfBirth.month, &students[i].dateOfBirth.year);
        printf("Tuoi cua sinh vien: ");
        scanf("%d", &students[i].age);
        printf("Diem trung binh: ");
        scanf("%f", &students[i].gpa);
    }
}

void addStudent(struct Student students[], int size) {
    if (size < 3) {
        printf("Nhap thong tin cho sinh vien moi\n");
        printf("Ma sinh vien: ");
        scanf("%d", &students[size].ID);
        printf("Ho va ten: ");
        getchar();
        fgets(students[size].name, 30, stdin);
        printf("Ngay sinh (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &students[size].dateOfBirth.day, &students[size].dateOfBirth.month, &students[size].dateOfBirth.year);
        printf("Tuoi cua sinh vien: ");
        scanf("%d", &students[size].age);
        printf("Diem trung binh: ");
        scanf("%f", &students[size].gpa);
        printf("Them sinh vien moi thanh cong.\n");
    } else {
        printf("Danh sach sinh vien da day. Khong the them sinh vien moi.\n");
    }
}

void editStudent(struct Student students[], int size) {
    int studentID;
    printf("Nhap ma sinh vien cua sinh vien can sua: ");
    scanf("%d", &studentID);

    int foundIndex = -1;
    int i;
    for (i = 0; i < size; i++) {
        if (students[i].ID == studentID) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Nhap thong tin moi cho sinh vien\n");
        printf("Ma sinh vien: ");
        scanf("%d", &students[foundIndex].ID);
        printf("Ho va ten: ");
        getchar();
        fgets(students[foundIndex].name, 30, stdin);
        printf("Ngay sinh (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &students[foundIndex].dateOfBirth.day, &students[foundIndex].dateOfBirth.month, &students[foundIndex].dateOfBirth.year);
        printf("Tuoi cua sinh vien: ");
        scanf("%d", &students[foundIndex].age);
        printf("Diem trung binh: ");
        scanf("%f", &students[foundIndex].gpa);
        printf("Sua thong tin sinh vien thanh cong.\n");
    } else {
        printf("Khong tim thay sinh vien co ma so %d trong danh sach.\n", studentID);
    }
}
void printStudents(struct Student students[], int size) {
    printf("Danh sach sinh vien:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("Sinh vien thu %d\n", i + 1);
        printf("Ma sinh vien: %d\n", students[i].ID);
        printf("Ho va ten: %s", students[i].name);
        printf("Ngay sinh: %d/%d/%d\n", students[i].dateOfBirth.day, students[i].dateOfBirth.month, students[i].dateOfBirth.year);
        printf("Tuoi: %d\n", students[i].age);
        printf("Diem trung binh: %.2f\n", students[i].gpa);
        printf("\n");
    }
}
void sortStudents(struct Student students[], int size);
void selectionSort(struct Student students[], int size);
void swap(struct Student a, struct Student b);

void sortStudents(struct Student students[], int size) {
    selectionSort(students, size);
    printf("Danh sach sinh vien sau khi sap xep:\n");
    printStudents(students, size);
}

void selectionSort(struct Student students[], int size) {
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (students[j].ID < students[minIndex].ID) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(students[i], students[minIndex]);
        }
    }
}
void swap(struct Student a, struct Student b) {
    struct Student temp = a;
    a = b;
    b = temp;
}
void findStudents(struct Student students[], int size){
	if (size > 0) {
        int studentID;
        printf("Nhap ma sinh vien can tim: ");
        scanf("%d", &studentID);
        int foundIndex = -1;
        int i;
        for ( i = 0; i < size; i++) {
                if (students[i].ID == studentID) {
                foundIndex = i;
                break;
                }
            }

        if (foundIndex != -1) {
            printf("Tim thay sinh vien co ma so %d:\n", studentID);
            printf("Ho va ten: %s", students[foundIndex].name);
            printf("Ngay sinh: %d/%d/%d\n", students[foundIndex].dateOfBirth.day, students[foundIndex].dateOfBirth.month, students[foundIndex].dateOfBirth.year);
            printf("Tuoi: %d\n", students[foundIndex].age);
            printf("Diem trung binh: %.2f\n", students[foundIndex].gpa);
            } else {
            printf("Khong tim thay sinh vien co ma so %d trong danh sach.\n", studentID);
            }
            } else {
            printf("Danh sach sinh vien rong. Vui long them sinh vien truoc khi tim kiem.\n");
            }
}
int main() {
    struct Student students[3];
    int size = 0;
    int choice = 0;

    do {
        printf("CHUONG TRINH QUAN LY SINH VIEN\n");
        printf("1. Khoi tao danh sach\n");
        printf("2. Them moi sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Sap xep danh sach\n");
        printf("5. Tim kiem thong tin sinh vien\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban la gi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("BAT DAU KHOI TAO DANH SACH\n");
                initStudents(students, 3);
                break;
            case 2:
                addStudent(students, size);
                break;
            case 3:
                editStudent(students, size);
                break;
            case 4:
                sortStudents(students, size);
                break;
            case 5:
                findStudents(students, size);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }

        printf("\n");
    } while (choice != 0);

	return 0;
}
