#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int size;
    printf("Nhap kich thuoc cua mang: ");
    scanf("%d", &size);

    // Cap phat dong
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }

    NhapMang(arr, size);
    InMang(arr, size);

    // giai phong
    free(arr);

    return 0;
}
