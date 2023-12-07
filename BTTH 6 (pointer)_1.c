#include <stdio.h>

void NhapMang(int* arr, int size) {
    printf("Nhap cac phan tu cua mang:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", arr + i);
    }
}

void InMang(int* arr, int size) {
    printf("Cac phan tu cua mang:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int TimKiem(int* arr, int size, int key) {
	int i;
    for (i = 0; i < size; i++) {
        if (*(arr + i) == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &size);

    int arr[size];

    NhapMang(arr, size);
    InMang(arr, size);

    int key;
    printf("Nhap phan tu can tim kiem: ");
    scanf("%d", &key);

    int index = TimKiem(arr, size, key);
    if (index != -1) {
        printf("Phan tu %d co trong mang tai vi tri %d.\n", key, index);
    } else {
        printf("Phan tu %d khong co trong mang.\n", key);
    }

    return 0;
}
