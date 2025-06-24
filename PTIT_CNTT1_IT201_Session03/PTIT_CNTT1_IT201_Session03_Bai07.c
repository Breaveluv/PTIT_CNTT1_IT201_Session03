//
// Created by nambu on 20/06/2025.
//
#include <stdio.h>
#include <stdlib.h>
void nhapMangHaiCHieu(int rows, int cols, int **matrix) {
    printf("Nhap cac phan tu cua mang: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap phan tu arr[%d][%d]",i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
int sumRow(int rows, int cols, int **matrix, int k) {
    if (k<0 || k > rows) {
        return -1;
    }
    int rowSum = 0;
    for (int j = 0; j < cols; j++) {
        rowSum += matrix[k][j];

    }
    return rowSum;

}
int main() {
    int rows, cols;
    int k;
    do {
        printf("Nhap so hang: \n");
        scanf("%d", &rows);
        printf("Nhap so cot: \n");
        scanf("%d", &cols);
        if (rows <= 0 ||rows>=1000||cols>=1000 ||cols <= 0) {
            printf("So hang hoac so cot khong hop le");
        }
    }while (rows <= 0 ||rows>=1000 ||cols <= 0 ||cols>=1000 );
    int **matrix=(int **)malloc(rows *sizeof(int *));
    if (matrix == NULL) {
        printf("Loi khong du bo nho");
        return -1;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Loi khong du bo nho");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return -1;
        }
    }
    nhapMangHaiCHieu(rows, cols, matrix);
    printf("Nhap chi so hang ");
    scanf("%d", &k);

    int resultSum = sumRow(rows, cols, matrix, k);
    if (resultSum == -1) {
        printf("hang can tnh khong hop le");
    }else {
        printf("sum= %d\n", resultSum);
    }
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    matrix=NULL;
    return 0;
}