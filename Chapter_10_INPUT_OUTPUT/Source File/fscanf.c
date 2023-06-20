#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    FILE* fp = NULL;
    char words[MAX];
    char buff[255];

    fp = fopen("data.txt", "a+"); // Mở tệp để ghi và đọc

    if (fp == NULL) {
        fprintf(stderr, "Can't open file.\n"); //thong bao loi
        exit(EXIT_FAILURE);
    }

    while (fscanf(fp, "%s", buff) != EOF)
    {
        printf("%s ", buff);
    }

    puts("\nEnter words to add to the file; press the #");
    puts("Key at the beginning of a line to terminate.");

    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) //==1 if success read
    {
        fprintf(fp, "%s\n", words);
    }

    puts("File contents: ");
    rewind(fp);
    while (fscanf(fp, "%s", words) == 1)
    {
        puts(words);
    }

    puts("Done!");
   // fflush(fp);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "Error closing file\n");
    }

    return 0;
}
