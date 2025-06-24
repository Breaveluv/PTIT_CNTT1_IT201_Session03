#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;


    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);


    if (n <= 0 || n > 1000) { // Nên kiểm tra cả trường hợp n=0
        printf("So luong phan tu khong hop le (phai lon hon 0 và nho hon 1000).\n");
        return 1; // Thoát chương trình với mã lỗi
    }


    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Loi cap phat bo nho!\n");
        return 1;
    }


    printf("Nhap %d phan tu cho mang:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("\nCac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        // Thêm %d thứ hai và \n để xuống dòng
        printf("So thu %d = %d\n", i + 1, arr[i]);
    }


    double sum_chan = 0.0;
    int count_chan = 0;


    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            sum_chan += arr[i];
            count_chan++;
        }
    }


    printf("\n--- KET QUA TRUNG BINH CONG ---\n");
    if (count_chan > 0) {

        double trung_binh = sum_chan / count_chan;
        printf("Tim thay %d so chan.\n", count_chan);
        printf("Tong cac so chan la: %.0f\n", sum_chan); // Dùng %.0f để in như số nguyên
        printf("Trung binh cong cac so chan la: %.2f\n", trung_binh);
    } else {

        printf("Khong tim thay so chan nao trong mang.\n");
    }

    // Bước 8: Giải phóng bộ nhớ
    free(arr);
    arr = NULL;

    return 0;
}