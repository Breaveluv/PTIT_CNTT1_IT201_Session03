#include <stdio.h>
#include <stdlib.h>
int main () {
    int n;
    int arr[n];
    printf("Nhập so luong phan tu");
    scanf("%d",&n);
    if (n<0||n>1000) {
        printf("khong hop le");
    }
    arr=(int*)malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("NOOOOO");
    }
    printf("Phan tu thu n %d",n);
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n;i++) {
        printf("So thu %d cua mang ",i+1,arr[i]);

    }
    int max=arr[0];
    for (int i=0;i<n;i++) {
        if (arr[i]>max) {
            max=arr[i];
            return 1;
        }
    }
    printf("So lon nhat trong mang la %d",max);
    return 0;
}