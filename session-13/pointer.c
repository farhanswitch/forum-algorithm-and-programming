#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
 * Check is string is a string of number (positive / negative & integer / decimal)
 * {char[]} strNumber - String that u wanna check
 * returns {bool}
 */
bool isValidNumber(char str[], bool acceptNegative, bool acceptFloat);
/**
 * Name must contains letters and spaces only
 * {char[]} name - String that u wanna check is it valid name or not
 * returns {bool} - True if valid and False if not valid
 */
bool isValidName(char str[]);

typedef enum Prodi
{
    SISFOR = 1,
    TI,
    MB,
    TEKDUS,
    Other
} PRODI;
typedef struct Mahasiswa
{
    char ID[50];
    char Nama[50];
    PRODI Prodi;
    float GPA;
} MHS;
/**
 * Function to handle menu input data
 */
void menuInputData(MHS *listData[], int *COUNT);

/**
 * Function to handle tampilkan semua data
 */
void menuPrintAllData(MHS *listData[], int COUNT);
/**
 * Function to cleanup all dynamic allocation memory
 */
void cleanUp(MHS *listData[], int COUNT);
int main()
{
    bool stillPlay = true;
    int COUNT = 0;
    MHS *listMhs[50];

    while (stillPlay)
    {
        int menu = 0;
        clearscr();
        printf("========================================\n");
        printf("PROGRAM DATA MAHASISWA\n");
        printf("========================================\n");

        printf("Daftar Menu:\n");
        printf("1. Input Data Mahasiswa\n");
        printf("2. Tampilkan Semua Data Mahasiswa\n");
        printf("3. Keluar\n");

        while (true)
        {
            char input[20];
            printf("\nSilahkan pilih menu: ");
            scanf("%[^\n]s", input);
            getchar();

            // Check input is valid number
            if (isValidNumber(input, false, false))
            {
                // convert to integer
                menu = atoi(input);

                // Check is valid menu
                if (menu >= 1 & menu <= 3)
                {
                    break;
                }
            }
            printf("Menu yang anda pilih tidak valid!\n");
        }

        switch (menu)
        {
        case 1:
            menuInputData(listMhs, &COUNT);
            break;
        case 2:
            menuPrintAllData(listMhs, COUNT);
            break;
        case 3:
            printf("\nTerima kasih telah menggunakan program kami\n");
            stillPlay = false;
            break;
        }
    }

    cleanUp(listMhs, COUNT);
    return 0;
}
void menuInputData(MHS *listData[], int *COUNT)
{
    clearscr();
    printf("Menu Input Data\n\n");

    // allocate memory
    MHS *data = (MHS *)malloc(sizeof(MHS));

    if (data == NULL)
    {
        printf("Gagal mengalokasikan memori!\n");
        return;
    }

    while (true)
    {
        char input[50];
        printf("\nInput ID Mahasiswa: ");
        scanf("%[^\n]s", input);
        getchar();

        // check input is valid number
        if (isValidNumber(input, false, false))
        {
            // set name
            strcpy(data->ID, input);
            break;
        }
        printf("ID Mahasiswa hanya boleh berisi angka\n");
    }

    while (true)
    {
        char input[50];
        printf("\nInput Nama Mahasiswa: ");
        scanf("%[^\n]s", input);
        getchar();

        // check input is valid name
        if (isValidName(input))
        {
            // set data->Nama
            strcpy(data->Nama, input);
            break;
        }
        printf("Nama hanya boleh berisi huruf dan spasi\n");
    }

    printf("\nDaftar Program Studi: \n");
    printf("1. Sistem Informasi\n");
    printf("2. Teknik Informatika\n");
    printf("3. Manajemen Bisnis\n");
    printf("4. Teknik Industri\n");
    printf("5. Lainnya\n");

    while (true)
    {
        char input[50];
        printf("\nPilih nomor urut program studi: ");
        scanf("%[^\n]s", input);
        getchar();

        // check input is valid number
        if (isValidNumber(input, false, false))
        {
            // convert to integer
            int num = atoi(input);
            // check is valid prodi
            if (num >= SISFOR && num <= Other)
            {
                data->Prodi = num;
                break;
            }
        }
        printf("Input tidak valid. Silakan pilih nomor urut yang sesuai.\n");
    }

    while (true)
    {
        char input[50];
        printf("\nInput GPA: ");
        scanf("%[^\n]s", input);
        getchar();

        // check input is valid number
        if (isValidNumber(input, false, true))
        {
            // convert to float
            float num = atof(input);
            // check is valid GPA
            if (num >= 0 && num <= 4)
            {
                data->GPA = num;
                break;
            }
        }
        printf("Input tidak valid. GPA harus berupa angka dalam range 0.00 - 4.00\n");
    }

    listData[*COUNT] = data;
    *COUNT += 1;
    printf("Data berhasil disimpan.\n");
    printf("\nTekan enter untuk kembali ke menu utama...\n");
    while (getchar() != '\n')
    {
    }
}
void menuPrintAllData(MHS *listData[], int COUNT)
{
    clearscr();
    printf("Menu Tampilkan Semua Mahasiswa\n\n");
    if (COUNT == 0)
    {
        printf("Oops! Data Kosong.\n");
    }
    else
    {

        int i = 0;
        for (; i < COUNT; i++)
        {
            printf("%d. %-40s: %s\n", i + 1, "ID", listData[i]->ID);
            printf("   %-40s: %s\n", "Nama", listData[i]->Nama);
            printf("   %-40s: ", "Program Studi");

            switch (listData[i]->Prodi)
            {
            case SISFOR:
                printf("Sistem Informasi\n");
                break;
            case TI:
                printf("Teknik Informatika\n");
                break;
            case MB:
                printf("Manajemen Bisnis\n");
                break;
            case TEKDUS:
                printf("Teknik Industri\n");
                break;
            case Other:
                printf("Lainnya\n");
                break;
            }
            printf("   %-40s: %.2f\n", "GPA", listData[i]->GPA);
        }
    }
    printf("\nTekan enter untuk kembali ke menu utama...\n");
    while (getchar() != '\n')
    {
    }
}
bool isValidNumber(char str[], bool acceptNegative, bool acceptFloat)
{

    bool isValid = true;

    int startIndex = 48;
    int endIndex = 57;
    int indexDash = 45;
    int indexDot = 46;

    int len = strlen(str);
    if (len == 0)
    {
        return false;
    }
    int totalDot = 0;
    for (int i = 0; i < len; i++)
    {
        if (acceptNegative)
        {
            if (str[i] == indexDash && i == 0)
            {
                continue;
            }
        }
        if (acceptFloat)
        {
            if (str[i] == indexDot && i != 0 && i != len - 1 && totalDot == 0)
            {
                totalDot += 1;
                continue;
            }
        }
        if (!(str[i] >= startIndex && str[i] <= endIndex))
        {
            isValid = false;
            break;
        }
    }

    return isValid;
}

bool isValidName(char str[])
{
    int len = strlen(str);

    int startIndexUpperCase = 65;
    int endIndexUpperCase = 90;

    int startIndexLowerCase = 97;
    int endIndexLowerCase = 122;

    int indexSpace = 32;

    bool isValid = true;

    for (int i = 0; i < len; i++)
    {
        // Check is an uppercase letter
        bool isValidUpperCase = false;
        if (str[i] >= startIndexUpperCase && str[i] <= endIndexUpperCase)
        {
            isValidUpperCase = true;
        }
        // Check is an lowercase letter
        bool isValidLowerCase = false;
        if (str[i] >= startIndexLowerCase && str[i] <= endIndexLowerCase)
        {
            isValidLowerCase = true;
        }

        // Check is a space
        bool isABlankSpace = false;
        if (str[i] == indexSpace)
        {
            isABlankSpace = true;
        }

        if (!isValidUpperCase && !isValidLowerCase && !isABlankSpace)
        {
            isValid = false;
            break;
        }
    }
    return isValid;
}

void cleanUp(MHS *listData[], int COUNT)
{
    int i = 0;
    for (; i < COUNT; i++)
    {
        free(listData[i]);
    }
}