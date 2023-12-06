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
    printf("Sýrasýz liste\n\n");
    for (i = 0; i < N; i++) {
        printf("%s   ", dizi[i]);
    }
    printf("\n\n\n");
    qsort(dizi, N, sizeof(dizi[0]), KtenB);
    printf("Qsort algoritmasý ile Küçük'ten Büyüðe sýralanmýþ liste\n\n");
    for (i = 0; i < N; i++) {
        printf("%s   ", dizi[i]);
    }
    printf("\n\n\n");
    printf("%d\n", dizi);
    printf("Aranan:");
    scanf("%s",ara_il);
    sonuc = (char*)bsearch(&ara_il, &dizi, N, sizeof(dizi[0]), KtenB);
    if (sonuc != NULL) {
        printf("Baþlangýç adresi %d olan dizi içinde aranan deðeri buldum adresi : %s\n",sonuc, sonuc);
    }
    else {
        printf("Aranan sayýyý bulamadým.\n");
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
