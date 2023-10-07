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
 * Function untuk cek apakah email sesuai dengan format email yang valid
 * email {char[]}
 *
 * returns {bool}
 */
bool isValidEmail(char email[]);
/**
 * Name must contains letters and spaces only
 * {char[]} name - String that u wanna check is it valid name or not
 * returns {bool} - True if valid and False if not valid
 */
bool isValidName(char str[]);
/**
 * Check is valid phone number. Phone number must starts with 0 and minimum length is 11
 * {char[]} number = string that u wanna check
 * returns {bool}
 */
bool isValidPhoneNumber(char number[]);
typedef struct Contact
{
    char name[50];
    char phoneNumber[30];
    char emailAddress[50];
    char companyName[50];
    char companyPhone[30];
} CONTACT;
/**
 * Function to handle menu "Tampilkan Kontak"
 */
void menuGetAllContacts(CONTACT *listContact[], unsigned int COUNT);

/**
 * Function to handle menu "Tambah Kontak"
 */
void menuAddContact(CONTACT *listContact[], unsigned int *COUNT);
/**
 * Function to handle menu "Hapus Kontak"
 */
void menuDeleteContact(CONTACT *listContact[], unsigned int *COUNT);

void cleanUp(CONTACT *listContact[], unsigned int COUNT);

int main()
{
    bool stillPlay = true;

    unsigned int COUNT = 0;
    CONTACT **listContact;
    listContact = (CONTACT **)malloc(10 * sizeof(CONTACT *));
    if (listContact == NULL)
    {
        printf("Gagal mengalokasikan memori untuk Daftar Kontak.\n");
        return 1;
    }

    while (stillPlay)
    {
        unsigned short int menu = 0;
        clearscr();
        printf("========================================\n");
        printf("PROGRAM KELOLA KONTAK\n");
        printf("========================================\n");

        printf("\nMenu: \n");
        printf("1. Tampilkan Kontak\n");
        printf("2. Tambah Kontak\n");
        printf("3. Hapus Kontak\n");
        printf("4. Keluar\n");

        while (true)
        {
            char input[20];
            printf("\nPilih menu ( 1 - 4 ): ");
            scanf("%[^\n]s", input);
            getchar();

            // Check is user input is the valid number
            if (isValidNumber(input, false, false))
            {
                // Convert string to integer
                menu = atoi(input);
                if (menu >= 1 && menu <= 4)
                {
                    break;
                }
            }
            printf("Menu yang anda pilih tidak valid! Harap masukkan angka 1 - 4.\n");
        }
        switch (menu)
        {
        case 1:
            menuGetAllContacts(listContact, COUNT);
            break;
        case 2:
            menuAddContact(listContact, &COUNT);
            break;
        case 3:
            menuDeleteContact(listContact, &COUNT);
            break;
        case 4:
            printf("Terima aksih telah menggunakna program kami.\n");
            stillPlay = false;
            break;
        default:
            printf("Terima aksih telah menggunakna program kami.\n");
            stillPlay = false;
            break;
        }
    }

    // Free dynamic memory
    cleanUp(listContact, COUNT);
    return 0;
}

