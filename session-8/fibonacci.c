#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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
 * Function untuk mencari bilangan ke-n dari deret fibonacci dengan metode rekursif
 * {long} num - index dari bilangan yang akan dicari
 */
long fibonacciRecursion(long num);
/**
 * Function untuk mencari bilangan ke-n dari deret fibonacci dengan metode perulangan
 * {long} num - index dari bilangan yang akan dicari
 */
long fibonacciIteration(long num);
/**
 * Function untuk cek apakah suatu input merupakan bilangan yang valid
 * {char[]} str - input yang akan divalidasi
 * {bool} isAcceptNegative - apakah bilangan bulat negatif juga diizinkan
 * returns {bool}
 */
bool isValidNumber(char str[], bool isAcceptNegative);
void menuFibonacci();
int main()
{
  bool stillPlay = true;
  while (stillPlay)
  {
    clearscr();
    printf("========================================\n");
    printf("PROGRAM MENCARI BILANGAN FIBONACCI\n");
    printf("========================================\n");

    printf("Menu: \n");
    printf("1. Cari bilangan fibonacci\n");
    printf("2. Keluar\n");
    int indexMenu = 0;
    while (true)
    {

      printf("Silahkan pilih menu ( 1 atau 2 ): ");
      char menu[50];
      scanf("%s", menu);
      getchar();
      // Cek apakah menu yang dinput adalah bilangan yang valid
      if (isValidNumber(menu, false))
      {
        // Konversi menu dari string jadi integer
        int numberMenu = atoi(menu);
        if (numberMenu == 1 || numberMenu == 2)
        {
          indexMenu = numberMenu;
          break;
        }
      }
      printf("Menu yang anda pilih tidak valid!\n");
    }

    switch (indexMenu)
    {
    case 1:
      menuFibonacci();
      break;
    case 2:
      stillPlay = false;
      printf("Terima kasih telah menggunakan program kami!\n");
      break;
    default:
      break;
    }
  }
  return 0;
}

long fibonacciRecursion(long num)
{
  if (num == 0)
  {
    return 0;
  }
  if (num == 1)
  {
    return 1;
  }

  return fibonacciRecursion(num - 1) + fibonacciRecursion(num - 2);
}
long fibonacciIteration(long num)
{
  long first = 0;
  long second = 1;
  long next;
  if (num == 0)
    return first;
  if (num == 1)
    return second;

  for (int x = 2; x <= num; x++)
  {
    next = first + second;
    first = second;
    second = next;
  }
  return next;
}
void menuFibonacci()
{
  clock_t t;

  long num = 0;
  while (true)
  {
    char input[50];
    printf("Silahkan masukkan index dari bilangan Fibonacci yang ingin dicari: ");
    scanf("%s", input);
    getchar();
    // Cek apakah input adalah bilangan yang valid
    bool isValidInput = isValidNumber(input, false);
    if (isValidInput)
    {
      // Konversi input dari string ke integer
      int numberInput = atoi(input);
      if (input >= 0)
      {
        num = numberInput;
        break;
      }
    }
    printf("Input tidak valid! Tolong masukkan angka yang sama dengan atau lebih besar dari 0\n");
  }
  // Mencari bilangan Fibonacci dengan metode rekursif
  printf("\n----------------------------------------\n");
  printf("Fibonacci dengan Rekursif\n");
  printf("----------------------------------------\n");
  t = clock();
  long numRes = fibonacciRecursion(num);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;
  printf("Bilangan Fibonacci yang ke-%ld adalah: %ld\n", num, numRes);
  printf("Proses memerlukan waktu:  %f detik\n", time_taken);
  // Mencari bilangan Fibonacci dengan metode rekursif
  printf("\n----------------------------------------\n");
  printf("Fibonacci dengan Perulangan\n");
  printf("----------------------------------------\n");
  clock_t t2;
  t2 = clock();
  long numIteration = fibonacciIteration(num);
  t2 = clock() - t2;
  double time_taken2 = ((double)t2) / CLOCKS_PER_SEC;
  if (time_taken2 == 0.000000)
  {
    time_taken2 = 0.000001;
  }
  printf("Bilangan Fibonacci yang ke-%ld adalah: %ld\n", num, numIteration);
  printf("Proses memerlukan waktu:  %f detik\n", time_taken2);

  char fastest[15] = "";
  if (time_taken < time_taken2)
  {
    strcpy(fastest, "Rekursif");
  }
  else
  {
    strcpy(fastest, "Perulangan");
  }
  printf("\n\nProses yang paling cepat adalah dengan metode: %s\n", fastest);
  printf("Tekan enter untuk melanjutkan...");
  while (getchar() != '\n')
  {
  }
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
