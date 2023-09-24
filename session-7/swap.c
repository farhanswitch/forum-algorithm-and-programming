#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
/**
 * Function yang parameter nya adalah value dari variabel
 * {int} x - Bilangan peratama
 * {int} y - Bilangan kedua
 */
void passByValue(int x, int y);
/**
 * Function yang parameter nya adalah address dari variabel
 * {int} x - Bilangan peratama
 * {int} y - Bilangan kedua
 */
void passByAddress(int *x, int *y);
/**
 * Function untuk bersihkan layar
 */
void clearscr()
{
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(__unix__) || defined(__unix) || \
    (defined(__APPLE__) && defined(__MACH__))
    system("clear");
#else
#error "OS not supported."
#endif
}
/**
 * Function untuk cek apakah suatu input merupakan bilangan yang valid
 * {char[]} str - input yang akan divalidasi
 * {bool} isAcceptNegative - apakah bilangan bulat negatif juga diizinkan
 * returns {bool}
 */
bool isValidNumber(char str[], bool isAcceptNegative);
int main()
{
    bool stillContinue = true;
    while (stillContinue)

    {
        clearscr();
        int num1 = 0, num2 = 0;
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Program Tukar Angka\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        while (true)
        {
            char inputNum[20];
            printf("Masukkan angka pertama: ");
            scanf("%s", inputNum);
            getchar();
            // Check apakah nilai yang diinput adalah bilangan yang valid
            if (isValidNumber(inputNum, true))
            {
                // Konversi dari string ke integer
                num1 = atoi(inputNum);
                break;
            }
            printf("Input tidak valid!\n");
        }
        while (true)
        {
            char inputNum2[20];
            printf("Masukkan angka kedua: ");
            scanf("%s", inputNum2);
            getchar();
            // Check apakah nilai yang diinput adalah bilangan yang valid
            if (isValidNumber(inputNum2, true))
            {
                // Konversi dari string ke integer
                num2 = atoi(inputNum2);
                break;
            }
            printf("Input tidak valid!\n");
        }

        printf("\nNilai setelah Pass by Value\n");
        passByValue(num1, num2);
        printf("Angka pertama = %d\n", num1);
        printf("Angka kedua = %d\n", num2);
        printf("\nNilai setelah Pass by Address\n");
        passByAddress(&num1, &num2);
        printf("Angka pertama = %d\n", num1);
        printf("Angka kedua = %d\n", num2);

        while (true)
        {
            char next;
            printf("Apakah anda ingin melanjutkan? (ketik y atau n): ");
            next = getchar();
            if (toupper(next) == 'Y')
            {
                break;
            }
            else if (toupper(next) == 'N')
            {
                stillContinue = false;
                break;
            }
            else
            {
                printf("Input tidak valid!\n");
            }
        }
    }

    return 0;
}

bool isValidNumber(char input[], bool isAcceptNegative)
{
    bool isValid = true;
    for (int i = 0; i < strlen(input); i++)
    {
        if (isAcceptNegative && i == 0 && input[i] == '-')
        {
            // do nothing
            isValid = true;
        }
        else
        {
            if (!isdigit(input[i]))
            {
                isValid = false;
                break;
            }
        }
    }
    return isValid;
}
void passByValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}
void passByAddress(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}