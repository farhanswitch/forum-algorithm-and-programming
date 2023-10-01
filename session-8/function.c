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
 * Function untuk mendapatkan nama entitas desain
 * Params {string} designName
 * Params {string} designEntityNames
 */
void getDesignEntityNames(char designName[100], char designEntityNames[100]);
/**
 * Function untuk membuat laporan desain
 * Params {string} entityName
 */
void produceDesignReports(char entityName[100]);
/**
 * Function untuk gabungkan entitas desain
 * Params {string} entityName
 */
void collateEntities(char entityName[100]);
/**
 * Function untuk membuat laporan berdasarkan data entitas
 * Params {string} entityData
 */
void generateReport(char entityData[100]);
/**
 * Function untuk cek apakah suatu input merupakan bilangan yang valid
 * {char[]} str - input yang akan divalidasi
 * {bool} isAcceptNegative - apakah bilangan bulat negatif juga diizinkan
 * returns {bool}
 */
bool isValidNumber(char str[], bool isAcceptNegative);
void handleMenu1()
{
    char designName[100];
    char designEntityName[100];
    printf("Masukkan nama desain: ");
    scanf("%[^\n]s", designName);
    getchar();
    printf("Masukkan nama entitas desain: ");
    scanf("%[^\n]s", designEntityName);
    getchar();
    getDesignEntityNames(designName, designEntityName);
}
void handleMenu2()
{
    char designEntityName[100];
    printf("Masukkan nama entitas desain: ");
    scanf("%[^\n]s", designEntityName);
    getchar();
    produceDesignReports(designEntityName);
}
void handleMenu3()
{
    char entityName[100];
    printf("Masukkan nama entitas desain: ");
    scanf("%[^\n]s", entityName);
    getchar();
    collateEntities(entityName);
}
void handleMenu4()
{
    char entityData[100];
    printf("Masukkan data entitas: ");
    scanf("%[^\n]s", entityData);
    getchar();
    generateReport(entityData);
}
int main()
{
    bool stillPlay = true;
    while (stillPlay)
    {
        clearscr();
        printf("========================================\n");
        printf("PROGRAM BIRO DESAIN\n");
        printf("========================================\n");

        printf("Menu: \n");
        printf("1. Dapatkan Nama Entitas Desain\n");
        printf("2. Buat Laporan Desain\n");
        printf("3. Gabungkan Entitas\n");
        printf("4. Hasilkan Laporan\n");
        printf("5. Keluar\n");
        int indexMenu = 0;
        while (true)
        {

            printf("Silahkan pilih menu ( 1 sampai 5 ): ");
            char menu[50];
            scanf("%s", menu);
            getchar();
            // Cek apakah menu yang dinput adalah bilangan yang valid
            if (isValidNumber(menu, false))
            {
                // Konversi menu dari string jadi integer
                int numberMenu = atoi(menu);
                if (numberMenu >= 1 && numberMenu <= 5)
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
            handleMenu1();
            break;
        case 2:
            handleMenu2();
            break;
        case 3:
            handleMenu3();
            break;
        case 4:
            handleMenu4();
            break;
        case 5:
            stillPlay = false;
            printf("Terima kasih telah menggunakan program kami!\n");
            break;
        default:
            break;
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
void getDesignEntityNames(char designName[100], char designEntityNames[100])
{
    printf("\nMemanggil function getDesignEntityNames...\n");
    printf("Design Name: %s\nDesign Entity Names: %s\n", designName, designEntityNames);
    printf("\nTekan enter untuk melanjutkan...\n");
    while (getchar() != '\n')
    {
    }
}
void produceDesignReports(char entityName[100])
{
    printf("\nMemanggil function produceDesignReports...\n");
    printf("Entity Name: %s\n", entityName);
    printf("\nTekan enter untuk melanjutkan...\n");
    while (getchar() != '\n')
    {
    }
}
void collateEntities(char entityName[100])
{
    printf("\nMemanggil function collateEntities...\n");
    printf("Entity Name: %s\n", entityName);
    printf("\nTekan enter untuk melanjutkan...\n");
    while (getchar() != '\n')
    {
    }
}
void generateReport(char entityData[100])
{
    printf("\nMemanggil function generateReports...\n");
    printf("Entity Data: %s\n", entityData);
    printf("\nTekan enter untuk melanjutkan...\n");
    while (getchar() != '\n')
    {
    }
}