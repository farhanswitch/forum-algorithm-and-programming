#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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
 * Function untuk menukar dua item dalam array
 * {int} indexA - index dari item pertama
 * {int} indexB - index dari item kedua
 */
void swap(int indexA, int indexB, char listStr[][20]);
/**
 * Function untuk sorting data dengan algoritma Quick Sort
 * {int} low - index array terkecil
 * {int} high - index array terbesar
 * {char[][20]} - array of string yang akan diurutkan
 * {bool} isAscending - Jika true maka akan diurutkan secara ascending dan jika false maka secara descending
 */
void quickSort(int low, int high, char listStr[][20], bool isAscending);
/**
 * Function recursive dalam mengurutkan data. Akan mengurutkan data dengan cara membagi array yg diurutkan menjadi 2 bagian
 * {int} index awal
 * {int} index akhir
 * {char[][20]} - array of string yang akan diurutkan
 * {bool} isAscending - Jika true maka akan diurutkan secara ascending dan jika false maka secara descending
 */
void quickSortRecursion(int low, int high, char listStr[][20], bool isAscending);
/**
 * Function untuk mencari index pivot dan menukar item sesuai urutan seharusnya
 * {int} index awal
 * {int} index akhir
 * {char[][20]} - array of string yang akan diurutkan
 * {bool} isAscending - Jika true maka akan diurutkan secara ascending dan jika false maka secara descending
 * returns {int} - Index pivot selanjutnya
 */
int partition(int low, int high, char listStr[][20], bool isAscending);
/**
 * {int} len - jumlah item di dalam array
 * {char[][20]} - array of string yang ingin ditampilkan
 */
void printArray(int len, char listStr[][20]);
int main()
{
    clearscr();
    int arrayLength = 10;
    bool isAscending = true;
    char nama[10][20] = {"Fahmi Harahap", "Icha Nurlisa", "Agus Gumilang", "Zelda Zuraida", "Felix Halim", "Deddy Corbuizer", "Hassan Makmur", "Makmun Sukur", "Bella Christie", "Chelshe Love"};

    printf("========================================\n");
    printf("PROGRAM SORTING DATA STRING\n");
    printf("========================================\n");

    printf("\nData sebelum di sorting: \n");
    printArray(arrayLength, nama);
    quickSort(0, arrayLength, nama, isAscending);
    printf("\nData setelah di sorting secara %s: \n", isAscending ? "Ascending" : "Descending");
    printArray(arrayLength, nama);

    return 0;
}

void swap(int indexA, int indexB, char listStr[][20])
{
    // Siapkan variabel temp untuk menyimpan data sementara
    char temp[20] = "";
    // Masukkan item dengan indexA ke temp
    strcpy(temp, listStr[indexA]);
    // Copy item dengan indexB ke item dengan IndexB
    strcpy(listStr[indexA], listStr[indexB]);
    // Copy item di temp ke IndexB
    strcpy(listStr[indexB], temp);
}
void quickSort(int low, int high, char listStr[][20], bool isAscending)
{
    // Lakukan proses rekursif. High dikurangi 1 karena index array dimulai dari 0
    quickSortRecursion(low, high - 1, listStr, isAscending);
}
void quickSortRecursion(int low, int high, char listStr[][20], bool isAscending)
{
    // Selama index awal (low) lebih kecil dari index akhir (high), maka rekursif akan terus berjalan untuk menukar item
    if (low < high)
    {
        // Mendaptkan index dari pivot
        int pivotIndex = partition(low, high, listStr, isAscending);
        // Mengurutkan item secara rekursif untuk item di sebelah kiri (index lebih kecil) pivot
        quickSortRecursion(0, pivotIndex - 1, listStr, isAscending);
        // Mengurutkan item secara rekursif untuk item di sebelah kanan (index lebih besar) pivot
        quickSortRecursion(pivotIndex + 1, high, listStr, isAscending);
    }
}
int partition(int low, int high, char listStr[][20], bool isAscending)
{
    char pivotValue[20] = "";
    // Set nilai pivot yaitu item paling akhir di bagian / partisi tersebut
    strcpy(pivotValue, listStr[high]);
    int i = low;
    for (int j = low; j < high; j++)
    {
        // Bandingkan string pivo dengan string saat ini
        int diff = strcmp(listStr[j], pivotValue);
        // Handle jika ingin diurutkan secara Ascending
        if (isAscending)
        {

            // Jika diff lebih kecil dari 0 artinya perlu ditukar urutan itemnya
            if (diff < 0)
            {
                // memastikan bahwa index yang ingin ditukar tidak sama
                if (i != j)
                {
                    // Menukar 2 item dalam array
                    swap(i, j, listStr);
                }
                i++;
            }
        }
        else
        {
            // Jika diff lebih besar dari 0, maka akan ditukar
            if (diff > 0)
            {
                // Memastikan bahwa index yang akan ditukar tidak sama
                if (i != j)
                {
                    // Menukar 2 item dalam array
                    swap(i, j, listStr);
                }
                i++;
            }
        }
    }
    // Memastikan index nya tidak sama
    if (i != high)
    {
        // Menukar 2 item dalam array
        swap(i, high, listStr);
    }
    return i;
}
void printArray(int len, char listStr[][20])
{
    // Cetak setiap item dalam array
    for (int i = 0; i < len; i++)
    {
        printf("%2d. %s\n", i + 1, listStr[i]);
    }
}