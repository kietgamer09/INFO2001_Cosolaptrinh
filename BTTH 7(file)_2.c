#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

void writeBinaryFile() {
    FILE *file = fopen("data.bin", "wb");
    if (file == NULL) {
        printf("Loi: Khong the mo tep tin.\n");
        return;
    }

    Person person1 = {"Kieu Tuan Dung", 26, 1.6};
    Person person2 = {"Le Tri Kiet", 18, 1.83};

    fwrite(&person1, sizeof(Person), 1, file);
    fwrite(&person2, sizeof(Person), 1, file);

    fclose(file);
    printf("Da ghi du lieu vao tep tin nhi phan.\n");
}

void readBinaryFile() {
    FILE *file = fopen("data.bin", "rb");
    if (file == NULL) {
        printf("Loi: Khong the mo tep tin.\n");
        return;
    }

    Person person;

    printf("Du lieu trong tep tin:\n");
    while (fread(&person, sizeof(Person), 1, file) == 1) {
        printf("Ten: %s\n", person.name);
        printf("Tuoi: %d\n", person.age);
        printf("Chieu cao: %.2f\n", person.height);
        printf("----------------------\n");
    }

    fclose(file);
}

int main() {
    writeBinaryFile();
    readBinaryFile();

    return 0;
}
