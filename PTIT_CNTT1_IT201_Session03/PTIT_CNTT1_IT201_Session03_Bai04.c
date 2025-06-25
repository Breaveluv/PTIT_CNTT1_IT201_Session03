#include <stdio.h>
#include <stdlib.h>
void inputMatrix(int rows, int cols, int **matrix) {
    printf("Nhap vao so luong phan tu: ");
    for (int i =0; i<rows;i++) {
        for (int j=0; j<cols;j++) {
            printf("Nhap phan tu [%d][%d]: ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }

}
void find(int n, int m,int **arr) {
    int max=arr[0][0];
    int min=arr[0][0];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (arr[i][j]>max) {
                max=arr[i][j];
            }
            if (arr[i][j]<min) {
                min=arr[i][j];
            }


        }
    }
    printf("%d %d\n",max,min);
}
int main() {
    int n,m;
    do {
        printf("Nhan phan tu: (row>0)");
        scanf("%d",&n);
        printf("Nhan phan tu: (col>0)");
        scanf("%d",&m);
        if (n<=0 || m<=0) {
            printf("NOOOO");
        }
    }while(n<=0 || m<=0);
    int **arr=(int **)malloc(n*sizeof(int *));
    if (arr==NULL) {
        printf("MEM ERROR");
        return 1;
    }
    for (int i=0;i<n;i++) {
        arr[i]=(int*)malloc(m*sizeof(int));
        if (arr[i]==NULL) {
            printf("MEM ERROR");
        for (int k=0;k<m;k++) {
            free(arr[k]);
        }
            free(arr);
            return 1;
        }
    }
    inputMatrix(n,m,arr);
    find(n,m,arr);
    for (int i=0;i<n;i++) {
        free(arr[i]);
    }
    free(arr);
    arr=NULL;
    return 0;
}

