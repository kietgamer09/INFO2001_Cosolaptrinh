#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int employeeID;
    char name[50];
    char position[50];
    float salary;
};

int addEmployee(struct Employee employees[], int size);
int removeEmployee(struct Employee employees[], int size);
void displayEmployees(struct Employee employees[], int size);
void sortEmployees(struct Employee employees[], int size);

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int size = 0;
    int choice;

    do {
        printf("\n===== Quan Ly Nhan Su =====\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep danh sach nhan vien\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                size = addEmployee(employees, size);
                break;
            case 2:
                size = removeEmployee(employees, size);
                break;
            case 3:
                displayEmployees(employees, size);
                break;
            case 4:
                sortEmployees(employees, size);
                displayEmployees(employees, size);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

int addEmployee(struct Employee employees[], int size) {
    if (size >= MAX_EMPLOYEES) {
        printf("Danh sach nhan vien da day. Khong the them nhan vien moi.\n");
        return size;
    }

    struct Employee newEmployee;

    printf("Nhap ma nhan vien: ");
    scanf("%d", &(newEmployee.employeeID));

    printf("Nhap ten nhan vien: ");
    scanf(" %[^\n]", newEmployee.name);

    printf("Nhap chuc vu: ");
    scanf(" %[^\n]", newEmployee.position);

    printf("Nhap luong: ");
    scanf("%f", &(newEmployee.salary));

    employees[size] = newEmployee;
    size++;

    printf("Them nhan vien thanh cong.\n");
    return size;
}

int removeEmployee(struct Employee employees[], int size) {
    if (size <= 0) {
        printf("Danh sach nhan vien rong. Khong the xoa.\n");
        return size;
    }

    int employeeID;
    printf("Nhap ma nhan vien can xoa: ");
    scanf("%d", &employeeID);

    int foundIndex = -1;
    int i;
    for (i = 0; i < size; i++) {
        if (employees[i].employeeID == employeeID) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        int i;
		for (i = foundIndex; i < size - 1; i++) {
            employees[i] = employees[i + 1];
        }
        size--;
        printf("Xoa nhan vien thanh cong.\n");
    } else {
        printf("Khong tim thay nhan vien co ma so %d trong danh sach.\n", employeeID);
    }

    return size;
}

void displayEmployees(struct Employee employees[], int size) {
    if (size <= 0) {
        printf("Danh sach nhan vien rong.\n");
        return;
    }

    printf("Danh sach nhan vien:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("Ma nhan vien: %d\n", employees[i].employeeID);
        printf("Ten nhan vien: %s\n", employees[i].name);
        printf("Chuc vu: %s\n", employees[i].position);
        printf("Luong: %.2f\n", employees[i].salary);
        printf("-----------------------\n");
    }
}

void sortEmployees(struct Employee employees[], int size) {
    if (size <= 0) {
        printf("Danh sach nhan vien rong. Khong the sap xep.\n");
        return;
    }

    int i;
	for (i = 0; i < size - 1; i++) {
        int j;
		for ( j = i + 1; j < size- 1; j++) {
            if (employees[i].employeeID > employees[j].employeeID) {
                struct Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }

    printf("Sap xep danh sach nhan vien theo ma nhan vien.\n");
}
