#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Function untuk cek apakah suatu input merupakan bilangan yang valid
 * {char[]} str - input yang akan divalidasi
 * {bool} isAcceptNegative - apakah bilangan bulat negatif juga diizinkan
 * returns {bool}
 */
bool isValidNumber(char str[], bool isAcceptNegative);
/**
 * Function untuk meminta input matrix berukuran 2 x 2 dari user
 * {int[][22]} matrix - array yang akan menyimpan nilai matrix
 */
void inputMatrix(int matrix[][2]);
/**
 * Function untuk mengalikan dua matrix
 * {int[][2]} matrix1 - Matrix pertama
 * {int[][2]} matrix2 - Matrix kedua
 * {int[][2]} matrixResult - Matrix hasil perkalian
 */
void matrixMultiplier(int matrix1[][2], int matrix2[][2], int matrixResult[][2]);
/**
 * Function untuk menampilkan matrix
 * {int[][2]} matrix - Matrix yang akan ditampilkan
 */
void printOutMatrix(int matrix[][2]);

int main()
{
    printf("==============================\n");
    printf("PROGRAM PERKALIAN MATRIKS 2 x 2\n");
    printf("==============================\n\n");

    int matrix1[2][2];
    int matrix2[2][2];
    int resultMatrix[2][2];
    printf("Masukkan elemen dari Matrix 1: \n");
    inputMatrix(matrix1);
    printf("Masukkan elemen dari Matrix 2: \n");
    inputMatrix(matrix2);
    matrixMultiplier(matrix1, matrix2, resultMatrix);
    printf("\nMatrix 1\n");
    printOutMatrix(matrix1);
    printf("\nMatrix 2\n");
    printOutMatrix(matrix2);
    printf("\nMatrix 1 x Matrix 2\n");
    printOutMatrix(resultMatrix);

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

void inputMatrix(int matrix[][2])
{
    for (int i = 0; i < 4; i++)
    {
        while (true)
        {
            char input[100];
            printf("Elemen ke %d: ", i + 1);
            scanf("%s", input);
            getchar();

            if (isValidNumber(input, true))
            {
                matrix[i / 2][i % 2] = atoi(input);
                break;
            }
            else
            {
                printf("Input yang anda masukkan tidak valid!\n");
            }
        }
    }
}
void matrixMultiplier(int matrix1[][2], int matrix2[][2], int matrixResult[][2])
{
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            matrixResult[x][y] = 0;
            for (int z = 0; z < 2; z++)
            {
                matrixResult[x][y] += (matrix1[x][z] * matrix2[z][y]);
            }
        }
    }
}
void printOutMatrix(int matrix[][2])
{

    printf(" --------------\n");
    for (int i = 0; i < 2; i++)
    {
        printf("| ");
        for (int j = 0; j < 2; j++)
        {
            printf("%5d |", matrix[i][j]);
        }
        printf(" \n");
        printf(" --------------\n");
    }
}