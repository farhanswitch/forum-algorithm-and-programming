#include <stdio.h>
#include <string.h>

int main()
{
    // Menyimpan array of characters dengan panjang 20 karakter
    char nama1[20];
    // Menyimpan pointer ke character / array of characters
    char *nama2;
    // Menyimpan array pointer ke character / array of characters. Banyaknya pointer ada 20
    char *nama3[20];

    // Assign Value
    strcpy(nama1, "Brisia Jodie");
    nama2 = "Brisia Jodie";
    nama3[0] = "Brisia Jodie";

    printf("Nama 1: %s\n", nama1);
    printf("Nama 2: %s\n", nama2);
    printf("Nama 3: %s\n", nama3[0]);
}