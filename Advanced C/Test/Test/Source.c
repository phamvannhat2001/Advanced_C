#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>
jmp_buf buffer;

void foo() {
    printf("Inside foo()\n");
    longjmp(buffer,6);
}

int main() {
    int i = setjmp(buffer);
    if (i == 0) {
        printf("Initial setjmp() call\n");
        foo();
        printf("say");
    }
    else {
        printf("Returned from longjmp()\n %d", i);
    }

    return 0;
}
