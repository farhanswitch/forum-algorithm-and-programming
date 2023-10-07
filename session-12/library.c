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

typedef enum Publisher
{
    Gramedia = 1,
    Elexmedia,
    AndiOffset,
    Pustaka,
    OtherPublisher
} PUBLISHER;
typedef enum Category
{
    Fiction = 1,
    History,
    Novel,
    OtherCategory
} CATEGORY;
typedef struct Book
{
    char isbn[50];
    char title[50];
    char writer[50];
    unsigned int year;
    PUBLISHER publisher;
    CATEGORY category;
} BOOK;
/**
 * Function to handle menu "Tampilkan Buku"
 */
void menuGetListBooks(BOOK *listBook[], unsigned int COUNT);

/**
 * Function to print the Book
 */
void printBook(BOOK book, unsigned int id);
/**
 * Function to handle menu "Tambah Buku"
 */
void menuAddBook(BOOK *listBook[], unsigned int *COUNT);
/**
 * Function to handle mmenu "Hapus Buku"
 */
void menuDeleteBook(BOOK *listBook[], unsigned int *COUNT);

void cleanUp(BOOK *listBook[], unsigned int COUNT);
int main()
{
    unsigned int COUNT = 0;
    BOOK **listBook;
    listBook = (BOOK **)malloc(10 * sizeof(BOOK));

    if (listBook == NULL)
    {
        printf("Gagal mengalokasikan memori untuk Daftar Buku\n");
        return 1;
    }

    bool stillPlay = true;
    while (stillPlay)
    {
        unsigned short int menu = 0;
        clearscr();
        printf("========================================\n");
        printf("PROGRAM PERPUSTAKAAN\n");
        printf("========================================\n");

        printf("\nMenu: \n");
        printf("1. Tampilkan Buku\n");
        printf("2. Tambah Buku\n");
        printf("3. Hapus Buku\n");
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
            menuGetListBooks(listBook, COUNT);
            break;
        case 2:
            menuAddBook(listBook, &COUNT);
            break;
        case 3:
            menuDeleteBook(listBook, &COUNT);
            break;
        default:
            printf("Terima kasih telah menggunakan program kami.\n");
            stillPlay = false;
            break;
        }
    }

    cleanUp(listBook, COUNT);
    return 0;
}
void printBook(BOOK book, unsigned int id)
{
    if (id)
    {
        printf("\n%d. %-37s: %s\n", id, "ISBN", book.isbn);
    }
    else
    {
        printf("\n%-40s: %s\n", "ISBN", book.isbn);
    }

    printf("%-40s: %s\n", "Judul Buku", book.title);
    printf("%-40s: %s\n", "Penulis Buku", book.writer);
    printf("%-40s: %d\n", "Tahun Terbit", book.year);
    printf("%-40s: ", "Penerbit");
    switch (book.publisher)
    {
    case Gramedia:
        printf("Gramedia\n");
        break;
    case Elexmedia:
        printf("Elexmedia\n");
        break;
    case AndiOffset:
        printf("Andi Offset\n");
        break;
    case Pustaka:
        printf("Pustaka");
        break;
    default:
        printf("Lainnya\n");
        break;
    }
    printf("%-40s: ", "Kategori");
    switch (book.category)
    {
    case Fiction:
        printf("Fiksi\n");
        break;
    case History:
        printf("Sejarah\n");
        break;
    case Novel:
        printf("Novel\n");
        break;
    default:
        printf("Lainnya\n");
        break;
    }
}
void menuGetListBooks(BOOK *listBook[], unsigned int COUNT)
{
    clearscr();
    if (COUNT == 0)
    {
        printf("\nDaftar Buku kosong!\n");
        printf("Tekan enter untuk melanjutkan...");
        while (getchar() != '\n')
        {
        }
        return;
    }
    printf("Daftar Buku.\nAnda memiliki %d buah buku\n", COUNT);
    for (int i = 0; i < COUNT; i++)
    {

        printBook(*listBook[i], i + 1);
    }
    printf("Tekan enter untuk melanjutkan...");
    while (getchar() != '\n')
    {
    }
}
void menuDeleteBook(BOOK *listBook[], unsigned int *COUNT)
{
    clearscr();
    unsigned int totalBook = *COUNT;
    if (totalBook == 0)
    {
        printf("\nDaftar Buku kosong!\n");
        printf("Tekan enter untuk melanjutkan...");
        while (getchar() != '\n')
        {
        }
        return;
    }

    printf("Daftar Buku.\nAnda memiliki %d buah buku\n", totalBook);
    for (int i = 0; i < totalBook; i++)
    {

        printBook(*listBook[i], i + 1);
    }

    unsigned int indexToDelete = 0;
    while (true)
    {
        char input[10];
        printf("Pilih nomor urut buku yang akan dihapus (1-%d): ", totalBook);
        scanf("%[^\n]s", input);
        getchar();

        // Check is input user is a valid index
        if (isValidNumber(input, false, false))
        {
            // COnvert string to integer
            unsigned int num = atoi(input);
            if (num >= 1 && num <= totalBook)
            {
                indexToDelete = num;
                break;
            }
        }
        printf("Input tidak valid. Silahkan pilih dari nomor urut yang tersedia.\n");
    }

    free(listBook[indexToDelete - 1]);
    for (int i = indexToDelete; i < totalBook; i++)
    {
        listBook[i - 1] = listBook[i];
    }
    *COUNT = *COUNT - 1;
    printf("Buku berhasil dihapus.\n");
    printf("Tekan enter untuk melanjutkan...");
    while (getchar() != '\n')
    {
    }
}
void menuAddBook(BOOK *listBook[], unsigned int *COUNT)
{
    clearscr();
    unsigned int totalBook = *COUNT;
    printf("Buku baru: \n");
    BOOK *book;
    book = (BOOK *)malloc(sizeof(BOOK));

    if (book == NULL)
    {
        printf("Gagal mengalokasikan memori untuk Buku Baru.\n");
        printf("Tekan enter untuk melanjutkan...");
        while (getchar() != '\n')
        {
        }
        return;
    }

    // Input ISBN
    while (true)
    {
        char input[30];
        printf("ISBN (Angka 13 digit): ");
        scanf("%[^\n]s", input);
        getchar();

        // Check is input user is a valid ISBN number
        if (isValidNumber(input, false, false) && strlen(input) == 13)
        {
            strncpy(book->isbn, input, sizeof(input));
            break;
        }
        printf("Nomor ISBN terdiri dari 13 digit angka.\n");
    }

    // Input title
    while (true)
    {
        char input[50];
        printf("Judul Buku: ");
        scanf("%[^\n]s", input);
        getchar();

        // Check is input user is valid title
        if (strlen(input) > 0)
        {
            strncpy(book->title, input, sizeof(input));
            break;
        }
        printf("Judul Buku tidak boleh kosong\n");
    }

    // input writer
    while (true)
    {
        char input[50];
        printf("Penulis Buku: ");
        scanf("%[^\n]s", input);
        getchar();

        // Check is input user is valid name
        if (isValidName(input))
        {
            strncpy(book->writer, input, sizeof(input));
            break;
        }
        printf("Nama Penulis hanya boleh terdiri dari huruf dan spasi.\n");
    }

    // Input tahun terbit
    while (true)
    {
        char input[10];
        printf("Tahun Terbit: ");
        scanf("%[^\n]s", input);
        getchar();

        // Check is input user is a valid year
        if (isValidNumber(input, false, false))
        {
            // Convert string to integer
            book->year = atoi(input);
            break;
        }
        printf("Tahun Terbit harus berupa angka dan lebih besar dari 0.\n");
    }

    // Input publisher
    printf("\nDaftar Penerbit: \n");
    printf("1. Gramedia\n");
    printf("2. Elexmedia\n");
    printf("3. Andi Offset\n");
    printf("4. Pustaka\n");
    printf("5. Lainnya\n");
    while (true)
    {
        char input[10];
        printf("\nPenerbit (1-5): ");
        scanf("%[^\n]s", input);
        getchar();

        // Check is input user is valid publisher
        if (isValidNumber(input, false, false))
        {
            // Convert string to integer
            unsigned int num = atoi(input);
            if (num >= Gramedia && num <= OtherPublisher)
            {
                book->publisher = (PUBLISHER)num;
                break;
            }
        }
        printf("Penerbit tidak valid. Silahkan pilih salah satu dari daftar di atas.\n");
    }

    // Input Category
    printf("\nKategori Buku: \n");
    printf("1. Fiksi\n");
    printf("2. Sejarah\n");
    printf("3. Novel\n");
    printf("4. Lainnya\n");
    while (true)
    {
        char input[15];
        printf("\nPilih kategori buku: ");
        scanf("%[^\n]s", input);
        getchar();

        // Check is valid category
        if (isValidNumber(input, false, false))
        {
            // Convert string to integer
            unsigned int num = atoi(input);
            if (num >= Fiction && num <= OtherCategory)
            {
                book->category = (CATEGORY)num;
                break;
            }
        }
    }

    listBook[totalBook] = book;
    *COUNT = *COUNT + 1;
    printf("\nBuku berhasil disimpan.\n");
    printf("Tekan enter untuk melanjutkan...");
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

void cleanUp(BOOK *listBook[], unsigned int COUNT)
{
    for (int i = 0; i < COUNT; i++)
    {
        free(listBook[i]);
    }

    free(listBook);
}