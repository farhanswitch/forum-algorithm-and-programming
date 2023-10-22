#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("filename.txt", "r");
    int ch = getc(fp);
    while (ch != EOF)
    {
        putchar(ch);
        ch = getc(fp);
    }
    if (feof(fp))
    {
        printf("\n Reached the end of file.");
    }
    else
    {
        printf("\n Something gone wrong.");
    }
    fclose(fp);
    getchar();

    return 0;
}