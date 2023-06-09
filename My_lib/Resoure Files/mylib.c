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

