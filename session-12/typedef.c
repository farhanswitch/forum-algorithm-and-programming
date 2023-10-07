#include <stdio.h>
#include <string.h>

typedef struct Book
{
    char title[50];
    char writer[50];
} BOOK;

struct Painting
{
    char title[50];
    char creator[50];
};
int main()
{

    BOOK book1;
    strcpy(book1.title, "The Da Vinci Code");
    strcpy(book1.writer, "Dan Brown");

    struct Painting paint1;
    strcpy(paint1.title, "Madonna of The Rock");
    strcpy(paint1.creator, "Leonardo Da Vinci");

    printf("Book: \n");
    printf("Title: %s\n", book1.title);
    printf("Writer: %s\n", book1.writer);

    printf("\nPainting: \n");
    printf("Title: %s\n", paint1.title);
    printf("Creator: %s\n", paint1.creator);

    return 0;
}