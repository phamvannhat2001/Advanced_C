#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

CRITICAL_SECTION criticalSection;
CONDITION_VARIABLE conditionVariable;
int sharedData = 0;

DWORD WINAPI producer(LPVOID lpParam) {
    for (int i = 0; i < 5; i++) {
        // Khóa critical section trước khi thay đổi dữ liệu chia sẻ
        EnterCriticalSection(&criticalSection);

        // Thay đổi giá trị của dữ liệu chia sẻ
        sharedData = i;

        printf("Producer: Produced data %d\n", sharedData);

        // Thông báo cho consumer rằng đã có dữ liệu mới
        WakeConditionVariable(&conditionVariable);

        // Mở khóa critical section sau khi hoàn thành
        LeaveCriticalSection(&criticalSection);

        // Tạm dừng để cho consumer tiêu thụ dữ liệu
        Sleep(1000);
    }

    return 0;
}

DWORD WINAPI consumer(LPVOID lpParam) {
    for (int i = 0; i < 5; i++) {
        // Khóa critical section trước khi kiểm tra dữ liệu chia sẻ
        EnterCriticalSection(&criticalSection);

        // Kiểm tra xem dữ liệu có sẵn hay không
        while (sharedData == 0) {
            // Chờ dữ liệu mới từ producer
            SleepConditionVariableCS(&conditionVariable, &criticalSection, INFINITE);
        }

        // Tiêu thụ dữ liệu
        printf("Consumer: Consumed data %d\n", sharedData);

        // Thiết lập lại giá trị của dữ liệu chia sẻ về 0
        sharedData = 0;

        // Mở khóa critical section sau khi hoàn thành
        LeaveCriticalSection(&criticalSection);
    }

    return 0;
}

int main() {
    HANDLE producerThread, consumerThread;

    // Khởi tạo critical section và condition variable
    InitializeCriticalSection(&criticalSection);
    InitializeConditionVariable(&conditionVariable);

    // Tạo các luồng producer và consumer
    producerThread = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    consumerThread = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    // Đợi các luồng hoàn thành
    WaitForSingleObject(producerThread, INFINITE);
    WaitForSingleObject(consumerThread, INFINITE);

    // Đóng handles của các luồng
    CloseHandle(producerThread);
    CloseHandle(consumerThread);

    // Hủy critical section và condition variable
    DeleteCriticalSection(&criticalSection);

    return 0;
}