void menuGetAllContacts(CONTACT *listContact[], unsigned int COUNT)
{
    clearscr();
    if (COUNT == 0)
    {
        printf("Anda tidak memiliki kontak!.\n");
    }
    else
    {
        printf("DAFTAR KONTAK.\nAnda memiliki %d kontak.\n", COUNT);
        for (int i = 0; i < COUNT; i++)
        {
            CONTACT *currentContact = listContact[i];
            printf("\n%d. %-37s: %s\n", i + 1, "Nama", currentContact->name);
            printf("%-40s: %s\n", "No HP", currentContact->phoneNumber);
            printf("%-40s: %s\n", "Email", currentContact->emailAddress);
            printf("%-40s: %s\n", "Nama Perusahaan", currentContact->companyName);
            printf("%-40s: %s\n", "No Telepon Kantor", currentContact->companyPhone);
        }
    }

    printf("Tekan enter untuk melanjutkan...");
    while (getchar() != '\n')
    {
    }
}
void menuAddContact(CONTACT *listContact[], unsigned int *COUNT)
{
    clearscr();
    CONTACT *contact;
    contact = (CONTACT *)malloc(sizeof(CONTACT));
    if (contact == NULL)
    {
        printf("Gagal mengalokasikan memori untuk Kontak Baru.\nGagal membuat kontak.\n");
        return;
    }

    printf("Tambah Kontak.\n");
    // Input name
    while (true)
    {
        char input[50];
        printf("Nama Kontak: ");
        scanf("%[^\n]s", input);
        getchar();

        // Check is user input is valid name
        if (isValidName(input))
        {
            strncpy(contact->name, input, sizeof(input));
            break;
        }

        printf("Nama harus terdiri dari huruf dan spasi\n");
    }

    // Input Phone Number
    while (true)
    {
        char input[30];
        printf("NO HP: ");
        scanf("%[^\n]s", input);
        getchar();

        // Check is user input is a valid phone number
        if (isValidPhoneNumber(input))
        {
            strncpy(contact->phoneNumber, input, sizeof(input));
            break;
        }
        printf("Nomor telepon harus diawali dengan 0 dan minimal 11 karakter\n");
    }

    // Input email
    while (true)
    {
        char input[50];
        printf("Alamat email: ");
        scanf("%[^\n]s", input);
        getchar();

        // Check is user input is a valid email address
        if (isValidEmail(input))
        {
            strncpy(contact->emailAddress, input, sizeof(input));
            break;
        }

        printf("Email address yang nada masukkan tidak valid.\n");
    }

    // Input Company Name

    while (true)
    {

        char input[50];
        printf("Nama Perusahaan: ");
        scanf("%[^\n]s", input);
        getchar();

        if (strlen(input) > 0)
        {

            strncpy(contact->companyName, input, sizeof(input));
            break;
        }
        printf("Nama Perusahaan tidak boleh kosong.\n");
    }

    // Input Company Phone Number
    while (true)
    {
        char input[30];
        printf("No Telepon Kantor: ");
        scanf("%[^\n]s", input);
        getchar();

        // Check user input is a valid phone number
        if (isValidPhoneNumber(input))
        {
            strncpy(contact->companyPhone, input, sizeof(input));
            break;
        }
        printf("No Telepon harus diawali dengan 0 dan minimal 11 karakter.\n");
    }

    listContact[*COUNT] = contact;
    *COUNT = *COUNT + 1;
    printf("Kontak berhasil disimpan.\n");
    printf("\nTekan enter untuk melanjutkan...");
    while (getchar() != '\n')
    {
    }
}
void menuDeleteContact(CONTACT *listContact[], unsigned int *COUNT)
{
    clearscr();
    unsigned int totalContact = *COUNT;
    if (totalContact == 0)
    {
        printf("Anda tidak memiliki kontak!.\n");
        printf("\nTekan enter untuk melanjutkan...");
        while (getchar() != '\n')
        {
        }
        return;
    }

    printf("DAFTAR KONTAK.\nAnda memiliki %d kontak.\n", totalContact);
    for (int i = 0; i < totalContact; i++)
    {
        CONTACT *currentContact = listContact[i];
        printf("\n%d. %-37s: %s\n", i + 1, "Nama", currentContact->name);
        printf("%-40s: %s\n", "No HP", currentContact->phoneNumber);
        printf("%-40s: %s\n", "Email", currentContact->emailAddress);
        printf("%-40s: %s\n", "Nama Perusahaan", currentContact->companyName);
        printf("%-40s: %s\n", "No Telepon Kantor", currentContact->companyPhone);
    }

    unsigned int indexContactToDelete = 0;
    while (true)
    {
        char input[30];
        printf("\nPilih nomor urut kontak yang ingin dihapus (1-%d): ", totalContact);
        scanf("%[^\n]s", input);
        getchar();

        // Check is user input is a valid number
        if (isValidNumber(input, false, false))
        {
            // Convert string to integer
            indexContactToDelete = atoi(input);
            if (indexContactToDelete >= 1 && indexContactToDelete <= totalContact)
            {
                break;
            }
        }

        printf("Nomor urut kontak tidak valid!\n");
    }
    // Clean up dynamic memory for contact that u wanna delete
    free(listContact[indexContactToDelete - 1]);
    // Delete contact
    for (int i = indexContactToDelete; i < totalContact; i++)
    {
        listContact[i - 1] = listContact[i];
    }
    // Update total contact
    *COUNT = *COUNT - 1;
    printf("Kontak berhasil dihapus!\n");
    printf("\nTekan enter untuk melanjutkan...");
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

bool isValidEmail(char email[])
{
    bool isValid = false;
    int len = strlen(email);

    // Hanya melakukan pengecekan apakah memiliki karakter @
    for (int i = 0; i < len; i++)
    {
        if (email[i] == '@')
        {
            isValid = true;
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

bool isValidPhoneNumber(char number[])
{
    bool isValidDigit = isValidNumber(number, false, false);
    bool isStartsWithZero = number[0] == '0' ? true : false;
    bool hasValidLength = false;

    int len = strlen(number);
    if (len >= 11)
    {
        hasValidLength = true;
    }

    if (isValidDigit && isStartsWithZero && hasValidLength)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void cleanUp(CONTACT *lisContact[], unsigned int COUNT)
{
    for (int i = 0; i < COUNT; i++)
    {
        free(lisContact[i]);
    }

    free(lisContact);
}
