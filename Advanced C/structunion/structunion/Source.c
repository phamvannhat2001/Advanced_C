#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct point1
{
    int a;
    char b;
    unt16_t c;
    char d;
} POINT;

int main()
{
    POINT myPoint;
    printf("Kích thước của POINT: %zu", sizeof(char));

    return 0;
}
