#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char ten[50];
    char tacGia[50];
    float gia;
} Book;

void NhapSach(Book* sach, int soLuong) {
    printf("Nhap thong tin cho cac quyen sach:\n");
    int i;
    for (i = 0; i < soLuong; i++) {
        printf("Sach thu %d:\n", i + 1);
        printf("Ten sach: ");
        scanf("%s", sach[i].ten);
        printf("Tac gia: ");
        scanf("%s", sach[i].tacGia);
        printf("Gia: ");
        scanf("%f", &sach[i].gia);
    }
}

void HienThiSach(Book* sach, int soLuong) {
    printf("Danh sach cac quyen sach:\n");
    int i;
    for (i = 0; i < soLuong; i++) {
        printf("Sach thu %d:\n", i + 1);
        printf("Ten sach: %s\n", sach[i].ten);
        printf("Tac gia: %s\n", sach[i].tacGia);
        printf("Gia: %.2f\n", sach[i].gia);
        printf("\n");
    }
}

int main() {
    int soLuongSach;
    printf("Nhap so luong sach: ");
    scanf("%d", &soLuongSach);

    // Cap phat dong
    Book* danhSachSach = (Book*)malloc(soLuongSach * sizeof(Book));
    if (danhSachSach == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }

    NhapSach(danhSachSach, soLuongSach);
    HienThiSach(danhSachSach, soLuongSach);

    // Giai phong bo nho
    free(danhSachSach);

    return 0;
}
