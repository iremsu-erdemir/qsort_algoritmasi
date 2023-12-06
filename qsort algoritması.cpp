#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define N 7
int KtenB(const void*, const void*);
int BtenK(const void*, const void*);
int main() {
    setlocale(LC_ALL, "Turkish");
    int i;
    char dizi[N][10] = { "istanbul","edirne","kars","van","bursa","ankara","hatay" };
    char ara_il[10],*sonuc;
    printf("S�ras�z liste\n\n");
    for (i = 0; i < N; i++) {
        printf("%s   ", dizi[i]);
    }
    printf("\n\n\n");
    qsort(dizi, N, sizeof(dizi[0]), KtenB);
    printf("Qsort algoritmas� ile K���k'ten B�y��e s�ralanm�� liste\n\n");
    for (i = 0; i < N; i++) {
        printf("%s   ", dizi[i]);
    }
    printf("\n\n\n");
    printf("%d\n", dizi);
    printf("Aranan:");
    scanf("%s",ara_il);
    sonuc = (char*)bsearch(&ara_il, &dizi, N, sizeof(dizi[0]), KtenB);
    if (sonuc != NULL) {
        printf("Ba�lang�� adresi %d olan dizi i�inde aranan de�eri buldum adresi : %s\n",sonuc, sonuc);
    }
    else {
        printf("Aranan say�y� bulamad�m.\n");
    }

    printf("\n\n\n");
    system("pause");
    return 0;
}

int KtenB(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}
int BtenK(const void* a, const void* b) {
    return (*(char*)b - *(char*)a);
}
