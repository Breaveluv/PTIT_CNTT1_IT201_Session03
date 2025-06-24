//
// Created by nambu on 20/06/2025.
//
#include <stdio.h>
#include <stdlib.h>

 void inputElement( int *arr, int size) {
     for (int i = 0; i < size; i++) {
         printf("Nhap phan tu arr[%d]: ");
         scanf("%d", &arr[i]);

     }
 }
void printArray(int *arr, int size) {

     for (int i=0; i < size; i++) {
         printf("%d, ", arr[i]);
         if (i<size-1) {
             printf(",");
         }
     }

 }
int main() {
     int n;
     do {
         printf("Nh: Nhap so luong phan tu ban dau: ");
         scanf("%d", &n);
         if (n <= 0 || n > 1000) {
             printf("So luong phan tu ban dau khong hop le ");

         }
     }while (n <= 0 || n > 1000);
        int *arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("loi cap nhap bo nho lan 1 \n");
            return 1;
        }
    print("Nhap %d phan tu cho mang ban dau: \n",n);
     printf("Mang ban dau ");
     printArray(arr, n);
     int m;
     int cunrent_size = n;
     printf("Nhao so luong phan tu mang muon them m (m>=0)");
     scanf("%d", &m);
     if (cunrent_size +m>=1000) {
         printf("Tong so luong phan tu (n+m) vuot qua gioi han 1000 khong the them");
         free(arr);
         return 1;
     }
     if (m>0) {
         int *temp_arr=(int*)(realloc(arr,(cunrent_size+m)*sizeof(int)));
         if (temp_arr == NULL) {
             printf("loi cap nhap bo nho lan 2 \n");
             free(arr);
             return 1;
         }
         arr=temp_arr;
         printf("Nhap %d phan tu muon them vao ",m);
         for (int i = 0; i < m; i++) {
             printf("Nhap phan tu moi thu %:, ", i+1);
             scanf("%d", &arr[cunrent_size+i]);

         }
         cunrent_size+=m;
     }else{
         printf("Khong co phan tu nao them vào")
     }
     printf("\n Mang sau khi them");
     printArray(arr, cunrent_size);
     free(arr);
     arr = NULL;
     return 0;
 }
