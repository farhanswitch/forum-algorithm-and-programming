#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("filename.txt", "w");
    if (fp == NULL)
    {
        printf("File annot be opened..");
    }
    return 0;
}