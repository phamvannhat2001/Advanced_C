#include <stdio.h>
#include <windows.h>

HANDLE mutex;
CONDITION_VARIABLE cond;
int sharedData = 0;
int isDataReady = 0;

DWORD WINAPI producer(LPVOID lpParam) {
    int newData = 42;

    // Tạo dữ liệu mới
    EnterCriticalSection(&mutex);
    sharedData = newData;
    isDataReady = 1;
    printf("Producer: Produced data %d\n", sharedData);
    WakeConditionVariable(&cond);
    LeaveCriticalSection(&mutex);

    return 0;
}

DWORD WINAPI consumer(LPVOID lpParam) {
    // Kiểm tra dữ liệu đã sẵn sàng chưa
    EnterCriticalSection(&mutex);
    while (!isDataReady) {
        SleepConditionVariableCS(&cond, &mutex, INFINITE);
    }
    int data = sharedData;
    printf("Consumer: Consumed data %d\n", data);
    LeaveCriticalSection(&mutex);

    return 0;
}

int main() {
    HANDLE producerThread, consumerThread;

    // Khởi tạo mutex và condition variable
    InitializeCriticalSection(&mutex);
    InitializeConditionVariable(&cond);

    // Tạo các luồng producer và consumer
    producerThread = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    consumerThread = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    // Đợi các luồng hoàn thành
    WaitForSingleObject(producerThread, INFINITE);
    WaitForSingleObject(consumerThread, INFINITE);

    // Đóng handles của các luồng
    CloseHandle(producerThread);
    CloseHandle(consumerThread);

    // Hủy mutex và condition variable
    DeleteCriticalSection(&mutex);

    return 0;
}
