#include <stdio.h>
#include <stdarg.h>

void print_strings(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        char* str = va_arg(args, char*);
        printf("%s ", str);
    }

    va_end(args);
}

int main() {
    print_strings(3, "Hello", "world", "!");
    return 0;
}
