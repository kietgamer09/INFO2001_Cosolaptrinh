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