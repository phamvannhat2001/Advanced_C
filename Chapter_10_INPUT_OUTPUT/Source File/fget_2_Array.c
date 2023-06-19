#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate2Dmatrix(char*** a, int rows, int columns)
{
    char** myMat = (char**)malloc(rows * sizeof(char*));
    if (myMat == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    for (int i = 0; i < rows; i++) {
        myMat[i] = (char*)malloc(columns * sizeof(char));

        if (myMat[i] == NULL) {
            printf("Memory allocation failed.\n");

            for (int j = 0; j < i; j++) {
                free(myMat[j]);
            }
            free(myMat);
            return;
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

    *a = myMat;
}

int main()
{
    int rows = 3;
    int columns = 256;
    char** matrix = NULL;

    allocate2Dmatrix(&matrix, rows, columns);

    // Giải phóng bộ nhớ
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
