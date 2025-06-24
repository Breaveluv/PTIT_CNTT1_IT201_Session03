#include <stdio.h>
#include <stdlib.h>
void sum(int n ,int m , int **arr) {
    int sum1 = 0;
    int sum2 = 0;
if (n != m) {
    printf("EROR");
    return;
}
    for (int i = 0; i < n; i++) {
        sum1 += arr[i][i];
        sum2 += arr[i][m-i-1];

    }
    printf("Sum (Tong duong cheo chinh) = %d\n",sum1);
    printf("Sum (Tong duong cheo phu) = %d\n",sum2);

}
void inputHe(int rows, int cols, int **hehe ) {
    printf("Nhap cac phan tu cua mang \n ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d",hehe[i][j]);
        }
    }
}
int main () {
    do {
        printf("Nhap so dong: ");
        scanf("%d",&n);
        printf("Nhap so cot: ");
        scanf("%d",&n);
        if (n<=0|| m<=0) {
            printf("Invalid input \n");

        }

    }while (n<=0 || m<=0);
    if ( n != m) {
        printf("EROR");
        return 0;
    }
    int **arr=(int **)malloc(n * sizeof(int *));
    if (arr == NULL) {
        printf("MEM ERROR");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i]=(int *)malloc(m*sizeof(int));
        if (arr[i] == NULL) {
            printf("MEM ERROR");
            for (int k = 0; k < i; k++) {
                free(arr[k]);
            }
            free(arr);
            return 1;

        }
    }
    inputHe(n,m,arr);
    sum(n,m,arr);
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;
}
