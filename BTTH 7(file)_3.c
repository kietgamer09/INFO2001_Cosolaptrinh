#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} ContactBook;

void initializeContactBook(ContactBook *book) {
    book->count = 0;
}

void addContact(ContactBook *book, const char *name, const char *phone, const char *email) {
    if (book->count >= MAX_CONTACTS) {
        printf("So lien lac da day.\n");
        return;
    }

    Contact *contact = &(book->contacts[book->count]);
    strncpy(contact->name, name, sizeof(contact->name) - 1);
    strncpy(contact->phone, phone, sizeof(contact->phone) - 1);
    strncpy(contact->email, email, sizeof(contact->email) - 1);

    book->count++;
}

void displayContacts(const ContactBook *book) {
    printf("Danh sach lien lac:\n");
    printf("------------------\n");
    int i;
    for (i = 0; i < book->count; i++) {
        const Contact *contact = &(book->contacts[i]);
        printf("Ten: %s\n", contact->name);
        printf("So dien thoai: %s\n", contact->phone);
        printf("Email: %s\n", contact->email);
        printf("------------------\n");
    }
}

int findContact(const ContactBook *book, const char *name) {
	int i;
    for (i = 0; i < book->count; i++) {
        const Contact *contact = &(book->contacts[i]);
        if (strcmp(contact->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteContact(ContactBook *book, const char *name) {
    int index = findContact(book, name);
    if (index == -1) {
        printf("Khong tim thay.\n");
        return;
    }
	int i;
    for (i = index; i < book->count - 1; i++) {
        Contact *current = &(book->contacts[i]);
        Contact *next = &(book->contacts[i + 1]);
        memcpy(current, next, sizeof(Contact));
    }

    book->count--;
}

void updateContact(ContactBook *book, const char *name, const char *phone, const char *email) {
    int index = findContact(book, name);
    if (index == -1) {
        printf("Khong tim thay.\n");
        return;
    }

    Contact *contact = &(book->contacts[index]);
    strncpy(contact->phone, phone, sizeof(contact->phone) - 1);
    strncpy(contact->email, email, sizeof(contact->email) - 1);
}

void saveContactBook(const ContactBook *book, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Loi khong the mo.\n");
        return;
    }

    fwrite(book, sizeof(ContactBook), 1, file);

    fclose(file);
    printf("Da luu.\n");
}

void loadContactBook(ContactBook *book, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Loi khong the mo.\n");
        return;
    }

    fread(book, sizeof(ContactBook), 1, file);

    fclose(file);
    printf("Da tai.\n");
}

int main() {
    ContactBook book;
    initializeContactBook(&book);

    loadContactBook(&book, "contacts.txt");

    addContact(&book, "Kieu Tuan Dung", "0123123123", "kieutuandung@gmail.com");
    addContact(&book, "Le Tri Kiet", "987654321", "kietgamer09@gmail.com");

    displayContacts(&book);

    deleteContact(&book, "Kieu Tuan Dung");

    updateContact(&book, "Le Tri Kiet", "0858478875", "spectrumcheese09@gmail.com");

    displayContacts(&book);

    saveContactBook(&book, "contacts.txt");

    return 0;
}
