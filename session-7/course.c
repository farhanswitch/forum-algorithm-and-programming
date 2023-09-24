#include <stdio.h>

int main()
{
    int N = 2; // Jumlah mata kuliah
    char listMataKuliah[2][50] = {"Algoritma dan Pemrograman", "Matematika Diskrit dan Aljabar Linear"};
    char listKodeMataKuliah[2][50] = {"COMP6112036", "MATH6184036"};
    int listSKS[2] = {4, 6};
    char listGrade[2] = {'B', 'A'};

    printf("==============================\n");
    printf("Program Daftar Mata Kuliah\n");
    printf("==============================\n");

    int i;
    for (i = 0; i < N; i++)
    {
        printf("%-15s: %s (%s)\n", "Mata Kuliah", listKodeMataKuliah[i], listKodeMataKuliah[i]);
        printf("%-15s: %d\n", "Jumlah SKS", listSKS[i]);
        printf("%-15s: %c\n\n", "Grade", listGrade[i]);
    }
    return 0;
}