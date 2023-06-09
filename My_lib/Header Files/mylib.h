#pragma once
#pragma once
//Mang 1 chieu
void printValueFrequency(int* arr, int size);
void swap(int* ptr1, int* ptr2);
void sorted_array(int* arr, int size);
void printfArray(int* arr, int size);
//Mang 2 chieu
void freeMatrix(int** a, int rows);
void swapValue(void* value1, void* value2, int size);
void swapcolumns(int** a, int column1, int column2, int totalRow);
void swaprows(void** a, int row_1, int row_2);
int** allocate2Dmatrix(unsigned rows, unsigned columns);
void print2Dmatrix(int** matrix, unsigned rows, unsigned columns);
void freeMatrix(int** a, int rows);
