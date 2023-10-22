#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Deklarasi variable
    char NIM[50];
    char name[100];
    char balance[100];

    // Baca file
    FILE *fp = fopen("data.txt", "r");
    // Check apakah berhasil buka file
    if (fp == NULL)
    {
        printf("Gagal membuka file\n");
        return 1;
    }
    else
    {
        printf("===================================================================\n");
        printf("%-10s|%-25s|%-25s\n", "NIM", "Nama", "Saldo");
        printf("===================================================================\n");

        while (fscanf(fp, "%s %[^0-9] %s", NIM, name, balance) != EOF)
        {

            printf("%-10s|%-25s|%-25s\n", NIM, name, balance);
        }
        printf("===================================================================\n");
    }
    fclose(fp);

    return 0;
}