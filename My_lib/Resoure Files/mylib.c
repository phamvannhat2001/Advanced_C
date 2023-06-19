#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

void printValueFrequency(int* arr, int size)
{
    int leftflag;
    int countValue;
    int i, j;

    for (i = 0; i < size; i++)
    {
        leftflag = 0;

        // Check if the value was already counted
        for (int k = 0; k < i; k++)
        {
            if (arr[k] == arr[i])
            {
                leftflag = 1;
                break;
            }
        }

        if (leftflag == 1)
        {
            continue;
        }

        countValue = 1;

        for (j = i + 1; j < size; j++)
        {
            if (arr[j] == arr[i])
            {
                countValue++;
            }
        }
        printf("%d\t%d\n", arr[i], countValue);
    }
}
void swap(int* ptr1, int* ptr2)
{
    int temp;
    temp = *ptr2;
    *ptr2 = *ptr1;
    *ptr1 = temp;
}
void sorted_array(int* arr, int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);

            }
    }
}
void printfArray(int* arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
}
int* creatArray(int size)
{
    int i;
    int* arr = malloc(sizeof(int) * size); // Cấp phát bộ nhớ cho con trỏ arr

    if (arr == NULL) // Kiểm tra cấp phát bộ nhớ thành công hay không
    {
        printf("Khong du bo nho!\n");
        return 1;
    }
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    return arr;
}


//Array_2_dimention

void freeMatrix(int** a, int rows)
{
    for (int i = 0; i < rows; i++) {
        free(a[i]);
    }
    free(a);
}
void swapValue(void* value1, void* value2, int size)
{
    void* temp = malloc(size * sizeof(int));
    if (!temp) {
        return NULL;
    }

    memcpy(temp, value1, size * sizeof(int));
    memcpy(value1, value2, size * sizeof(int));
    memcpy(value2, temp, size * sizeof(int));

    free(temp);
}

void swapcolumns(int** a, int column1, int column2, int totalRow)
{
    int i;
    for (i = 0; i < totalRow; i++)
    {
        swapValue(&a[i][column1], &a[i][column2], 2);
    }
}

void swaprows(void** a, int row_1, int row_2)
{
    void* temp;
    temp = a[row_1];
    a[row_1] = a[row_2];
    a[row_2] = temp;
}

int** allocate2Dmatrix(unsigned rows, unsigned columns)
{
    int** a = (int**)malloc(rows * sizeof(int*));
    if (!a) {
        return NULL;
    }

    for (unsigned i = 0; i < rows; i++)
    {
        a[i] = (int*)malloc(columns * sizeof(int));
        if (!a[i])
        {
            freeMatrix(a, i);
            return NULL;
        }
    }

    //Nhap gia tri
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < columns; j++)
        {
            printf("\nEnter value a[%u][%u] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    return a;
}

void allocate2Dmatric(char*** a, int rows, int columns)
{
    int** myMat;
    int i;
    myMat = (char**)malloc(rows * sizeof(char*));
    if (myMat == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        myMat[i] = (char*)malloc(columns * sizeof(char));

        if (myMat[i] == NULL) {
            printf("Memory allocation failed.\n");

            for (int j = 0; j < i; j++) {
                free(myMat[j]);
            }
            free(myMat);
            return 1;
        }
    }

    //Nhap gia tri
    printf("Enter lines of text:\n");
    for (int i = 0; i < rows; i++) {
        fgets(myMat[i], columns, stdin);
    }

    //In gia tri

    printf("You entered:\n");
    for (int i = 0; i < rows; i++) {
        fputs(myMat[i], stdout);
    }
}

void print2Dmatrix(int** matrix, unsigned rows, unsigned columns)
{
    int** a = matrix;
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < columns; j++)
        {
            printf("%d \t", a[i][j]);
        }
        printf("\n");
    }
}

