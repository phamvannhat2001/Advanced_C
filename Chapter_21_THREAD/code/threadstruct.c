#include <stdio.h>
#include <windows.h>

typedef struct {
    int param1;
    int param2;
} ThreadParams;

DWORD WINAPI threadFunction(LPVOID arg) {
    ThreadParams* params = (ThreadParams*)arg;
    int sum = params->param1 + params->param2;
    printf("Sum: %d\n", sum);
    return 0;
}

int main() {
    HANDLE thread;
    DWORD threadId;
    ThreadParams params;
    params.param1 = 5;
    params.param2 = 10;

    thread = CreateThread(NULL, 0, threadFunction, (LPVOID)&params, 0, &threadId);
    if (thread == NULL) {
        printf("Error creating thread\n");
        return 1;
    }

    WaitForSingleObject(thread, INFINITE);
    CloseHandle(thread);

    return 0;
}
