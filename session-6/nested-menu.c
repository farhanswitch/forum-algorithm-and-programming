#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

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
 * Function untuk menampilkan judul program
 * { char[] } menuName - nama menu (optional)
 */
void printTitle(char menuName[]);
void menuAdd(char listName[][100], int *count);
void menuView(char listName[][100], int count);
void menuUpdate(char listName[][100], int count);
void menuDelete(char listName[][100], int *count);
bool isValidMenu(char menu[]);
bool isValidNumber(char input[], bool isAcceptNegative);

int main()
{
    int count = 0;
    char listContact[100][100];
    bool isActive = true;
    while (isActive)
    {
        int menu = 0;
        clearscr();
        printTitle("");
        printf("Daftar Menu: \n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Update Contacts\n");
        printf("4. Delete Contacts\n");
        printf("5. Exit\n");

        while (true)
        {
            char inputMenu[100];
            printf("Pilih menu: ");
            scanf("%s", inputMenu);
            getchar();
            if (isValidMenu(inputMenu))
            {
                menu = atoi(inputMenu);
                break;
            }
            printf("Menu yang anda pilih tidak valid!\n");
        }

        switch (menu)
        {
        case 1:
            menuAdd(listContact, &count);
            break;
        case 2:
            menuView(listContact, count);
            break;
        case 3:
            menuUpdate(listContact, count);
            break;
        case 4:
            menuDelete(listContact, &count);
            break;
        case 5:
            printf("Terima kasih sudah menggunakan program kami.\nSampai jumpa\n");
            isActive = false;
        default:
            break;
        }
    }
    return 0;
}

void printTitle(char menuName[])
{
    if (strcmp(menuName, "") == 0)
    {
        printf("             PROGRAM KONTAK             \n");
    }
    else
    {
        printf("%-19s %20s\n", "PROGRAM KONTAK", menuName);
    }
}

void menuAdd(char listName[][100], int *count)
{
    clearscr();
    printTitle("Add Contact");
    char inputName[100];
    printf("Masukkan nama kontak: ");
    scanf("%[^\n]s", inputName);
    getchar();
    strcpy(listName[(*count)], inputName);
    *count += 1;
    printf("Tekan enter untuk kembali ke menu utama...");
    while (getchar() != '\n')
    {
    }
}
void menuView(char listName[][100], int count)
{
    clearscr();
    printTitle("View Contacts");
    if (count == 0)
    {
        printf("Anda tidak memiliki kontak!\n");
        printf("Tekan enter untuk kembali ke menu utama...");
        while (getchar() != '\n')
        {
        }
        return;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, listName[i]);
    }
    printf("Tekan enter untuk kembali ke menu utama...");
    while (getchar() != '\n')
    {
    }
}
void menuUpdate(char listName[][100], int count)
{
    clearscr();
    printTitle("Update Contact");
    if (count == 0)
    {
        printf("Anda tidak memiliki kontak!\n");
        printf("Tekan enter untuk kembali ke menu utama...");
        while (getchar() != '\n')
        {
        }
    }
    else
    {

        printf("Daftar kontak: \n");
        for (int i = 0; i < count; i++)
        {
            printf("%d. %s\n", i + 1, listName[i]);
        }

        int idContact = 0;
        while (true)
        {
            char inputId[100];
            if (count == 1)
            {

                printf("Masukkan id kontak yang akan diupdate: ( 1 ): ");
            }
            else
            {

                printf("Masukkan id kontak yang akan diupdate: ( 1 - %d): ", count);
            }
            scanf("%s", inputId);
            getchar();

            if (isValidNumber(inputId, true))
            {
                int numId = atoi(inputId);

                if (count == 1 && numId == 1)
                {
                    idContact = 0;
                    break;
                }
                else if (numId >= 1 && numId <= count)
                {
                    idContact = numId;
                    break;
                }
            }
            printf("Id yang diinput tidak valid!\n");
        }
        char inputNewName[100];
        printf("Masukkan nama kontak yang baru: ");
        scanf("%[^\n]s", inputNewName);
        getchar();
        strcpy(listName[idContact - 1], inputNewName);
        printf("\nKontak dengan id %d berhasil diupdate menjadi %s\n", idContact, inputNewName);
        printf("\nTekan enter untuk kembali ke menu utama...");
        while (getchar() != '\n')
        {
        }
    }
}
void menuDelete(char listName[][100], int *count)
{
    clearscr();
    printTitle("Delete Contact");
    if (*count == 0)
    {
        printf("Anda tidak memiliki kontak!\n");
        printf("Tekan enter untuk kembali ke menu utama...");
        while (getchar() != '\n')
        {
        }
    }
    else
    {

        printf("Daftar kontak: \n");
        for (int i = 0; i < *count; i++)
        {
            printf("%d. %s\n", i + 1, listName[i]);
        }

        int idContact = 0;
        while (true)
        {
            char inputId[100];
            if (*count == 1)
            {

                printf("Masukkan id kontak yang akan didelete: ( 1 )");
            }
            else
            {

                printf("Masukkan id kontak yang akan didelete: ( 1 - %d)", *count);
            }
            scanf("%s", inputId);
            getchar();

            if (isValidNumber(inputId, true))
            {
                int numId = atoi(inputId);

                if (*count == 1 && numId == 1)
                {
                    idContact = 0;
                    break;
                }
                else if (numId >= 1 && numId <= *count)
                {
                    idContact = numId;
                    break;
                }
            }
            printf("Id yang diinput tidak valid!\n");
        }
        char inputNewName[100];
        // Geser kontak setelah hapus salah satu kontak
        for (int i = idContact; i < *count; i++)
        {
            strcpy(listName[i - 1], listName[i]);
        }
        *count -= 1;
        printf("Kontak dengan id %d berhasil dihapus\n", idContact);
        printf("Tekan enter untuk kembali ke menu utama...");
        while (getchar() != '\n')
        {
        }
    }
}
bool isValidMenu(char menu[])
{
    switch (atoi(menu))
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return true;
    default:
        return false;
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