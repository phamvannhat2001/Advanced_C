#include <stdio.h>
#include <windows.h>

#define NUM_THREADS 5

int counter = 0;
HANDLE mutex;

DWORD WINAPI threadFunction(LPVOID arg) {
    // Khóa mutex trước khi truy cập vào biến counter
    WaitForSingleObject(mutex, INFINITE);

    // Tăng giá trị của counter
    counter++;

    // In giá trị của counter
    printf("Thread ID: %ld, Counter: %d\n", GetCurrentThreadId(), counter);

    // Mở khóa mutex sau khi hoàn thành
    ReleaseMutex(mutex);

    return 0;
}

int main() {
    HANDLE threads[NUM_THREADS];
    DWORD threadIds[NUM_THREADS];
    int i;

    // Khởi tạo mutex
    mutex = CreateMutex(NULL, FALSE, NULL);
    if (mutex == NULL) {
        printf("Failed to create mutex\n");
        return -1;
    }

    // Tạo các luồng
    for (i = 0; i < NUM_THREADS; i++) {
        threads[i] = CreateThread(NULL, 0, threadFunction, NULL, 0, &threadIds[i]);
        if (threads[i] == NULL) {
            printf("Failed to create thread\n");
            return -1;
        }
    }

    // Đợi các luồng hoàn thành
    WaitForMultipleObjects(NUM_THREADS, threads, TRUE, INFINITE);

    // Đóng handles của các luồng
    for (i = 0; i < NUM_THREADS; i++) {
        CloseHandle(threads[i]);
    }

    // Đóng mutex
    CloseHandle(mutex);

    return 0;
}
