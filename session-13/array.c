#include <stdio.h>
#include <stdlib.h>

/**
 * Function to implement static memory allocation
 */
void staticMemory();
/**
 * Function to implement dynamic memory allocation
 */
void dynamicMemory();

int main()
{

    staticMemory();
    dynamicMemory();
    return 0;
}

void staticMemory()
{
    int SIZE = 9;
    int data[SIZE];

    int i = 0;
    for (; i < SIZE; i++)
    {
        data[i] = i + 2;
    }

    // Print all values
    printf("Data Array of Number ( Memori Statis ) \n");
    i = 0;
    for (; i < SIZE; i++)
    {
        printf("Data ke-%d: %d\n", i + 1, data[i]);
    }
}

void dynamicMemory()
{
    int SIZE = 9;
    int *dataPtr;

    // Allocate memory
    dataPtr = (int *)malloc(SIZE * sizeof(int));

    // Handle if we failed to allocate memory for dataPtr
    if (dataPtr == NULL)
    {
        printf("Failed to allocate memory.\nProgram exit.\n");
        return;
    }

    // initiate data
    int i = 0;
    for (; i < SIZE; i++)
    {
        dataPtr[i] = i + 2;
    }

    // Print the data
    i = 0;
    printf("Data Array of Number ( Memori Dinamis ) \n");
    for (; i < SIZE; i++)
    {
        printf("Data ke-%d: %d\n", i + 1, dataPtr[i]);
    }

    // Release the memory
    free(dataPtr);
}